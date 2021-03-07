//
// Created by rus8- on 07.03.2021.
//

#include "Room.h"
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

ClassRoom::ClassRoom(QString RoomNumber):Room(RoomNumber){
    roomType = "Class Room";
}

LectureRoom::LectureRoom(QString RoomNumber): Room(RoomNumber){
    roomType = "Lecture Room";
}

ConferenceRoom::ConferenceRoom(QString RoomNumber): Room(RoomNumber){
    roomType = "Conference Room";
}

Cabinet::Cabinet(QString RoomNumber) : Room(RoomNumber){
    roomType = "Cabinet";
}
DirectorCabinet::DirectorCabinet(QString RoomNumber): Room(RoomNumber){
    roomType = "Director Cabinet";
}
