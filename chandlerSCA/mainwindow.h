#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "slotsautodescribe.h"
#include "highlighter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Highlighter* _highlighter;

private slots:
    void _newReview();
    void _doGameReview();
    void _doRngReview();
    void _changeLandFlag(bool flag);
    void _autoFillDescription();

public slots:
    void fileMenu(QAction *action);
    void setDescription(const QString& string);

};

#endif // MAINWINDOW_H
