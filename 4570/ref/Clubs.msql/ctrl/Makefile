#
# Makefile for the library (object layer)
#

include		../Makefile.glob


# we are making this library
#
LIBRARY		= libClubs_ctrl.a

# target directories
#
LIBBIN		= ../lib
LIBINC		= ../include


# sources
#
LIBSRCS		= ctrl_FindAllPersons.cpp \
		  ctrl_FindAllClubs.cpp \
		  ctrl_FindClubMembers.cpp \
		  ctrl_CreateClub.cpp \
		  ctrl_JoinClub.cpp

# headers
#
LIBHDRS		= ctrl_FindAllPersons.h \
		  ctrl_FindAllClubs.h \
		  ctrl_FindClubMembers.h \
		  ctrl_CreateClub.h \
		  ctrl_JoinClub.h

# objects
#
LIBOBJS		= ctrl_FindAllPersons.o \
		  ctrl_FindAllClubs.o \
		  ctrl_FindClubMembers.o \
		  ctrl_CreateClub.o \
		  ctrl_JoinClub.o

# local CPPFLAGS
#
CPPFLAGS	= -I$(MSQL_INC) -I$(LIBINC)



##############################
#
# 	Targets
#

all: setup build install

setup: .setup

.setup: $(LIBHDRS)
	@echo === Setting up in ctrl
	cp $(LIBHDRS) $(LIBINC)
	touch .setup

# must install headers and lib as part of build!
#
build: msg Makefile.deps $(LIBRARY) install

msg:
	@echo === Making the Clubs_ctrl library \(control classes in object layer\)...

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
	@echo === Rebuilding dependencies for the Clubs_ctrl library \(control classes in object layer\)
	$(MAKEDEP) $(CPPFLAGS) $(LIBSRCS)


####################################################################
##
##			Dependencies
##
## Dependencies are made by a special shell script and included below
##

-include Makefile.deps
