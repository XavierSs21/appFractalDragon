#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPainter>
#include <QRandomGenerator>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushBtnSalir_clicked();

private:
    Ui::Dialog *ui;

    int ejeX [4098];
    int ejeY [4098];

    int paso, signo;

    void paintEvent(QPaintEvent *event) override;  // sobreescribir

    void dragon(); // representa a main en consola
    void generarDragon(QPainter *canvas); //
};
#endif // DIALOG_H
