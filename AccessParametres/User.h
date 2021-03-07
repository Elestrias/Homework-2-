//
// Created by Elestrias on 07.03.2021.
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
    QString UserType;
    QString personalRoom="No Cabinet";

public:
    User(const QPair<QString, QString>& initials, const QString &lovedJoke, const QString log, const QString pass);
    User();
    //~User();
    virtual AccessType getAccess();
    virtual QPair<QString, QString> getInitials();
    virtual QPair<AccessType, bool> changeGlobalAccess(AccessType acc, AccessType newacc);
    virtual bool changeRoomAccess(AccessType acc, Room *room);
    virtual bool comeIn(Room &room);
    virtual QPair<QString, QString> getAccount();
    virtual QString getJoke();
    virtual QString toString(AccessType AT);
    virtual QString getUserType();
    virtual QString getCabinet();
    virtual void setCabinet(Room room);
};
class Student: public User{
public:
    Student(const QPair<QString, QString> &initials, const QString &lovedJoke, const QString log, const QString pass);
   // ~Student();
};
class Professor: public User{
protected:
    QString personalCabinete = "AAAAAAAA";
public:
    Professor(const QPair<QString, QString> &initials, const QString personalRoom, const QString &lovedJoke, const QString log, const QString pass);
    Professor();
    //~Professor();
    QString getCabinet() override;
    void setCabinet(Room room) override;

};
class LabStuff: public User{
public:

    LabStuff(const QPair<QString, QString> &initials, const QString &lovedJoke, const QString log, const QString pass);
};
class Director: public Professor{
public:

    Director(const QPair<QString, QString> &initials, const QString &personalRoom, const QString &lovedJoke, const QString log, const QString pass);
};
class Admin: public Professor{
public:

    Admin(const QPair<QString, QString> &initials, const QString &personalRoom, const QString &lovedJoke, const QString log, const QString pass);
    void giveGarant(User user, Room *room);
    void updateAccessRoots(User user, AccessType newacc);
};



#endif //UNTITLED4_USER_H
