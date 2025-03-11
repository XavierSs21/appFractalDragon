#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushBtnSalir_clicked() {

}

void Dialog::paintEvent(QPaintEvent *event) {

    Q_UNUSED(event);
    dragon();
}

void Dialog::dragon() {  // representar a main

}

void Dialog::generarDragon(QPainter *canvas) {

}
