#include "oyna2.h"
#include "ui_oyna2.h"
#include <QDebug>

#include "QSql"
#include <QtSql/QSqlTableModel>
#include "QSqlDatabase"
#include "QMessageBox"
#include <QSqlError>
#include <QFileDialog>
#include <QSqlQuery>


oyna2::oyna2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::oyna2)
{


        QSqlDatabase db2 = QSqlDatabase::addDatabase("QSQLITE");
        db2.setHostName("localhost");
        db2.setDatabaseName("C:/Users/User/Desktop/users.db");
        bool tekshir=db2.open();
        if(!tekshir){
            qDebug()<<"Error";
        }
        else{
            qDebug()<<"Database OK!";
        }

        QSqlTableModel *model;
            model = new QSqlTableModel(this);
            model->setTable("students");
            ui->tableView->setModel(model);
            model->select();
        ui->setupUi(this);
}

oyna2::~oyna2()
{
    delete ui;
}
