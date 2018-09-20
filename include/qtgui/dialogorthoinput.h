#ifndef DIALOGORTHOINPUT_H
#define DIALOGORTHOINPUT_H

#include <QDialog>
#include <QTextBrowser>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QPushButton>
#include <QPlainTextEdit>

class dialogOrthoInput : public QDialog
{
    Q_OBJECT

public:
    explicit dialogOrthoInput(QWidget *parent = 0);
    ~dialogOrthoInput();

private slots:
    void on_openFileOrthoBtn_clicked();

    void on_proceedOrthoFileBtn_clicked();

    void on_proceedOrthoBtn_clicked();

private:
    QTextBrowser *fileNameDisplay;
    QPlainTextEdit *interactiveInputTextEdit;
};

#endif // DIALOGORTHOINPUT_H
