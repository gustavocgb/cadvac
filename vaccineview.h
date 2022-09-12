#ifndef VACCINEVIEW_H
#define VACCINEVIEW_H

#include "lib/hpp/dataBase.h"
#include "lib/hpp/posts.h"

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>

namespace Ui {
class VaccineView;
}

class VaccineView : public QDialog
{
    Q_OBJECT

public:
    explicit VaccineView(QWidget *parent = nullptr);
    ~VaccineView();

    DataBase *dataBase;
    Posts *posts;

    DataBase* getDataBase();
    void setDataBase(DataBase*);
    Posts* getPosts();
    void setPosts(Posts*);
    void getVaccines();

private slots:
    void on_removeButton_clicked();

private:
    Ui::VaccineView *ui;
};

#endif // VACCINEVIEW_H
