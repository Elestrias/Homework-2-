//
// Created by rus8- on 07.03.2021.
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

bool User::comeIn(Room *room) {
    bool opened = room->getAccess(access);
    if(!opened) {
        for (int i = 0; i < adminGarants.size(); ++i) {
            if(adminGarants[i].second == room->getNumber()){
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
Student::Student(const QPair<QString, QString> &initials, const QString &lovedJoke, const QString log, const QString pass) : User(initials, lovedJoke, log, pass){
    access = NO_LEVEL;
}

Professor::Professor(const QPair<QString, QString> &initials,const Room &personalRoom, const QString &LovedJoke, const QString log, const QString pass): User(initials, LovedJoke, log, pass), PersonalRoom(personalRoom){
    access = GREEN;
}

LabStuff::LabStuff(const QPair<QString, QString> &initials, const QString &personalRoom, const QString log, const QString pass): User(initials, personalRoom, log, pass) {
    access = GREEN;
}

Director::Director(const QPair<QString, QString> &initials, const Room &personalRoom,const QString &LovedJoke, const QString log, const QString pass): Professor(initials,
                                                                                                                   personalRoom,
                                                                                                                      LovedJoke, log, pass){
    access = YELLOW;
}

Admin::Admin(const QPair<QString, QString> &initials, const Room &PersonalRoom, const QString &LovedJoke, const QString log, const QString pass):Professor(initials,
                                                                                                                  PersonalRoom,
                                                                                                                  LovedJoke, log, pass){
    access = RED;
}

void Admin::updateAccessRoots(User user, AccessType newacc) {
    user.changeGlobalAccess(this->access, newacc);
}
void Admin::giveGarant(User user, Room *room) {
    user.changeRoomAccess(this->access, room);
}


