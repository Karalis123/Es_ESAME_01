//
// Created by Utente on 08/09/2023.
//

#include "Chat.h"
#include <iostream>
#include<fstream>
#include <filesystem>

using std::filesystem::exists;

Chat::Chat(int n) : num(n){}

Chat::Chat() = default;

void Chat::insertLast(User* u) {
    users.push_back(u);
}



int Chat::chatProper() {
    int cont1 = 0;
    int user1 = 0;
    int user2 = 0;
    int numero = 0;
    int cont2;
    int permit = 0;

    showUsers();
    cout<<endl<<"Chi sono i due utenti che si parlano attraverso la chat?"<<endl;
    for (int i=0; i<2; i++){
        cout<<"Scrivi il numero dell'utente "<<endl;
        cin>>numero;
        if(maxdimension<numero || numero==user1){
            cout<<"Inserisci il numero di un utente esistente o non selezionato"<<endl;
            i--;
        }
        else{
            if(i==0){
                user1 = numero;
            }
            else{
                user2 = numero;
            }
        }
    }

    showUsersInChat(user1, user2);

    do{
        cont2 = 1;
        for(int x=0; x<1; x++) {
            cout << "Inserisci il numero di quale utente vuoi sia il mittente del messaggio oppure scrivi 0 per chiudere la chat"
                 << endl;
            cin >> cont1;
            if (cont1 != 0) {
                permit = 1;
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
                            sendingProcess(user1, user2, cont2);
                            x--;
                            showChat();
                            cont2++;
                        }
                        else if(cont1==user2){
                            sendingProcess(user2, user1, cont2);
                            x--;
                            showChat();
                            cont2++;
                        }
                    }
                }
            }
        }


    }while(cont1!=0);
    return permit;
}

void Chat::sendingProcess(int mitt, int dest, int cont) {
    string s1, s2, s3, s4;
    string s;
    for (auto it = begin(users); it != users.end(); it++) {
        if (mitt == (*it)->getName()) {
            (*it)->write();
            storedMessage = (*it)->getMessage();
        }
    }
    s1 = "Utente "; s2= to_string(mitt); s3= ": << "; s4= " >>";
    s = s1+s2+s3+storedMessage+s4;
    conversazione.insert(pair<int, string>(cont, s));
    for (auto itr = begin(users); itr != users.end(); itr++) {
        if (dest == (*itr)->getName()) {
            (*itr)->setMessage(storedMessage);
        }
    }
}

void Chat::incrementMaxDimension() {
    maxdimension++;
}



void Chat::create() {
    string file = "registro.txt";
    if(exists(file)){
        registerOnScreen();
    }
    else{
        ofstream fout(file);
    }
}

void Chat::registerOnScreen() {
    ifstream fin("registro.txt");

    char var;
    cout<<endl;
    while(fin.get(var))
    {
        cout<<var;
    }
    fin.close();
}

void Chat::save() {
    ofstream fout("registro.txt", ios::app);

    multimap<int, string>::iterator itr;
    fout<<"Chat numero "<< num <<endl;
    for (itr = conversazione.begin(); itr != conversazione.end(); ++itr) {
        fout<< (*itr).second <<endl;
    }
    fout << endl;
    fout.close();
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

void Chat::showChat() {
    multimap<int, string>::iterator itr;
    cout<<endl;
    for (itr = conversazione.begin(); itr != conversazione.end(); ++itr) {
        cout<< (*itr).second <<endl;
    }
    cout << endl;
}



const multimap<int, string> &Chat::getConversazione() const {
    return conversazione;
}

void Chat::setConversazione(const multimap<int, string> &convers) {
    Chat::conversazione = convers;
}

int Chat::getNum() const {
    return num;
}

void Chat::setNum(int number) {
    Chat::num = number;
}

const list<User *> &Chat::getUsers() const {
    return users;
}

void Chat::setUsers(const list<User *> &users1) {
    Chat::users = users1;
}

int Chat::getMaxdimension() const {
    return maxdimension;
}

void Chat::setMaxdimension(int maxdim) {
    Chat::maxdimension = maxdim;
}

const string &Chat::getStoredMessage() const {
    return storedMessage;
}

void Chat::setStoredMessage(const string &storedMessaggio) {
    Chat::storedMessage = storedMessaggio;
}

Chat::~Chat() {

}





















