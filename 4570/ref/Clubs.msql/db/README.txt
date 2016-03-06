This directory contains the SQL file necessary to create the
Clubs database schema.  You must compile and properly install
the MSQL system before you can create the schema.

To create the clubs database, type 'make createdb'.

To clear and reset the database type 'make resetdb' (you will have
to answer 'y' to msqladmin warning prompt.

The database has three tables:

  Person	- to hold Person objects
  Club		- to hold Club objects
  Membership	- to hold Club memeberships (it is a many-to-many
		  association with a link attribute -- time a given
		  member joined ta given club)

The object model classes (Person, Club, and Membership -- which holds
the association links) read and write objects and links to the
appropriate tables.  See the library (object layer) source code
in the src directory.


clubs-mysql.sql is a mySQL version of the database schema and will
not work with mSQL.
