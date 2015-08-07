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
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::_newReview()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::_doGameReview()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->nmi_ref_text->setText("NMI-"+ui->customerNumber->text()+"-"+ui->projectNumber->text());
}

void MainWindow::_doRngReview()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::_changeLandFlag(bool flag)
{

    ui->onlineBox->setEnabled(!flag);
    ui->onlineBox->setVisible(!flag);
    ui->landBox->setEnabled(flag);
    ui->landBox->setVisible(flag);
}

void MainWindow::_autoFillDescription()
{
    QString typestr = ui->gameTypeCombo->currentText();
    if(typestr == "Slots"){
        //make a slots description dialogue
        slotsAutoDescribe* autodesc = new slotsAutoDescribe(this);

        //make it visible
        autodesc->show();

        //connect its output up to the 'setDescription' qt slot.
        connect(autodesc,SIGNAL(haveGenerated(QString)),this,SLOT(setDescription(QString)));

        return;
    }
    else{
        //just call the setDescription slot
    }


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

void MainWindow::setDescription(const QString& string)
{
    ui->gameDescription->setText(string);
}
