#!/bin/sh
#


set -ex

aclocal 
autoheader
autoconf
automake --add-missing --copy --foreign
