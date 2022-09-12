#ifndef PATIENTVIEW_H
#define PATIENTVIEW_H

#include "lib/hpp/patient.h"

#include "patientvaccineview.h"

#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>
#include <QDialog>

namespace Ui {
class PatientView;
}

class PatientView : public QDialog
{
    Q_OBJECT

public:
    explicit PatientView(QWidget *parent = nullptr);
    ~PatientView();

    Patient *patient;

    Patient* getPatient();
    void setPatient(Patient*);
    void formView();

private slots:
    void on_vaccine_clicked();

    void on_updateNurseButton_clicked();

    void on_removeNurseButton_clicked();

private:
    Ui::PatientView *ui;
};

#endif // PATIENTVIEW_H
