#############################################################
##
##  File:  Makefile.glob
##
##  Global settings for the Clubs project
##
##


include		../Makefile.glob


##
## Exception sources
##
EXCEPT_SRCS	= except/ClubsException.java


##
## Object model sources
##
MODEL_SRCS	= model/entity/Club.java \
		  model/entity/IsMemberOf.java \
		  model/entity/Person.java \
		  model/entity/Entity.java \
		  model/entity/ModelFactory.java \
		  model/entity/impl/ClubImpl.java \
		  model/entity/impl/PersonImpl.java \
		  model/entity/impl/IsMemberOfImpl.java \
		  model/ctrl/CtrlCreateClub.java \
		  model/ctrl/CtrlFindAllPersons.java \
		  model/ctrl/CtrlCreatePerson.java \
		  model/ctrl/CtrlFindClubMembers.java \
		  model/ctrl/CtrlFindAllClubs.java \
		  model/ctrl/CtrlJoinClub.java


##
## Persistence module sources
##
PERSIST_SRCS	= persist/PersistenceModule.java \
		  persist/PersistenceModuleFactory.java \
		  persist/impl/Club2IsMemberOfIteratorImpl.java \
		  persist/impl/Person2IsMemberOfIteratorImpl.java \
		  persist/impl/ClubIteratorImpl.java \
		  persist/impl/PersonIteratorImpl.java \
		  persist/impl/PersistenceModuleImpl.java


CLUBS_SRCS	= $(EXCEPT_SRCS) $(MODEL_SRCS) $(PERSIST_SRCS)

PACKAGES	= except model persist

##
## Targets
##
all:
	@echo Select a proper target

build: modules ui

modules: $(LIBDIR)/clubs.jar

$(LIBDIR)/clubs.jar: $(CLUBS_SRCS)
	$(JAVAC) -d $(CLASSESDIR) -classpath $(CLASSESDIR):$(JDBC_JAR):$(J2EE_JAR) $(CLUBS_SRCS)
	cd $(CLASSESDIR); $(JAR) cvf $(LIBDIR)/clubs.jar $(PACKAGES)

ui:
	cd servlets; $(MAKE) build

install: $(LIBDIR)/clubs.jar
	$(INSTALL) -f $(INST_LIBDIR) -m 644 $(LIBDIR)/clubs.jar
	cd servlets; $(MAKE) install

clean:
	$(RM) -f $(LIBDIR)/clubs.jar
	cd $(CLASSESDIR); $(RM) -fr $(PACKAGES)
	cd servlets; $(MAKE) clean

realclean: clean
	$(RM) -f $(INST_LIBDIR)/clubs.jar
	cd servlets; $(MAKE) realclean
