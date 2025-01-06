#include <iostream>
#include <string>
#include <fstream>
#include "user.h"
using namespace std;

User::User(int id, string name) {
    userId = id;
    userName = name;
}

User::User(int id) {
    userId = id;
    userName = "Placeholder";
}