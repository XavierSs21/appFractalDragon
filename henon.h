#ifndef HENON_H
#define HENON_H
#include <QPainter>

class Henon
{
public:
    Henon();

    double escalaX, escalaY, despX, despY;
    double lastX, newX, lastY, newY;

    QPainter *canvas;

    void dibujar(QPainter *canvas);
    void generarHenon(QPainter *painter);

};

#endif // HENON_H
