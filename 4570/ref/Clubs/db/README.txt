This directory contains the SQL file necessary to create the
Clubs database schema.  You must have access to a mysql database
before you can create the schema.

The database has three tables:

  Person	- to hold Person objects
  Club		- to hold Club objects
  IsMemberOf	- to hold Club memeberships (it is a many-to-many
		  association with a link attribute -- the time a 
		  given member joined a given club)

The object model classes (Person, Club, and IsMemberOf -- which holds
the association links) may be stored in the persistent module.
