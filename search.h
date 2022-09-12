#ifndef SEARCH_H
#define SEARCH_H

#include "lib/hpp/dataBase.h"
#include "lib/hpp/user.h"
#include "lib/hpp/patient.h"
#include "lib/hpp/posts.h"

#include "nurseview.h"
#include "postsview.h"
#include "patientview.h"

#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>
#include <QDialog>

namespace Ui {
class Search;
}

class Search : public QDialog
{
    Q_OBJECT

public:
    explicit Search(QWidget *parent = nullptr);
    ~Search();

    int type;
    DataBase *dataBase;
    User *user;
    Patient *patient;
    Posts *post;
    User *currentUser;

    User* getCurrentUser();
    void setCurrentUser(User*);
    DataBase* getDataBase();
    void setDataBase(DataBase*);
    User* getUser();
    void setUser(User*);
    Patient* getPatient();
    void setPatient(Patient*);
    Posts* getPost();
    void setPost(Posts*);
    int getType();
    void setType(int);
    void typeUi();
    void patientView();
    void nurseView();
    void postView();

private slots:

    void on_search_button_clicked();

private:
    Ui::Search *ui;
};

#endif // SEARCH_H
