#ifndef DRAGON_H
#define DRAGON_H

#include <QObject>
#include <QPainter>
#include <QRandomGenerator>
#include <QTimer>

#include "graficos.h"

class Dragon : public QObject
{
    Q_OBJECT

public:
    explicit Dragon(QObject *parent = nullptr);
    ~Dragon();

    Graficos *linea;
    QTimer *timer;

    int ejeX [4098];
    int ejeY [4098];
    int paso, signo;

    void dragon(QPainter *canvas); // representa a main en consola
    void dragon(QPainter *canvas, int limInferior); // representa a main en consola
    void generarDragon(QPainter *canvas); //

    void startAnimation();
    void stopAnimation();

    int limInferior, limSuperior; // Controlar los limites del dibujo del dragon
    bool flag;

signals:
    void updateNeeded();

public slots:
    void updateAnimation();


};

#endif // DRAGON_H
