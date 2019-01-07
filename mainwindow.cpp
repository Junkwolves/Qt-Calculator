#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->zero,SIGNAL(clicked()),this,SLOT(number_check()));
    connect(ui->one,SIGNAL(clicked()),this,SLOT(number_check()));
    connect(ui->two,SIGNAL(clicked()),this,SLOT(number_check()));
    connect(ui->three,SIGNAL(clicked()),this,SLOT(number_check()));
    connect(ui->four,SIGNAL(clicked()),this,SLOT(number_check()));
    connect(ui->five,SIGNAL(clicked()),this,SLOT(number_check()));
    connect(ui->six,SIGNAL(clicked()),this,SLOT(number_check()));
    connect(ui->seven,SIGNAL(clicked()),this,SLOT(number_check()));
    connect(ui->eight,SIGNAL(clicked()),this,SLOT(number_check()));
    connect(ui->nine,SIGNAL(clicked()),this,SLOT(number_check()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::number_check()
{
    QPushButton *any_button = (QPushButton *) sender();

    double storing_numbers;

    QString st_convert;

    storing_numbers = (ui->result->text() + any_button->text()).toDouble();

    st_convert = QString::number(storing_numbers, 'g', 12);

    ui->result->setText(st_convert);
}

void MainWindow::on_dot_clicked()
{
    if(!(ui->result->text().contains('.')))
    ui->result->setText(ui->result->text() + ".");
}
