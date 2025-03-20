#include "graficos.h"

// Graficos::Graficos() {}

void Graficos::lineaDDA(QPainter *canvas, int x1, int y1, int x2, int y2) {

    int steps;

    float x_inc, y_inc, x, y;

    int dx = x2 - x1;
    int dy = y2 - y1;

    if(abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    x_inc = (float)dx / steps;
    y_inc = (float)dy / steps;

    x = x1;
    y = y1;

    canvas->setPen(QColor(0,0,200));
    canvas->drawPoint(x, y);

    for(int k = 0; k < steps; k ++){
        x += x_inc;
        y += y_inc;
        canvas->drawPoint(round(x), round(y) + 0.5);

    }
}

void Graficos::lineaDDA(QPainter *canvas, int x1, int y1, int x2, int y2, QColor color) {
    int steps;

    float x_inc, y_inc, x, y;

    int dx = x2 - x1;
    int dy = y2 - y1;

    if(abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    x_inc = (float)dx / steps;
    y_inc = (float)dy / steps;

    x = x1;
    y = y1;

    // canvas->setPen(QColor(0,0,200));

    QPen pen(color, 2);
    canvas->setPen(pen);

    canvas->drawPoint(round(x), redondear(y));

    for(int k = 0; k < steps; k ++){
        x += x_inc;
        y += y_inc;
        canvas->drawPoint(round(x), redondear(y)); // + 0.5);
    }
}
