#!/bin/csh -f
#
# simple script to produce dependencies suitable for
# Makefiles;
# the dependencies are places in file Makefile.deps
# and later included in the host Makefile
#

g++ -M $* >! Makefile.deps
