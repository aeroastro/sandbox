#!/usr/bin/env perl
use strict;
use warnings;
use utf8;

use Fcntl;
$|= 1; # Disable buffer

# http://man7.org/linux/man-pages/man2/dup.2.html
# https://linuxjm.osdn.jp/html/LDP_man-pages/man2/dup.2.html
# https://perldoc.perl.org/functions/open.html
open my $fh, '>', 'logfile';
open STDOUT, '>&', $fh; # Here, original STDOUT is closed and fh is duplicated to STDOUT
print $fh "Write text to file handle\n"; # Write via normal file handle
print STDOUT "Write text to STDOUT\n"; # Write via STDOUT with duplicated file descriptor

# https://linuxjm.osdn.jp/html/LDP_man-pages/man2/fcntl.2.html
# https://www.gnu.org/software/libc/manual/html_node/Duplicating-Descriptors.html
fcntl($fh, F_SETFD, my $flags = '') or die "$!"; # Disable FD_CLOEXEC

my $no = fileno($fh);
exec("echo good code && echo bad code >&$no"); # If you do not close $fd, execve-ed process can unintentionally use fd
