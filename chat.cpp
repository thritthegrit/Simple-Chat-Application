#include <iostream>
#include <string>
#include <fstream>
#include "chat.h"
using namespace std;

int userTurn = 1;

void write() {
    string message;
    cout << "Type your message"<<endl;
    cin >> message;
    ofstream fout;
    fout.open("chatlog.txt", ios::app);
    fout << "User " + to_string(userTurn) + ": " + message <<endl;
    fout.close();
}

void display(){
    string line;
    ifstream fin;
    fin.open("chatlog.txt");
    while (fin >> line) {
        cout<<line<<endl;
    }

    fin.close();
}

int main() {
    ofstream("chatlog.txt");
    int choice;
    while (true) {
        cout << "Select Choice By Number:";
        cout << "1. Write Message" <<endl;
        cout << "2. Display Messages" <<endl;
        cout << "3. Exit" <<endl;

        cin >> choice;
        if (choice==1){
            write();
        } else if (choice==2) {
            display();
        } else if (choice==3) {
            break;
        }

        remove("chatlog.txt");
        return 0;

    }
}