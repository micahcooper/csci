#
# Makefile for the apps in the Clubs system
#

TARGETS = build install clean realclean
DIRS	= FindAllPersons FindAllClubs JoinClub CreateClub FindClubMembers


# targets

all: build install

build: msg

msg:
	@echo === Making the Clubs application programs \(application layer\)...

setup:
	@echo === Setting up in apps


##
## application targets
##

# targets

$(TARGETS):
	$(MAKE) $(DIRS) TARGET=$@

$(DIRS): .FORCE
	cd $@; $(MAKE) $(TARGET)

.FORCE:

