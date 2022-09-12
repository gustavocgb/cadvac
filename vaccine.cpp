#include "vaccine.h"
#include "ui_vaccine.h"

Vaccine::Vaccine(QWidget *parent):QDialog(parent),ui(new Ui::Vaccine){
    ui->setupUi(this);

    // factory
    this->setDataBase(DataBase::createDataBase());
}

Vaccine::~Vaccine()
{
    delete ui;
}

DataBase* Vaccine::getDataBase(){
    return dataBase;
}
void Vaccine::setDataBase(DataBase* data){
    dataBase = data;
}
Posts* Vaccine::getPosts(){
    return posts;
}
void Vaccine::setPosts(Posts* data){
    posts = data;
}

void Vaccine::on_button_clicked()
{
    if(!this->getDataBase()->openDb()){
        QMessageBox::warning(this, "ERROR", "Conexão com a base de dados falhou");

    } else{

        QString name = ui->name->text();
        QString cod = ui->cod->text();
        QString qtd = ui->qtd->text();
        QString date = ui->date->text();
        QString id = QString::number(this->getPosts()->getId());

        QSqlQuery query;
        if(query.prepare("INSERT INTO Vaccine (name, validate, cod, amount, post)"
                         "VALUES('"+name+"', '"+date+"', '"+cod+"', '"+qtd+"', '"+id+"')")){
           if(query.exec()){
               QMessageBox::information(this, "SUCCESS", "Vacina cadastrada com sucesso");
               clearForm();
               this->getDataBase()->closeDb();
               this->close();
           } else{
               QMessageBox::warning(this, "ERROR", "Erro ao inserir");
           }
        } else {
            QMessageBox::warning(this, "ERROR", "Erro");
        }
    }
    this->getDataBase()->closeDb();
}

void Vaccine::clearForm()
{
    ui->name->clear();
    ui->cod->clear();
    ui->qtd->clear();
    ui->date->clear();
}
