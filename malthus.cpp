#include "malthus.h"

malthus::malthus(QObject *parent)
    : QObject{parent}
{
    PobAnt = PobNueva = 0.0;
    Razon = 2.3;
    x = y = 0;
}

void malthus::dibujar(QPainter *canvas) {

    const int width = canvas->window().width();
    const int height = canvas->window().height();

    QFont fuente = canvas->font();

    fuente.setPointSize(fuente.pointSize() * 2); // -> agrgar un size a la letra
    canvas->setFont(QFont("Ebrima", 22));
    canvas->drawText(10, 40, "Flujo maltusiano");

    int contador = 0;

    canvas->setPen(QColor(186, 43, 26));

    for(int i = 1; i <= 15; i++){

        for(int j = 1; j <= 10; j++){
            Razon += 0.01;
            PobAnt = 0.01;
            for (int k = 1; k <= 1000; i++){
                PobNueva = Razon * ( PobAnt * ( 1 - PobAnt ) );
                x = PobNueva - PobAnt;
                const auto & newX = x * width / 2;
                const auto & newY = ( height / 2 ) - ( y * height / 2 );
                canvas->drawPoint( newX, newY );
                if( PobAnt == PobNueva )
                    contador++;
                else
                    contador = 0;
                if ( contador > 100 )
                    i = 10000;

                PobAnt = PobNueva;
                y = x;
            }
        }

    }

}
