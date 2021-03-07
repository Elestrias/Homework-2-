//
// Created by Elestrias on 07.03.2021.
//

#include "User.h"
#include "dependencies.h"

User::User(const pair<string, string> &initials, const string &LovedJoke, const string log, const string pass) :
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

pair<string, string> User::getInitials(){
    return initials;
}

pair<AccessType, bool> User::changeGlobalAccess(AccessType acc, AccessType newacc) {
    if (acc == RED) {
        access = newacc;
        return {access, true};
    }
    return {access, false};
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

string User::getCabinet(){
    return personalCabinet;
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
pair<string, string> User::getAccount(){
    return make_pair(login, password);
}
string User::getJoke(){
    return lovedJoke;
}

string User::toString(AccessType AT){
    switch(AT){
        case(NO_LEVEL): return "NO LEVEL";
        case(GREEN): return "GREEN";
        case(YELLOW): return "YELLOW";
        case(RED): return "RED";
    }
}
string User::getUserType(){
    return UserType;
}

Student::Student(const pair<string, string> &initials, const string &lovedJoke, const string log, const string pass) : User(initials, lovedJoke, log, pass){
    access = NO_LEVEL;
    UserType = "Student";
}


Professor::Professor(const pair<string, string> &initials,const string personalRoom, const string &LovedJoke, const string log, const string pass): User(initials, LovedJoke, log, pass), PersonalRoom(personalRoom){
    access = GREEN;
    UserType = "Professor";
}


string Professor::getCabinet(){
    return PersonalRoom;
}

void Professor::setCabinet(Room &room){
    PersonalRoom = room.getNumber();
}

LabStuff::LabStuff(const pair<string, string> &initials, const string &personalRoom, const string log, const string pass): User(initials, personalRoom, log, pass) {
    access = GREEN;
    UserType = "LabStuff";
}
Director::Director(const pair<string, string> &initials, const string &personalRoom,const string &LovedJoke, const string log, const string pass): Professor(initials,
                                                                                                                   personalRoom,
                                                                                                                      LovedJoke, log, pass){
    access = YELLOW;
    UserType = "Director";
}


Admin::Admin(const pair<string, string> &initials, const string &PersonalRoom, const string &LovedJoke, const string log, const string pass):Professor(initials,
                                                                                                                  PersonalRoom,
                                                                                                                  LovedJoke, log, pass){
    access = RED;
    UserType = "Admin";
}

void Admin::updateAccessRoots(User user, AccessType newacc) {
    user.changeGlobalAccess(this->access, newacc);
}
void Admin::giveGarant(User user, Room *room) {
    user.changeRoomAccess(this->access, room);
}


