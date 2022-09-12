#ifndef NURSEVIEW_H
#define NURSEVIEW_H

#include "lib/hpp/user.h"

#include <QDebug>
#include <QDialog>

namespace Ui {
class NurseView;
}

class NurseView : public QDialog
{
    Q_OBJECT

public:
    explicit NurseView(QWidget *parent = nullptr);
    ~NurseView();

    User *user;

    User* getUser();
    void setUser(User*);
    void formView();

private slots:
    void on_updateNurseButton_clicked();

    void on_removeNurseButton_clicked();

private:
    Ui::NurseView *ui;
};

#endif // NURSEVIEW_H
