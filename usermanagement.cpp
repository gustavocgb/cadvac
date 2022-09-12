#include "usermanagement.h"
#include "ui_usermanagement.h"

UserManagement::UserManagement(QWidget *parent):QDialog(parent),ui(new Ui::UserManagement)
{
    ui->setupUi(this);
}

UserManagement::~UserManagement()
{
    delete ui;
}

User* UserManagement::getCurrentUser(){

    return currentUser;
}
Posts* UserManagement::getPosts(){
    return posts;
}
void UserManagement::setPosts(Posts* data){
    posts = data;
}
void UserManagement::setCurrentUser(User* data){

    currentUser = data;
}
int UserManagement::getType(){
    return type;
}
void UserManagement::setType(int data){
    type = data;
}

void UserManagement::titleUi(){

    ui->lineEdit_user_2->setText(QString::fromStdString(currentUser->getName()));

    switch (this->getType()) {
      case 0:
        ui->label_name->setText("Paciente");
        break;
      case 1:
        ui->label_name->setText("Enfermeiro");
        break;
      case 2:
        ui->label_name->setText("Posto");
        break;
      case 3:
        ui->label_name->setText("Vacina");
        break;
    }
}


void UserManagement::on_btn_search_clicked()
{
    if(this->getType() == 3){
        this->vaccineView();
    } else {

        Search *search = new Search(this);
        switch (this->getType()) {
          case 0:
            search->setType(0);
            break;
          case 1:
            search->setType(1);
            break;
          case 2:
            search->setType(2);
            break;
        }
        search->setCurrentUser(this->getCurrentUser());
        search->typeUi();
        search->exec();
    }
}

void UserManagement::on_btn_add_clicked()
{
    switch (this->getType()) {
      case 0:
        this->patient();
        break;
      case 1:
        this->nurse();
        break;
      case 2:
        this->post();
        break;
      case 3:
        this->vaccine();
        break;
    }
}

void UserManagement::patient(){

}

void UserManagement::nurse(){

}

void UserManagement::vaccine(){
    Vaccine *vaccine = new Vaccine(this);
    vaccine->setPosts(this->getPosts());
    vaccine->exec();
}
void UserManagement::vaccineView(){
    VaccineView *vaccineView = new VaccineView(this);
    vaccineView->setPosts(this->getPosts());
    vaccineView->getVaccines();
    vaccineView->exec();
}

void UserManagement::post(){

}
