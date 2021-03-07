#**Homework 2**

##**Description**
This is a OOP-oriented project of Room Access System of Innopolis University
##**Dependencies**
 - STL14
##**Run instructions**
- run main.cpp
- follow given instructions
- Keep in mind that for access operations you should input indexes of rooms and users at the same time to perform Access Rights changingoperations - input real number of a room and index of a user.

###Small adition:
- All users can access roms according to their level
- Admins can access any room
-Admin can open any room for anybody or change AccessType(For exmpl change Director access level to GREEN, because he was fired and he works as Professor now)
- Having Garant from admin to any room means that this is your  personal room



##Code Description:
###main.cpp
- getAccess - checks Access permisison of user that have Admin garants
- parsebyPROBEL - parses sentences by spaces
- parserFormTxt - gets data from txt database to Vector strucutre
- generateRooms - generates University rooms
###Room.h
- class Room
- - Room(string) constructor
- - bool getAccess(AccessType) geting of  Access for users without admin garant
- - string getNumber();  getting of Room number
- - string getRoomType(); returns Type of Room 
- - AccessType getAccessType(); returns needed level of access

- class ClassRoom
- class LectureRoom
- class ConferenceRoom
- class Cabinet
- class DirectorCabinet
###User.h
- class User
- - User(const pair<string, string>&, const string&, const string, const string)
- - User()
- - AccessType getAccess()
- - pair<string, string> getInitials()
- - pair<AccessType, bool> changeGlobalAccess(AccessType, AccessType)
- - bool changeRoomAccess(AccessType, Room*)
- - bool comeIn(Room&)
- - string toString(AccessType)
- - string getUserType()
    
- class Student
- class Professor
- class LabStuff
- class Director
- class Admin
