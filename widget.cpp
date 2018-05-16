#include "widget.h"
#include "ui_widget.h"
#include "mysqlquerymodel.h"
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlRecord>
#include <QModelIndex>
#include <QDebug>
#include <QtSql>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QSqlQueryModel *model =new QSqlQueryModel;
    model->setQuery("select * from studentss");
    model->setHeaderData(0,Qt::Horizontal,tr("id"));
    model->setHeaderData(1,Qt::Horizontal,tr("name"));
    QTableView *view=new QTableView;
    view->setModel(model);
    view->show();

    MySqlQueryModel *mymodel=new MySqlQueryModel;
    mymodel->setQuery("select * from studentss");
    mymodel->setHeaderData(0,Qt::Horizontal,tr("id"));
    mymodel->setHeaderData(1,Qt::Horizontal,tr("name"));
    QTableView *view1=new QTableView;
    view1->setWindowTitle("mySqlQueryModel");
    view1->setModel(mymodel);
    view1->show();
}
