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
    void chatProper();
    void showUsers();
    void showUsersInChat(int u1, int u2);
    void incrementMaxDimension();
    void sendingProcess(int mit, int dest);

    const list<User *> &getUsers() const;
    void setUsers(const list<User *> &users);

    const multimap<int, string> &getConversazione() const;
    void setConversazione(const multimap<int, string> &conversazione);

    int getNum() const;
    void setNum(int num);

    int getMaxdimension() const;

    void setMaxdimension(int maxdimension);

private:
    list<User*> users;
    multimap<int, string> conversazione;
    int num{};
    int maxdimension = 2;
};


#endif //ES_ESAME_01_CHAT_H
