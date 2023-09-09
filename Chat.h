//
// Created by Utente on 08/09/2023.
//

#ifndef ES_ESAME_01_CHAT_H
#define ES_ESAME_01_CHAT_H

#include <list>
#include <string>
#include <iterator>
#include <map>
#include "User.h"


using namespace std;
class Chat {
public:

    Chat();
    explicit Chat(int n);

    void insertLast(User* u);


    const list<User *> &getUsers() const;

    void setUsers(const list<User *> &users);

    const multimap<int, string> &getConversazione() const;

    void setConversazione(const multimap<int, string> &conversazione);

    int getNum() const;

    void setNum(int num);

private:
    list<User*> users;
    multimap<int, string> conversazione;
    int num{};
};


#endif //ES_ESAME_01_CHAT_H
