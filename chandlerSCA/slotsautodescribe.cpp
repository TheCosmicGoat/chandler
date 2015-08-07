#include "slotsautodescribe.h"
#include "ui_slotsautodescribe.h"

slotsAutoDescribe::slotsAutoDescribe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::slotsAutoDescribe)
{
    ui->setupUi(this);
}

slotsAutoDescribe::~slotsAutoDescribe()
{
    delete ui;
}

void slotsAutoDescribe::accept()
{
    //calls the signal
    QString header ("* This is a slots (reels) type game\n");
    QString reeldesc (" - The reel dimesions are "+ui->reelNumSB->text()+"x"+ui->reelHieghtSB->text()+"\n");
    QString paylinedesc (" - There are "+ui->payLineNumSB->text()+" winning lines");
    if(ui->evaluationCB->currentText() == "Left To Right") paylinedesc.append(" evaluated from left to right");
    if(ui->evaluationCB->currentText() == "Right To Left") paylinedesc.append(" evaluated from right to left");
    if(ui->evaluationCB->currentText() == "Both Directions") paylinedesc.append(" evaluated in both directions");
    paylinedesc.append("\n");
    QString extradesc;
    if(ui->expandingWildsX->isChecked()) extradesc.append(" - This game has expanding wilds\n");
    if(ui->transWildsX->isChecked()) extradesc.append(" - This game has transparent wilds\n");
    if(ui->roamingWildsX->isChecked()) extradesc.append(" - This game has roaming wilds\n");
    if(ui->stickyWildsX->isChecked()) extradesc.append(" - This game has sticky wilds\n");
    if(ui->wildsPayX->isChecked()) extradesc.append(" - Wilds pay in this game\n");
    haveGenerated(header+reeldesc+paylinedesc+extradesc);
    this->close();
}
