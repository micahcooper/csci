#
# this SQL file creates the schema for the Clubs database
#

#
# Table structure for table 'Person'
#
CREATE TABLE Person (
  Id UINT NOT NULL,
  SSN CHAR(12),
  FirstName CHAR(30),
  LastName CHAR(30),
  Address CHAR(50),
  Age INT
) \g

CREATE SEQUENCE ON Person \g

#
# Table structure for table 'Club'
#
CREATE TABLE Club (
  Id UINT NOT NULL,
  Name CHAR(30),
  Address CHAR(50),
  Established DATE
) \g

CREATE SEQUENCE ON Club \g

#
# Table structure for table 'Membership'
#
CREATE TABLE Membership (
  personid UINT NOT NULL,
  clubid UINT NOT NULL,
  joined DATE
) \g



