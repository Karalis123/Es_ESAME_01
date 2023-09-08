//
// Created by Utente on 08/09/2023.
//

#include "Chat.h"

const list<User> &Chat::getUsers() const {
    return users;
}

void Chat::setUsers(const list<User> &users) {
    Chat::users = users;
}

const multimap<int, string> &Chat::getConversazione() const {
    return conversazione;
}

void Chat::setConversazione(const multimap<int, string> &conversazione) {
    Chat::conversazione = conversazione;
}

Chat::Chat() = default;
