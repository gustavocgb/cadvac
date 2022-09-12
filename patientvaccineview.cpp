#include "patientvaccineview.h"
#include "ui_patientvaccineview.h"

PatientVaccineView::PatientVaccineView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PatientVaccineView)
{
    ui->setupUi(this);
    // factory
    this->setPatient(Patient::generatePatient());
    this->setDataBase(DataBase::createDataBase());
}

PatientVaccineView::~PatientVaccineView()
{
    delete ui;
}

Patient* PatientVaccineView::getPatient(){
    return patient;
}
void PatientVaccineView::setPatient(Patient* data){
    patient = data;
}
Posts* PatientVaccineView::getPosts(){
    return posts;
}
void PatientVaccineView::setPosts(Posts* data){
    posts = data;
}
DataBase* PatientVaccineView::getDataBase(){
    return dataBase;
}
void PatientVaccineView::setDataBase(DataBase* data){
    dataBase = data;
}

void PatientVaccineView::getVaccines()
{
    if(!this->getDataBase()->openDb()){
        QMessageBox::warning(this, "ERROR", "Conexão com a base de dados falhou");
    } else {

       QSqlQuery query;

       QString id = QString::number(this->getPatient()->getId());

       if(query.prepare("SELECT Vaccine.name, Vaccine.cod, certificate.coment, certificate.date, HelthPosts.name FROM certificate JOIN Vaccine ON certificate.vaccine = Vaccine.id JOIN HelthPosts ON certificate.post = HelthPosts.id WHERE certificate.patient = "+id+"")){
          if(query.exec()){
              int row = 0;

              ui->table->setColumnCount(5);
              ui->table->setColumnWidth(0, 130);
              ui->table->setColumnWidth(1, 80);
              ui->table->setColumnWidth(2, 150);
              ui->table->setColumnWidth(3, 100);
              ui->table->setColumnWidth(4, 110);
              QStringList titleColumn = {"Vacina", "Código", "Observação", "Data", "Posto"};
              ui->table->setHorizontalHeaderLabels(titleColumn);
              ui->table->setEditTriggers(QAbstractItemView::NoEditTriggers);
              ui->table->setSelectionBehavior(QAbstractItemView::SelectRows);
              ui->table->verticalHeader()->setVisible(false);
              ui->table->setStyleSheet("QTableView {selection-background-color: green}");

              while (query.next()) {
                  ui->table->insertRow(row);
                  ui->table->setItem(row,0, new QTableWidgetItem(query.value(0).toString()));
                  ui->table->setItem(row,1, new QTableWidgetItem(query.value(1).toString()));
                  ui->table->setItem(row,2, new QTableWidgetItem(query.value(2).toString()));
                  ui->table->setItem(row,3, new QTableWidgetItem(query.value(3).toString()));
                  ui->table->setItem(row,4, new QTableWidgetItem(query.value(4).toString()));
                  ui->table->setRowHeight(row, 20);
                  row++;
              }

          } else{
             QMessageBox::warning(this, "ERROR", "Não encontrado");
          }
       } else {
           QMessageBox::warning(this, "ERROR", "Erro query");
       }
    }
    this->getDataBase()->closeDb();
}
