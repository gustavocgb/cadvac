#ifndef POSTSVIEW_H
#define POSTSVIEW_H

#include "lib/hpp/posts.h"

#include "search.h"
#include "usermanagement.h"

#include <QDebug>
#include <QDialog>

namespace Ui {
class PostsView;
}

class PostsView : public QDialog
{
    Q_OBJECT

public:
    explicit PostsView(QWidget *parent = nullptr);
    ~PostsView();

    Posts *posts;
    User *currentUser;

    User* getCurrentUser();
    void setCurrentUser(User*);
    Posts* getPosts();
    void setPosts(Posts*);
    void formView();

private slots:
    void on_vaccine_clicked();

    void on_update_clicked();

    void on_remove_clicked();

private:
    Ui::PostsView *ui;
};

#endif // POSTSVIEW_H
