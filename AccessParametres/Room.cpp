//
// Created by Elestrias on 07.03.2021.
//

#include "Room.h"
#include "AccessType.h"
Room::Room(QString RoomNumber): roomNumber(RoomNumber){
}
QString Room::getNumber(){
    return roomNumber;
}
QString Room::getRoomType() {
    return roomType;
}
bool Room::getAccess(AccessType acc) {
    if(acc >= neededAccess){
        return true;
    } else{
        return false;
    }
}

AccessType Room::getAccessType(){
    return neededAccess;
}

ClassRoom::ClassRoom(QString RoomNumber):Room(RoomNumber){
    roomType = "Class Room";
    neededAccess = NO_LEVEL;
}

LectureRoom::LectureRoom(QString RoomNumber): Room(RoomNumber){
    roomType = "Lecture Room";
    neededAccess = GREEN;
}

ConferenceRoom::ConferenceRoom(QString RoomNumber): Room(RoomNumber){
    roomType = "Conference Room";
    neededAccess = GREEN;
}

Cabinet::Cabinet(QString RoomNumber) : Room(RoomNumber){
    roomType = "Cabinet";
    neededAccess = RED;
}
DirectorCabinet::DirectorCabinet(QString RoomNumber): Room(RoomNumber){
    roomType = "Director Cabinet";
    neededAccess = RED;
}
