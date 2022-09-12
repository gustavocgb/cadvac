#ifndef LOGIN_H
#define LOGIN_H

#include "dashboard.h"
#include "lib/hpp/dataBase.h"
#include "lib/hpp/user.h"
#include "ui_login.h"
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>
#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

    bool isLogin;

    User *currentUser;
    DataBase *dataBase;

    User* getCurrentUser();
    void setCurrentUser(User*);
    DataBase* getDataBase();
    void setDataBase(DataBase*);
    bool getIsLogin();

private slots:
    void on_btn_Login_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
