#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->pushBtnIniciar->setEnabled(false);

    connect(ui->comboBoxFractal, SIGNAL(currentIndexChanged(int)),
            this, SLOT(validarSeleccionFractal()));

    // Fractal de Dragon / Arabesco
    dragonFractal = new Dragon(this);
    connect(dragonFractal, SIGNAL(updateNeeded()), this, SLOT(update()));

    // Fractal de Henon
    henonFractal = new Henon();
    connect(henonFractal, SIGNAL(updateNeeded()), this, SLOT(update()));

    // Fractal de Malthus
    malthusFractal = new malthus();
    connect(malthusFractal, SIGNAL(updateNeeded()), this, SLOT(update()));


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

    int index = ui->comboBoxFractal->currentIndex();

    switch (index) {
    case 1:  // Dragon
        dragonFractal->dragon(canvas, dragonFractal->limInferior);
        break;
    case 2:  // Henon
        henonFractal->generarHenon(canvas);
        break;
    case 3:  // Malthus
        malthusFractal->generarMalthus(canvas);
        break;
    case 4:  // Mandel
        mandelFractal->dibujar(canvas);
        break;
    }

    canvas->end();
}


void Dialog::on_pushBtnIniciar_clicked() {
    dragonFractal->startAnimation();
    henonFractal->startAnimation();
    malthusFractal->startAnimation();
}

void Dialog::on_pushBtnDetener_clicked() {
    dragonFractal->stopAnimation();
    henonFractal->stopAnimation();
    malthusFractal->stopAnimation();

}

void Dialog::validarSeleccionFractal() {
    int index = ui->comboBoxFractal->currentIndex();
    ui->pushBtnIniciar->setEnabled(index != 0);
}

