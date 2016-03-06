#############################################################
##
##  File:  Makefile
##
##  Makefile for the Error class
##
##


include		../../../Makefile.glob


##
## Servlet source files
##
ERROR_SRCS	= ClubsError.java


##
## Servlet class files
##
ERROR_CLASSES	= $(CLASSESDIR)/ClubsError.class


##
## Servlet template files
##
ERROR_TMPLS	= ClubsError-Result.ftl


##
## Targets
##
all:
	@echo Select a proper target

build: $(ERROR_CLASSES)

$(ERROR_CLASSES): $(ERROR_SRCS)
	$(JAVAC) -d $(CLASSESDIR) -classpath $(LIBDIR)/clubs.jar:$(JDBC_JAR):$(J2EE_JAR):$(FREEMARKER_JAR) $(ERROR_SRCS)


install: $(ERROR_CLASSES)
	$(foreach class, $(ERROR_CLASSES), $(INSTALL) -f $(INST_CLASSESDIR) -m 644 $(class);)
	$(foreach templ, $(ERROR_TMPLS), $(INSTALL) -f $(INST_TEMPLDIR) -m 644 $(templ);)

clean:
	$(RM) -f $(ERROR_CLASSES)

realclean: clean
	cd $(INST_CLASSESDIR); $(foreach class, $(ERROR_CLASSES), $(RM) -f $(notdir $(class));)
	cd $(INST_TEMPLDIR); $(foreach templ, $(ERROR_TMPLS), $(RM) -f $(notdir $(templ));)
