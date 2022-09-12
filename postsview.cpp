#include "postsview.h"
#include "ui_postsview.h"

PostsView::PostsView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PostsView)
{
    ui->setupUi(this);
}

PostsView::~PostsView()
{
    delete ui;
}

Posts* PostsView::getPosts(){
    return posts;
}
void PostsView::setPosts(Posts* data){
    posts = data;
}
void PostsView::formView(){
    ui->name->setText(QString::fromStdString(this->getPosts()->getPostName()));
    ui->address->setText(QString::fromStdString(this->getPosts()->getAddress()));
}

User* PostsView::getCurrentUser(){

    return currentUser;
}

void PostsView::setCurrentUser(User* data){

    currentUser = data;
}

void PostsView::on_vaccine_clicked()
{
    UserManagement *userManagement = new UserManagement(this);
    userManagement->setCurrentUser(this->getCurrentUser());
    userManagement->setPosts(this->getPosts());
    userManagement->setType(3);
    userManagement->titleUi();
    userManagement->exec();
}

void PostsView::on_update_clicked()
{

}

void PostsView::on_remove_clicked()
{

}
