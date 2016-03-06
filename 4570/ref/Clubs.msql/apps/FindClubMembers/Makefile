#
# Makefile for the application programs
#

include		../../Makefile.glob


CLUBSBINDIR	= ../../bin
CLUBSLIBDIR	= ../../lib
CLUBSINCDIR	= ../../include


LIBHDRS		= DBObject.h DBObjectIterator.h \
		  Person.h PersonIterator.h Club.h ClubIterator.h \
		  Membership.h \
		  ClubsException.h HTMLTemplate.h cgipp.h


CPPFLAGS	= -I$(MSQL_INC) -I$(CLUBSINCDIR)
LDFLAGS		= -L$(MSQL_LIB) -L$(CLUBSLIBDIR)
LDLIBS		= -lClubs_ctrl -lClubs -lhtml -lmsql -lsocket -lnsl -lgen 



######## FindClubMembers use case #######
##
APP1		= FindClubMembers
APP1SRCS	= cgi_FindClubMembers.cpp FindClubMembers.cpp
APP1HDRS	= cgi_FindClubMembers.h
APP1OBJS	= cgi_FindClubMembers.o FindClubMembers.o
APP1HTML	= FindClubMembers.html FindClubMembers-Result.html FindClubMembers-Error.html

APP2		= FindClubMembers-Clubs
APP2SRCS	= cgi_FindClubMembers.cpp FindClubMembers-Clubs.cpp
APP2HDRS	= cgi_FindClubMembers.h
APP2OBJS	= cgi_FindClubMembers.o FindClubMembers-Clubs.o
APP2HTML	= FindClubMembers-Clubs.html

ALLSRCS		= $(APP1SRCS) $(APP2SRCS)
ALLHDRS		= $(APP1HDRS) $(APP2HDRS)



# targets

all: build install

build: Makefile.deps $(APP1) $(APP2)

## 
## targets for applications.
##

$(APP1): $(APP1OBJS) $(CLUBSLIBDIR)/libClubs.a $(CLUBSLIBDIR)/libClubs_ctrl.a $(CLUBSLIBDIR)/libhtml.a
	$(LINK.cpp) -o $@ $(APP1OBJS) $(LDLIBS)

$(APP2): $(APP2OBJS) $(CLUBSLIBDIR)/libClubs.a $(CLUBSLIBDIR)/libClubs_ctrl.a $(CLUBSLIBDIR)/libhtml.a
	$(LINK.cpp) -o $@ $(APP2OBJS) $(LDLIBS)


install: .install

.install: $(APP1) $(APP2) $(APP1HTML) $(APP2HTML)
	$(INSTALL) -m 755 $(APP1) $(CGIBINDIR)
	$(INSTALL) -m 744 $(APP1HTML) $(HTMLDESTDIR)
	$(INSTALL) -m 755 $(APP2) $(CGIBINDIR)
	$(INSTALL) -m 744 $(APP2HTML) $(HTMLDESTDIR)
	touch .install

clean:
	/bin/rm -f *.o

realclean:
	/bin/rm -f *.o $(APP1) $(APP2) Makefile.deps .install
	cd $(CGIBINDIR); /bin/rm -f $(APP1) $(APP2)
	cd $(HTMLDESTDIR); /bin/rm -f $(APP1HTML) $(APP2HTML)

 
Makefile.deps: $(ALLSRCS) $(ALLHDRS)
	@echo === Rebuilding dependencies for the FindClubMembers application
	$(MAKEDEP) $(CPPFLAGS) $(ALLSRCS)


####################################################################
##
##			Dependencies
##
## Dependencies are made by a special shell script and included below
##

-include Makefile.deps
