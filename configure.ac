AC_INIT([Casper], [0.0.1], [brice.p.thomas@gmail.com], [casper])

AC_CONFIG_AUX_DIR([build-aux])

AC_CONFIG_MACRO_DIR([build-aux])

AM_INIT_AUTOMAKE([foreign -Wall])

# Check C++
AC_LANG([C++])
AC_PROG_CXX

# Check Qt
AT_WITH_QT([widgets])

AC_CONFIG_FILES([
  Makefile
    src/Makefile
      src/gui/Makefile
])

AC_OUTPUT
