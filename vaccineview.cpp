#include "vaccineview.h"
#include "ui_vaccineview.h"

VaccineView::VaccineView(QWidget *parent):QDialog(parent),ui(new Ui::VaccineView)
{
    ui->setupUi(this);
    // factory
    this->setDataBase(DataBase::createDataBase());
}

VaccineView::~VaccineView()
{
    delete ui;
}

Posts* VaccineView::getPosts(){
    return posts;
}
void VaccineView::setPosts(Posts* data){
    posts = data;
}
DataBase* VaccineView::getDataBase(){
    return dataBase;
}

void VaccineView::setDataBase(DataBase* data){
    dataBase = data;
}


void VaccineView::getVaccines()
{
    if(!this->getDataBase()->openDb()){
        QMessageBox::warning(this, "ERROR", "Conexão com a base de dados falhou");
    } else {

       QSqlQuery query;

       QString id = QString::number(this->getPosts()->getId());

       if(query.prepare("SELECT * FROM Vaccine WHERE post='"+id+"'")){
          if(query.exec()){
              int row = 0;

              ui->table->setColumnCount(5);
              ui->table->setColumnWidth(0, 25);
              ui->table->setColumnWidth(1, 175);
              ui->table->setColumnWidth(2, 125);
              ui->table->setColumnWidth(3, 150);
              ui->table->setColumnWidth(4, 75);
              QStringList titleColumn = {"Id", "Nome", "Validade", "Código", "Quantidade"};
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

void VaccineView::on_removeButton_clicked()
{

    int ret = QMessageBox::question(this, "CADVAC", "Realmente deseja remover?");
    switch (ret) {
      case QMessageBox::Yes:{
            int row = ui->table->currentRow();
            QString id = QString::number(ui->table->item(row,0)->text().toInt());

            if(!this->getDataBase()->openDb()){
                QMessageBox::warning(this, "ERROR", "Conexão com a base de dados falhou");
            } else{
                QSqlQuery query;
                if(query.prepare("DELETE FROM Vaccine WHERE id="+id+"")){
                   if(query.exec()){
                       QMessageBox::information(this, "SUCCESS", "Vacina removida com sucesso");
                       ui->table->removeRow(row);
                   } else{
                       QMessageBox::warning(this, "ERROR", "Erro ao deletar");
                   }
                } else {
                    QMessageBox::warning(this, "ERROR", "Erro");
                }
            }
            this->getDataBase()->closeDb();
        }
        break;
      case QMessageBox::No:
          return;
      default:
          break;
    }
}
