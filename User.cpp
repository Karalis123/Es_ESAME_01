//
// Created by Utente on 08/09/2023.
//

#include "User.h"

User::User(int n) : name(n){}

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
