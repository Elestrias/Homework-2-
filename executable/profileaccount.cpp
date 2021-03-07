#include "../headers/profileaccount.h"
#include "ui_profileaccount.h"
#include "../dependencies.h"
#include "../headers/mainwindow.h"

ProfileAccount::ProfileAccount(QWidget *parent, User *user, QVector<Room> rooms, QVector<User> users) :
    QMainWindow(parent), user(user), rooms(rooms), people(users),
    ui(new Ui::ProfileAccount)
{

    ui->setupUi(this);
    for (int i = 0;i<rooms.size() ;i++ ) {
        Room room = rooms[i];
        if(room.getRoomType() == "Cabinet" || room.getRoomType() == "Director Cabinet"){
            ui->PersonalCabinetes->addItem(room.getNumber());
        }
        ui->AccessRooms->addItem(room.getNumber());
        ui->Room->addItem(room.getNumber());
    }
    for(int i=0; i<people.size();i++){
        ui->Users->addItem(people[i].getAccount().first);
        ui->Users_2->addItem(people[i].getAccount().first);
    }
    connect(ui->exit, &QPushButton::clicked, this, &QApplication::exit);
    }


ProfileAccount::~ProfileAccount()
{
    delete ui;
}

void ProfileAccount::SetData(User* user, QString personalcabinet, QVector<User> users, QVector<Room> rooms){
    this->user = user;
    QPair<QString, QString> initials = user->getInitials();
    ui->Name->setText(initials.first);
    ui->Surname->setText(initials.second);
    ui->PersonalRoom->setText(personalcabinet);
    ui->AccesLevel->setText(user->toString(user->getAccess()));
    ui->likedjoke->setText(user->getJoke());
    ui->accesLabel->setText("Check your room access");
    this->rooms = rooms;
    this->people = users;
}

void ProfileAccount::on_logout_clicked(){
    this->close();
    emit goToLoginWindow();
}

bool getAccessf(User us, Room rm){
    if(us.getAccess() >= rm.getAccessType() || us.comeIn(rm)){
        return true;
    } else{
        return false;
    }
}

void ProfileAccount::on_getAccess_clicked(){
    qDebug()<<"1";
    QString roomnumber = ui->PersonalCabinetes->currentText();

    Room *room;
    bool flag = false;
    ;
    for(int i=0; i<rooms.size();i++){

        if(rooms[i].getNumber() == roomnumber){
            flag = user->comeIn(rooms[i]);

        }
    }
    flag = flag || getAccessf(*user, Room(roomnumber));
    if(flag){
        ui->accesLabel->setText("Welcome in!");
    }else{
        ui->accesLabel->setText("You are not allowed to enter this room");
    }
}

void ProfileAccount::on_apllyChanges_clicked(){
    QString roomnumber = ui->PersonalCabinetes->currentText();
    qDebug()<<roomnumber;
    if(user ->getUserType() == "Professor" || user->getUserType() == "Director"){
        for (int i = 0; i<rooms.size();i++ ) {
            if(rooms[i].getNumber() == roomnumber){
                user->setCabinet(rooms[i]);
                ui->PersonalRoom->setText(rooms[i].getNumber());
                break;
            }
        }
    }else{
        ui->CabinetLabel->setText("You have no permission");
    }
}

void ProfileAccount::on_ApplyOpen_clicked(){
    if(user->getUserType() == "Admin"){
    QString roomnumber = ui->Room->currentText();
    QString human = ui->Users->currentText();
    bool flag = false;
    for(int i = 0; i<rooms.size(); i++){
        if(roomnumber == rooms[i].getNumber()){
            for(int j = 0; j<people.size();j++){
                if(people[i].getAccount().first == human){
                    Admin &admin = (Admin &) user;
                    admin.giveGarant(people[i], &rooms[i]);
                    ui->OpenRoom->setText("Successfuly done!");
                    break;
                }
            }
        }
        if(flag){
            break;
        }
    }
    }else{
        ui->OpenRoom->setText("You dont have access!");
    }
}

