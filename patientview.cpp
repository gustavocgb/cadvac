#include "patientview.h"
#include "ui_patientview.h"

PatientView::PatientView(QWidget *parent):QDialog(parent),ui(new Ui::PatientView){
    ui->setupUi(this);

    // factory
    this->setPatient(Patient::generatePatient());
}

PatientView::~PatientView()
{
    delete ui;
}

Patient* PatientView::getPatient(){
    return patient;
}
void PatientView::setPatient(Patient* data){
    patient = data;
}

void PatientView::formView(){
    ui->cpf->setText(QString::fromStdString(this->getPatient()->getCpf()));
    ui->name->setText(QString::fromStdString(this->getPatient()->getName()));
    ui->sus->setText(QString::fromStdString(this->getPatient()->getSusNumber()));
    ui->date->setText(QString::fromStdString(this->getPatient()->getBirthDate()));
}

void PatientView::on_vaccine_clicked()
{
    PatientVaccineView *patientVaccineView = new PatientVaccineView(this);
    patientVaccineView->setPatient(this->getPatient());
    patientVaccineView->getVaccines();
    patientVaccineView->exec();
}

void PatientView::on_updateNurseButton_clicked()
{

}

void PatientView::on_removeNurseButton_clicked()
{

}
