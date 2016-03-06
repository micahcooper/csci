This is directory for the application test programs.

CreateObjects creates a number of Person and Club objects
and writes them to the database.

JoinClubs retrieves existing objects from the database and
creates links between them, representing memberships in
clubs.

ListClubs lists club memberships.

Note that the application programs rely *only* on
the object layer, i.e. the library Clubs.

This is just a test of the implementation of the object 
layer, not including the control classes.

FindAllClubs is an example application invoking a control class
realizing one of the use cases.

