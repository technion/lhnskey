#!/usr/bin/perl -w

use strict;

my $ret = `echo AC:16:2D:XX:XX:XX | ./lhnskey`;

my $exp = "Enter Support Key: Generating root password....
ecdf308e1d\nGenerating S/Key secret...\n4bfdf1ebfd7a126b345b752111f55cc2\n";

if ($ret ne $exp) {
	print "The generator failed to pass the reference test\n"
} else {
	print "lhnskey passed reference test\n";
}

