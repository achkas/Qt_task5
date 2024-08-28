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

    QTimer *timer;

    int s=0;
    bool ss=1;
    int ls,lm;
    int nl=0;
    int lms=0;

    void SendSignal();
    void CirclSignal();
    void ClireSignal();

public slots:
    void strttimer();

signals:
void sgnl();
void sig_circl();
void sig_clire();

};

#endif // SWATCH_H
