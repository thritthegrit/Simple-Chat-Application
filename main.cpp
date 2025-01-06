#include <iostream>
#include <string>
#include <fstream>
#include "chat.cpp"
#include "user.cpp"
#include <vector>
using namespace std;

int main() {
    vector<User> users = {User(1, "Default_1"), User(2, "Default_2")};

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
        } else {
            cout << "Invalid choice. Try again."<<endl;
        }

        
    }
    remove("chatlog.txt");
    return 0;
}
