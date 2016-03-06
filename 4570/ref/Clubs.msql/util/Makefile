#
# Makefile for the html library (utilities)
#

include		../Makefile.glob

# we are making this library
#
LIBRARY		= libhtml.a

# target directories
#
LIBBIN		= ../lib
LIBINC		= ../include



# sources
#
LIBSRCS		= HTMLTemplate.cpp cgipp.cpp

# headers
#
LIBHDRS		= HTMLTemplate.h cgipp.h

# objects
#
LIBOBJS		= HTMLTemplate.o cgipp.o



##############################
#
# 	Targets
#

all:	setup build install

setup: .setup

.setup: $(LIBHDRS)
	@echo === Setting up in util
	cp $(LIBHDRS) $(LIBINC)
	touch .setup

build: msg Makefile.deps $(LIBRARY) install

msg:
	@echo === Making the html utilities library...

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
	@echo === Rebuilding dependencies in the Clubs library \(object layer\)...
	$(MAKEDEP) $(CPPFLAGS) $(LIBSRCS)


####################################################################
##
##			Dependencies
##
## Dependencies are made by a special shell script and included below
##

-include Makefile.deps
