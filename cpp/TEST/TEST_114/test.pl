#! /usr/bin/perl

eval "exec /usr/bin/perl -S $0 @ARGV"
  if 0;

# Copyright (C) 2000, 2001, 2002, 2003, 2004, 2005 Ulrich Drepper
# Written by Ulrich Drepper <drepper@gmail.com>, 2000.

# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License version 2 as
# published by the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software Foundation,
# Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */

for ($cnt = 0; $cnt <= $#ARGV; ++$cnt) {
  $relent = 0;
  $relsz = 0;
  $relcount = 0;
  $pltrelsz = 0;
  $extplt = 0;
  $users = 0;
  
  open(READLINK, "readlink -f $ARGV[$cnt] |") || die "cannot open readlink";
  while (<READLINK>) {
    chop;
    $fullpath = $_;
  }
  close(READLINK);

  open(READELF, "eu-readelf -d $ARGV[$cnt] |") || die "cannot open $ARGV[$cnt]";
  while (<READELF>) {
    chop;
    if (/.*RELAENT\s+([0-9]+).*/) {
      $relent = $1 + 0;
    } elsif (/.*RELASZ\s+([0-9]+).*/) {
      $relsz = $1 + 0;
    } elsif (/.*RELACOUNT\s+([0-9]+).*/) {
      $relcount = $1 + 0;
    } elsif (/.*PLTRELSZ\s+([0-9]+).*/) {
      $pltrelsz = $1 + 0;
    }
  }
  close(READELF);

  open(READELF, "eu-readelf -r $ARGV[$cnt] |") || die "cannot open $ARGV[$cnt]";
  while (<READELF>) {
    chop;
    if (/.*JUMP_SLOT\s+0x[0-9a-fA-F]+.*/) {
      ++$extplt;
    }
  }
  close(READELF);

  if (open(PRELINK, "prelink -p 2>/dev/null | fgrep \"$fullpath\" |")) {
    while (<PRELINK>) {
      ++$users;
    }

    close(PRELINK);
  } else {
    $users = -1;
  }

  printf("%d\n", $relsz);
  printf("%d\n", $relcount);
  printf("%d\n", $relent);
  printf("%d\n", $pltrelsz);
  printf("%d\n", $pltrelsz);

  printf("%s: %d relocations, %d relative (%d%%), %d PLT entries, %d for local syms (%d%%)",
    $ARGV[$cnt], 
    $relent == 0 ? 0 : $relsz / $relent, $relcount,
    $relent == 0 ? 0 : ($relcount * 100) / ($relsz / $relent),
    $relent == 0 ? 0 : $pltrelsz == 0 ? 0 : $pltrelsz / $relent,
    $relent == 0 ? 0 : $pltrelsz == 0 ? 0 : $pltrelsz / $relent - $extplt,
    $relent == 0 ? 0 : $pltrelsz == 0 ? 0 : ((($pltrelsz / $relent - $extplt) * 100) / ($pltrelsz / $relent)));

  if ($users  >=  0) {
    printf(", %d users", $users);
  }

  printf("\n");
}
