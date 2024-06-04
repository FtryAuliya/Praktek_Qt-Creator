#ifndef FORMPENGIRIMAN_H
#define FORMPENGIRIMAN_H

#include <QWidget>
#include <biaya.h>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class FormPengiriman;
}

class FormPengiriman : public QWidget
{
    Q_OBJECT

public:
    explicit FormPengiriman(QWidget *parent = nullptr);
    ~FormPengiriman();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::FormPengiriman *ui;
    biaya uji;
    QSqlDatabase koneksi;
    QSqlQuery sql;
};

#endif // FORMPENGIRIMAN_H
