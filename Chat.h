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
    int chatProper();
    void sendingProcess(int mitt, int dest, int cont);
    void incrementMaxDimension();

    void create();
    void registerOnScreen();
    void save();

    void showUsers();
    void showUsersInChat(int u1, int u2);
    void showChat();




    const list<User *> &getUsers() const;
    void setUsers(const list<User *> &users1);

    const multimap<int, string> &getConversazione() const;
    void setConversazione(const multimap<int, string> &convers);

    int getNum() const;
    void setNum(int number);

    int getMaxdimension() const;

    void setMaxdimension(int maxdim);

    const string &getStoredMessage() const;

    void setStoredMessage(const string &storedMessaggio);

private:
    list<User*> users;
    multimap<int, string> conversazione;
    int num{};
    int maxdimension = 2;
    string storedMessage;
};


#endif //ES_ESAME_01_CHAT_H
