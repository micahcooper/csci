This is the main directory of a small system for
maintaining Clubs and their memberships.

The directory structure is as follows:

  apps		application program source files (application layer)
  bin		binaries for test programs
  include	include directory for the object layer class declarations
		  (including control classes)
  lib		libraries with the object layer and control classes (static libraries)
  src		sources for object layer class library (entity classes)
  ctrl		sources for control class class library (sequence diagrams)
  http_ui	sources for user interface (HTML files for basic HTTP interface)
  db		database schema and support activities
  test		test source programs (TTY-based)

Subdirectories apps, src, and db have specific README files
explaining a variety of related issues.

The main directory and subdirectories apps, src, and db have
Makefiles to build appropriate system components. 

In order to compile the system:

  1. compile and install the mSQL database system (one per team
     please -- additional explanations will be given in class)
  2. start the database server daemon (msql2d)
  3. update the Makefile.glob to reflect your placement 
     of the mSQL library and include files, as well as other
     settings
  4. go to the main directory and run:

	make setup
	make build
	make install

Step 4. above should create the libraries and the application
programs as follows:

  'make setup'   copies the necessary files to the include directory.
  'make build'   updates the dependencies and creates all 
                 binaries (compiles everything)
  'make install' installs the binaries and HTML files in suitable
	         direectories for Web access


Then you should create, populate and test the database for the Clubs system:

  5. go the db subdirectory and type 'make createdb'

  6. then (also in the db subdirectory) type 'make populatedb'.
  
To verify proper installation, go to the bin subdirectory and type:

  7. ./ListClubs		to list initial club rosters

The last step above should produce output similar to the one
presented at the end of this file.


Then test the full system.  Open a Web browser and direct it to
the Clubs.html page and check all of the functions.


Note:

Additionally, the target 'realclean' removes all of the automatically
generated files, including the published headers (in the include dir)
libraries (in the lib dir) and object and executable files.  This also
removes the installed files from the public cgi-bin directory.

  8. make realclean





---------- sample output of step 7 above ---------------------------------
gemini:31% ListClubs 
Current members of club: Chess

        Doe, Joe, 123-45-1001, 55, 133 Maple St., Big Town, AZ. 87888
        Wilson, Robert, 123-45-1003, 34, 33 Cedar Cr., Middle Town, NV. 81888


Current members of club: Bridge

        Swift, Mary, 123-45-1002, 24, 14 Oak Dr., Small Town, TX. 77888
        Wilson, Robert, 123-45-1003, 34, 33 Cedar Cr., Middle Town, NV. 81888
        Brooks, Heather, 123-45-1005, 18, 1 Pine Ave., Boom Town, GA. 30688


Current members of club: Tennis

        Swift, Mary, 123-45-1002, 24, 14 Oak Dr., Small Town, TX. 77888
        Hart, Julie, 123-45-1004, 29, 99 Magnolia St., Splash Town, NY. 21888
        Brooks, Heather, 123-45-1005, 18, 1 Pine Ave., Boom Town, GA. 30688


Current club membership of person: 123-45-1002

        Bridge, 734 Pine Straw Dr., Bloom, KY. 48878, 11/09/97 00:00:00
        Tennis, 333 Wide St., Flower, RI. 17345, 11/09/97 00:00:00


Club memberships have been listed.
Closing the database.

