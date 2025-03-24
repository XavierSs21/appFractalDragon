#ifndef MANDEL_H
#define MANDEL_H

#include <QObject>
#include <QPainter>

class Mandel : public QObject
{
    Q_OBJECT
public:
    explicit Mandel(QObject *parent = nullptr);
    ~Mandel();

    int Limite, Steps, Terminar;
    double stepX, stepY, posX, posY, origX, origY;
    double dimX, dimY, iterX, iterY, tempX;

    void dibujar(QPainter *canvas);

signals:
};

#endif // MANDEL_H
