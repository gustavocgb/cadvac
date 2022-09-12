#include "search.h"
#include "ui_search.h"

Search::Search(QWidget *parent):QDialog(parent),ui(new Ui::Search){

    ui->setupUi(this);

    // factory
    this->setDataBase(DataBase::createDataBase());
}

Search::~Search()
{
    delete ui;
}

int Search::getType(){
    return type;
}
void Search::setType(int data){
    type = data;
}
DataBase* Search::getDataBase(){
    return dataBase;
}
void Search::setDataBase(DataBase* data){
    dataBase = data;
}
User* Search::getUser(){
    return user;
}
void Search::setUser(User* data){
    user = data;
}
Patient* Search::getPatient(){
    return patient;
}
void Search::setPatient(Patient* data){
    patient = data;
}
Posts* Search::getPost(){
    return post;
}
void Search::setPost(Posts* data){
    post = data;
}
User* Search::getCurrentUser(){

    return currentUser;
}
void Search::setCurrentUser(User* data){

    currentUser = data;
}


void Search::typeUi(){

    if(this->getType() == 0 || this->getType() == 1){
        ui->label->setText("CPF");
    } else {
        ui->label->setText("Nome");
    }
}



void Search::on_search_button_clicked()
{
    switch (this->getType()) {
      case 0:
        this->patientView();
        break;
      case 1:
        this->nurseView();
        break;
      case 2:
        this->postView();
        break;
    }
}


void Search::patientView(){
    if(!this->getDataBase()->openDb()){
        QMessageBox::warning(this, "ERROR", "Conexão com a base de dados falhou");
    } else{

       QString cpf = ui->line_edit->text();

       QSqlQuery query;
       if(query.prepare("SELECT * FROM Patients WHERE cpf='"+cpf+"'")){
          if(query.exec()){
              query.first();

              QString cpf = query.value(0).toString();
              QString name = query.value(1).toString();
              QString birth = query.value(2).toString();
              QString sus = query.value(3).toString();
              int id = query.value(4).toInt();

              if(cpf.toStdString() != ""){
                  // factory
                  this->setPatient(Patient::generatePatient());

                  this->getPatient()->setId(id);
                  this->getPatient()->setName(name.toStdString());
                  this->getPatient()->setCpf(cpf.toStdString());
                  this->getPatient()->setBirthDate(birth.toStdString());
                  this->getPatient()->setSusNumber(sus.toStdString());

                  this->getDataBase()->closeDb();
                  this->close();

                  PatientView *patientView = new PatientView(this);
                  patientView->setPatient(this->getPatient());
                  patientView->formView();
                  patientView->exec();

               } else{
                   QMessageBox::warning(this, "ERROR", "Não encontrado");
               }
            }
        }
    }
    this->getDataBase()->closeDb();
}

void Search::nurseView(){

    if(!this->getDataBase()->openDb()){
        QMessageBox::warning(this, "ERROR", "Conexão com a base de dados falhou");
    } else{

       QString cpf = ui->line_edit->text();

       QSqlQuery query;
       if(query.prepare("SELECT * FROM Users WHERE cpf='"+cpf+"'")){
          if(query.exec()){
              query.first();

              int id = query.value(0).toInt();
              QString name = query.value(1).toString();
              QString email = query.value(2).toString();
              QString cpf = query.value(3).toString();
              QString password = query.value(4).toString();
              QString birth = query.value(5).toString();
              int coren = query.value(6).toInt();
              int type = query.value(7).toInt();

              if(cpf.toStdString() != "" && type == 3){
                  // factory
                  this->setUser(User::createUser());

                  this->getUser()->setId(id);
                  this->getUser()->setName(name.toStdString());
                  this->getUser()->setEmail(email.toStdString());
                  this->getUser()->setCpf(cpf.toStdString());
                  this->getUser()->setPassword(password.toStdString());
                  this->getUser()->setBirth(birth.toStdString());
                  this->getUser()->setCoren(coren);
                  this->getUser()->setType(type);

                  this->getDataBase()->closeDb();
                  this->close();
                  NurseView *nurseView = new NurseView(this);
                  nurseView->setUser(this->getUser());
                  nurseView->formView();
                  nurseView->exec();

               } else{
                   QMessageBox::warning(this, "ERROR", "Não encontrado");
               }
            }
        }
    }
    this->getDataBase()->closeDb();
}

void Search::postView(){
    if(!this->getDataBase()->openDb()){
        QMessageBox::warning(this, "ERROR", "Conexão com a base de dados falhou");
    } else{
       QString name = ui->line_edit->text();
       QSqlQuery query;
       if(query.prepare("SELECT * FROM HelthPosts WHERE name='"+name+"'")){
          if(query.exec()){
              query.first();

              int id = query.value(0).toInt();
              QString name = query.value(1).toString();
              QString address = query.value(2).toString();
              int amountVaccine = query.value(3).toInt();

              if(name.toStdString() != ""){
                  // factory
                  this->setPost(Posts::generatePost());

                  this->getPost()->setId(id);
                  this->getPost()->setPostName(name.toStdString());
                  this->getPost()->setAddress(address.toStdString());
                  this->getPost()->setVaccineCount(amountVaccine);

                  this->close();
                  this->getDataBase()->closeDb();
                  PostsView *postView = new PostsView(this);
                  postView->setPosts(this->getPost());
                  postView->setCurrentUser(this->getCurrentUser());
                  postView->formView();
                  postView->exec();

               } else{
                   QMessageBox::warning(this, "ERROR", "Não encontrado");
               }
            }
        }
    }
    this->getDataBase()->closeDb();
}
