#include "formtarif.h"
#include "ui_formtarif.h"

FormTarif::FormTarif(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormTarif)
{
    ui->setupUi(this);
}

FormTarif::~FormTarif()
{
    delete ui;
}

void FormTarif::on_pushButton_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("INSERT INTO tarif (id_tarif,asal,tujuan,biaya_tarif)"
                "VALUE(:id_tarif,:asal,:tujuan,:biaya_tarif)");
    sql.bindValue(":id_tarif",ui->iDTarifLineEdit->text());
    sql.bindValue(":asal",ui->asalLineEdit->text());
    sql.bindValue(":tujuan",ui->tujuanLineEdit->text());
    sql.bindValue(":biaya_tarif",ui->biayaTarifLineEdit->text());


    if (sql.exec()){
        qDebug()<<"Data Berhasil Disimpan";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void FormTarif::on_pushButton_2_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("UPDATE tarif SET asal=:asal, tujuan=:tujuan, biaya_tarif=:biaya_tarif "
                "where id_tarif=:id_tarif");
    sql.bindValue(":id_tarif",ui->iDTarifLineEdit->text());
    sql.bindValue(":asal",ui->asalLineEdit->text());
    sql.bindValue(":tujuan",ui->tujuanLineEdit->text());
    sql.bindValue(":biaya_tarif",ui->biayaTarifLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di ubah";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void FormTarif::on_pushButton_3_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("DELETE FROM tarif WHERE id_tarif=:id_tarif");
    sql.bindValue(":id_tarif",ui->iDTarifLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Hapus";
    }else{
        qDebug()<<sql.lastError().text();
    }
}

