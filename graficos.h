#ifndef GRAFICOS_H
#define GRAFICOS_H

#include <QPainter>
#include <QtCore>
#include <QtGUI>
#include <QColor>

class Graficos
{
public:
    // Graficos();

    int redondear(float val){
        return int(val + 0.5);
    }

    void lineaDDA(QPainter *canvas, int x1, int y1, int x2, int y2);
    void lineaDDA(QPainter *canvas, int x1, int y1, int x2, int y2, QColor color);

    int x1, y1;
    int x2, y2;
};



#endif // GRAFICOS_H
