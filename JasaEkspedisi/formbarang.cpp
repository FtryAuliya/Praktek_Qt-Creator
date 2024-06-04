#include "formbarang.h"
#include "ui_formbarang.h"

FormBarang::FormBarang(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormBarang)
{
    ui->setupUi(this);
}

FormBarang::~FormBarang()
{
    delete ui;
}

void FormBarang::on_pushButton_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("INSERT INTO barang (kode_barang,nama_barang,jenis_barang,jml_barang,berat_barang,harga_barang)"
                "VALUE(:kode_barang,:nama_barang,:jenis_barang,:jml_barang,:berat_barang,:harga_barang)");
    sql.bindValue(":kode_barang",ui->kodeBarangLineEdit->text());
    sql.bindValue(":nama_barang",ui->namaBarangLineEdit->text());
    sql.bindValue(":jenis_barang",ui->jenisBarangLineEdit->text());
    sql.bindValue(":jml_barang",ui->jumlahBarangLineEdit->text());
    sql.bindValue(":berat_barang",ui->beratBarangLineEdit->text());
    sql.bindValue(":harga_barang",ui->hargaBarangLineEdit->text());


    if (sql.exec()){
        qDebug()<<"Data Berhasil Disimpan";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void FormBarang::on_pushButton_3_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("DELETE FROM barang WHERE kode_barang=:kode_barang");
    sql.bindValue(":kode_barang",ui->kodeBarangLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Hapus";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void FormBarang::on_pushButton_2_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("UPDATE barang SET nama_barang=:nama_barang, jenis_barang=:jenis_barang, jml_barang=:jml_barang, "
                "berat_barang=:berat_barang, harga_barang=:harga_barang where kode_barang=:kode_barang");
    sql.bindValue(":kode_barang",ui->kodeBarangLineEdit->text());
    sql.bindValue(":nama_barang",ui->namaBarangLineEdit->text());
    sql.bindValue(":jenis_barang",ui->jenisBarangLineEdit->text());
    sql.bindValue(":jml_barang",ui->jumlahBarangLineEdit->text());
    sql.bindValue(":berat_barang",ui->beratBarangLineEdit->text());
    sql.bindValue(":harga_barang",ui->hargaBarangLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di ubah";
    }else{
        qDebug()<<sql.lastError().text();
    }
}

