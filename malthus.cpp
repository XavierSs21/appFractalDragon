#include "malthus.h"

malthus::malthus(QObject *parent)
    : QObject{parent}
{
    PobAnt = PobNueva = x = y = 0.0;
    Razon = 2.3;

    pasosActuales = 0;
    pasosMaximos = 15;

    escalaFactor = 1.0;
    expandiendo = true;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateAnimation()));
}

malthus::~malthus() { }

void malthus::dibujar(QPainter *canvas) {
    const int width = canvas->window().width();
    const int height = canvas->window().height();

    QFont fuente = canvas->font();
  
    fuente.setPointSize(fuente.pointSize() * 2);
    canvas->setFont(QFont("Ebrima", 22));
  
    canvas->setPen(QColor(155,75,75));
    canvas->drawText(10, 40, "Flujo maltusiano");

    for (int i = 1; i <= pasosActuales; i++) {
      
        for (int j = 1; j <= 10; j++) {
            y = 0.0;
            int contador = 0;

            Razon += 0.01;
            PobAnt = 0.01;

            int color = QColor::fromHsv((j * 17) % 360, 255, 255).rgb();
            canvas->setPen(QColor(color));

            for (int k = 1; k <= 1000; k++) {
                PobNueva = Razon * (PobAnt * (1 - PobAnt));
                x = PobNueva - PobAnt;

                const auto & newX = static_cast<int>((x * width / 2) * escalaFactor + width / 2);
                const auto & newY = static_cast<int>((height / 2) - (y * height / 2) * escalaFactor);

                canvas->drawPoint(newX, newY);

                if (std::abs(PobAnt - PobNueva) < 1e-6)
                    contador++;
                else
                    contador = 0;

                if (contador > 100)
                    break;

                PobAnt = PobNueva;
                y = x;
            }
        }
    }
}

void malthus::generarMalthus(QPainter *canvas) {
    dibujar(canvas);
}

void malthus::startAnimation() {
    pasosActuales = 0;
    timer->start(150);  // Puedes ajustar este valor si quieres más suavidad
}

void malthus::stopAnimation() {
    timer->stop();
}

void malthus::updateAnimation() {
    if (expandiendo) {
        escalaFactor += 0.01;
        if (pasosActuales < pasosMaximos)
            pasosActuales++;
        if (escalaFactor >= 1.2)
            expandiendo = false;
    } else {
        escalaFactor -= 0.01;
        if (pasosActuales > 1)
            pasosActuales--;
        else
            expandiendo = true;

        if (escalaFactor <= 0.8)
            expandiendo = true;
    }

    emit updateNeeded();
}
