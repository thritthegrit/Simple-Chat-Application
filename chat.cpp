#include <iostream>
#include <string>
#include <fstream>
#include "chat.h"
using namespace std;

int userTurn = 1;

void write(string message) {
    ofstream fout;
    fout.open("chatlog.txt", ios::app);
    fout << "User " + to_string(userTurn) + ": " + message <<endl;
    fout.close();
}

void display(){
    string line;
    ifstream fin;
    fin.open("chstlog.txt");
    while (fin >> line) {
        cout<<line<<endl;
    }

    fin.close();
}