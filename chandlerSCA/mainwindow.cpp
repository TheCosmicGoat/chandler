#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QFileDialog"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _highlighter()
{
    ui->setupUi(this);
    ui->plainTextEdit->setPlainText("Hello");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fileMenu(QAction *action)
{
    if(action->text() == "Open"){
        QString filename = QFileDialog::getOpenFileName(this,tr("Open Source File"), "/home/guy/svn", tr("Source (*.cpp *.h *.java)"));
        if(filename!=""){
            QFile file(filename);
            file.open(QIODevice::ReadOnly);
            ui->plainTextEdit->setPlainText(file.readAll());
            _highlighter = new Highlighter(ui->plainTextEdit->document());
            ui->statusBar->showMessage("File: "+filename);
        }
    }
}
