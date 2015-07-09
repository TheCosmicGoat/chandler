#ifndef CODEEDITOR_H
#define CODEEDITOR_H

#include <QPlainTextEdit>
#include <QPainter>
#include <QTextBlock>



class CodeEditor : public QPlainTextEdit
{
    Q_OBJECT

public:
    CodeEditor(QWidget *parent = 0);

    void lineNumberAreaPaintEvent(QPaintEvent *event);
    int lineNumberAreaWidth();

protected:
    void resizeEvent(QResizeEvent *event);

private slots:
    void updateLineNumberAreaWidth(int newBlockCount);
    void highlightCurrentLine();
    void updateLineNumberArea(const QRect &, int);

private:
    QWidget* _lineNumberWidget;
};

class LineNumberWidget : public QWidget
{
public:
    explicit LineNumberWidget(CodeEditor *editor):
        QWidget(editor)
    {
        _codeEditor = editor;
    }

    QSize sizeHint() const
    {
        return QSize(_codeEditor->lineNumberAreaWidth(),0);
    }


protected:
    void paintEvent(QPaintEvent* event)
    {
        _codeEditor->lineNumberAreaPaintEvent(event);
    }

private:
    CodeEditor* _codeEditor;
};


#endif
