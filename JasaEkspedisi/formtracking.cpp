#include "formtracking.h"
#include "ui_formtracking.h"

FormTracking::FormTracking(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormTracking)
{
    ui->setupUi(this);
}

FormTracking::~FormTracking()
{
    delete ui;
}

void FormTracking::on_pushButton_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("INSERT INTO tracking (id_tracking,no_resi,id_kurir,tgl_kirim,tgl_sampai,status_kirim,ket)"
                "VALUE(:id_tracking,:no_resi,:id_kurir,:tgl_kirim,:tgl_sampai,:status_kirim,:ket)");
    sql.bindValue(":id_tracking",ui->iDTrackingLineEdit->text());
    sql.bindValue(":no_resi",ui->noResiLineEdit->text());
    sql.bindValue(":id_kurir",ui->iDKurirLineEdit->text());
    sql.bindValue(":tgl_kirim",ui->tanggalKirimDateEdit->date());
    sql.bindValue(":tgl_sampai",ui->tanggalSampaiDateEdit->date());
    sql.bindValue(":status_kirim",ui->statusKirimLineEdit->text());
    sql.bindValue(":ket",ui->keteranganLineEdit->text());


    if (sql.exec()){
        qDebug()<<"Data Berhasil Disimpan";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void FormTracking::on_pushButton_2_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("UPDATE tracking SET no_resi=:no_resi, id_kurir=:id_kurir, tgl_kirim=:tgl_kirim, "
                "tgl_sampai=:tgl_sampai, status_kirim=:status_kirim, ket=:ket where id_tracking=:id_tracking");
    sql.bindValue(":id_tracking",ui->iDTrackingLineEdit->text());
    sql.bindValue(":no_resi",ui->noResiLineEdit->text());
    sql.bindValue(":id_kurir",ui->iDKurirLineEdit->text());
    sql.bindValue(":tgl_kirim",ui->tanggalKirimDateEdit->date());
    sql.bindValue(":tgl_sampai",ui->tanggalSampaiDateEdit->date());
    sql.bindValue(":status_kirim",ui->statusKirimLineEdit->text());
    sql.bindValue(":ket",ui->keteranganLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di ubah";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void FormTracking::on_pushButton_3_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("DELETE FROM tracking WHERE id_tracking=:id_tracking");
    sql.bindValue(":id_tracking",ui->iDTrackingLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Hapus";
    }else{
        qDebug()<<sql.lastError().text();
    }
}

