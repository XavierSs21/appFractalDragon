#ifndef MALTHUS_H
#define MALTHUS_H

#include <QObject>
#include <QPainter>
#include <QTimer>

class malthus : public QObject
{
    Q_OBJECT
public:
    explicit malthus(QObject *parent = nullptr);
    ~malthus();

    double PobAnt, PobNueva, x, y, Razon;

    void dibujar(QPainter *canvas);
    void generarMalthus(QPainter *canvas);

    // Animacion del fractal
    QTimer *timer;

    int pasosActuales;
    int pasosMaximos;

    double escalaFactor;
    bool expandiendo;

    void startAnimation();
    void stopAnimation();

signals:
    void updateNeeded();

public slots:
    void updateAnimation();

signals:
};

#endif // MALTHUS_H
