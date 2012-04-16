use Algorithm::RectanglesContainingDot;
$a = Algorithm::RectanglesContainingDot->new;

sub Build
{
    my $infile=shift;
    open IN , "$infile";
    while(<IN>)
    {
#type:W current_id :20678253 name: Brooklyn Public Library: Central Branch ndcount:11 box : Min: Lat:40.672771 Lon:-73.9674641 Max: Lat:40.671482 Lon:-73.9687515
	#                        1           2           3                     4              5                    6                 7
	if (/type:W current_id :(\d+) name:(.*)ndcount:(\d+) box : Min: Lat:([\-\.\d]+) Lon:([\-\.\d]+) Max: Lat:([\-\.\d]+) Lon:([\-\.\d]+)/)
	{
	    my $name=$1 . ":" .$2;
	    my $x0  =$4;
	    my $y0  =$5;
	    my $x1  =$6;
	    my $y1  =$7;
	    $a->add_rectangle($name, $x0, $y0, $x1, $y1);
	}
	else
	{
	    warn $_;
	}
	
    }
    close IN;
}

sub Scan
{
    my $infile=shift;
    open IN , "$infile";
    while(<IN>)
    {
#type:W current_id :20678253 name: Brooklyn Public Library: Central Branch ndcount:11 box : Min: Lat:40.672771 Lon:-73.9674641 Max: Lat:40.671482 Lon:-73.9687515
	#                        1           2           3                     4              5                    6                 7
	if (/type:W current_id :(\d+) name:(.*)ndcount:(\d+) box : Min: Lat:([\-\.\d]+) Lon:([\-\.\d]+) Max: Lat:([\-\.\d]+) Lon:([\-\.\d]+)/)
	{
	    my $name=$1 . ":" .$2;
	    my $x0  =$4;
	    my $y0  =$5;
	    my $x1  =$6;
	    my $y1  =$7;
	    #//$a->add_rectangle($name, $x0, $y0, $x1, $y1);

	    my $x = ($x0 + $x1) /2;
	    my $y = ($y0 + $y1) /2;

	    my %seen;
	    chomp;
#	    print $_;


	    foreach my $r ($a->rectangles_containing_dot($x, $y))
	    {
	#	print "In:" . $r . "\n";
		$seen{$r}++ unless $name eq $r;
	    }

	    foreach my $r ($a->rectangles_containing_dot($x0, $y0))
	    {
	#	print "In:" . $r . "\n";
		$seen{$r}++ unless $name eq $r;
	    }

	    foreach my $r ($a->rectangles_containing_dot($x1, $y0))
	    {
	#	print "In:" . $r . "\n";
		$seen{$r}++ unless $name eq $r;
	    }

	    foreach my $r ($a->rectangles_containing_dot($x1, $y1))
	    {
	#	print "In:" . $r . "\n";
		$seen{$r}++ unless $name eq $r;
	    }

	    foreach my $r ($a->rectangles_containing_dot($x1, $y0))
	    {
	#	print "In:" . $r . "\n";
		$seen{$r}++ unless $name eq $r;
	    }
	    
	    print $_ . " -> ". join ("\t",(keys %seen)) . "\n";
	    
	    
	}
	else
	{
	    warn $_;
	}

    }
    close IN;
}

my $file=shift;
Build $file;
Scan $file;


