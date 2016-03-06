#############################################################
##
##  File:  Makefile
##
##  Makefile for the FindAllPersons servlet
##
##


include		../../../Makefile.glob


##
## Servlet source files
##
SERVLET_SRCS	= FindAllPersons.java


##
## Servlet class files
##
SERVLET_CLASSES	= $(CLASSESDIR)/FindAllPersons.class


##
## Servlet template files
##
SERVLET_TMPLS	= FindAllPersons-Error.ftl \
		  FindAllPersons-Result.ftl


##
## Targets
##
all:
	@echo Select a proper target

build: $(LIBDIR)/clubs.jar $(SERVLET_CLASSES)

$(SERVLET_CLASSES): $(SERVLET_SRCS)
	$(JAVAC) -d $(CLASSESDIR) -classpath $(CLASSESDIR):$(LIBDIR)/clubs.jar:$(JDBC_JAR):$(J2EE_JAR):$(FREEMARKER_JAR) $(SERVLET_SRCS)


install: $(SERVLET_CLASSES)
	$(foreach class, $(SERVLET_CLASSES), $(INSTALL) -f $(INST_CLASSESDIR) -m 644 $(class);)
	$(foreach templ, $(SERVLET_TMPLS), $(INSTALL) -f $(INST_TEMPLDIR) -m 644 $(templ);)

clean:
	$(RM) -f $(SERVLET_CLASSES)

realclean: clean
	cd $(INST_CLASSESDIR); $(foreach class, $(SERVLET_CLASSES), $(RM) -f $(notdir $(class));)
	cd $(INST_TEMPLDIR); $(foreach templ, $(SERVLET_TMPLS), $(RM) -f $(notdir $(templ));)
