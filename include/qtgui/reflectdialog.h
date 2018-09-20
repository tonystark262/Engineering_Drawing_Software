#ifndef REFLECTDIALOG_H
#define REFLECTDIALOG_H

#include <QDialog>
#include <QLineEdit>

class ReflectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReflectDialog(QWidget *parent = 0);
    ~ReflectDialog();

private slots:
    void on_buttonBox_accepted();

private:
    QLineEdit *aLineEdit, *bLineEdit, *cLineEdit, *dLineEdit;
};

#endif // REFLECTDIALOG_H
