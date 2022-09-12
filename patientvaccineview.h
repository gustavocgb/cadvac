#ifndef PATIENTVACCINEVIEW_H
#define PATIENTVACCINEVIEW_H

#include "lib/hpp/patient.h"
#include "lib/hpp/dataBase.h"
#include "lib/hpp/posts.h"

#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>
#include <QDialog>

namespace Ui {
class PatientVaccineView;
}

class PatientVaccineView : public QDialog
{
    Q_OBJECT

public:
    explicit PatientVaccineView(QWidget *parent = nullptr);
    ~PatientVaccineView();

    Patient *patient;
    DataBase *dataBase;
    Posts *posts;

    Patient* getPatient();
    void setPatient(Patient*);
    void getVaccines();
    DataBase* getDataBase();
    void setDataBase(DataBase*);
    Posts* getPosts();
    void setPosts(Posts*);

private:
    Ui::PatientVaccineView *ui;
};

#endif // PATIENTVACCINEVIEW_H
