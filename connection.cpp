#include "connection.h"

Connection::Connection()
{}

bool Connection::createconnection()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test-bd");
db.setUserName("sami");// nom
db.setPassword("sami");// mot de passe

if (db.open())
    test=true;

    return  test;
}

void Connection::closeConnection(){db.close();}
