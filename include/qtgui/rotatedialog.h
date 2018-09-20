#ifndef ROTATEDIALOG_H
#define ROTATEDIALOG_H

#include <QDialog>
#include <QLineEdit>

class RotateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RotateDialog(QWidget *parent = 0);
    ~RotateDialog();

private slots:
    void on_buttonBox_accepted();

private:
    QLineEdit *angleLineEdit, *lDirection, *mDirection, *nDirection;
};

#endif // ROTATEDIALOG_H
