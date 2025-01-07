#include <iostream>
#include <string>
#include <fstream>
#include "chat.cpp"
#include "user.cpp"
#include <vector>
using namespace std;

int main() {
    Chat currChat;
    ofstream("chatlog.txt");

    int currUser = 1;

    int choice;

    cout << "Welcome to the chat!"<<endl;


    while (true) {
        cout << "------------------------"<<endl;
        cout <<"Menu:                 Current User: "<<currUser<<endl;
        cout << "1. Write Message" <<endl;
        cout << "2. Display Messages" <<endl;
        cout << "3. Add User" <<endl;
        cout << "4. Switch User"<<endl;
        cout << "5. Exit" <<"\n"<<endl;
        cout << "Select Choice By Number: ";

        cin >> choice;
        cout << "\n"<<endl;

        if (choice==1){
            currChat.write(currUser);
        } else if (choice==2) {
            currChat.display();
        } else if (choice==3) {
            currChat.addUser();
            cout<< "User successfully added!"<<endl;
        } else if (choice==4) {
            int temp;
            temp = currChat.switchUser();
            if (temp==0) {
                cout<<"User does not exist."<<endl; 
            } else {
                currUser = temp;
                cout <<"Switched to User "<<currUser<<endl;
            }
            cout <<"\n"<<endl;
        } else if (choice==5) {
            break;
        } else {
            cout << "Invalid choice. Try again."<<endl;
        }

        
    }
    remove("chatlog.txt");
    return 0;
}
