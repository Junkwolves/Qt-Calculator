#include "mainwindow.h"
#include "ui_mainwindow.h"

static double first_number;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->statusBar->showMessage("Pre-release. V 1.0  ");

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

    //-----------------------------------------------------------------

      connect(ui->plus,SIGNAL(clicked()),this,SLOT(calculations()));
      ui->plus->setCheckable(true);
      connect(ui->minus,SIGNAL(clicked()),this,SLOT(calculations()));
      ui->minus->setCheckable(true);
      connect(ui->divide,SIGNAL(clicked()),this,SLOT(calculations()));
      ui->divide->setCheckable(true);
      connect(ui->multiply,SIGNAL(clicked()),this,SLOT(calculations()));
      ui->multiply->setCheckable(true);

      //-----------------------------------------------------------------

      connect(ui->left_bracket,SIGNAL(clicked()),this,SLOT(calculations()));
      connect(ui->right_bracket,SIGNAL(clicked()),this,SLOT(calculations()));
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

void MainWindow::calculations()
{
    QPushButton *any_button = ( QPushButton *) sender();

    first_number = ui->result->text().toDouble();

    ui->result->setText("");

    ui->plus->setChecked(false);
    ui->minus->setChecked(false);
    ui->divide->setChecked(false);
    ui->multiply->setChecked(false);

    any_button->setChecked(true);

    if(ui->plus->isChecked())
    {
        ui->result->setText("+");
    }
    else if(ui->minus->isChecked())
    {
        ui->result->setText("-");
    }
    else if(ui->divide->isChecked())
    {
        ui->result->setText("/");
    }
    else if(ui->multiply->isChecked())
    {
        ui->result->setText("*");
    }
}

void MainWindow::on_dot_clicked()
{
    if(!(ui->result->text().contains('.')))
    ui->result->setText(ui->result->text() + ".");
}

void MainWindow::on_equally_clicked()
{

    double calculation_result; double second_number;

    QString st_convert;

    QString first; QString second;

    second_number = ui->result->text().toDouble();

    first = QString::number(first_number);

    second = QString::number(second_number);

    if(ui->plus->isChecked())
    {
        calculation_result = first_number + second_number;
        st_convert = QString::number(calculation_result, 'g', 12);
        ui->condition->setText(first + " + " + second + " = " + st_convert );

        ui->result->setText(st_convert);
        ui->plus->setChecked(false);
    }
    else if(ui->minus->isChecked())
    {
        calculation_result = first_number - second_number;
        st_convert = QString::number(calculation_result, 'g', 12);
        ui->condition->setText(first + " - " + second + " = " + st_convert);

        ui->result->setText(st_convert);
        ui->plus->setChecked(false);
    }
    else if(ui->divide->isChecked())
    {
        if(second_number == 0 || first_number == 0)
        {
            ui->result->setText("0");
        }
        else {
            calculation_result = first_number / second_number;
            st_convert = QString::number(calculation_result, 'g', 12);
            ui->condition->setText(first + " / " + second + " = " + st_convert);

            ui->result->setText(st_convert);
            ui->plus->setChecked(false);
        }
    }
    else if(ui->multiply->isChecked())
    {
        calculation_result = first_number * second_number;
        st_convert = QString::number(calculation_result, 'g', 12);
        ui->condition->setText(first + " * " + second + " = " + st_convert);

        ui->result->setText(st_convert);
        ui->plus->setChecked(false);
    }
}

void MainWindow::on_CE_clicked()
{
    ui->plus->setChecked(false);
    ui->minus->setChecked(false);
    ui->divide->setChecked(false);
    ui->multiply->setChecked(false);

    ui->result->setText("0");
    ui->condition->setText("");
}
