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



######## List all persons use cases #######
##
APP1		= CreateClub
APP1SRCS	= cgi_CreateClub.cpp CreateClub.cpp
APP1HDRS	= cgi_CreateClub.h
APP1OBJS	= cgi_CreateClub.o CreateClub.o
APP1HTML	= CreateClub.html CreateClub-Result.html CreateClub-Error.html

ALLSRCS		= $(APP1SRCS)
ALLHDRS		= $(APP1HDRS)


# targets

all: build install

build: Makefile.deps $(APP1)

## 
## targets for applications.
##

$(APP1): $(APP1OBJS) $(CLUBSLIBDIR)/libClubs.a $(CLUBSLIBDIR)/libClubs_ctrl.a $(CLUBSLIBDIR)/libhtml.a
	$(LINK.cpp) -o $@ $(APP1OBJS) $(LDLIBS)



install: .install

.install: $(APP1) $(APP1HTML)
	$(INSTALL) -m 755 $(APP1) $(CGIBINDIR)
	$(INSTALL) -m 744 $(APP1HTML) $(HTMLDESTDIR)
	touch .install

clean:
	/bin/rm -f *.o

realclean:
	/bin/rm -f *.o $(APP1) Makefile.deps .install
	cd $(CGIBINDIR); /bin/rm -f $(APP1)
	cd $(HTMLDESTDIR); /bin/rm -f $(APP1HTML)


Makefile.deps: $(ALLSRCS) $(ALLHDRS)
	@echo === Rebuilding dependencies for the CreateClub application
	$(MAKEDEP) $(CPPFLAGS) $(ALLSRCS)


####################################################################
##
##			Dependencies
##
## Dependencies are made by a special shell script and included below
##

-include Makefile.deps
