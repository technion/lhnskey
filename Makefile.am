bin_PROGRAMS = lhnskey

if MYMD5
lhnskey_SOURCES = lhnskey.c md5.c
else
lhnskey_SOURCES = lhnskey.c
endif

AUTOMAKE_OPTIONS = foreign

noinst_HEADERS = 

distclean-local:
	rm -rf autom4te.cache .deps Makefile.in configure

check:
	./check.pl
