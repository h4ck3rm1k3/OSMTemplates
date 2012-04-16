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
	
#              110000353153
	warn "$dir";
	system "mkdir $dir" unless -d $dir;
	system "mv national_kml.registry_html?p_registry_id=${dir}* ${dir}/";
    }
}
