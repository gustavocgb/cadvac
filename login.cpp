#include "login.h"

Login::Login(QWidget *parent):QDialog(parent),ui(new Ui::Login){

    ui->setupUi(this);

    isLogin = false;

    auto validator = new QDoubleValidator(0, 0, 0, ui->lineEdit_cpf);
    validator->setLocale(QLocale("pt_BR"));
    ui->lineEdit_cpf->setValidator(validator);
    ui->label_status->setText("*CPF somente números");

    // factory
    this->setCurrentUser(User::createUser());
    this->setDataBase(DataBase::createDataBase());

}

Login::~Login()
{
    delete ui;
}

User* Login::getCurrentUser(){

    return currentUser;
}

void Login::setCurrentUser(User* data){

    currentUser = data;
}

DataBase* Login::getDataBase(){
    return dataBase;
}

void Login::setDataBase(DataBase* data){
    dataBase = data;
}

bool Login::getIsLogin(){

    return isLogin;
}

void Login::on_btn_Login_clicked(){

    if(!this->getDataBase()->openDb()){
            QMessageBox::warning(this, "ERROR", "Conexão com a base de dados falhou");
            ui->label_status->setText("Conexão com a base de dados falhou");
    } else{
        QString username = ui->lineEdit_cpf->text();
        QString password = ui->lineEdit_password->text();

        QSqlQuery query;
        if(query.prepare("SELECT * FROM Users WHERE cpf='"+username+"' and password='"+password+"'")){
           if(query.exec()){

               query.first();

               int id = query.value(0).toInt();
               QString name = query.value(1).toString();
               QString email = query.value(2).toString();
               QString cpf = query.value(3).toString();
               QString password = query.value(6).toString();
               QString birth = query.value(4).toString();
               int coren = query.value(5).toInt();
               int type = query.value(7).toInt();

               if(cpf.toStdString() != ""){
                   this->getCurrentUser()->setId(id);
                   this->getCurrentUser()->setName(name.toStdString());
                   this->getCurrentUser()->setEmail(email.toStdString());
                   this->getCurrentUser()->setCpf(cpf.toStdString());
                   this->getCurrentUser()->setPassword(password.toStdString());
                   this->getCurrentUser()->setBirth(birth.toStdString());
                   this->getCurrentUser()->setCoren(coren);
                   this->getCurrentUser()->setType(type);
                   ui->label_status->setText("Usuário encontrado");
                   this->close();
                   isLogin = true;
                   this->getDataBase()->closeDb();
               } else{
                   QMessageBox::warning(this, "ERROR", "Usuário não encontrado");
                   ui->label_status->setText("Usuário não encontrado");
               }
           }
        }
    }

    this->getDataBase()->closeDb();

}


