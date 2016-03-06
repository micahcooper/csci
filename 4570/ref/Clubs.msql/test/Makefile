#
# Makefile for the application programs
#

include		../Makefile.glob


CLUBSBINDIR	= ../bin
LIBRARY		= Clubs
CLUBSLIBDIR	= ../lib
CLUBSINCDIR	= ../include


LIBHDRS		= DBObject.h DBObjectIterator.h \
		  Person.h PersonIterator.h Club.h ClubIterator.h \
		  Membership.h \
		  ClubsException.h


CPPFLAGS	= -I$(MSQL_INC) -I$(CLUBSINCDIR)
LDFLAGS		= -L$(MSQL_LIB) -L$(CLUBSLIBDIR)
LDLIBS		= -lClubs_ctrl -l$(LIBRARY) -lmsql -lsocket -lnsl -lgen



APP1		= CreateObjects
APP1SRCS	= CreateObjects.cpp
APP1OBJS	= CreateObjects.o

APP2		= JoinClubs
APP2SRCS	= JoinClubs.cpp
APP2OBJS	= JoinClubs.o

APP3		= ListClubs
APP3SRCS	= ListClubs.cpp
APP3OBJS	= ListClubs.o

APP4		= FindAllClubs
APP4SRCS	= FindAllClubs.cpp
APP4OBJS	= FindAllClubs.o

ALLSRCS		= $(APP1SRCS) $(APP2SRCS) $(APP3SRCS)  $(APP4SRCS)


# targets

all: build install

setup:
	@echo === Setting up in test

build: msg Makefile.deps $(APP1) $(APP2) $(APP3)

msg:
	@echo === Making the test programs...


## 
## targets for applications.
##

$(APP1): $(APP1OBJS)
	$(LINK.cpp) -o $@ $(APP1OBJS) $(LDLIBS)

$(APP2): $(APP2OBJS)
	$(LINK.cpp) -o $@ $(APP2OBJS) $(LDLIBS)

$(APP3): $(APP3OBJS)
	$(LINK.cpp) -o $@ $(APP3OBJS) $(LDLIBS)

$(APP4): $(APP4OBJS)
	$(LINK.cpp) -o $@ $(APP4OBJS) $(LDLIBS)


install: .install

.install: $(APP1) $(APP2) $(APP3) $(APP4)
	$(INSTALL) $(APP1) $(CLUBSBINDIR)
	$(INSTALL) $(APP2) $(CLUBSBINDIR)
	$(INSTALL) $(APP3) $(CLUBSBINDIR)
	$(INSTALL) $(APP4) $(CLUBSBINDIR)
	touch .install

clean:
	/bin/rm -f *.o

realclean:
	/bin/rm -f *.o $(APP1) $(APP2) $(APP3) $(APP4) Makefile.deps .install
	cd $(CLUBSBINDIR); /bin/rm -f $(APP1) $(APP2) $(APP3) $(APP4)

Makefile.deps: $(ALLSRCS)
	@echo === Rebuilding dependencies in the test directory...
	$(MAKEDEP) $(CPPFLAGS) $(ALLSRCS)


####################################################################
##
##			Dependencies
##
## Dependencies are made by a special shell script and included below
##

-include Makefile.deps
