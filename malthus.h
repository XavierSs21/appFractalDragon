#ifndef MALTHUS_H
#define MALTHUS_H

#include <QObject>
#include <QPainter>

class malthus : public QObject
{
    Q_OBJECT
public:
    explicit malthus(QObject *parent = nullptr);
    ~malthus();

    double PobAnt, PobNueva, x, y, Razon;

    void dibujar(QPainter *canvas);
    void generarMalthus(QPainter *canvas);

signals:
};

#endif // MALTHUS_H
