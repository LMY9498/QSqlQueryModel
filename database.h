#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>

static bool createConnection()
{
   QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
   db.setHostName("localhost");
   db.setPort(3306);
   db.setDatabaseName("test");
   db.setUserName("root");
   db.setPassword("limengyun");
   if(!db.open())
   {
       return false;
   }
   QSqlQuery query;
   query.exec("create table studentss (id int primary key,name varchar(20))");
   query.exec("insert into studentss values(0,'yafei0')");
   query.exec("insert into studentss values(1,'yafei1')");
   query.exec("insert into studentss values(2,'yafei2')");
   return true;
}
#endif // DATABASE_H
