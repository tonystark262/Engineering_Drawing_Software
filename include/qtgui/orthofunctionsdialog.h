#ifndef ORTHOFUNCTIONSDIALOG_H
#define ORTHOFUNCTIONSDIALOG_H

#include <QDialog>

class OrthoFunctionsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OrthoFunctionsDialog(QWidget *parent = 0);
    ~OrthoFunctionsDialog();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
};

#endif // ORTHOFUNCTIONSDIALOG_H
