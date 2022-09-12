#ifndef DATABASE_IMPL_H
#define DATABASE_IMPL_H
#include "dataBase.h"
#include <QtSql>
#include <QDebug>
#include <string>
#include <list>
#include <iostream>
using namespace std;

class DataBase_impl : DataBase {
protected:
    QSqlDatabase QDataBase;

    DataBase *dataBase;

public:

    DataBase_impl();
    virtual ~DataBase_impl();

    bool openDb();
    void closeDb();

    static DataBase *createDataBase();

};

#endif // DATABASE_IMPL_H
