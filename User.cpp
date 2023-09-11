//
// Created by Utente on 08/09/2023.
//

#include "User.h"
#include <string>
#include <iostream>

using namespace std;
User::User(int n) : name(n){}

void User::write() {
    cin.clear();
    cin.sync();

    string s;
    cout<< "Scrivi il messaggio" << endl;
    getline(cin, s);
    message=s;
}

int User::getName() const {
    return name;
}

void User::setName(int name) {
    User::name = name;
}

const std::string &User::getMessage() const {
    return message;
}

void User::setMessage(const std::string &message) {
    User::message = message;
}


