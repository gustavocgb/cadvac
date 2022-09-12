#include "./lib/hpp/user_impl.h"

User_impl::User_impl()
{
    setCpf("");
    setName("");
    setBirth("");
    setPassword("");
    setEmail("");
    setCoren(0);
    setType(0);
    setId(0);
}

User_impl::User_impl(string cpf, string name, string birth, string password, string email, int coren, int type, int id)
{
    setCpf(cpf);
    setName(name);
    setBirth(birth);
    setCoren(coren);
    setPassword(password);
    setEmail(email);
    setType(type);
    setId(id);
}

User_impl::~User_impl(){}

User *User::createUser(){
    return User_impl::createUser();
}
User *User_impl::createUser()
{
    User *user = new User_impl();
    return user;
}

string User_impl::getCpf() const
{
    return cpf;
}

void User_impl::setCpf(const string &value)
{
    cpf = value;
}

string User_impl::getName() const
{
    return name;
}

void User_impl::setName(const string &value)
{
    name = value;
}

string User_impl::getBirth() const
{
    return birth;
}

void User_impl::setBirth(const string &value)
{
    birth = value;
}

int User_impl::getCoren() const
{
    return coren;
}

void User_impl::setCoren(int value)
{
    coren = value;
}

void User_impl::setPassword(const string &value)
{
    password = value;
}

string User_impl::getEmail() const
{
    return email;
}

void User_impl::setEmail(const string &value)
{
    email = value;
}

int User_impl::getType() const
{
    return type;
}

void User_impl::setType(int value)
{
    type = value;
}

int User_impl::getId() const
{
    return id;
}

void User_impl::setId(int value)
{
    id = value;
}

//void User_impl::createNurse(string cpf, string name, string birthDate, int coren)
//{
//    User* nurse = new Nurse_Impl(cpf, name, birthDate, coren);
//    nurses.push_back(nurse);
//}

//bool Nurse_Impl::removeNurse(string cpf)
//{

//    for(auto i: nurses){

//        if(i->getCpf() == cpf){
//            nurses.remove(i);
//            return true;
//        }
//    }
//    return false;
//}

//bool Nurse_Impl::updateNurse(Nurse *n, string cpf, string name, string birthDate, int coren)
//{
//    for(auto i: nurses){
//        if(i == n){
//            i->setCpf(cpf);
//            i->setName(name);
//            i->setBirthDate(birthDate);
//            i->setCoren(coren);
//            return true;
//        }
//    }
//    return false;
//}

//Nurse* Nurse_Impl::getNurse(string cpf)
//{
//    for(auto it: nurses){
//        if(it->getCpf() == cpf){
//            return it;
//        }
//    }
//    return nullptr;
//}

//void Nurse_Impl::listNurses()
//{
//    cout<<"List Nurses"<<endl;
//    for(auto it : nurses){
//        cout<<it->getName()<<", "<<it->getCpf()<<endl;
//    }
//}

//ostream& operator<<(ostream &out, const Nurse_Impl &n){
//    out <<n.getName()<<", "<<n.getCpf()<<", "<<n.getBirthDate()<<", "<<n.getCoren()<<endl;
//    return out;
//}
//Nurse_Impl &Nurse_Impl::operator=(Nurse_Impl &copy)
//{
//    if(&copy == this) return (*this);

//    this->name = copy.name;
//    this->cpf = copy.cpf;
//    this->birthDate = copy.birthDate;
//    this->coren = copy.coren;
//    this->nurses = copy.nurses;


//    return (*this);
//}


//Nurse *Nurse::generateNurse(){
//    return Nurse_Impl::generateNurse();
//}
//Nurse *Nurse_Impl::generateNurse()
//{
//    Nurse *nurse = new Nurse_Impl();
//    return nurse;
//}


