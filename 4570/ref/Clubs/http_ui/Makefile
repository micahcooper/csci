#############################################################
##
##  File:  Makefile
##
##  Makefile for the HTTP User Interface
##
##


include		../Makefile.glob


##
## App HTML files
##
APPHTMLS	= Clubs.html



##
## Targets
##
all:
	@echo Select a proper target

build:


install: 
	$(foreach html, $(APPHTMLS), $(INSTALL) -f $(INST_WWWDIR) -m 644 $(html);)

clean:


realclean: clean
	cd $(INST_WWWDIR); $(foreach html, $(APPHTMLS), $(RM) -f $(notdir $(html));)
