#ifndef SCALEDIALOG_H
#define SCALEDIALOG_H

#include <QDialog>
#include <QLineEdit>

class ScaleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ScaleDialog(QWidget *parent = 0);
    ~ScaleDialog();

private slots:
    void on_buttonBox_accepted();

private:
    QLineEdit *xLineEdit, *yLineEdit, *zLineEdit;
};

#endif // SCALEDIALOG_H
