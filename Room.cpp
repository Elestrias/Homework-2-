//
// Created by Elestrias on 07.03.2021.
//

#include "Room.h"
#include "AccessType.h"
#include "User.h"
Room::Room(string RoomNumber): roomNumber(RoomNumber){
}
string Room::getNumber(){
    return roomNumber;
}
string Room::getRoomType() {
    return roomType;
}
bool Room::getAccess(AccessType acc) {
    if(acc >= neededAccess){
        return true;
    } else{
        return false;
    }
}

AccessType Room::getAccessType() {
    return neededAccess;
}

ClassRoom::ClassRoom(string RoomNumber):Room(RoomNumber){
    roomType = "Class Room";
    neededAccess = NO_LEVEL;
}

LectureRoom::LectureRoom(string RoomNumber): Room(RoomNumber){
    roomType = "Lecture Room";
    neededAccess = GREEN;
}

ConferenceRoom::ConferenceRoom(string RoomNumber): Room(RoomNumber){
    roomType = "Conference Room";
    neededAccess = YELLOW;
}

Cabinet::Cabinet(string RoomNumber) : Room(RoomNumber){
    roomType = "Cabinet";
    neededAccess = RED;
}
DirectorCabinet::DirectorCabinet(string RoomNumber): Room(RoomNumber){
    roomType = "Director Cabinet";
    neededAccess = RED;
}
