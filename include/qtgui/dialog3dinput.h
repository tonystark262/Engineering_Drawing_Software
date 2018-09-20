#ifndef DIALOG3DINPUT_H
#define DIALOG3DINPUT_H

#include <QDialog>
#include <QTextBrowser>
#include <QPlainTextEdit>


class Dialog3DInput : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog3DInput(QWidget *parent = 0);
    ~Dialog3DInput();
private slots:
    void on_pushButton_clicked();

    void on_proceed3DBtn_clicked();

    void on_proceedFileBtn_clicked();

private:

	QTextBrowser *fileNameDisplay;
    QPlainTextEdit *interactiveInputTextEdit;
};

#endif // DIALOG3DINPUT_H
