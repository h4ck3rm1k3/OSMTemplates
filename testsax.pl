package MySAXHandler;
use Data::Dumper;
use base qw(XML::SAX::Base);

sub start_document {
    my ($self, $doc) = @_;
    # process document start event
}

my %ids;
my %coords;
sub start_element {
    my ($self, $el) = @_;
    my $name=$el->{LocalName};
    if ($name eq "node")
    {
	my $lon =$el->{'Attributes'}{'{}lon'}{'Value'};
	my $lat =$el->{'Attributes'}{'{}lat'}{'Value'};
	my $id  =$el->{'Attributes'}{'{}id'}{'Value'};
	if ($ids{$id}++)
	{
	    warn "Duplicate id $id";
	}

	my $key="$lat|$lon";
	if (!$coords{$key})
	{
	    $coords{$key}=$id;
	}
	else
	{
	    my $old=$coords{$key};
	    warn "duplicate coord $id $old $key";
	}

    }
}

1;

use XML::SAX;


my $parser = XML::SAX::ParserFactory->parser(
    Handler => MySAXHandler->new
    );

$parser->parse_uri(shift);
