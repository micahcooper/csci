#############################################################
##
##  File:  Makefile
##
##  Main Makefile for the servlets of the Clubs system
##
##

TARGETS = build install clean realclean
SERVLETS = ClubsError CreateClub CreatePerson FindAllPersons FindAllClubs FindClubMembers JoinClub



# targets

$(TARGETS):
	$(MAKE) $(SERVLETS) TARGET=$@

$(SERVLETS): .FORCE
	cd $@; $(MAKE) $(TARGET)

.FORCE:

