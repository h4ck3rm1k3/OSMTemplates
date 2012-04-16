BEGIN
{
    print "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    print "<osm version=\"0.6\" generator=\"OpenStreetMap server\">\n";
}
while (<>)
{
    next if /<?xml version/;
    next if /<osm version/;
    next if /<\/osm>/;
    print $_;
}

END
{
    print "<\/osm>\n";
}
	
