#ifndef CHAT_H
#define CHAT_H
#include <iostream>
#include <string>
using namespace std; 

class Chat {
        
    public:
        vector<User> users;
        Chat();
        void write();
        void display();
        void addUser(int, string);
        void switchUser();
};

#endif