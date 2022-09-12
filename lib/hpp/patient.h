#ifndef PATIENT_H
#define PATIENT_H
#include <string>
using namespace std;

class Patient
{
public:

    virtual void createPatient(string cpf, string name, string birthDate,
                       string susNumber, int vaccine=0) = 0;
    virtual bool removePatient(string cpf)=0;
    virtual Patient* getPatient(string cpf)=0;
    virtual bool updatePatient(Patient* p, string cpf="", string name="", string birthDate="",
                       string susNumber="", int vaccine = -1)=0;

    virtual void listPatients()=0;

    static Patient *generatePatient();
    virtual ~Patient(){}

    virtual string getCpf() const=0;
    virtual string getName() const=0;
    virtual int getVaccineDosesTaken() const=0;
    virtual string getSusNumber() const=0;
    virtual string getBirthDate() const=0;
    virtual int getId() const=0;
    virtual void setId(int value)=0;
    virtual void setCpf(const string &value)=0;
    virtual void setName(const string &value)=0;
    virtual void setVaccineDosesTaken(int value)=0;
    virtual void setBirthDate(const string &value)=0;
    virtual void setSusNumber(const string &value)=0;

};

#endif // PATIENT_H
