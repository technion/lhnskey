bin_PROGRAMS = lhnskey

lhnskey_SOURCES = lhnskey.c md5.c

AUTOMAKE_OPTIONS = foreign

noinst_HEADERS = 

distclean-local:
	rm -rf autom4te.cache .deps Makefile.in configure

check:
	./check.pl
