#ifndef USER_IMPL_H
#define USER_IMPL_H
#include <string>
#include "user.h"
#include <iostream>
#include <list>
using namespace std;

class User_impl : User {
protected:
    string email;
    string password;
    string cpf;
    string name;
    string birth;
    int type;
    int coren;
    int id;

    User *user;

public:
    static User *createUser();

    User_impl();
    User_impl(string cpf, string name, string birth, string password, string email, int coren, int type, int id);
    virtual ~User_impl();

    string getEmail() const;
    string getCpf() const;
    string getName() const;
    string getBirth() const;
    int getCoren() const;
    int getType() const;
    int getId() const;

    void setPassword(const string &value);
    void setEmail(const string &value);
    void setCpf(const string &value);
    void setName(const string &value);
    void setBirth(const string &value);
    void setCoren(int value);
    void setType(int value);
    void setId(int value);

    //    void createUser(string cpf, string name, string birthDate, int coren);
    //    bool removeUser(string cpf);
    //    bool updateNurse(Nurse *n, string cpf="", string name="", string birthDate="", int coren=-1);
    //    User* getUser(string cpf);
    //    void listNurses();
    //factory
//    static User *generateNurse();
//    User_impl &operator=(User_impl&);
//    friend ostream &operator<<(ostream &out, const User_impl &n);

};

#endif // USER_IMPL_H
