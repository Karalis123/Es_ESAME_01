//
// Created by Utente on 08/09/2023.
//

#ifndef ES_ESAME_01_USER_H
#define ES_ESAME_01_USER_H

#include <iostream>
#include <string>


class User {
public:

    User(int n);

    void write();

    int getName() const;

    void setName(int name);

    const std::string &getMessage() const;

    void setMessage(const std::string &message);

private:
    int name;
    std::string message;
};


#endif //ES_ESAME_01_USER_H
