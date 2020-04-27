#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QRandomGenerator>
#include <QStatusBar>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Run_butt_clicked()
{
    int CNMTAVG = 0; // CountNumberMoreThanAVG
    // Get the size for tables
    int height = ui->height->text().toInt();
    int weight = ui->weight->text().toInt();

    //Get tables
    QTableWidget *Gen = ui->Gen_mat;
    QTableWidget *AVG = ui->AVG_mat;
    QTableWidget *Res = ui->Result_mat;

    //Set the size for tables:

    Gen->setEnabled(true); // Generated matrix
    Gen->setRowCount(height);
    Gen->setColumnCount(weight);


    Res->setEnabled(true); // Result matrix
    Res->setRowCount(height);
    Res->setColumnCount(weight);

    AVG->setEnabled(true);   // AVG matrix
    AVG->setRowCount(height);
    AVG->setColumnCount(1);

    // Get&Calc loop

    for(int i = 0; i < height; i++)
    {
        int sum = 0;
        for(int j = 0; j < weight; j++)
        {
              int rand = QRandomGenerator::global()->bounded(0, 10);
              QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg(rand));
              Gen->setItem(i, j, newItem);
              sum += rand;
        }
        int avg = sum / weight;
        QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg(avg));
        AVG->setItem(i, 0, newItem);
    }

    // fill result matrix
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < weight; j++)
        {
            QTableWidgetItem *GenItem = Gen->item(i, j);
            QString GenQS = GenItem->text();
            QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg(GenQS));
            QTableWidgetItem *AVGItem = AVG->item(i, 0);
            Res->setItem(i, j, newItem);
            if(QString(GenItem->text()).toInt() > QString(AVGItem->text()).toInt())
            {
                QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg("0"));
                Res->setItem(i, j, newItem);
                CNMTAVG ++;
            }
        }
    }
    auto barMessage = QStringLiteral("Powered by Rutukute | CNMTAVG = %1").arg(CNMTAVG);
    ui->statusbar->showMessage(barMessage);

}

void MainWindow::on_info_butt_clicked()
{
    QMessageBox::information(this, "Завдання до лабораторної роботи,","17.	Знайти кількість елементів, що перевищують значення середнього арифметичного елементів масиву. Вивести на екран вихідний масив і новий, в якому такі елементи замінено нулями.");

}
