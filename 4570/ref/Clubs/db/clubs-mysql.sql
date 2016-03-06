#
# this SQL file creates the schema for the Clubs database
#

#
# Table structure for table 'Person'
#
DROP TABLE IF EXISTS Person;
#
CREATE TABLE Person (
  Id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
  FirstName VARCHAR(255) NOT NULL,
  LastName VARCHAR(255) NOT NULL,
  Address VARCHAR(255),
  Phone VARCHAR(255),
  Age INT
);

#
# Table structure for table 'Club'
#
DROP TABLE IF EXISTS Club;
#
CREATE TABLE Club (
  Id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
  Name VARCHAR(255) NOT NULL,
  Address VARCHAR(255),
  Established DATETIME
) \g

#
# Table structure for table 'IsMemberOf'
#
# This is the many-to-many relationship
# between Person and Club
#
DROP TABLE IF EXISTS IsMemberOf;
#
CREATE TABLE IsMemberOf (
  Id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
  PersonId INT UNSIGNED NOT NULL,
  ClubId INT UNSIGNED NOT NULL,
  Joined DATETIME,
  FOREIGN KEY (PersonId) REFERENCES Person(Id),
  FOREIGN KEY (ClubId) REFERENCES Club(Id)
) \g



