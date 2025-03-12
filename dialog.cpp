#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushBtnSalir_clicked() {

}

void Dialog::paintEvent(QPaintEvent *event) {

    Q_UNUSED(event); // Evitar conflictos con el compilador
    dragon();
}

void Dialog::dragon() {  // representar a main

    QPainter canvas(this);

    // declarar e inicializar varaibles
    // int i;
    paso = 4096;
    signo = 1; //-1;

    ejeX[1] = canvas.window().width() / 4;
    ejeX[4097] = 3 * canvas.window().width() / 4;

    // ambos valores reciben el mismo valor
    ejeY[1]  = ejeY[4097] = 2 * canvas.window().height() / 3;

    // agregar color al dibujo por realizar
    canvas.setPen(QColor(QRandomGenerator::global()->bounded(50) + 200, QRandomGenerator::global()->bounded(101) + 155, 0));

    // -> Usar el generador de numeros aleatorios en QT

    QFont fuente = canvas.font();
    fuente.setPointSize(fuente.pointSize() * 2); // -> agrgar un size a la letra
    canvas.setFont(QFont("Ebrima", 22));

    // "titulo"
    canvas.drawText(this->width() / 8, 75, "Curva de fractal del Dragon");

    // dibujar una linea
    canvas.setPen(QColor(255,255,255));
    canvas.drawLine(ejeX[1], ejeY[1], ejeX[4097], ejeY[4097]);

    // obtener los valores de los ejes
    std::cout << "ejeX[1]: " << ejeX[1]<< std::endl;
    std::cout << "ejeY[1]: " << ejeY[1]<< std::endl;
    std::cout << "ejeX[4097]: " << ejeX[4097]<< std::endl;
    std::cout << "ejeY[4097]: " << ejeY[4097]<< std::endl;

    for(int i = 1; i <= 11; i++){

        canvas.setPen(QColor(0, QRandomGenerator::global()->bounded(101) + 155, 0)); // se va cambiar a un random generator
        generarDragon(&canvas);

        paso /= 2;
    }

}

void Dialog::generarDragon(QPainter *canvas) {

    int i, j, dx, dy;

    j = paso / 2;

    // canvas->setPen(QColor(50,50,200));

    for(i = 1; i <= 4096; i+= paso){
        dx = ejeX[paso + i] - ejeX[i];
        dy = ejeY[paso + i] - ejeY[i];

        signo *= -1;

        ejeX[i + j] = ejeX[i] + (dx + (dy * signo)) / 2;
        ejeY[i + j] = ejeY[i] + (dy - (dx * signo)) / 2;

        canvas->drawLine(ejeX[i], ejeY[i], ejeX[i + j], ejeY[i + j]);
        canvas->drawLine(ejeX[i + j], ejeY[i + j], ejeX[i + paso], ejeY[i + paso]);

    }

}


