#include "henon.h"

Henon::Henon(QObject *parent) : QObject(parent) {

    lastX = newX = lastY = newY = 0.1;

    escalaX = escalaY = 1;
    despX = despY = 0;

    iteracionActual = 0;
    iteracionMaxima = 15;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateAnimation()));

}

Henon::~Henon(){ }


void Henon::dibujar(QPainter *canvas) {

    int PosX, PosY;

    //====================================//
    //        Confinador de Henon         //
    //      x = y + 1 - ( 1.4 * x * x)    //
    //      y = 0.3 * x                   //
    //                                    //
    //====================================//

    const int width = canvas->window().width();
    const int height = canvas->window().height();

    QFont fuente = canvas->font();

    fuente.setPointSize(fuente.pointSize() * 2); // -> agrgar un size a la letra
    canvas->setFont(QFont("Ebrima", 22));
    canvas->drawText(10, 40, "Confinador de Henon");

    for(int i = 1; i <= iteracionActual; i++){
        for(int j = 1; j <= 0x2FF; j++){
            newX = lastY + 1 - ( 1.4 * pow(lastX, 2) );
            newY = 0.3 * lastX;

            PosX = (newX * width  / 3 * escalaX) + width / 2 + despX;
            PosY = (newY * height * escalaY) + height / 2 + despY;

            if( ( PosX >= 0 ) && ( PosX <= width ) &&
                ( PosY >= 0 ) && ( PosY <= height ) ){

                canvas->setPen(QColor(113, 28, 141));
                canvas->drawPoint(PosX, PosY);
            }
            lastY = newY;
            lastX = newX;
        }
    }

}

void Henon::generarHenon(QPainter *canvas) {

    escalaX = 1;
    escalaY = 1;
    despX = 0;
    despY = 0;
    dibujar(canvas);

}

void Henon::startAnimation() {
    timer->start(100);
}

void Henon::stopAnimation() {
    timer->stop();
}

void Henon::updateAnimation() {
    if (iteracionActual < iteracionMaxima) {
        iteracionActual++;
    } else {
        iteracionActual = 0;
        lastX = lastY = newX = newY = 0.1;
    }
    emit updateNeeded();
}
