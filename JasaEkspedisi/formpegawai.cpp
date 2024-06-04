#include "formpegawai.h"
#include "ui_formpegawai.h"

FormPegawai::FormPegawai(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormPegawai)
{
    ui->setupUi(this);

    QSqlDatabase koneksi = QSqlDatabase::addDatabase("QODBC");
    koneksi.setDatabaseName("dsn_ekspedisi");
    koneksi.setUserName("root");
    koneksi.setPassword("");

    if(!koneksi.open()){
        qDebug()<<koneksi.lastError().text();
    }else{
        qDebug()<<"Database Terkoneksi";

    }
}

FormPegawai::~FormPegawai()
{
    delete ui;
}

void FormPegawai::on_pushButton_3_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("DELETE FROM pegawai WHERE id_pegawai=:id_pegawai");
    sql.bindValue(":id_pegawai",ui->iDPegawaiLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Hapus";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void FormPegawai::on_pushButton_2_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("UPDATE pegawai SET nama_pegawai=:nama_pegawai, alamat_pegawai=:alamat_pegawai, telp_pegawai=:telp_pegawai "
                "where id_pegawai=:id_pegawai");
    sql.bindValue(":id_pegawai",ui->iDPegawaiLineEdit->text());
    sql.bindValue(":nama_pegawai",ui->namaPegawaiLineEdit->text());
    sql.bindValue(":alamat_pegawai",ui->alamatPegawaiLineEdit->text());
    sql.bindValue(":telp_pegawai",ui->telpPegawaiLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di ubah";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void FormPegawai::on_pushButton_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("INSERT INTO pegawai (id_pegawai,nama_pegawai,alamat_pegawai,telp_pegawai)"
                "VALUE(:id_pegawai,:nama_pegawai,:alamat_pegawai,:telp_pegawai)");
    sql.bindValue(":id_pegawai",ui->iDPegawaiLineEdit->text());
    sql.bindValue(":nama_pegawai",ui->namaPegawaiLineEdit->text());
    sql.bindValue(":alamat_pegawai",ui->alamatPegawaiLineEdit->text());
    sql.bindValue(":telp_pegawai",ui->telpPegawaiLineEdit->text());


    if (sql.exec()){
        qDebug()<<"Data Berhasil Disimpan";
    }else{
        qDebug()<<sql.lastError().text();
    }
}

