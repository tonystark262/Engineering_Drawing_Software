#ifndef TRANSLATEDIALOGT_H
#define TRANSLATEDIALOGT_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>

class TranslateDialogt : public QDialog
{
    Q_OBJECT

public:
    explicit TranslateDialogt(QWidget *parent = 0);
    ~TranslateDialogt();

private slots:
    void on_buttonBox_accepted();

private:
    QLineEdit *xLineEdit, *yLineEdit, *zLineEdit;
};

#endif // TRANSLATEDIALOGT_H
