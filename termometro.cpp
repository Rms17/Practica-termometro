#include "termometro.h"
#include "ui_termometro.h"
#include <QDebug>

Termometro::Termometro(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Termometro)
{
    ui->setupUi(this);

    //-
    connect(ui->dialCent, SIGNAL(valueChanged(int)),
              this, SLOT(cent2Fahr(int)));
    connect(ui->dialFahr, SIGNAL(valueChanged(int)),
              this, SLOT(fahr2Cent(int)));

    connect(ui->dialCent, SIGNAL(sliderPressed()),
              this, SLOT(dialPresionado()));
    connect(ui->dialFahr, SIGNAL(sliderPressed()),
              this, SLOT(dialPresionado()));

    connect(ui->dialCent, SIGNAL(sliderReleased()),
              this, SLOT(dialRelajado()));
    connect(ui->dialFahr, SIGNAL(sliderReleased()),
              this, SLOT(dialRelajado()));


    //*
    connect(ui->dialCent2, SIGNAL(valueChanged(int)),
              this, SLOT(centi2Kelv(int)));
    connect(ui->dialKelvin, SIGNAL(valueChanged(int)),
              this, SLOT(kelv2Cent(int)));


    connect(ui->dialCent2, SIGNAL(sliderPressed()),
              this, SLOT(dialPresionado()));
    connect(ui->dialKelvin, SIGNAL(sliderPressed()),
              this, SLOT(dialPresionado()));


    connect(ui->dialCent2, SIGNAL(sliderReleased()),
              this, SLOT(dialRelajado()));
    connect(ui->dialKelvin, SIGNAL(sliderReleased()),
              this, SLOT(dialRelajado()));
    //*

    connect(ui->dialFahr2, SIGNAL(valueChanged(int)),
              this, SLOT(fahren2Kelvin(int)));
    connect(ui->dialKel2, SIGNAL(valueChanged(int)),
              this, SLOT(kelvin2Fahren(int)));


    connect(ui->dialFahr2, SIGNAL(sliderPressed()),
              this, SLOT(dialPresionado()));
    connect(ui->dialKel2, SIGNAL(sliderPressed()),
              this, SLOT(dialPresionado()));


    connect(ui->dialFahr2, SIGNAL(sliderReleased()),
              this, SLOT(dialRelajado()));
    connect(ui->dialKel2, SIGNAL(sliderReleased()),
              this, SLOT(dialRelajado()));



    ui->dialFahr->setValue(32); // seteamos un valor en mi construtor para que el programa no tenga bugs

    ui->dialKelvin->setValue(273);

    ui->dialKel2->setValue(255);

}

Termometro::~Termometro()
{
    delete ui;
}
//*
float Termometro::cent2Fahr(int valor)
{
   if (ui->dialCent->hasFocus()){
    float f=valor * 9.0/ 5 + 32;
    ui->dialFahr->setValue(f);
    return f;
   }
    return 0;
}

float Termometro::fahr2Cent(int valor)
{
   if (ui->dialFahr->hasFocus()){
    float c = (valor -32) * 5.0/9;
    ui->dialCent->setValue(c);
    return c;
   }
   return 0;
}

float Termometro::centi2Kelv(int valor)
{
    if (ui->dialCent2->hasFocus()){
     float k=valor * 273.15;
     ui->dialKelvin->setValue(k);
     return k;
    }
    return 0;
}

float Termometro::kelv2Cent(int valor)
{
    if (ui->dialKelvin->hasFocus()){
     float c=valor -273.15;
     ui->dialCent2->setValue(c);
     return c;
    }
    return 0;
}

float Termometro::fahren2Kelvin(int valor)
{
    if (ui->dialFahr2->hasFocus()){
    float k= ((valor-32)* 5)/ (9+273);
     ui->dialKel2->setValue(k);
     return k;
    }
     return 0;
}

float Termometro::kelvin2Fahren(int valor)
{
    if (ui->dialKel2->hasFocus()){
     float f= ((valor-273)* 9)/5 + 32;
     ui->dialFahr2->setValue(f);
     return f;
    }
     return 0;
}


void  Termometro::dialPresionado()
{
    //if (ui->dialCent->hasFocus()){
     ui->dialCent->setCursor(Qt::ClosedHandCursor);
     ui->dialFahr->setCursor(Qt::ClosedHandCursor);

     ui->dialCent2->setCursor(Qt::ClosedHandCursor);
     ui->dialKelvin->setCursor(Qt::ClosedHandCursor);

     ui->dialFahr2->setCursor(Qt::ClosedHandCursor);
     ui->dialKel2->setCursor(Qt::ClosedHandCursor);
}

void  Termometro::dialRelajado()
{
     ui->dialCent->setCursor(Qt::ArrowCursor);
     ui->dialFahr->setCursor(Qt::ArrowCursor);

     ui->dialCent2->setCursor(Qt::ArrowCursor);
     ui->dialKelvin->setCursor(Qt::ArrowCursor);

     ui->dialFahr2->setCursor(Qt::ArrowCursor);
     ui->dialKel2->setCursor(Qt::ArrowCursor);
}





