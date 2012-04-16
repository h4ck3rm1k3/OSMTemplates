# copyright 2009 James Michael DuPont
# license AGPL 3.0
# http://www.fsf.org/licensing/licenses/agpl-3.0.html

use HTML::TableContentParser;
use strict;
use warnings;
use Data::Dumper;

my $ids = {
    '<A HREF="http://www.epa.gov/superfund/action/law/cercla.htm" target=_blank>COMPREHENSIVE ENVIRONMENTAL RESPONSE, COMPENSATION AND INFORMATION SYSTEM</A>' => "cercla",
    '<A HREF="http://www.epa.gov/osw/hazard/tsd/index.htm" target=_blank>RESOURCE CONSERVATION AND RECOVERY ACT INFORMATION SYSTEM</A>' => "RCRAISTSD",
    '<A HREF="http://www.epa.gov/osw/hazard/correctiveaction/index.htm" target=_blank>RESOURCE CONSERVATION AND RECOVERY ACT INFORMATION SYSTEM</A>' => 'RCRAISCA',
    '<A HREF="http://www.epa.gov/brownfields/" target=_blank>Office of Brownfields and Land Revitalization</A>' => "brownfields",
    '<A HREF="http://cfpub.epa.gov/npdes/" target=_blank>INTEGRATED COMPLIANCE INFORMATION SYSTEM</A>' =>"npdesicis",
    '<A HREF="http://cfpub.epa.gov/npdes/" target=_blank>PERMIT COMPLIANCE SYSTEM</A>' => "npdespcs",
    '<A HREF="http://www.epa.gov/osw/hazard/generation/lqg.htm" target=_blank>RESOURCE CONSERVATION AND RECOVERY ACT INFORMATION SYSTEM</A>	668RESOURCE CONSERVATION ARESOURCE CONSERVATION AND RECOVERY ACT INFORMATION SYSTEM`RESOURCE CONSERVATION AND RECOVERY ACT INFORMATION SYSTEMRESOURCE CONSERVATION AND RECOVERY ACT INFORMATION SYSTEMND RECOVERY ACT INFORMATION SYSTEM' => "RCARAIS",
    '<A HREF="http://www.epa.gov/RESOURCE CONSERVATION AND RECOVERY ACT INFORMATION SYSTEMRESOURCE CONSERVATION AND RECOVERY ACT INFORMATION SYSTEMair/oaqps/permits/obtain.html" target=_blank>AEROMETRIC INFORMATION RETRIEVAL SYSTEM / AIRS FACILITY SYSTEM</A>' => "AIRSAFS",
    '<A HREF="http://www.epa.gov/tri/" target=_blank>TOXIC CHEMICAL RELEASE INVENTORY SYSTEM</A>'=>"TCRIS"
};

my @columns =    
    (
    "REGISTRYID",
    "COUNTY NAME",
    "STREET",
    "LONGITUDE",
    "HORIZONTAL DATUM",
    "LOCATION ADDRESS",
    "ZIP",
    "STATE",
    "LATITUDE"
    );

sub DatabaseAdd
{
    my $o =shift;
# COUNTY NAME	3482
# REGISTRY ID	3484
# STREET	3484
# LONGITUDE	3484
# HORIZONTAL DATUM	3484
# LOCATION ADDRESS	3484
# ZIP	3484
# STATE	3484
# LATITUDE	3484
    my @values;
    foreach my $c (@columns)
    {
	push @values, "'" . ($o -> {$c} || "NULL") . "'";
    }
    print join(",",@values) ."\n";
}

my %schema = (
    "STATE" => 0,
    "ZIP" => 0,
    "STREET" => 0,
    "AREA" => 0,
    );

my %heading = (
    "PROGRAM"  => 1,
);

my %details = (
#HEADING    "PROGRAM"  => {},
    "HORIZONTAL DATUM"  => {},
# 	WGS84:	3484

    "COLLECTION METHOD" => {},

# combined into area
#    "COUNTY NAME" => {},
#    "STATE" => {},
#    "ZIP" => {},
    "AREA" => {},


# REGISTRY ID	3484
# LONGITUDE	3484
# LOCATION ADDRESS	3484
# LATITUDE	3484

);

my %parse = (
   "REGISTRY ID"  => sub {
	my $val = shift;
	my $data = shift;
#	warn "$val";
	if ($val =~ /(\d+)/)
	{
	    $data->{"REGISTRYID"}=$1;
	}
	else
	{
#	    $data->{"REGISTRYID"}="UNKNIONW";
	}
    },

    "LOCATION ADDRESS" => sub { 
	my $val = shift;
	my $data = shift;
	my @parts = split ",",$val;
	my $state = pop @parts;
	my $city = pop @parts;
#	my ($street,$city,$state) = split ",",$val;
	#warn Dumper(@parts);
	if ($state =~ /(\w+) (\d+)/)
	{
	    my $st = $1;
	    my $zip = $2;
#	    warn $zip;
	    $data -> {STATE} = $st;
	    $data -> {ZIP} = $zip;
	    $data -> {STREET} = join '\t', @parts;

	    # #return {
	    # 	state => $st,
	    # 	ZIP => $zip,
	    # 	addr => [@parts],		
	    # };
	}
	else
	{
#	    warn $val;
#no zip code!
#UNKNOWN, ALAKANUK, AK  at parse.pl line 31.
#UNKNOWN, ARCTIC VILLAGE, AK  at parse.pl line 31.
#VIADUCT RD, CHICKASAW, AL  at parse.pl line 31.
#BOUNDED BY ADAMS/NEWTON AVES & PROGRESS/MAPLE STS, CAMDEN, AR  at parse.pl line 31.
	    # return {
	    # 	state => $state,
	    # 	zip => "NONE",
	    # 	addr => [@parts],		
	    # };
	    $data -> {STATE} = $state;
	    $data -> {ZIP} = "NONE";
	    $data -> {STREET} = join '\t', @parts;


	}

	$schema{STATE}++;
	$schema{ZIP}++;
	$schema{STREET}++;
#	$details{state}{$data->{state}}++;
#	$details{zip}{$data->{zip}}++;

    });
    

sub Parse
{ 
    my $file =shift;
    my $HTML;
    my $tcp = HTML::TableContentParser->new;
    {
	local( $/, *FH ) ;
	open( FH, $file ) or die "cannot open $file with error $!\n";
	$HTML = <FH>;
    }
    

    my $tables = $tcp->parse($HTML);
    
#warn Dumper($tables);
    
    my %data; 
    
    foreach my $table (@{$tables}) {
	my @headers = map { $_->{data} } @{ $table->{headers} };
	# attributes of table tag available as keys in hash
	my $table_width = $table->{width};
	
	
# for each row
	foreach my $row (@{$table->{rows} }) {

# in our case, we know that the row will have two columns, we can just push the data into there.
	    my @ROW;

	    #for each column
	    foreach my $col (@{ $row->{cells} }) {
		# attributes of td tag available as keys in hash
		my $data = $col->{data};


#	print("DATA:$data\n");
		push @ROW,$data;
		
	    }
	    
	    my $name  =$ROW[0]; # the first column
	    my $value =$ROW[1]; # the second column

	    if (($name) && ($value))
	    {
		next if ($heading{$name}); # skip headings

#store the name value pair in the data hash 
		$data{$name}=$value;

#count the field name in the schema
		$schema{$name}++;

# if we are collecting details on this one field, store it
		if ($details{$name})
		{
		    # add the name/value pair for detail fiels, be careful, it can get big.
		    $details{$name}{$value}++;
		}
		if ($parse{$name})
		{
		    # call the parse routine on the value, overwrite the value
		    &{$parse{$name}}($value,\%data);
		}

	    }
	    else
	    {
		#'bgcolor' => '#9CBCE2'
		#warn Dumper($row);
	    }
	    
	}# end of row
	
	
    } # end of table


    #Derive(\%data);
#    my $area =    $data{"COUNTY NAME"} ." " . $data{"STATE"} . " " . $data{"ZIP"};
#    warn $area;
#    $details{"AREA"}{$area}++;
#    $schema{AREA}++;
    
#    warn Dumper(\%data);
#    return  \%data;
    DatabaseAdd(\%data);
}



sub ProcessDir
{
    my $dir=shift;
    warn "reading $dir";
    opendir(DIR, $dir);
    my @epafiles = readdir(DIR);
    foreach my $file (@epafiles)
    {
#	warn $file;
	next unless ($file =~/national_kml.registry_html/); # only process the results of the wget

	$schema{"FILES"}++; # cound the number of files

	if (-B $file)
	{
	    $schema{"NULL"}++; # count the null recotds
	}
	else
	{
	    Parse $dir ."/" .$file;
	}
    }
    closedir DIR;
}

# process the current directory
my @parts = (
    "110" ,
    "1100" ,
    "11000",
    "110000" ,
    "1100000" ,
    "11000000" 
    );

for my $y (@parts)
{
    for my $x (1..9)
    {
	my $dir = $y . $x;

	ProcessDir $dir;
    }
}

foreach my $k (sort {$schema{$a} <=> $schema{$b} } keys %schema)
{
    my $c =$schema{$k};
    warn "$k\t$c\n";

#    warn Dumper($details{$k});
    # foreach my $d (sort {$details{$k}{$a} <=> $details{$k}{$b} } keys %{$details{$k}})
    # {
    # 	my $c =$details{$k}{$d};
    # 	print "\t$d:\t$c\n";
    # }

}

# example output 

# COLLECTION METHOD	3263
# 	PUBLIC LAND SURVEY-SECTION:	1
# 	GPS CARRIER PHASE KINEMATIC RELATIVE POSITION:	1
# 	GPS CODE (PSEUDO RANGE) STANDARD POSITION (SA ON):	2
# 	GPS CODE (PSEUDO RANGE) PRECISE POSITION:	2
# 	LORAN C:	3
# 	GPS, WITH CANADIAN ACTIVE CONTROL SYSTEM:	3
# 	ADDRESS MATCHING-NEAREST INTERSECTION:	3
# 	INTERPOLATION-SATELLITE:	3
# 	ADDRESS MATCHING-STREET CENTERLINE:	4
# 	GPS CODE (PSEUDO RANGE) STANDARD POSITION (SA OFF):	4
# 	INTERPOLATION-OTHER:	5
# 	ADDRESS MATCHING-DIGITIZED:	6
# 	CENSUS BLOCK/GROUP-1990-CENTROID:	6
# 	PUBLIC LAND SURVEY - EIGHTH SECTION:	7
# 	CLASSICAL SURVEYING TECHNIQUES:	10
# 	ADDRESS MATCHING-BLOCK FACE:	11
# 	ADDRESS MATCHING-PRIMARY NAME:	14
# 	INTERPOLATION - DIGITAL MAP SRCE (TIGER):	44
# 	INTERPOLATION-PHOTO:	63
# 	UNKNOWN:	63
# 	GPS CARRIER PHASE STATIC RELATIVE POSITION:	116
# 	INTERPOLATION-MAP:	164
# 	GPS - UNSPECIFIED:	175
# 	GPS CODE (PSEUDO RANGE) DIFFERENTIAL:	225
# 	ADDRESS MATCHING-OTHER:	309
# 	ADDRESS MATCHING-HOUSE NUMBER:	2019
# COUNTY NAME	3482
# REGISTRY ID	3484
# LONGITUDE	3484
# HORIZONTAL DATUM	3484
# 	WGS84:	3484
# LOCATION ADDRESS	3484
# LATITUDE	3484
# FILES	3993
