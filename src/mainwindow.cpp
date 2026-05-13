#include "mainwindow.h"
#include "coderunner.h"
#include "./ui_mainwindow.h"
#include <QFile>
#include "cpphighlighter.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    // prevents typying in outuput label
    ui->outputLabel->setReadOnly(true);

    // adds problems
    ui->problemList->addItem("Sum of two numbers");
    ui->problemList->addItem("Division of two numbers");


    // automatically selects the 1 task
    ui->problemList->setCurrentRow(0);

    QFile file("main.cpp");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    file.close();

    new CppHighlighter(ui->plainTextEdit->document());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_runButton_clicked()
{
    CodeRunner runner;
    QString code = ui->plainTextEdit->toPlainText();

    QString result = runner.compileAndRun(code);

    ui->outputLabel->setPlainText(result);
}


void MainWindow::on_problemList_currentRowChanged(int currentRow)
{
    QString currentTaskLabel = ui->problemList->item(currentRow)->text();
    ui->label->setText("Current task: " + currentTaskLabel);
    switch(currentRow){
    case 0:
        ui->plainTextEdit->setPlainText(R"(#include <iostream>
int main() {
    int number1 = 5;
    int number2 = 10;
    std::cout << number1+number2;
    return 0;
})");
        break;
    case 1:
        ui->plainTextEdit->setPlainText(R"(#include <iostream>
int main() {
    int number1 = 10;
    int number2 = 2;
    std::cout << number1 / number2;
    return 0;
})");
        break;
    }
}

