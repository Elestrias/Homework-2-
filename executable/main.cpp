#include "../headers/mainwindow.h"

#include <QApplication>
#include <QString>
#include "../dependencies.h"
#include "../AccessParametres/User.h"
int admincode;


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

    QTextStream out(stdout);
    QString filename = "database.txt";
    QTextStream in(&filename);

    admincode = in.readLine().toInt();

    while(!in.atEnd()){
        QVector<QString> sentenses = parseByPROBEL(in.readLine());
         User x;
        if (sentenses[0] == "Student"){
             x = Student(qMakePair(sentenses[3], sentenses[4]), sentenses[6], sentenses[1], sentenses[2]);

        }
        if (sentenses[0] == "Professor"){
             x = Professor(qMakePair(sentenses[3], sentenses[4]), sentenses[5], sentenses[6], sentenses[1], sentenses[2]);
        }
        if (sentenses[0] == "Director"){
             x = Director(qMakePair(sentenses[3], sentenses[4]), sentenses[5], sentenses[6], sentenses[1], sentenses[2]);
        }
        if (sentenses[0] == "Admin"){
             x = Admin(qMakePair(sentenses[3], sentenses[4]), sentenses[5], sentenses[6], sentenses[1], sentenses[2]);
        }
        if (sentenses[0] == "LabStaff"){
             x = LabStuff(qMakePair(sentenses[3], sentenses[4]), sentenses[6], sentenses[1], sentenses[2]);
        }
        sentenses.push_back(x);
    }
    return users;
}

int main(int argc, char *argv[])
{
    QVector<User> users = parserFromTxt();
    QApplication a(argc, argv);
    MainWindow w(0, users);
    w.show();
    return a.exec();
}
