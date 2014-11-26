include $(top_srcdir)/build-aux/autotroll.mk

bin_PROGRAMS = Casper
Casper_SOURCES = main.cpp mainWindow.cpp moc_mainWindow.cpp
Casper_CXXFLAGS = $(QT_CXXFLAGS) $(AM_CXXFLAGS)
Casper_CPPFLAGS = $(QT_CPPFLAGS) $(AM_CPPFLAGS)
Casper_LDFLAGS = $(QT_LDFLAGS) $(LDFLAGS)
Casper_LDADD = $(QT_LIBS) $(LDADD)

BUILT_SOURCES = main.cpp

# Create moc_ files
moc_mainWindow.cpp: ../../include/gui/mainWindow.hpp
	moc $(DEFINES) $(INCPATH) $< -o $@
