//
// Created by Elestrias on 07.03.2021.
//

#ifndef UNTITLED4_ROOM_H
#define UNTITLED4_ROOM_H
#include <string>
#include "dependencies.h"
#include "AccessType.h"

using namespace std;
class Room {
protected:
    AccessType neededAccess;
    string roomNumber;
    string roomType;
public:
    Room(string RoomNumber);
    virtual bool getAccess(AccessType acc);
    virtual string getNumber();
    virtual string getRoomType();
    AccessType getAccessType();
};

class ClassRoom: public Room {
public:

    ClassRoom(string RoomNumber);
    //~ClassRoom();
};
class LectureRoom: public Room {
public:

    LectureRoom(string RoomNumber);
   //~LectureRoom();
};
class ConferenceRoom: public Room {
public:

    ConferenceRoom(string RoomNumber);
    //~ConferenceRoom();
};

class Cabinet: public Room{
public:

    Cabinet(string RoomNumber);
    //~Cabinet();
};

class DirectorCabinet: public Room{
public:

    DirectorCabinet(string RoomNumber);
    //~DirectorCabinet();
};

#endif //UNTITLED4_ROOM_H
