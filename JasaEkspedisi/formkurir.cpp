#include "formkurir.h"
#include "ui_formkurir.h"

FormKurir::FormKurir(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormKurir)
{
    ui->setupUi(this);
}

FormKurir::~FormKurir()
{
    delete ui;
}

void FormKurir::on_pushButton_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("INSERT INTO kurir (id_kurir,nama_kurir,telp_kurir,wilayah,alamat_kurir)"
                "VALUE(:id_kurir,:nama_kurir,:telp_kurir,:wilayah,:alamat_kurir)");
    sql.bindValue(":id_kurir",ui->iDKurirLineEdit->text());
    sql.bindValue(":nama_kurir",ui->namaKurirLineEdit->text());
    sql.bindValue(":telp_kurir",ui->telpKurirLineEdit->text());
    sql.bindValue(":wilayah",ui->wilayahLineEdit->text());
    sql.bindValue(":alamat_kurir",ui->alamatKurirLineEdit->text());


    if (sql.exec()){
        qDebug()<<"Data Berhasil Disimpan";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void FormKurir::on_pushButton_2_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("UPDATE kurir SET nama_kurir=:nama_kurir, telp_kurir=:telp_kurir, wilayah=:wilayah, alamat_kurir=:alamat_kurir where id_kurir=:id_kurir");
    sql.bindValue(":id_kurir",ui->iDKurirLineEdit->text());
    sql.bindValue(":nama_kurir",ui->namaKurirLineEdit->text());
    sql.bindValue(":telp_kurir",ui->telpKurirLineEdit->text());
    sql.bindValue(":wilayah",ui->wilayahLineEdit->text());
    sql.bindValue(":alamat_kurir",ui->alamatKurirLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di ubah";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void FormKurir::on_pushButton_3_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("DELETE FROM kurir WHERE id_kurir=:id_kurir");
    sql.bindValue(":id_kurir",ui->iDKurirLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Hapus";
    }else{
        qDebug()<<sql.lastError().text();
    }
}

