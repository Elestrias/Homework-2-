#include "../headers/mainwindow.h"

#include <iostream>
#include <QApplication>
#include <QString>
#include "../dependencies.h"
#include "../AccessParametres/User.h"
#include <QDebug>
int admincode;
using namespace std;

bool getAccess(User us, Room rm){
    if(us.getAccess() >= rm.getAccessType() || us.comeIn(rm)){
        return true;
    } else{
        return false;
    }
}

QVector<QString> parseByPROBEL(QString x){
    QVector<QString> ans;
    QString temp = "";
    for(int i = 0; i < x.size(); ++i){
        if (x[i] == ' '){
            ans.push_back(temp);
            temp = "";
        } else{
            temp += x[i];
        }
    }
    ans.push_back(temp);
    return ans;
}

QVector<User> parserFromTxt(){
    QVector<User> users;

    QFile file("C://Users/rus8-/Documents/Homework2/executable/database.txt");

    if ((file.exists() && file.open(QIODevice::ReadOnly))){
        admincode = file.readLine().toInt();
        qDebug() << admincode;

        while(!file.atEnd()){
            QVector<QString> sentenses = parseByPROBEL(file.readLine());
             User x;
             QString joke;
             for(int i = 6; i < sentenses.size(); ++i){
                 joke += sentenses[i] + " ";
             }
             qDebug() << joke;
            if (sentenses[0] == "Student"){
                 x = Student(qMakePair(sentenses[3], sentenses[4]), joke, sentenses[1], sentenses[2]);

            }
            if (sentenses[0] == "Professor"){
                 x = Professor(qMakePair(sentenses[3], sentenses[4]), sentenses[5], joke, sentenses[1], sentenses[2]);
            }
            if (sentenses[0] == "Director"){
                 x = Director(qMakePair(sentenses[3], sentenses[4]), sentenses[5], joke, sentenses[1], sentenses[2]);
            }
            if (sentenses[0] == "Admin"){
                 x = Admin(qMakePair(sentenses[3], sentenses[4]), sentenses[5], joke, sentenses[1], sentenses[2]);
            }
            if (sentenses[0] == "LabStaff"){
                 x = LabStuff(qMakePair(sentenses[3], sentenses[4]), joke, sentenses[1], sentenses[2]);
            }
            users.push_back(x);
            //qDebug() << x.getInitials().first << '\n' << x.getInitials().second << "\n\n";
            //qDebug() << x.getAccount().first << '\n' << x.getAccount().second << "\n\n\n";
            if (sentenses.size() >= 5){
                qDebug() << sentenses[5];
            }
        }

    }


    return users;
}

QVector<Room> generateRooms(){
    QVector<Room> rooms;
    Room *room;
    room = new DirectorCabinet("101");
    rooms.push_back(*room);
    room = new Cabinet("400");
    rooms.push_back(*room);
    room = new Cabinet("401");
    rooms.push_back(*room);
    room = new Cabinet("402");
    rooms.push_back(*room);
    room = new Cabinet("403");
    rooms.push_back(*room);
    room = new Cabinet("404");
    rooms.push_back(*room);
    room = new Cabinet("405");
    rooms.push_back(*room);
    room = new LectureRoom("105");
    rooms.push_back(*room);
    room = new LectureRoom("106");
    rooms.push_back(*room);
    room = new LectureRoom("107");
    rooms.push_back(*room);
    room = new LectureRoom("108");
    rooms.push_back(*room);
    room = new ClassRoom("301");
    rooms.push_back(*room);
    room = new ClassRoom("302");
    rooms.push_back(*room);
    room = new ClassRoom("303");
    rooms.push_back(*room);
    room = new ClassRoom("304");
    rooms.push_back(*room);
    room = new ClassRoom("305");
    rooms.push_back(*room);
    room = new ClassRoom("306");
    rooms.push_back(*room);
    room = new ClassRoom("307");
    rooms.push_back(*room);
    room = new ClassRoom("308");
    rooms.push_back(*room);
    room = new ConferenceRoom("1.1");
    rooms.push_back(*room);
    room = new ConferenceRoom("1.2");
    rooms.push_back(*room);
    room = new ConferenceRoom("1.3");
    rooms.push_back(*room);
    room = new ConferenceRoom("1.4");
    rooms.push_back(*room);
    room = new ConferenceRoom("2.1");
    rooms.push_back(*room);
    room = new ConferenceRoom("2.2");
    rooms.push_back(*room);
    room = new ConferenceRoom("2.3");
    rooms.push_back(*room);
    room = new ConferenceRoom("3.1");
    rooms.push_back(*room);
    return rooms;
}

int main(int argc, char *argv[])
{
    QVector<User> users = parserFromTxt();
    QVector<Room> rooms = generateRooms();
    QApplication a(argc, argv);
    MainWindow w(0, users, rooms);
    w.show();
    return a.exec();
}
