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
    int mitt =0;
    int dest = 0;
    int cont2 = 0;
    int user1 = 0;
    int user2 = 0;
    int num=0;

    showUsers();
    cout<<endl<<"Chi sono i due utenti che si parlano attraverso la chat?"<<endl;
    for (int i=0; i<2; i++){
        cout<<"Scrivi il numero dell'utente "<<endl;
        cin>>num;
        if(maxdimension<num || num==user1){
            cout<<"Inserisci il numero di un utente esistente o non selezionato"<<endl;
            i--;
        }
        else{
            if(i==0){
                user1 = num;
            }
            else{
                user2 = num;
            }
        }
    }

    showUsersInChat(user1, user2);

    do{
        for(int x=0; x<1; x++) {
            cout << "Inserisci il numero di quale utente vuoi sia il mittente del messaggio oppure scrivi 0 per chiudere la chat"
                 << endl;
            cin >> cont1;
            if (cont1 != 0) {
                if (cont1>maxdimension) {
                    cout << "Inserisci il numero di un utente esistente" << endl;
                    x--;
                }
                else{
                    if (cont1!=user1 && cont1!=user2){
                        cout << "Inserisci il numero di un utente partecipante alla chat" << endl;
                        x--;
                    }
                    else{
                        if(cont1==user1){
                            sendingProcess(user1, user2);
                        }
                        else if(cont1==user2){
                            sendingProcess(user2, user1);
                        }
                    }
                }
            }
        }


    }while(cont1!=0);

}

void Chat::sendingProcess(int mit, int dest) {

}

void Chat::showUsers() {
    cout<<endl<<"Elenco di utenti"<<endl;
    for (auto it = begin(users); it != users.end(); it++) {
        cout << "Utente numero "<< (*it)->getName()<<std::endl;
    }
}

void Chat::showUsersInChat(int u1, int u2) {
    cout<<endl<<"Utenti nella chat"<<endl;
    for (auto it = begin(users); it != users.end(); it++) {
        if (u1 == (*it)->getName() || u2 == (*it)->getName()) {
            cout << "Utente numero: "<< (*it)->getName()<<std::endl;
        }
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











