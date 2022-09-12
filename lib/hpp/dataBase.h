#ifndef DATABASE_H
#define DATABASE_H
#include <string>
using namespace std;

class DataBase{
public:
    // destructor
    virtual ~DataBase(){}

    // methods
    virtual bool openDb()=0;
    virtual void closeDb()=0;

    // factory
    static DataBase *createDataBase();
};

#endif // DATABASE_H
