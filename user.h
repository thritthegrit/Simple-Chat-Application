#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#ifndef USER_H
#define USER_H

class User {
    public:
        int userId;
        string userName;
        User(int, string);
        User(int);
        //get user id by counting number of items in vector in main when you create user
};

#endif