//
// Created by Elestrias on 07.03.2021.
//

#ifndef UNTITLED4_USER_H
#define UNTITLED4_USER_H
#include "Room.h"
#include <vector>
#include "AccessType.h"
#include "dependencies.h"
using namespace std;
class User {
protected:
    pair<string, string> initials;
    AccessType access;
    string lovedJoke;
    vector<pair<AccessType, string>> adminGarants;
    string login;
    string password;
    string UserType;
    string personalCabinet="No Cabinet";

public:
    User(const pair<string, string>& initials, const string &lovedJoke, const string log, const string pass);
    User();
    //~User();
    virtual AccessType getAccess();
    virtual pair<string, string> getInitials();
    virtual pair<AccessType, bool> changeGlobalAccess(AccessType acc, AccessType newacc);
    virtual bool changeRoomAccess(AccessType acc, Room *room);
    virtual bool comeIn(Room &room);
    static string toString(AccessType AT);
    virtual string getUserType();

};
class Student: public User{
public:
    Student(const pair<string, string> &initials, const string &lovedJoke, const string log, const string pass);
   // ~Student();
};
class Professor: public User{
protected:
    string PersonalRoom = "000";
public:
    Professor(const pair<string, string> &initials, const string personalRoom, const string &lovedJoke, const string log, const string pass);
    Professor();
    //~Professor();
    string getCabinet() override;
    void setCabinet(Room &room);

};
class LabStuff: public User{
public:

    LabStuff(const pair<string, string> &initials, const string &lovedJoke, const string log, const string pass);
};
class Director: public Professor{
public:

    Director(const pair<string, string> &initials, const string &personalRoom, const string &lovedJoke, const string log, const string pass);
};
class Admin: public Professor{
public:

    Admin(const pair<string, string> &initials, const string &personalRoom, const string &lovedJoke, const string log, const string pass);
    void giveGarant(User user, Room *room);
    void updateAccessRoots(User user, AccessType newacc);
};



#endif //UNTITLED4_USER_H
