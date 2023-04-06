#!/usr/bin/perl
use strict;
use warnings;

print("Enter a string: ");
my $str = <STDIN>;
my $rev_str;
$str =~ tr/ //ds;
$str =~ s/\R//g;
$str = lc $str;
$rev_str = reverse $str;
if ($str eq $rev_str)
{
	print "The string is a palindrome!\n";
}
else
{
	print "The string is not a palindrome.\n";
}
