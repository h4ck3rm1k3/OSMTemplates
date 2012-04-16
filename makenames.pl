 #    copyright 2009 
 #    "James Michael Dupont (H4ck3rm1k3)"  <jamesmikedupont@gmail.com>
 #    http://www.fsf.org/licensing/licenses/agpl-3.0.html
 #    This program is free software: you can redistribute it and/or modify
 #    it under the terms of the GNU General Public License as published by
 #    the Free Software Foundation, either version 3 of the License, or
 #    (at your option) any later version.
 #    This program is distributed in the hope that it will be useful,
 #    but WITHOUT ANY WARRANTY; without even the implied warranty of
 #    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 #    GNU General Public License for more details.
 #    You should have received a copy of the GNU General Public License
 #    along with this program.  If not, see <http://www.gnu.org/licenses/>.

use strict;
use warnings;
sub name
{
    my $x=shift;
    if ($x =~ /[0-9]/)
    {
	return "chDigit_" .$x;
    }
    elsif ($x =~ /[a-zA-Z]/)
    {
	return "chLatin_" .$x;
    }
    elsif ($x eq '_')
    {
	return "chUnderscore";
    }   
    elsif ($x eq '.')
    {
	return "chPeriod";
    }   
    elsif ($x eq ';')
    {
	return "chSemiColon";
    }   
    elsif ($x eq ',')
    {
	return "chComma";
    }   


    elsif ($x eq ' ')
    {
	return "chSpace";
    }    
    elsif ($x eq ':')
    {
	return "chColon";
    }
    else
    {
	die "unknown $x";
    }

}

while (<>)
{
    chomp;
    my $name = uc ($_);
    $name =~ s/\W/_/g;
    my @chars= split //;
    my $out = "static XMLCh sz${name}\[\]=\{";

	$out .= join (",", map {
	name($_ )
		  } @chars);
    $out .= ", chNull }; // $_\n";
    print $out;
}
