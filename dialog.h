#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPainter>
#include <QRandomGenerator>

#include <QTimer>
#include <QKeyEvent>

#include "dragon.h"
#include "henon.h"
#include "malthus.h"

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

    void paintEvent(QPaintEvent *event) override;  // sobreescribir

    // =============== Dragon =============== //

    Dragon *dragonFractal;

    // =============== Dragon =============== //



    // =============== Henon =============== //

    Henon *henonFractal;

    // =============== Henon =============== //

    // =============== Malthus =============== //

    malthus *malthusFractal;

    // =============== Malthus =============== //

};

#endif // DIALOG_H
