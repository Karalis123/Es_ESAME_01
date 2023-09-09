//
// Created by Utente on 08/09/2023.
//

#include "Chat.h"

Chat::Chat(int n) : num(n){}

Chat::Chat() = default;

void Chat::insertLast(User* u) {
    users.push_back(u);
}








const multimap<int, string> &Chat::getConversazione() const {
    return conversazione;
}

void Chat::setConversazione(const multimap<int, string> &conversazione) {
    Chat::conversazione = conversazione;
}

int Chat::getNum() const {
    return num;
}

void Chat::setNum(int num) {
    Chat::num = num;
}

const list<User *> &Chat::getUsers() const {
    return users;
}

void Chat::setUsers(const list<User *> &users) {
    Chat::users = users;
}

