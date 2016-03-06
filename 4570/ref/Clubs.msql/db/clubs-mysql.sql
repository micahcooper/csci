#
# this SQL file creates the schema for the Clubs database
#

#
# Table structure for table 'Person'
#
CREATE TABLE Person (
  Id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
  SSN VARCHAR(12),
  FirstName VARCHAR(30),
  LastName VARCHAR(30),
  Address VARCHAR(255),
  Age INT
);

#
# Table structure for table 'Club'
#
CREATE TABLE Club (
  Id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
  Name VARCHAR(50),
  Address VARCHAR(255),
  Established DATETIME
) \g

#
# Table structure for table 'Membership'
#
CREATE TABLE Membership (
  personid INT UNSIGNED NOT NULL,
  clubid INT UNSIGNED NOT NULL,
  joined DATETIME
) \g



