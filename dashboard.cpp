#include "dashboard.h"

Dashboard::Dashboard(QWidget *parent):QMainWindow(parent),ui(new Ui::Dashboard){

    ui->setupUi(this);

    this->logo();
    this->setDisabledButtons(-1);

    isLogin = false;
    ui->pushButton->setText("Login");

}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::logo(){
    QString path = qApp->applicationDirPath();
    auto path2 = path.split("/");
    path2.removeLast();
    path2.removeLast();
    QString dir = path2.join("/");
    QString filename = dir+"/cadvac/images/logo.png";
    QImage image(filename);
    ui->logo->setPixmap(QPixmap::fromImage(image));
}


User* Dashboard::getCurrentUser(){

    return currentUser;
}

void Dashboard::setCurrentUser(User* data){

    currentUser = data;
}

void Dashboard::on_pushButton_clicked()
{
    if(isLogin){
        int ret = QMessageBox::question(this, "CADVAC", "Realmente deseja fazer Logoff?");
        switch (ret) {
          case QMessageBox::Yes:
              break;
          case QMessageBox::No:
              return;
          default:
              break;
        }
    }

    Login *login = new Login(this);
    login->exec();
    this->setCurrentUser(login->getCurrentUser());
    ui->lineEdit_user_2->setText(QString::fromStdString(this->getCurrentUser()->getName()));

    if(login->getIsLogin()){
        isLogin = true;
        ui->pushButton->setText("Logoff");
        this->setDisabledButtons(this->getCurrentUser()->getType());
    }else{        
        this->setDisabledButtons(-1);
        isLogin = false;
        ui->pushButton->setText("Login");
    }
}

void Dashboard::setDisabledButtons(int type){

    switch (type) {
       case -1:
        ui->nurse_btn_2->setDisabled(true);
        ui->patients_btn_2->setDisabled(true);
        ui->posts_btn_2->setDisabled(true);
        break;
      case 0:
        // admin
        ui->nurse_btn_2->setDisabled(false);
        ui->patients_btn_2->setDisabled(false);
        ui->posts_btn_2->setDisabled(false);
        break;
      case 1:
        // secretary
        ui->patients_btn_2->setDisabled(false);
        break;
      case 2:
        // cordinator
        // reports
        ui->patients_btn_2->setDisabled(false);
        ui->nurse_btn_2->setDisabled(false);
        ui->posts_btn_2->setDisabled(false);
        break;
      case 3:
        // nurse
        ui->patients_btn_2->setDisabled(false);
        break;
    }


}

void Dashboard::on_patients_btn_2_clicked()
{
    this->setUserManagement(0);
}

void Dashboard::on_nurse_btn_2_clicked()
{
    this->setUserManagement(1);
}

void Dashboard::on_posts_btn_2_clicked()
{
    this->setUserManagement(2);
}

void Dashboard::setUserManagement(int type){
    UserManagement *userManagement = new UserManagement(this);
    userManagement->setCurrentUser(this->getCurrentUser());
    userManagement->setType(type);
    userManagement->titleUi();
    userManagement->exec();
}
