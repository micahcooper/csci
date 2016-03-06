#############################################################
##
##  File:  Makefile
##
##  Makefile for the test programs
##
##


include		../Makefile.glob


##
## Test program source files
##
TEST_SRCS	= CreateObjects.java \
		  ListAllPersons.java \
		  EnrollMembers.java \
		  ListAllClubs.java \
		  ListClubMembers.java \
		  JoinClubByName.java


##
## Servlet class files
##
TEST_CLASSES	= CreateObjects.class \
		  ListAllPersons.class \
		  EnrollMembers.class \
		  ListAllClubs.class \
		  ListClubMembers.class \
		  JoinClubByName.class


##
## Targets
##
all:
	@echo Select a proper target

build: $(LIBDIR)/clubs.jar .compiled

.compiled: $(TEST_SRCS)
	$(JAVAC) -d $(CLASSESDIR) -classpath $(LIBDIR)/clubs.jar:$(JDBC_JAR):$(J2EE_JAR):$(FREEMARKER_JAR) $(TEST_SRCS)
	touch .compiled

install: 


clean:
	$(RM) -f $(TEST_CLASSES)
	$(RM) -f .compiled

realclean: clean
	cd $(CLASSESDIR); $(foreach class, $(TEST_CLASSES), $(RM) -f $(notdir $(class));)
