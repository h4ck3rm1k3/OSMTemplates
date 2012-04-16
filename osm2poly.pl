#!/usr/bin/perl

# script to convert an OSM file to a polygon file.
# the OSM file must follow certain conventions, namely
# each way must have a polygon_file and polygon_id tag,
# may have a note tag and must not have others.
#
# written by Frederik Ramm <frederik@remote.org>, public domain.
# hacked by James Michael DuPont <jamesMikeDuPont@gmail.com>, all changes AGPL 3.0

use strict;
use warnings;
my $poly_id;
my $poly_file;
my $polybuf;
#my $outbuf;
my $nodes;
my $id=0;
my %seen;
my %seenattr;

#
my @nodes;

while(<>) 
{
    if (/\<node/)
    {
	if (/^\s*<node.*\sid=["']([0-9-]+)['"].*lat=["']([0-9.eE-]+)["'] lon=["']([0-9.eE-]+)[\"\']/)
	{
	    $nodes->{$1}=[$2,$3];
	}
	else
	{
	    die "Bad Regex $_";
	}
    }
    elsif (/^\s*<way /)
    {
        undef $poly_id;
        undef $poly_file;
        $polybuf = "";
    }
    elsif (defined($polybuf) && /k=[\"\'](.*)[\"\']\s*v=[\"\'](.*?)[\"\']/)
    {
        if ($1 eq "polygon_file") 
        {
            $poly_file=$2;
        }
        elsif ($1 eq "polygon_id")
        {
            $poly_id=$2;
        }
	elsif ($1 eq 'admin_level'){}
	elsif ($1 eq 'attribution'){}
	elsif ($1 eq 'border_type'){}
	elsif ($1 eq 'boundary'){}
	elsif ($1 eq 'created_by'){}
	elsif ($1 eq 'is_in'){}
	elsif ($1 eq 'is_in:country'){}
	elsif ($1 eq 'is_in:country_code'){}
	elsif ($1 eq 'is_in:iso_3166_2'){}
	elsif ($1 eq 'is_in:state'){}
	elsif ($1 eq 'is_in:state_code'){}
	elsif ($1 eq 'left:county'){}
	elsif ($1 eq 'left:township'){}
	elsif ($1 eq 'maritime'){}
	elsif ($1 eq 'nist:fips_code'){}
	elsif ($1 eq 'nist:state_fips'){}
	elsif ($1 eq 'place'){}
	elsif ($1 eq 'place_name'){}
	elsif ($1 eq 'right:county'){}
	elsif ($1 eq 'right:state'){}
	elsif ($1 eq 'source'){}
	elsif ($1 eq 'tiger:CLASSFP'){}
	elsif ($1 eq 'tiger:CPI'){}
	elsif ($1 eq 'tiger:FUNCSTAT'){}
	elsif ($1 eq 'tiger:LSAD'){}
	elsif ($1 eq 'tiger:MTFCC'){}
	elsif ($1 eq 'tiger:NAME'){}
	elsif ($1 eq 'tiger:NAMELSAD'){}
	elsif ($1 eq 'tiger:PCICBSA'){}
	elsif ($1 eq 'tiger:PCINECTA'){}
	elsif ($1 eq 'tiger:PLACEFP'){}
	elsif ($1 eq 'tiger:PLACENS'){}
	elsif ($1 eq 'tiger:PLCIDFP'){}
	elsif ($1 eq 'tiger:STATEFP'){}
	elsif ($1 eq 'tiger:reviewed'){}
	elsif ($1 eq 'wikipedia'){}
	elsif ($1 eq 'addr:state'){}
	elsif ($1 eq 'collection'){}
	elsif ($1 eq 'colour'){}
	elsif ($1 eq 'description'){}
	elsif ($1 eq 'hour_off'){}
	elsif ($1 eq 'hour_on'){}
	elsif ($1 eq 'landuse'){}
	elsif ($1 eq 'leisure'){}
	elsif ($1 eq 'line'){}
	elsif ($1 eq 'maxheight'){}
	elsif ($1 eq 'maxheight:feet'){}
	elsif ($1 eq 'military'){}
	elsif ($1 eq 'modifier'){}
	elsif ($1 eq 'name:de'){}
	elsif ($1 eq 'name:en'){}
	elsif ($1 eq 'name:fr'){}
	elsif ($1 eq 'name:ru'){}
	elsif ($1 eq 'network'){}
	elsif ($1 eq 'note'){}
	elsif ($1 eq 'operator'){}
	elsif ($1 eq 'railway'){}
	elsif ($1 eq 'ref'){}
	elsif ($1 eq 'restriction'){}
	elsif ($1 eq 'route'){}
	elsif ($1 eq 'shop'){}
	elsif ($1 eq 'state'){}
	elsif ($1 eq 'state_id'){}
	elsif ($1 eq 'surface'){}
	elsif ($1 eq 'symbol'){}
	elsif ($1 eq 'type'){}
	elsif ($1 eq 'url'){}
	elsif ($1 eq 'wikipedia:en'){}

        elsif ($1 eq 'ZCTA5CE')
        {
#            print ("cannot process tag '$1' with val '$2' \n");
	    $poly_file=$2;
	    $poly_id=$2;

        }

	elsif ($1 eq 'name'){
	    $poly_file=$2;
	    $poly_id=$2;
	}
	elsif ($1 eq 'waterway'){}

	else
	{
	    
	    print "elsif (\$1 eq '$1'){}\n" unless $seenattr{$1}++;
	    
	}
    }
    elsif (/^\s*<nd ref=[\'\"]([0-9-]+)[\"\']/)
    {
	my $id=$1;
	warn("dangling reference to node $id") unless defined($nodes->{$id});
	push @nodes,$id;
	
	$polybuf .= sprintf("   %E   %E\n", $nodes->{$id}->[1], $nodes->{$id}->[0]);
    }
    elsif (/^\s*<\/way/) 
    {
	if (!defined($polybuf))
	{
	    die("incomplete way definition");
	}
	next unless defined($poly_id);
	next unless defined($poly_file);
	my $outbuf = "$poly_id\n$polybuf"."END\nEND\n";
	my $count =$seen{${poly_file}}++;
	my $filename="${poly_file}_$count.poly";
	$filename =~ s/\W/_/g; ## clean up 

	{
	    mkdir "out" unless -d "out";
	    open OUT, ">out/$filename" or die "cannot open out/$filename";
	    print OUT "$filename\n";
	    print OUT "$outbuf";
	    $outbuf ="";
	    close OUT;
	    
	}
	
	undef $polybuf;
    }
}
$poly_file = "polygon" unless defined($poly_file);

my @parts;
my $base="wget http://api.openstreetmap.org/api/0.6/nodes?nodes=";
open OUT, ">get.sh";
my %seen2;
my $batch=1;
foreach my $id (@nodes )
{
    chomp $id;
    next if $seen2{$id}++;
    push @parts,$id;
#    warn "LOOK $id";
    if ($#parts >100)
    {
	print OUT "$base". join (",",@parts) . " --output-document=fetch_${batch}.osm\n";;
	@parts=();	    
    }
    $batch++;
}
if (@parts)
{
    print OUT "$base". join (",",@parts) . " --output-document=fetch_${batch}.osm\n";;
}

