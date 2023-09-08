#include <iostream>


#include <list>
#include <string>
#include <iterator>
#include <map>
#include "User.h"
#include "Chat.h"


using namespace std;
int main() {
int uscita = 0;
int numChat = 1;
int numUsers = 1;


    do{
        cout<<"Iniziare una chat? Scrivi 1 per iniziarne una o 0 per chiudere il programma"<<endl;
        cin>>uscita;
        if(uscita==1){
            Chat* chat = new Chat(numChat);
            numChat++;
            User* user1 = new User(numUsers);
            numUsers++;
            User* user2 = new User(numUsers);
            numUsers++;


        }

    }while(uscita!=0);





    return 0;
}
