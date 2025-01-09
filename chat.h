#ifndef CHAT_H
#define CHAT_H
#include <iostream>
#include <string>
#include <vector>
#include "user.h"
using namespace std; 

class Chat {
        
    public:
        vector<User> users;
        Chat();
        void write(int);
        void display();
        void addUser();
        int switchUser();
        string encryptDecrypt(const string&);
};

#endif