#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPainter>
#include <QRandomGenerator>
#include <iostream>
#include "graficos.h"

#include <QTimer>
#include <QKeyEvent>

#include "graficos.h"

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

    void on_pushBtnIniciar_clicked();

    void on_pushBtnDetener_clicked();

private:
    Ui::Dialog *ui;

    int ejeX [4098];
    int ejeY [4098];

    int paso, signo;

    void paintEvent(QPaintEvent *event) override;  // sobreescribir

    void dragon(); // representa a main en consola

    // Sobrecarga del metodo para la animacion
    void dragon(QPainter *canvas, int limInferior); // representa a main en consola
    void generarDragon(QPainter *canvas); //

    Graficos *linea;

    QTimer *timer;

    int limInferior, limSuperior; // Controlar los limites del dibujo del dragon
    bool flag;
};

#endif // DIALOG_H
