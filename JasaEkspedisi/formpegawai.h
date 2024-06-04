#ifndef FORMPEGAWAI_H
#define FORMPEGAWAI_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class FormPegawai;
}

class FormPegawai : public QWidget
{
    Q_OBJECT

public:
    explicit FormPegawai(QWidget *parent = nullptr);
    ~FormPegawai();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::FormPegawai *ui;
    QSqlDatabase koneksi;
    QSqlQuery sql;
};

#endif // FORMPEGAWAI_H
