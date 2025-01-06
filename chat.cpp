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

    if (!fout) {
        cerr<<"Error: Unable to open chat log for writing.\n";
    }

    fout.open("chatlog.txt", ios::app);
    fout << "User " << userTurn << ": " << message <<endl;
    fout.close();
    cout<<"Message Sent!"<<endl;
}

void display(){
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

void switchUSer(){

}

