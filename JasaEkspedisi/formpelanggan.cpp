#include "formpelanggan.h"
#include "ui_formpelanggan.h"

FormPelanggan::FormPelanggan(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormPelanggan)
{
    ui->setupUi(this);
}

FormPelanggan::~FormPelanggan()
{
    delete ui;
}

void FormPelanggan::on_pushButton_3_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("DELETE FROM pelanggan WHERE id_pelanggan=:id_pelanggan");
    sql.bindValue(":id_pelanggan",ui->iDPelangganLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Hapus";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void FormPelanggan::on_pushButton_2_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("UPDATE pelanggan SET alamat_pelanggan=:alamat_pelanggan, telp_pelanggan=:telp_pelanggan "
                "where id_pelanggan=:id_pelanggan");
    sql.bindValue(":id_pelanggan",ui->iDPelangganLineEdit->text());
    sql.bindValue(":alamat_pelanggan",ui->alamatPelangganLineEdit->text());
    sql.bindValue(":telp_pelanggan",ui->telpPelangganLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di ubah";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void FormPelanggan::on_pushButton_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("INSERT INTO pelanggan (id_pelanggan,alamat_pelanggan,telp_pelanggan)"
                "VALUE(:id_pelanggan,:alamat_pelanggan,:telp_pelanggan)");
    sql.bindValue(":id_pelanggan",ui->iDPelangganLineEdit->text());
    sql.bindValue(":alamat_pelanggan",ui->alamatPelangganLineEdit->text());
    sql.bindValue(":telp_pelanggan",ui->telpPelangganLineEdit->text());


    if (sql.exec()){
        qDebug()<<"Data Berhasil Disimpan";
    }else{
        qDebug()<<sql.lastError().text();
    }
}

