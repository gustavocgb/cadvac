#ifndef DASHBOARD_H
#define DASHBOARD_H

#include "ui_dashboard.h"
#include "login.h"
#include "usermanagement.h"

#include "lib/hpp/dataBase.h"
#include "lib/hpp/user.h"

#include <QDialog>
#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>

namespace Ui {
class Dashboard;
}

class Dashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit Dashboard(QWidget *parent = nullptr);
    ~Dashboard();

    bool isLogin;
    User *currentUser;

    User* getCurrentUser();
    void setCurrentUser(User*);

    void logo();
    void setDisabledButtons(int);
    void setUserManagement(int);


private slots:
    void on_pushButton_clicked();

    void on_patients_btn_2_clicked();

    void on_nurse_btn_2_clicked();

    void on_posts_btn_2_clicked();

private:
    Ui::Dashboard *ui;
};

#endif // DASHBOARD_H
