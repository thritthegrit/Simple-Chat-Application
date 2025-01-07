#include <iostream>
#include <string>
#include <fstream>
#include "chat.h"
#include "user.h"
using namespace std;

int userTurn = 1;

Chat::Chat(){
    users.push_back(User(1, "Default_1"));
    users.push_back(User(2, "Default_2"));

    //vector<User> users = {User(1, "Default_1"), User(2, "Default_2")};
}

void Chat::write(int userTurn) {
    string message;
    cout << "Type your message: ";
    cin.ignore();
    getline(cin, message);
    ofstream fout;

    if (!fout) {
        cerr<<"Error: Unable to open chat log for writing.\n";
    }

    fout.open("chatlog.txt", ios::app);
    fout << "User " << userTurn << ": " << message <<endl;
    fout.close();
    cout<<"Message Sent!"<<endl;
}

void Chat::display(){
    string line;
    ifstream fin;
    
    if (!fin) {
        cerr << "Error: Unable to open chat log for reading.\n";
    }

    fin.open("chatlog.txt");
    cout<< "Chat History"<<endl;
    cout<< "------------"<<endl;
    while (getline(fin, line)) {
        cout<<line<<endl;
        cout<<"\n"<<endl;
    }
    fin.close();
}

int Chat::switchUser(){
    int choice;
    cout<<"Current Available Users:"<<endl;
    for (int i=0;i<users.size();i++) {
        cout<<i+1<<". User ID: "<<users[i].userId<<"    User Name: "<<users[i].userName<<endl;
    }
    cout<<"Select user by User ID: ";
    cin >> choice;
    for (int i=0;i<users.size();i++){
        if (users[i].userId==choice) {
            return users[i].userId; //set current user in main
        }
    }
    return 0;
}

void Chat::addUser(){
    cout<<"Current Users:"<<endl;
    for (int i=0;i<users.size();i++) {
        cout<<i+1<<". User ID: "<<users[i].userId<<"    User Name: "<<users[i].userName<<endl;
    }
    
    int id;
    string name;
    cout << "Enter User Id Number: ";
    cin >> id;
    cout << "Enter User Name: ";
    cin >> name;
    users.push_back(User(id, name));
}

