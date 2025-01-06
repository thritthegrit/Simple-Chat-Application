#include <iostream>
#include <string>
#include <fstream>
#include "chat.h"
using namespace std;

int userTurn = 1;

void write() {
    string message;
    cout << "Type your message: ";
    cin.ignore();
    getline(cin, message);
    ofstream fout;
    fout.open("chatlog.txt", ios::app);
    fout << "User " << userTurn << ": " << message <<endl;
    fout.close();
    cout<<"Message Sent!"<<endl;
}

void display(){
    string line;
    ifstream fin;
    fin.open("chatlog.txt");
    cout<< "Chat History"<<endl;
    cout<< "------------"<<endl;
    while (getline(fin, line)) {
        cout<<line<<endl;
        cout<<"\n"<<endl;
    }
    fin.close();
}

int main() {
    ofstream("chatlog.txt");
    int choice;

    cout << "Welcome to the chat!"<<endl;


    while (true) {
        cout << "------------------------"<<endl;
        cout <<"Menu:                 Current User: "<<userTurn<<endl;
        cout << "1. Write Message" <<endl;
        cout << "2. Display Messages" <<endl;
        cout << "3. Switch User"<<endl;
        cout << "4. Exit" <<"\n"<<endl;
        cout << "Select Choice By Number: ";

        cin >> choice;
        cout << "\n"<<endl;

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