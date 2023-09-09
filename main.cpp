#include <iostream>


#include <list>
#include <string>
#include <iterator>
#include <map>
#include "User.h"
#include "Chat.h"


using namespace std;
int main() {
int uscita1 = 0;
int uscita2 = 0;
int numChat = 1;
int numUsers = 1;


    do{
        cout<<"Iniziare una chat? Scrivi 1 per iniziarne una o 0 per chiudere il programma"<<endl;
        cin>>uscita1;
        if(uscita1==1){
            Chat* chat = new Chat(numChat);
            numChat++;
            User* user1 = new User(numUsers);
            numUsers++;
            User* user2 = new User(numUsers);
            numUsers++;
            chat->insertLast(user1);
            chat->insertLast(user2);
            cout<<"Utente 1 e Utente 2 sono già stati creati, vuoi creare altri utenti? Scrivi 1 per crearne uno o 0 per andare avanti"<<endl;
            cin>>uscita2;
            while(uscita2!=0){
                User* user = new User(numUsers);
                numUsers++;
                chat->insertLast(user);
                cout<<"Vuoi creare altri utenti? Scrivi 1 per crearne uno o 0 per andare avanti"<<endl;
                cin>>uscita2;
            }
        }

    }while(uscita1!=0);





    return 0;
}
