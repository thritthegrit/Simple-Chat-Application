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