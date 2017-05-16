AC_INIT(lhnskey, [1.11], [technion@lolware.net])
AM_INIT_AUTOMAKE(lhnskey, 1.0)
AM_CONFIG_HEADER(config.h)

AC_LANG_C
AC_HEADER_STDC
AC_PROG_CC
AC_PROG_MAKE_SET

AC_ARG_ENABLE(development, [ --enable-development enable developer features [default=no]])

AC_ARG_ENABLE(secure, [ --enable-secure turn on security features [default=yes]])
	
AS_IF([test "x$enable_secure" != "xno"], [
	if test "x$enable_development" = "xyes" ; then
		AC_MSG_WARN("Developer on: Turning off secure")
		AM_SILENT_RULES([no])
		CFLAGS="-Wall -O0 -g -fsanitise=address"
	else
		AM_SILENT_RULES([yes])
		CFLAGS="-Wall -fstack-protector -D_FORTIFY_SOURCE=2 -O2"
	fi
])

AC_OUTPUT(Makefile)


