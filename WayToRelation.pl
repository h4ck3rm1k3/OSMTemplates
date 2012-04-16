#   copyright 2009 
#   "James Michael Dupont (H4ck3rm1k3)"  <jamesmikedupont@gmail.com>
#   http://www.fsf.org/licensing/licenses/agpl-3.0.html

#   takes two ways and finds the common waypoints...
#   just the start of the processing.

use strict;
use XML::Twig;
use warnings;

# input is two ways in two files

# first look for nodes that are shared.
sub ProcessFile
{
    my $file=shift;
    my $twig= new XML::Twig();                              # create the twig
    
    $twig->parsefile( $file);
   
    my $world= $twig->root;                           # grab the root
    my @nodes= $world->children('node');              # get its children
    my @ways= $world->children('way');                # get its children
    my %nodes;    
    my @way; #in the way, an array of nodes
    foreach my $node ( @nodes)
    { 
#	warn "$node ";
	#print $node->print();
#	my $id  = $node->first_child( "id")->text;
#	my $lat = $node->first_child( "lat")->text;
#	my $lon = $node->first_child( "lon")->text;

#id="-286" lat="40.729110" lon="-74.535390"/
	my $id  = $node->att( 'id');  # get the elements
	my $lat = $node->att( 'lat');  # get the elements
	my $lon = $node->att( 'lon');  # get the elements
#	print "$id: \t$lat\t$lon\n";                    # print the info 
	#$nodes{"$lat|$lon"}{$file}{count}++;
	my $key ="$lat|$lon";
	die "$key is duplicate in file" if $nodes{key}{$key};
	# all the nodes are unique in a file
	$nodes{key}{$key}=$id;
	$nodes{id}{$id}=$key;
    }
    foreach my $way ( @ways)
    {
#	warn "$way ";
	foreach my $ref ($way->children('nd'))
	{
	    my $id = $ref->att("ref");
#	    print "$id " . $nodes{id}{$id} . "\n";
	    push @way,$nodes{id}{$id};
	}    
    }
    
    $nodes{way}=\@way;

    return \%nodes;

}


sub BruteForce
{
    my $in=0;
# mark each one as shared
    foreach my $n (@{$a->{way}})
    {
	$in++;
	my $im=0;
	#look for that way in the second one.
	foreach my $m (@{$b->{way}})
	{
	    $im++;
	    if ($n eq $m)
	    {
		warn "match $n \[$in\] $m \[$im\]";
	    }
	}
    }
}

# process a range of nodes
sub Process 
{
    my $a=shift;
    my $b=shift;
    my @edges = @_;
    foreach my $e (@edges)
    {
	warn "Match:". $e->[0] . "|" . $e->[1] . "\n";
    }
}


sub General
{
    my $a=shift;
    my $b=shift;
    my $in=0;    

#    foreach my $x ($#$a
#    print length($a);
    print "Length of a:" . $#{$a} . "\n";
    print "Length of b:" . $#{$b} . "\n";

    my @match; # the array of matched nodes

    # now scan in a direction 
    for (my $in =0; $in< $#{$a}; $in ++)
    {
	my $found=0;
	my $n = $a->[$in];

#	for my $im ($#{$b} .. 0)
	for (my $im =0; $im< $#{$b}; $im ++)
	{
	    my $m = $b->[$im];
	    if ($m  eq $n)
	    {
		warn "match $n \[$in\] $m \[$im\]";		
		push @match,[$in,$im];
		$found++;
		# we dont need to process the rest of b
		$im=$#{$b}; # short circut the search
	    }
	}

	#if we did not find a match for this node, prcocess the matches and reset the list
	if (!$found)
	{
	    Process $a,$b,@match;	
	    @match=();
	}
    }
}

sub ProcessPair
{
    my $a= ProcessFile shift;
    my $b= ProcessFile shift;   
    General ($a->{way},$b->{way});
}


# 
ProcessPair @ARGV;

