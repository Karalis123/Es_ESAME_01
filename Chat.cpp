//
// Created by Utente on 08/09/2023.
//

#include "Chat.h"

Chat::Chat(int n) : num(n){}

Chat::Chat() = default;

void Chat::insertLast(User* u) {
    users.push_back(u);
}

void Chat::chatProper() {
    int cont1 = 0;
    int user1 = 0;
    int user2 = 0;
    int num;

    showUsers();
    cout<<endl<<"Chi sono i due utenti che si parlano attraverso la chat?"<<endl;
    for (int i=0; i<2; i++){
        cout<<"Scrivi il numero dell'utente"<<endl;
        cin>>num;
        if(maxdimension<num){
            cout<<"Inserisci il numero di un utente esistente"<<endl;
            i--;
        }
        else{
            if(i=0){
                user1 = num;
            }
            else{
                user2 = num;
            }
        }
    }



}


void Chat::showUsers() {
    cout<<endl<<"Elenco di utenti"<<endl;
    for (auto it = begin(users); it != users.end(); it++) {
        cout << "Utente numero "<< (*it)->getName()<<std::endl;
    }
}

void Chat::incrementMaxDimension() {
    maxdimension++;
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

int Chat::getMaxdimension() const {
    return maxdimension;
}

void Chat::setMaxdimension(int maxdimension) {
    Chat::maxdimension = maxdimension;
}







