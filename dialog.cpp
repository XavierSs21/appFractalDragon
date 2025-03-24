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

    // Fractal de Malthus
    malthusFractal = new malthus();

    // Fractal de Mandel
    mandelFractal = new Mandel();

}

Dialog::~Dialog() {

    delete dragonFractal;
    delete henonFractal;
    delete malthusFractal;
    delete mandelFractal;
    delete ui;
}

void Dialog::on_pushBtnSalir_clicked() {
    this->close();
}

void Dialog::paintEvent(QPaintEvent *event) {

    Q_UNUSED(event); // Evitar conflictos con el compilador

    QPainter *canvas = new QPainter(this);

    // dragonFractal->dragon(canvas, dragonFractal->limInferior);
    // // henonFractal->generarHenon(canvas);

    // // malthusFractal->generarMalthus(canvas);
    mandelFractal->dibujar(canvas);

    canvas->end();
}


void Dialog::on_pushBtnIniciar_clicked() {
    dragonFractal->startAnimation();
}

void Dialog::on_pushBtnDetener_clicked() {
    dragonFractal->stopAnimation();
}

