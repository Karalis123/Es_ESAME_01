#include <iostream>


#include <list>
#include "User.h"
#include "Chat.h"
#include<fstream>
#include <filesystem>

using namespace std;
using std::filesystem::exists;
int readNum();
int createNum();
void saveNum(int numr);
int main() {
int uscita1 = 0;
int uscita2 = 0;
int numChat;
int permit;


    do{
        int numUsers = 1;
        cout<<"Iniziare una chat? Scrivi 1 per iniziarne una o 0 per chiudere il programma"<<endl;
        cin>>uscita1;
        if(uscita1==1){
            numChat = createNum();
            Chat* chat = new Chat(numChat);
            numChat++;
            chat->create();
            User* user1 = new User(numUsers);
            numUsers++;
            User* user2 = new User(numUsers);
            numUsers++;
            chat->insertLast(user1);
            chat->insertLast(user2);
            cout<<"Utente 1 e Utente 2 sono gia' stati creati, vuoi creare altri utenti? Scrivi 1 per crearne uno o 0 per andare avanti"<<endl;
            cin>>uscita2;
            while(uscita2!=0){
                User* user = new User(numUsers);
                numUsers++;
                chat->insertLast(user);
                chat->incrementMaxDimension();
                cout<<"Vuoi creare altri utenti? Scrivi 1 per crearne uno o 0 per andare avanti"<<endl;
                cin>>uscita2;
            }
            permit = chat->chatProper();
            if(permit==1){
                chat->save();
                saveNum(numChat);
            }
            else{
                numChat--;
                saveNum(numChat);
            }

        }

    }while(uscita1!=0);





    return 0;
}



int createNum() {
    string file = "registroNum.txt";
    int var;
    if(exists(file)){
        var=readNum();
    }
    else{
        saveNum(1);
        var = 1;
    }
    return var;
}

int readNum() {
    ifstream fin("registroNum.txt");

    int var;
    fin>>var;
    fin.close();
    return var;
}

void saveNum(int numr) {
    ofstream fout("registroNum.txt");
    fout<< numr ;
    fout.close();
}