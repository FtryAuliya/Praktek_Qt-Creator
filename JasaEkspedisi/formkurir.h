#ifndef FORMKURIR_H
#define FORMKURIR_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>


namespace Ui {
class FormKurir;
}

class FormKurir : public QWidget
{
    Q_OBJECT

public:
    explicit FormKurir(QWidget *parent = nullptr);
    ~FormKurir();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::FormKurir *ui;
    QSqlDatabase koneksi;
    QSqlQuery sql;
};

#endif // FORMKURIR_H
