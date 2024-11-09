#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/phil3/Documents/Development/weiss/build
  make -f /Users/phil3/Documents/Development/weiss/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/phil3/Documents/Development/weiss/build
  make -f /Users/phil3/Documents/Development/weiss/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/phil3/Documents/Development/weiss/build
  make -f /Users/phil3/Documents/Development/weiss/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/phil3/Documents/Development/weiss/build
  make -f /Users/phil3/Documents/Development/weiss/build/CMakeScripts/ReRunCMake.make
fi

