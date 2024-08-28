#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<swatch.h>
//#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void Mmtimer();
    void Clear();
    void Circle();

signals:

private slots:
    void on_StartStop_clicked();
    void on_Clear_clicked();
    void on_Circle_clicked();

private:
    Ui::MainWindow *ui;
    Swatch *swatch;

};
#endif // MAINWINDOW_H
