#include "mandel.h"

Mandel::Mandel(QObject *parent)
    : QObject{parent}
{
    Limite = 10;
    origX = -2.0;
    origY = -1.25;
    dimX = 0.5;
    dimY = 1.25;
}

Mandel::~Mandel() { }

void Mandel::dibujar(QPainter *canvas) {

    const int width = canvas->window().width();
    const int height = canvas->window().height();

    stepX = (dimX - origX) / width;
    stepY = (dimY - origY) / height;

    for (int i = 0; i <= width; i++) {
        for (int j = 0; j <= height; j++) {
            posX = origX + i * stepX;
            posY = origY + j * stepY;

            iterX = 0.0;
            iterY = 0.0;
            Steps = 0;
            Terminar = 0;

            while (!Terminar) {
                tempX = (iterX * iterX - iterY * iterY) + posX;
                iterY = 2 * iterX * iterY + posY;
                iterX = tempX;

                Steps++;

                if (std::hypot(iterX, iterY) >= 2.0 || Steps >= Limite)
                    Terminar = 1;
            }

            if (Steps < Limite) {
                int intensidad = static_cast<int>(255.0 * Steps / Limite);
                canvas->setPen(QColor::fromRgb(intensidad, intensidad, intensidad));
                canvas->drawPoint(i, j);
            }
        }
    }


}
