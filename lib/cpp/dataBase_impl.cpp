#include "../hpp/dataBase_impl.h"

DataBase_impl::DataBase_impl(){}
DataBase_impl::~DataBase_impl(){}

// factory
DataBase *DataBase::createDataBase(){
    return DataBase_impl::createDataBase();
}
DataBase *DataBase_impl::createDataBase(){
    DataBase *db = new DataBase_impl();
    return db;
}

// methods
bool DataBase_impl::openDb(){

    QDataBase = QSqlDatabase::addDatabase("QSQLITE");
    QString path = qApp->applicationDirPath();
    auto path2 = path.split("/");
    path2.removeLast();
    path2.removeLast();
    QString dir = path2.join("/");
    QString db = dir+"/cadvac/cadvac_db/cadvac_db.db";
    QDataBase.setDatabaseName(db);

    if(QDataBase.open()){
        return true;
    } else {
        return false;
    }
}

void DataBase_impl::closeDb(){
    QDataBase.close();
}
