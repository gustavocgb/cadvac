#ifndef VACCINE_H
#define VACCINE_H

#include "lib/hpp/dataBase.h"
#include "lib/hpp/posts.h"

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>

namespace Ui {
class Vaccine;
}

class Vaccine : public QDialog
{
    Q_OBJECT

public:
    explicit Vaccine(QWidget *parent = nullptr);
    ~Vaccine();

    DataBase *dataBase;
    Posts *posts;

    DataBase* getDataBase();
    void setDataBase(DataBase*);
    Posts* getPosts();
    void setPosts(Posts*);
    void formView();
    void clearForm();

private slots:
    void on_button_clicked();

private:
    Ui::Vaccine *ui;
};

#endif // VACCINE_H
