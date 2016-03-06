#############################################################
##
##  File:  Makefile
##
##  Main Makefile for the CLubs system
##
##

TARGETS = build install clean realclean
DIRS = src http_ui test



# targets

$(TARGETS):
	$(MAKE) $(DIRS) TARGET=$@

$(DIRS): .FORCE
	cd $@; $(MAKE) $(TARGET)

.FORCE:

