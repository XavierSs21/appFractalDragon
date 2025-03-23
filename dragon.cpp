#include "dragon.h"

Dragon::Dragon(QObject *parent) : QObject(parent) {

    paso = 4096;
    signo = 1;

    linea = new Graficos();

    // Inicialización de variables de animación
    limInferior = 0;
    limSuperior = 12; // Por ejemplo, 12 niveles de iteración
    flag = true;

    // Crear y configurar el timer para animación
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateAnimation()));
}

Dragon::~Dragon() {
    delete linea;
}

void Dragon::dragon(QPainter *canvas) {

    int width = canvas->window().width();
    int height = canvas->window().height();

    // Iniacilizar variables
    paso = 4096;
    signo = 1;
    ejeX[1] = width / 4;
    ejeX[4097] = 3 * width / 4;
    ejeY[1] = ejeY[4097] = 2 * height / 3;

    // agregar color al dibujo por realizar
    canvas->setPen(QColor(QRandomGenerator::global()->bounded(50) + 200,
                          QRandomGenerator::global()->bounded(101) + 155,
                          0));
    // -> Usar el generador de numeros aleatorios en QT

    QFont fuente = canvas->font();
    fuente.setPointSize(fuente.pointSize() * 2); // -> agrgar un size a la letra
    canvas->setFont(QFont("Ebrima", 22));

    // "titulo"
    canvas->drawText(width / 8, 75, "Curva de fractal del Dragon");

    // dibujar una linea
    canvas->setPen(QColor(255,255,255));
    linea->lineaDDA(canvas, ejeX[1], ejeY[1], ejeX[4097], ejeY[4097]);

    for (int i = 1; i <= 11; i++) {
        canvas->setPen(QColor(0, QRandomGenerator::global()->bounded(101) + 155, 0));
        generarDragon(canvas);
        paso /= 2;
    }
}

void Dragon::dragon(QPainter *canvas, int limInferior) {

    int width = canvas->window().width();
    int height = canvas->window().height();

    paso = 4096;
    signo = 1;
    ejeX[1] = width / 4;
    ejeX[4097] = 3 * width / 4;
    ejeY[1] = ejeY[4097] = 2 * height / 3;

    // agregar color al dibujo por realizar
    canvas->setPen(QColor(QRandomGenerator::global()->bounded(50) + 200,
                          QRandomGenerator::global()->bounded(101) + 155,
                          0));

    QFont fuente = canvas->font();
    fuente.setPointSize(fuente.pointSize() * 2);
    canvas->setFont(QFont("Ebrima", 22));
    canvas->drawText(width / 8, 75, "Curva de fractal del Dragon");

    // "titulo"
    // dibujar una linea
    canvas->setPen(QColor(255,255,255));
    linea->lineaDDA(canvas, ejeX[1], ejeY[1], ejeX[4097], ejeY[4097]);

    for (int i = 1; i <= limInferior; i++) {
        canvas->setPen(QColor(0, QRandomGenerator::global()->bounded(101) + 155, 0));
        generarDragon(canvas);
        paso /= 2;
    }
}

void Dragon::generarDragon(QPainter *canvas) {

    int i, j, dx, dy;

    j = paso / 2;

    for(i = 1; i <= 4096; i+= paso){
        dx = ejeX[paso + i] - ejeX[i];
        dy = ejeY[paso + i] - ejeY[i];

        // signo *= -1;

        ejeX[i + j] = ejeX[i] + (dx + (dy * signo)) / 2;
        ejeY[i + j] = ejeY[i] + (dy - (dx * signo)) / 2;

        linea->lineaDDA(canvas, ejeX[i], ejeY[i], ejeX[i + j], ejeY[i + j]);
        linea->lineaDDA(canvas, ejeX[i + j], ejeY[i + j], ejeX[i + paso], ejeY[i + paso]);
    }
}

void Dragon::startAnimation() {
    timer->start(100);
}

void Dragon::stopAnimation() {
    timer->stop();
}

void Dragon::updateAnimation() {

    if (flag) {
        if (limInferior < limSuperior) {
            limInferior++;
        } else {
            flag = false;
        }
    } else {
        if (limInferior > 0) {
            limInferior--;
        } else {
            flag = true;
        }
    }
    // Emite una señal para notificar que se requiere actualizar la vista
    emit updateNeeded();

}



