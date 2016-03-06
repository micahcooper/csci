#
# Makefile for the application programs
#


HTMLDESTDIR	= /home/profs/kochut/public_html


######## Clubs User Interface #######
##

HTML		= Clubs.html


INSTALL		= /usr/ucb/install


# targets

all:	build install

setup:
	@echo === Setting up in http_ui

build: msg

msg:
	@echo === Making the Clubs user interface \(user interface layer\)...


## 
## targets for HTTP UI  building
##


install: .install

.install: $(HTML)
	$(INSTALL) -m 744 $(HTML) $(HTMLDESTDIR)
	touch .install

clean:
	@echo Nothing to clean in http_ui...

realclean:
	/bin/rm -f .install
	cd $(HTMLDESTDIR); /bin/rm -f $(HTML)

