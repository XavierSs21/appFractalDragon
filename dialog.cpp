#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // Fractal de Dragon / Arabesco
    dragonFractal = new Dragon(this);
    connect(dragonFractal, SIGNAL(updateNeeded()), this, SLOT(update()));


    // Fractal de Henon
    henonFractal = new Henon();

}

Dialog::~Dialog() {

    delete dragonFractal;
    delete henonFractal;
    delete ui;
}

void Dialog::on_pushBtnSalir_clicked() {
    this->close();
}

void Dialog::paintEvent(QPaintEvent *event) {

    Q_UNUSED(event); // Evitar conflictos con el compilador

    QPainter *canvas = new QPainter(this);

    dragonFractal->dragon(canvas, dragonFractal->limInferior);
    henonFractal->generarHenon(canvas);
}


void Dialog::on_pushBtnIniciar_clicked() {
    dragonFractal->startAnimation();
}

void Dialog::on_pushBtnDetener_clicked() {
    dragonFractal->stopAnimation();
}

