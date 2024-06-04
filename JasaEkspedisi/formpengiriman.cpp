#include "formpengiriman.h"
#include "ui_formpengiriman.h"

FormPengiriman::FormPengiriman(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormPengiriman)
{
    ui->setupUi(this);
}

FormPengiriman::~FormPengiriman()
{
    delete ui;

    biaya uji;
}

void FormPengiriman::on_pushButton_clicked()
{

    uji.getbiayaPacking(ui->biayaPackingLineEdit->text().toInt());
    uji.getbiayaAsuransi(ui->biayaAsuransiLineEdit->text().toInt());

    QSqlQuery sql(koneksi);
    sql.prepare("INSERT INTO pengiriman (no_resi,kode_barang,tgl_pengiriman, id_pegawai,id_pelanggan, "
                "tgl_diterima, nama_penerima, alamat_penerima, telp_penerima, id_tarif, biaya_packing, biaya_asuransi, berat_barang, total_biaya)"
                "VALUE(:no_resi, :kode_barang, :tgl_pengiriman, :id_pegawai, :id_pelanggan, :tgl_diterima, "
                ":nama_penerima, :alamat_penerima, :telp_penerima, :id_tarif, :biaya_packing, :biaya_asuransi, :berat_barang, :total_biaya)");
    sql.bindValue(":no_resi",ui->noResiLineEdit->text());
    sql.bindValue(":kode_barang",ui->kodeBarangLineEdit->text());
    sql.bindValue(":tgl_pengiriman",ui->tanggalPengirimanDateEdit->date());
    sql.bindValue(":id_pegawai",ui->iDPegawaiLineEdit->text());
    sql.bindValue(":id_pelanggan",ui->iDPelangganLineEdit->text());
    sql.bindValue(":tgl_diterima",ui->tanggalDiterimaDateEdit->date());
    sql.bindValue(":nama_penerima",ui->namaPenerimaLineEdit->text());
    sql.bindValue(":alamat_penerima",ui->alamatTujuanPenerimaLineEdit->text());
    sql.bindValue(":telp_penerima",ui->telpPenerimaLineEdit->text());
    sql.bindValue(":id_tarif",ui->iDTarifLineEdit->text());
    sql.bindValue(":biaya_packing",ui->biayaPackingLineEdit->text().toInt());
    sql.bindValue(":biaya_asuransi",ui->biayaAsuransiLineEdit->text().toInt());
    sql.bindValue(":berat_barang",ui->beratBarangLineEdit->text());
    sql.bindValue(":total_biaya",uji.TotalBiaya());


    if (sql.exec()){
        qDebug()<<"Data Berhasil Disimpan";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void FormPengiriman::on_pushButton_2_clicked()
{
    uji.getbiayaPacking(ui->biayaPackingLineEdit->text().toInt());
    uji.getbiayaAsuransi(ui->biayaAsuransiLineEdit->text().toInt());

    QSqlQuery sql(koneksi);
    sql.prepare("UPDATE pengiriman SET kode_barang=:kode_barang, tgl_pengiriman=:tgl_pengiriman, id_pegawai=:id_pegawai,"
                "id_pelanggan=:id_pelanggan, tgl_diterima=:tgl_diterima, nama_penerima=:nama_penerima,"
                "alamat_penerima=:alamat_penerima, telp_penerima=:telp_penerima, id_tarif=:id_tarif, biaya_packing=:biaya_packing,"
                "biaya_asuransi=:biaya_asuransi, berat_barang=:berat_barang, total_biaya=:total_biaya where no_resi=:no_resi");
    sql.bindValue(":no_resi",ui->noResiLineEdit->text());
    sql.bindValue(":kode_barang",ui->kodeBarangLineEdit->text());
    sql.bindValue(":tgl_pengiriman",ui->tanggalPengirimanDateEdit->date());
    sql.bindValue(":id_pegawai",ui->iDPegawaiLineEdit->text());
    sql.bindValue(":id_pelanggan",ui->iDPelangganLineEdit->text());
    sql.bindValue(":tgl_diterima",ui->tanggalDiterimaDateEdit->date());
    sql.bindValue(":nama_penerima",ui->namaPenerimaLineEdit->text());
    sql.bindValue(":alamat_penerima",ui->alamatTujuanPenerimaLineEdit->text());
    sql.bindValue(":telp_penerima",ui->telpPenerimaLineEdit->text());
    sql.bindValue(":id_tarif",ui->iDTarifLineEdit->text());
    sql.bindValue(":biaya_packing",ui->biayaPackingLineEdit->text().toInt());
    sql.bindValue(":biaya_asuransi",ui->biayaAsuransiLineEdit->text().toInt());
    sql.bindValue(":berat_barang",ui->beratBarangLineEdit->text());
    sql.bindValue(":total_biaya",uji.TotalBiaya());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di ubah";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void FormPengiriman::on_pushButton_3_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("DELETE FROM pengiriman WHERE no_resi=:no_resi");
    sql.bindValue(":no_resi",ui->noResiLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Hapus";
    }else{
        qDebug()<<sql.lastError().text();
    }
}

