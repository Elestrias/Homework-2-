//
// Created by rus8- on 07.03.2021.
//

#ifndef UNTITLED4_USER_H
#define UNTITLED4_USER_H
#include "Room.h"
#include <vector>
#include "AccessType.h"
#include "../dependencies.h"
using namespace std;
class User {
protected:
    QPair<QString, QString> initials;
    AccessType access;
    QString lovedJoke;
    vector<QPair<AccessType, QString>> adminGarants;
    QString login;
    QString password;

public:
    User(const QPair<QString, QString>& initials, const QString &lovedJoke, const QString log, const QString pass);
    User();
    //~User();
    virtual AccessType getAccess();
    virtual QPair<QString, QString> getInitials();
    virtual QPair<AccessType, bool> changeGlobalAccess(AccessType acc, AccessType newacc);
    virtual bool changeRoomAccess(AccessType acc, Room *room);
    virtual bool comeIn(Room *room);
    virtual QPair<QString, QString> getAccount();
};

class Student: public User{
public:
    Student(const QPair<QString, QString> &initials, const QString &lovedJoke, const QString log, const QString pass);
   // ~Student();
};
class Professor: public User{
protected:
    Room PersonalRoom;
public:
    Professor(const QPair<QString, QString> &initials, const Room &personalRoom, const QString &lovedJoke, const QString log, const QString pass);
    Professor();
   // ~Professor();
    void getCabinet(Room *room);
};
class LabStuff: public User{
public:

    LabStuff(const QPair<QString, QString> &initials, const QString &lovedJoke, const QString log, const QString pass);
};
class Director: public Professor{
public:

    Director(const QPair<QString, QString> &initials, const Room &personalRoom, const QString &lovedJoke, const QString log, const QString pass);
};
class Admin: public Professor{
public:

    Admin(const QPair<QString, QString> &initials, const Room &personalRoom, const QString &lovedJoke, const QString log, const QString pass);
    void giveGarant(User user, Room *room);
    void updateAccessRoots(User user, AccessType newacc);
};

#endif //UNTITLED4_USER_H
