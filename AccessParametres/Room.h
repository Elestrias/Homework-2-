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
    QString roomNumber;
    QString roomType;
public:
    Room(QString RoomNumber);
    virtual bool getAccess(AccessType acc);
    virtual QString getNumber();
    virtual QString getRoomType();
    AccessType getAccessType();
};



class ClassRoom: public Room {
public:

    ClassRoom(QString RoomNumber);
    //~ClassRoom();
};
class LectureRoom: public Room {
public:

    LectureRoom(QString RoomNumber);
   //~LectureRoom();
};
class ConferenceRoom: public Room {
public:

    ConferenceRoom(QString RoomNumber);
    //~ConferenceRoom();
};

class Cabinet: public Room{
public:

    Cabinet(QString RoomNumber);
    //~Cabinet();
};

class DirectorCabinet: public Room{
public:

    DirectorCabinet(QString RoomNumber);
    //~DirectorCabinet();
};

#endif //UNTITLED4_ROOM_H
