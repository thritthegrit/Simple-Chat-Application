#ifndef CHAT_H
#define CHAT_H
#include <iostream>
#include <string>
using namespace std; 

class Chat {
    private:
        int userTurn;
    public:
        void write();
        string display();
};

#endif