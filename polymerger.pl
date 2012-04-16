## read in all the files and merge the ones that have the same starting prefix
# this is a very nasty and badly written hack by James Michael DuPont
# copyright 2009, AGPL 3.0 

use strict;
use warnings;
my $BASE=shift || die "the first parameter is the key for output";
sub value
{
    my $name=shift;
#    warn "looking at $name";
    if($name =~ /(\w+)_(\d+)\.poly/)
    {	
#	warn sprintf("%d_%0.3d",$1,$2);
	return sprintf("%s_%0.3d",$1,$2);
    }
    else
    {
#	warn "Bad!" . $name;
	return "";
    }
}

#parts of the key
my %parts;
my $processed=0;
sub Process
{
    my $key=shift;
    my $parts=shift;
    my $file ="merge/${BASE}_${key}.poly";
    warn "writing $file";
    open OUT, ">$file" or die "cannot open $file";
    print OUT "MergedFile\n";
    $parts .= "END\n";
    print OUT $parts;
    close OUT;

#    die if $processed++>10;    

}
opendir(IN,"out");
my $key ="";
my $count=0;
my $parts="";
my $filen= "";

foreach  (sort  map {value($_).":$_";}  readdir(IN))
{
    if(/(\w+)_(\d+):(.+)/)
    {
	my $nkey =$1;
	my $part=$2;
	my $filen=$3;
	warn "Processing $nkey $part $filen";
	if ($key ne $nkey)
	{	    
	    if ($count)
	    {
		warn "finished with $key at $count";
		Process($key,$parts);
		$parts="";
	    }
	    warn "starting $nkey";
	    $key=$nkey;
	    $count=0;
	}
	$count++;
	
	warn "opening $filen";
	open INF,"out/".$filen or die "cannot open $filen";
	
	my $linecount=0;
	while (<INF>)
	{
	    $linecount++;
	    if ($linecount ==2) # skip
	    {
		warn "Skipping $_";
		next;
	    }
	    next if /END/; # skip the end
	    $parts .= $_;
	}
	$parts .= "END\n";
	close INF;

    }
}
Process($key,$parts); #last one
closedir IN;
