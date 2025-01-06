#include <iostream>
#include <string>
#include <fstream>
#include "chat.h"
using namespace std;

int userTurn = 1;

void write() {
    string message;
    cout<<"\n"<<endl;
    cout << "Type your message"<<endl;
    cin.ignore();
    getline(cin, message);
    ofstream fout;
    fout.open("chatlog.txt", ios::app);
    fout << "User " << userTurn << ": " << message <<endl;
    fout.close();
}

void display(){
    string line;
    ifstream fin;
    fin.open("chatlog.txt");
    cout<< "Chat History"<<endl;
    while (getline(fin, line)) {
        cout<<line<<endl;
        cout<<"\n"<<endl;
    }
    fin.close();
}

int main() {
    ofstream("chatlog.txt");
    int choice;
    while (true) {
        cout << "Welcome to the chat! Currently set as User "<<userTurn<<endl;
        cout << "Select Choice By Number:"<<endl;
        cout << "1. Write Message" <<endl;
        cout << "2. Display Messages" <<endl;
        cout << "3. Switch User"<<endl;
        cout << "4. Exit" <<endl;
        cout << "\n"<<endl;

        cin >> choice;
        if (choice==1){
            write();
        } else if (choice==2) {
            display();
        } else if (choice==3) {
            if (userTurn==1) {
                userTurn=2;
                cout<<"Switched to User 2"<<endl;
                cout<<"\n"<<endl;
            } else {
                userTurn=1;
                cout<<"Switched to User 1"<<endl;
                cout<<"\n"<<endl;
            }
        } else if (choice==4) {
            break;
        }

        
    }
    remove("chatlog.txt");
    return 0;
}