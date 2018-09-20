#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPlainTextEdit>

class PlainTextEdit;
class QPushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

private slots:
    void on_input3DSelectBtn_clicked();
    void on_orthoInputSelectBtn_clicked();

private:
    QPlainTextEdit *textInputArea;
    QPushButton *renderBtn;
};

#endif // MAINWINDOW_H
