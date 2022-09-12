#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

class User
{
public:

//    virtual void createUser(string cpf, string name, string birthDate, int coren)=0;
//    virtual bool createUser(string cpf)=0;
//    virtual bool updateUser(Nurse *n, string cpf="", string name="",
//                             string birthDate="", int coren=-1)=0;
//    virtual User* getUser(string cpf)=0;
//    virtual void listUSer()=0;
    virtual ~User(){}
//    static User *generateUser();

    virtual string getEmail() const=0;
    virtual string getCpf() const=0;
    virtual string getName() const= 0;
    virtual string getBirth() const=0;
    virtual int getCoren() const=0;
    virtual int getType() const=0;
    virtual int getId() const=0;


    virtual void setPassword(const string &value)=0;
    virtual void setEmail(const string &value)=0;
    virtual void setCpf(const string &value)=0;
    virtual void setName(const string &value)=0;
    virtual void setBirth(const string &value)=0;
    virtual void setCoren(int coren)=0;
    virtual void setType(int type)=0;
    virtual void setId(int id)=0;


    static User *createUser();

//    bool login(string cpf, string password);
//    string getSecretaryCpf() const;
//    string getPassword() const;
};

#endif // USER_H
