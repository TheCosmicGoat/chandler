#ifndef SLOTSAUTODESCRIBE_H
#define SLOTSAUTODESCRIBE_H

#include <QDialog>
#include <QDebug>


namespace Ui {
class slotsAutoDescribe;
}

class slotsAutoDescribe : public QDialog
{
    Q_OBJECT

public:
    explicit slotsAutoDescribe(QWidget *parent = 0);
    ~slotsAutoDescribe();

public slots:
    void accept();

private:
    Ui::slotsAutoDescribe *ui;

signals:
    void haveGenerated(const QString& str);
};

#endif // SLOTSAUTODESCRIBE_H
