#include <iostream>
#include <string>
#include "dependencies.h"
#include "User.h"
#include "Room.h"
#include <fstream>
int admincode;
using namespace std;

bool getAccess(User us, Room rm){
    if(us.getAccess() >= rm.getAccessType() || us.comeIn(rm)){
        return true;
    } else{
        return false;
    }
}


vector<string> parseByPROBEL(string x){
    vector<string> ans;
    string temp = "";
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

vector<User> parserFromTxt(){
    vector<User> users;

    ifstream file("/home/mark/CLionProjects/Ruslan/database.txt");

    if (file.is_open()){
        file >> admincode;

        string s;
        getline(file, s);
        while(!file.eof()){
            getline(file, s);
            vector<string> sentenses = parseByPROBEL(s);
             User x;
             string joke;
             for(int i = 6; i < sentenses.size(); ++i){
                 joke += sentenses[i] + " ";
             }
            if (sentenses[0] == "Student"){
                 x = Student(make_pair(sentenses[3], sentenses[4]), joke, sentenses[1], sentenses[2]);

            }
            if (sentenses[0] == "Professor"){
                 x = Professor(make_pair(sentenses[3], sentenses[4]), sentenses[5], joke, sentenses[1], sentenses[2]);
            }
            if (sentenses[0] == "Director"){
                 x = Director(make_pair(sentenses[3], sentenses[4]), sentenses[5], joke, sentenses[1], sentenses[2]);
            }
            if (sentenses[0] == "Admin"){
                 x = Admin(make_pair(sentenses[3], sentenses[4]), sentenses[5], joke, sentenses[1], sentenses[2]);
            }
            if (sentenses[0] == "LabStaff"){
                 x = LabStuff(make_pair(sentenses[3], sentenses[4]), joke, sentenses[1], sentenses[2]);
            }
            users.push_back(x);
        }

    }


    return users;
}

vector<Room> generateRooms(){
    vector<Room> rooms;
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
    vector<User> users = parserFromTxt();
    users.pop_back();
    vector<Room> rooms = generateRooms();

    while(1){
        cout << "\n\n\nEnter END to end programm!!!\n\n\n";
        cout << "Users: \n";
        int k = 0;
        for(auto& u : users){
            cout << k++ << ") " << u.getUserType() << " : " << u.getInitials().first << ' ' << u.getInitials().second
            << "| Access Type: " << User::toString(u.getAccess()) <<'\n';
        }

        cout << "Choose User: ";
        string str;
        cin >> str;
        if (str == "END"){
            break;
        }
        int x = stoi(str);

        if (users[x].getUserType() == "Admin"){
            cout << "You want to enter to room(0) or change permission(1)?: ";
            cin >> str;
            if (str == "END"){
                break;
            }
            int t = stoi(str);
            if (t == 0){
                goto enter;
            } else{
                cout << "Choose user, which you wanna change a permission: ";
                cin >> str;
                if (str == "END"){
                    break;
                }

                int us = stoi(str);

                cout << "Choose room which you want to open for him/her: ";
                cin >> str;
                if (str == "END"){
                    break;
                }

                users[us].changeRoomAccess(RED, new Room(str));
            }
        } else{
            enter:
            cout << "Rooms: \n";
            int k = 0;
            for(auto& u: rooms){
                cout << k ++ << ") " << u.getNumber() << " | Type: " << u.getRoomType() <<'\n';
            }

            cout << "Choose Room: ";
            cin >> str;
            if (str == "END"){
                break;
            }
            int xRoom = stoi(str);

            if (getAccess(users[x], rooms[xRoom])){
                cout << "\n\nAccess!!!\n\n";
            } else{
                cout << "\n\n***WRONG***\n\n";
            }
        }
    }

    return 0;
}
