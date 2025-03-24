#ifndef HENON_H
#define HENON_H

#include <QObject>
#include <QPainter>
#include <QTimer>

class Henon : public QObject
{
    Q_OBJECT
public:
    explicit Henon(QObject *parent = nullptr);
    ~Henon();

    QTimer *timer;

    double escalaX, escalaY, despX, despY;
    double lastX, newX, lastY, newY;

    void dibujar(QPainter *canvas);
    void generarHenon(QPainter *painter);

    // Animacion del fractal
    int iteracionActual;
    int iteracionMaxima;

    void startAnimation();
    void stopAnimation();

signals:
    void updateNeeded();

public slots:
    void updateAnimation();

};

#endif // HENON_H
