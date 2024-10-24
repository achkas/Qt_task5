#ifndef SWATCH_H
#define SWATCH_H

#include <QObject>
#include <QTimer>

class Swatch : public QObject
{
    Q_OBJECT
public:
    explicit Swatch(QObject *parent = nullptr);
    ~Swatch();

    bool ss=1;
    int nl=0;
    QTimer *timer;
    void StartStopwatch();
    void CirclSignal();
    void ClireSignal();
    int getLaptime();
    int getCurrenttime();    
    int getCurrent_decsectime();

private:   
    int s=0;
    int ls,lm;
    int lms=0;
    int msec;
    int dec_sec;

public slots:
    void strttimer();

signals:
    void sgnl();
};

#endif // SWATCH_H
