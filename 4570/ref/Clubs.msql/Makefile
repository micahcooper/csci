#
# Makefile for the Clubs system
#
# Main Makefile
#

TARGETS = setup depend build install clean realclean
DIRS = util src ctrl apps http_ui test



# targets

$(TARGETS):
	$(MAKE) $(DIRS) TARGET=$@

$(DIRS): .FORCE
	cd $@; $(MAKE) $(TARGET)

.FORCE:

