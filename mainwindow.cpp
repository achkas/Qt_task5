#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    swatch = new Swatch(this);
    ui->Circle->setEnabled(0);
    connect(swatch->timer, &QTimer::timeout, this, &MainWindow::Mmtimer);    
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Mmtimer()
{   
    ui->Timelabel->setText(QString::number(swatch->getCurrenttime())+":"+QString::number(swatch->getCurrent_decsectime()));
}

void MainWindow::on_StartStop_clicked()
{
    swatch->StartStopwatch();
    ui->Circle->setDisabled(swatch->ss==1);
}

void MainWindow::on_Clear_clicked()
{
    swatch->ClireSignal();
    ui->Timelabel->setText(QString::number(0));
    ui->time_circle_output->clear();
}


void MainWindow::on_Circle_clicked()
{
    swatch->CirclSignal();
    ui->time_circle_output->append("Круг "+ QString::number(swatch->nl)+" время "+ QString::number(swatch->getLaptime())+"сек. ");    
}

