#!/usr/bin/perl
use strict; use warnings;

foreach (1..$ARGV[0]) {
  print rand(100), "\n";
}
