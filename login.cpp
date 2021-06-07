#include "login.h"
#include "ui_login.h"

//yozmoqchi bo'lgan fayllarimizni adresini yozib olamiz.
QString fns1="C:\\Users\\User\\Desktop\\session1.txt";
QString fns2="C:\\Users\\User\\Desktop\\session2.txt";
//---------------------------------------------------

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    qDebug() << QApplication::libraryPaths();

    //Database ni ulaymiz-------------------------

    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/User/Desktop/users.db");

    if (!db.open()){
            qDebug() << "Error";
        } else {
            qDebug() << "Ok";
        }
    //@@@@@@@@@@@@@@@@@@@--------------------------
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    //vaqtni olamiz -----------------------
    QTime time=QTime::currentTime();
    QDate date=QDate::currentDate();
    QString sdate=date.toString("dd.MM.yyyy");
    QString stime=time.toString("H:m:s");
    //*************------------------------

    // fayllarni yozish uchun e'lon qilamiz
    QFile file1(fns1);
    QFile file2(fns2);
    if (!file1.open( QIODevice::Text | QIODevice::ReadWrite)){
             return;}
    if (!file2.open(QIODevice::ReadWrite | QIODevice::Text)){
             return;}
    //************************************

    //tashqaridagi ma'lumotlarni olamiz
    QString login=ui->lineEdit_2->text();
    QString parol=ui->lineEdit_3->text();
    //*********************************

    //Bazaga so'rovni yuborish uchun
    QString sql="SELECT *FROM students WHERE login='"+login+"' AND parol='"+parol+"'";
    QSqlQuery query(sql);
//    query.exec(sql);
    int kk=0;
    while(query.next()){
        kk++;
    }
    if(kk>0){
        QMessageBox::information(this,"kirish",". \tLogin va Parol tasdiqlandi!!!\n",QMessageBox::Cancel);
        QTextStream fout1(&file1);
        QString t1=fout1.readAll()+"\n";
        fout1<<sdate<<" da. \t"<<stime<<".\n";
        file1.close();

        this->hide();
        w2=new oyna2();
        w2->show();
    }else{
        QMessageBox::critical(this,"Xa'to","Login yoki Parol xato!!!\n",QMessageBox::Cancel);
        QTextStream fout2(&file2);
        QString t2=fout2.readAll()+"\n";
        fout2<<sdate<<" da. \t"<<stime<<"\n";

        file2.close();
    }


}

void login::on_checkBox_toggled(bool checked)
{
    if(checked){
        ui->lineEdit_3->setEchoMode(QLineEdit::Normal);
    }
    else{
        ui->lineEdit_3->setEchoMode(QLineEdit::Password);
    }
}
