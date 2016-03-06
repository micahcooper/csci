#
# Makefile for the library (object layer)
#

include		../Makefile.glob


# we are making this library
#
LIBRARY		= libClubs.a


# target directories
#
LIBBIN		= ../lib
LIBINC		= ../include


# sources
#
LIBSRCS		= Person.cpp PersonIterator.cpp \
		  DBObject.cpp DBObjectIterator.cpp \
		  Club.cpp ClubIterator.cpp \
		  Membership.cpp MembershipIterator.cpp \
		  ClubsException.cpp

# headers
#
LIBHDRS		= DBObject.h DBObjectIterator.h \
		  Person.h PersonIterator.h \
		  Club.h ClubIterator.h \
		  Membership.h MembershipIterator.h \
		  ClubsException.h

# objects
#
LIBOBJS		= DBObject.o DBObjectIterator.o \
		  Person.o PersonIterator.o \
		  Club.o ClubIterator.o \
		  Membership.o MembershipIterator.o \
		  ClubsException.o


# local CPPFLAGS
#
CPPFLAGS	= -I$(MSQL_INC)



##############################
#
# 	Targets
#

all: setup build install

setup: .setup

.setup: $(LIBHDRS)
	@echo === Setting up in src
	cp $(LIBHDRS) $(LIBINC)
	touch .setup

build: msg Makefile.deps $(LIBRARY) install

msg:
	@echo === Making the Clubs library \(object layer\)...


##
## library targets
##

lib: $(LIBRARY)

$(LIBRARY): $(LIBOBJS)
	$(AR) -vr $(LIBRARY) $(LIBOBJS)


install: .install

.install: .setup $(LIBRARY) $(LIBHDRS)
	$(INSTALL) $(LIBRARY) $(LIBBIN)
	touch .install


clean:
	/bin/rm -f *.o

realclean:
	/bin/rm -f *.o $(LIBRARY) Makefile.deps .install .setup
	cd $(LIBINC); rm -f $(LIBHDRS)
	cd $(LIBBIN); rm -f $(LIBRARY)
 
Makefile.deps: $(LIBSRCS) $(LIBHDRS)
	@echo === Rebuilding dependencies in the Clubs library \(object layer\)
	$(MAKEDEP) $(CPPFLAGS) $(LIBSRCS)


####################################################################
##
##			Dependencies
##
## Dependencies are made by a special shell script and included below
##

-include Makefile.deps

