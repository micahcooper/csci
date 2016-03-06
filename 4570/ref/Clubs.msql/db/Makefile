#
# Makefile for the database
#

CLUBSBINDIR	= ../bin


# targets

all:	
	@echo You must select a proper target:
	@echo
	@echo '  ' \'make resetdb\' ' 'to clear and restart the database
	@echo '  ' \'make createdb\'  to create the database for the first time
	@echo '  ' \'make populatedb\'  to populate the database with a few entries
	@echo

resetdb:
	msqladmin drop clubs
	msqladmin create clubs
	msql clubs < clubs.sql

createdb:
	msqladmin create clubs
	msql clubs < clubs.sql

populatedb:
	$(CLUBSBINDIR)/CreateObjects
	$(CLUBSBINDIR)/JoinClubs
