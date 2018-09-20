#ifndef PROJECTIONDIALOG_H
#define PROJECTIONDIALOG_H

#include <QDialog>
#include <QLineEdit>


class ProjectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProjectionDialog(QWidget *parent = 0);
    ~ProjectionDialog();

private slots:
    void on_buttonBox_accepted();

private:
    QLineEdit *aLineEdit, *bLineEdit, *cLineEdit, *dLineEdit;

};

#endif // PROJECTIONDIALOG_H
