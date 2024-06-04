#ifndef FORMTRACKING_H
#define FORMTRACKING_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class FormTracking;
}

class FormTracking : public QWidget
{
    Q_OBJECT

public:
    explicit FormTracking(QWidget *parent = nullptr);
    ~FormTracking();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::FormTracking *ui;
    QSqlDatabase koneksi;
    QSqlQuery sql;
};

#endif // FORMTRACKING_H
