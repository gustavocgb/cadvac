#include "./lib/hpp/patient_impl.h"

Patient_Impl::Patient_Impl()
{
    setId(0);
    setCpf("");
    setName("");
    setBirthDate("");
    setSusNumber("");
    setVaccineDosesTaken(-1);
}

Patient_Impl::~Patient_Impl()
{

}

Patient_Impl::Patient_Impl(string cpf, string name, string birthDate, string susNumber, int vaccine)
{
    setCpf(cpf);
    setName(name);
    setBirthDate(birthDate);
    setSusNumber(susNumber);
    setVaccineDosesTaken(vaccine);
}

void Patient_Impl::createPatient(string cpf, string name, string birthDate, string susNumber, int vaccine)
{
    Patient *p = new Patient_Impl(cpf, name, birthDate, susNumber, vaccine);
    patients.push_back(p);
}

bool Patient_Impl::removePatient(string cpf)
{
    cout<<"Remove patients"<<endl;
    for(auto i: patients){

        if(i->getCpf() == cpf){
            patients.remove(i);
            return true;
        }
    }
    return false;
}

Patient *Patient_Impl::getPatient(string cpf)
{
    for(auto it: patients){
        if(it->getCpf() == cpf){
            return it;
        }
    }
    return nullptr;
}

bool Patient_Impl::updatePatient(Patient *p, string cpf, string name, string birthDate,
                            string susNumber, int vaccine)
{
    for(auto i: patients){
        if(i == p){
            i->setCpf(cpf);
            i->setName(name);
            i->setBirthDate(birthDate);
            i->setSusNumber(susNumber);
            i->setVaccineDosesTaken(vaccine);
            return true;
        }
    }
    return false;
}

void Patient_Impl::listPatients()
{
    cout<<"List patients"<<endl;
    for(auto it : patients){
        cout<<it->getName()<<", "<<it->getCpf()<<endl;
    }
}
list<Patient*> Patient_Impl::patients;
Patient *Patient::generatePatient(){
    return Patient_Impl::generatePatient();
}
Patient *Patient_Impl::generatePatient()
{
    Patient *patient = new Patient_Impl();
    return patient;
}


Patient_Impl &Patient_Impl::operator=(Patient_Impl &copy)
{
    if(&copy == this) return (*this);

    this->name = copy.name;
    this->cpf = copy.cpf;
    this->birthDate = copy.birthDate;
    this->susNumber = copy.susNumber;
    this->vaccineDosesTaken = copy.vaccineDosesTaken;
    this->patients = copy.patients;


    return (*this);
}
ostream &operator<<(ostream &out, const Patient_Impl &p)
{
    out<<p.getName()<<", "<<p.getCpf()<<", "<<p.getSusNumber()<<", "<<
         p.getVaccineDosesTaken()<<", "<<p.getBirthDate()<<endl;
    return out;
}

string Patient_Impl::getCpf() const
{
    return cpf;
}

void Patient_Impl::setCpf(const string &value)
{
    cpf = value;
}

string Patient_Impl::getName() const
{
    return name;
}

void Patient_Impl::setName(const string &value)
{
    name = value;
}

int Patient_Impl::getVaccineDosesTaken() const
{
    return vaccineDosesTaken;
}

void Patient_Impl::setVaccineDosesTaken(int value)
{
    vaccineDosesTaken = value;
}

string Patient_Impl::getSusNumber() const
{
    return susNumber;
}

void Patient_Impl::setSusNumber(const string &value)
{
    susNumber = value;
}

string Patient_Impl::getBirthDate() const
{
    return birthDate;
}

void Patient_Impl::setBirthDate(const string &value)
{
    birthDate = value;
}

int Patient_Impl::getId()const{
    return id;
}
void Patient_Impl::setId(int value){
    id = value;
}
