#include "mysqlquerymodel.h"
#include <QSqlQuery>
#include <QColor>
#include <QSqlQueryModel>
MySqlQueryModel::MySqlQueryModel()
{
}
Qt::ItemFlags MySqlQueryModel::flags(const QModelIndex &index)const
{
    Qt::ItemFlags flags=QSqlQueryModel::flags(index);
    if(index.column()==1)
        flags|=Qt::ItemIsEditable;
    return flags;
}
bool MySqlQueryModel::setData(const QModelIndex &index,const QVariant &value,int /*role*/)
{
    if(index.column()<0||index.column()>1)
        return false;
    QModelIndex primaryKeyIndex=QSqlQueryModel::index(index.row(),0);
    int id=data(primaryKeyIndex).toInt();
    clear();
    bool ok;
    if(index.column()==1)
        ok=setName(id,value.toString());
    refresh();
    return ok;
}
void MySqlQueryModel::refresh()
{
   setQuery("select ) from studentss");
   setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
   setHeaderData(1,Qt::Horizontal,QObject::tr("name"));
}
bool MySqlQueryModel::setName(int studentssId, const QString &name)
{
    QSqlQuery query;
    query.prepare("update studentss set name=? where id=?");
    query.addBindValue(name);
    query.addBindValue(studentssId);
    return query.exec();
}
QVariant MySqlQueryModel::data(const QModelIndex &index,int role) const
{
    QVariant value=QSqlQueryModel::data(index,role);
    if(role==Qt::TextColorRole && index.column()==0)
        return qVariantFromValue(QColor(Qt::red));
    return value;
}
