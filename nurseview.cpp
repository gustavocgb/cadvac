#include "nurseview.h"
#include "ui_nurseview.h"

NurseView::NurseView(QWidget *parent):QDialog(parent),ui(new Ui::NurseView){
    ui->setupUi(this);

}

NurseView::~NurseView()
{
    delete ui;
}

User* NurseView::getUser(){
    return user;
}
void NurseView::setUser(User* data){
    user = data;
}

void NurseView::formView(){
    ui->cpf->setText(QString::fromStdString(this->getUser()->getCpf()));
    ui->name->setText(QString::fromStdString(this->getUser()->getName()));
    ui->coren->setText(QString::number(this->getUser()->getCoren()));
    ui->date->setText(QString::fromStdString(this->getUser()->getBirth()));
}

void NurseView::on_updateNurseButton_clicked()
{

}

void NurseView::on_removeNurseButton_clicked()
{

}
