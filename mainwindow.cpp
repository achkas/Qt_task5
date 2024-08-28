#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    swatch=new Swatch(this);
    ui->Circle->setEnabled(0);

    connect(swatch->timer,SIGNAL(timeout()),this,SLOT(Mmtimer()));    
    connect(swatch,&Swatch::sig_circl,this,&MainWindow::Circle);
    connect(swatch,&Swatch::sig_clire,this,&MainWindow::Clear);

}

MainWindow::~MainWindow()
{
    delete ui;    
}

void MainWindow::Mmtimer()
{
    ui->Timelabel->setText(QString::number(swatch->s));    
}

void MainWindow::Clear()
{
    ui->Timelabel->setText(QString::number(0));
    ui->textBrowser->clear();
}

void MainWindow::Circle()
{
ui->textBrowser->append("Круг "+ QString::number(swatch->nl)+" время "+ QString::number(swatch->lm)+"сек. ");
}

void MainWindow::on_StartStop_clicked()
{
    swatch->SendSignal();    
   ui->Circle->setDisabled(swatch->ss==1);

}

void MainWindow::on_Clear_clicked()
{
    swatch->ClireSignal();
}


void MainWindow::on_Circle_clicked()
{
   swatch->CirclSignal();
}

