This is the directory with source files for the object layer, ie.
class diagram in UML.

Note, that the classes Person and Club have no explicit
data members to represent the association between them.  
The associated is maintained by the class Membership.

The classes Person and Club have methods DBWrite and DBRead
to save and restore, respectively, the objects to the MSQL 
database.  The DBRead methods are static methods, as explained
during the lecture.

Both classes have associated iterator classes (PersonIterator and
ClubIterator) to enumerate the existing objects (these classes
interact with the MSQL database).

Object instances in the Membership class represent individual links
between Person and Club objects, together with the associated link
attribute value.  

MembershipIterator is used to enumerate all of the Membership (link)
objects from the database, or all of the Membership (link)
objects representing links between a specific Person and any Club,
or between a specific Club and any Person.

ClubsException is an exception class which is used in signaling
abnormal conditions encountered by the system.  Please study the
use of try/catch clauses in various classes.

All of the classes here rely on the RogueWave C++ class library
(additional explanations will be given in class).

You should study carefully all of the source files in this directory
to understand the interplay of the C++ classes and the MSQL database.



