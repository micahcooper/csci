This is the main directory of a small system for
maintaining Clubs, Persons, and Club memberships.

The directory structure is as follows:

  classes       directory with the compiled class files
  lib		libraries with the object layer and control classes (jar files)
  src		sources for the system;  subdirectory:
		  except  includes the exception class
		  model   includes the entity classes and control classes
		  persist includes the persistence module
		  ui      includes the User Interface (servlets)
  http_ui	sources for user interface screens (HTML files for the
 	        basic HTTP interface)
  db		database schema
  test		test source programs (TTY-based)


The system has a network of Makefiles to build and install it.
In order to be able to compile the whole system, examine the macro 
definitions in Makefile.glob and update them as needed.  This file 
is included in all of the Makefiles to keep these settings consistent.

You must use the GNU Make program to build the system (make sure that
you invoke the make program in /usr/local/bin, not the one in
/usr/ccs/bin; use the Unix utility 'which' to find out which make
program you will be invoking).

To compile and install the system, type:

1. make build
2. make install

Also, if you don't use the invoker method for servlet mapping,
you may copy the included web.xml file into your WEB-INF directory.

You may later clean up the local class files by executing:

3. make clean

In order to uninstall the system execute:

4. make realclean


