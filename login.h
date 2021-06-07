#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "oyna2.h"
#include <QSqlDatabase>
#include <QtSql>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QSqlRecord>

namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

private slots:
    void on_pushButton_clicked();

    void on_checkBox_toggled(bool checked);

private:
    Ui::login *ui;
    QSqlDatabase db;
    oyna2 *w2;
};

#endif // LOGIN_H
