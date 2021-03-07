//
// Created by Elestrias on 07.03.2021.
//

#include "User.h"
#include "../dependencies.h"

User::User(const QPair<QString, QString> &initials, const QString &LovedJoke, const QString log, const QString pass) :
                                                                                            initials(initials),
                                                                                            lovedJoke(LovedJoke),
                                                                                                    login(log),password(pass){
    access = NO_LEVEL;
}
 AccessType User::getAccess(){
    return access;
}

 User::User(){
     access = NO_LEVEL;
 }

QPair<QString, QString> User::getInitials(){
    return initials;
}

QPair<AccessType, bool> User::changeGlobalAccess(AccessType acc, AccessType newacc) {
    if (acc == RED) {
        access = newacc;
        return {access, true};
    }
    return {access, false};
}

QString User::getCabinet(){
    return personalRoom;
}
void User::setCabinet(Room room){
}

bool User::comeIn(Room &room) {
    bool opened = room.getAccess(access);
    if(!opened) {
        for (int i = 0; i < adminGarants.size(); ++i) {
            if(adminGarants[i].second == room.getNumber()){
                opened = true;
            }
        }
    }
    return opened;
}

bool User::changeRoomAccess(AccessType acc, Room *room){
    bool flag = false;
    if(acc == RED){
        for(int i = 0; i < adminGarants.size(); ++i) {
            if (room->getNumber() == adminGarants[i].second){
                flag = true;
            }
        }
        if(!flag){
            adminGarants.push_back({RED, room->getNumber()});
            return true;
        }else{
            return false;
        }
    }
    else{
        return false;
    }
}
QPair<QString, QString> User::getAccount(){
    return qMakePair(login, password);
}
QString User::getJoke(){
    return lovedJoke;
}

QString User::toString(AccessType AT){
    switch(AT){
        case(NO_LEVEL): return "NO LEVEL";
        case(GREEN): return "GREEN";
        case(YELLOW): return "YELLOW";
        case(RED): return "RED";
    }
}
QString User::getUserType(){
    return UserType;
}

Student::Student(const QPair<QString, QString> &initials, const QString &lovedJoke, const QString log, const QString pass) : User(initials, lovedJoke, log, pass){
    access = NO_LEVEL;
    UserType = "Student";
}


Professor::Professor(const QPair<QString, QString> &initials,const QString personalRoom, const QString &LovedJoke, const QString log, const QString pass): User(initials, LovedJoke, log, pass){
    access = GREEN;
    personalCabinete = personalRoom;
    UserType = "Professor";
}


QString Professor::getCabinet(){
    return personalCabinete;
}
void Professor::setCabinet(Room room){
    personalCabinete = room.getNumber();
}

LabStuff::LabStuff(const QPair<QString, QString> &initials, const QString &personalRoom, const QString log, const QString pass): User(initials, personalRoom, log, pass) {
    access = GREEN;
    UserType = "LabStuff";
}
Director::Director(const QPair<QString, QString> &initials, const QString &personalRoom,const QString &LovedJoke, const QString log, const QString pass): Professor(initials,
                                                                                                                   personalRoom,
                                                                                                                      LovedJoke, log, pass){
    access = YELLOW;
    UserType = "Director";
}


Admin::Admin(const QPair<QString, QString> &initials, const QString &PersonalRoom, const QString &LovedJoke, const QString log, const QString pass):Professor(initials,
                                                                                                                  PersonalRoom,
                                                                                                                  LovedJoke, log, pass){
    access = RED;
    UserType = "Admin";
}

void Admin::updateAccessRoots(User user, AccessType newacc) {
    user.changeGlobalAccess(this->access, newacc);
}
void Admin::giveGarant(User user, Room *room) {
    user.changeRoomAccess(RED, room);
}





