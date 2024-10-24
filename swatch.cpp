#include "swatch.h"
#include<QDebug>

Swatch::Swatch(QObject *parent)
    : QObject{parent}
{
    timer=new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Swatch::strttimer);
}

Swatch::~Swatch(){}

void Swatch::StartStopwatch()
{    
    emit sgnl();

    ss=!ss;

    if(ss==1)
    {
        timer->stop();
    }

    if(ss==0)
    {
        timer->start(1);
    }

}

void Swatch::CirclSignal()
{
    nl++;
    ls=s;
    lm=ls-lms;
    lms=ls;
}

void Swatch::ClireSignal()
{
    s=0;
    nl=0;
    lms=0;
}

int Swatch::getLaptime()
{
    return lm;
}

int Swatch::getCurrenttime()
{
    return s;
}

int Swatch::getCurrent_decsectime()
{
    return dec_sec;
}

void Swatch::strttimer()
{
    msec++;

    if (msec>=100)
    {
        msec=0;
        dec_sec++;
    }

    if(dec_sec>=10)
    {
        dec_sec=0;
        s++;
    }
}





