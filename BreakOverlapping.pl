use Algorithm::BreakOverlappingRectangles;
$a = Algorithm::BreakOverlappingRectangles->new;

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
#	    my $name=$1 . ":" .$2;
	    my $name=$1;
	    my $x0  =$4;
	    my $y0  =$5;
	    my $x1  =$6;
	    my $y1  =$7;

#	    $a->add_rectangle( A =>  0,  4,  7, 10);
	    #$a->add_rectangle($name => $x0, $y0, $x1, $y1);
	    $a->add_rectangle($x0, $y0, $x1, $y1, $1);
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
#Scan $file;

my $rect = $a->get_rectangles_as_array_ref;
for (@$rect)
{
    my @ids = @$_;
    my $x0 = shift @ids;
    my $y0 = shift @ids;
    my $x1 = shift @ids;
    my $y1 = shift @ids;
    
    print "[$x0 $y0 $x1 $y1 ]" . join (",",@ids). "\n";

}
