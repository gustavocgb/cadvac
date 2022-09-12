#ifndef USERMANAGEMENT_H
#define USERMANAGEMENT_H

#include "search.h"
#include "vaccine.h"
#include "vaccineview.h"

#include "lib/hpp/user.h"

#include <QDialog>
#include <QDebug>

namespace Ui {
class UserManagement;
}

class UserManagement : public QDialog
{
    Q_OBJECT

public:
    explicit UserManagement(QWidget *parent = nullptr);
    ~UserManagement();

    User *currentUser;
    Posts *posts;
    int type;

    Posts* getPosts();
    void setPosts(Posts*);
    User* getCurrentUser();
    void setCurrentUser(User*);
    int getType();
    void setType(int);
    void titleUi();
    void patient();
    void nurse();
    void post();
    void vaccine();
    void vaccineView();

private slots:

    void on_btn_search_clicked();

    void on_btn_add_clicked();

private:
    Ui::UserManagement *ui;
};

#endif // USERMANAGEMENT_H
