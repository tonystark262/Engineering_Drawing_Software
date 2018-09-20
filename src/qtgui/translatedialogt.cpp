#include "translatedialogt.h"

#include <stdlib.h>
#include <iostream>
#include"display.h"

#include <QPushButton>
#include <QDialogButtonBox>

TranslateDialogt::TranslateDialogt(QWidget *parent) : QDialog(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QHBoxLayout *layout1 = new QHBoxLayout();

    QLabel *xLabel = new QLabel();
    xLabel->setText(tr("Translate in X : "));

    xLineEdit = new QLineEdit();
    xLineEdit->setText("0.0");

    layout1->addWidget(xLabel);
    layout1->addWidget(xLineEdit);

    QHBoxLayout *layout2 = new QHBoxLayout();

    QLabel *yLabel = new QLabel();
    yLabel->setText(tr("Translate in Y : "));

    yLineEdit = new QLineEdit();
    yLineEdit->setText("0.0");

    layout2->addWidget(yLabel);
    layout2->addWidget(yLineEdit);

    QHBoxLayout *layout3 = new QHBoxLayout();

    QLabel *zLabel = new QLabel();
    zLabel->setText(tr("Translate in Z : "));

    zLineEdit = new QLineEdit();
    zLineEdit->setText("0.0");

    layout3->addWidget(zLabel);
    layout3->addWidget(zLineEdit);

    mainLayout->addLayout(layout1);
    mainLayout->addLayout(layout2);
    mainLayout->addLayout(layout3);

    QDialogButtonBox *dialogBtnBox = new QDialogButtonBox((QDialogButtonBox::Ok | QDialogButtonBox::Cancel));

    connect(dialogBtnBox, SIGNAL(accepted()), this, SLOT(on_buttonBox_accepted()));
    connect(dialogBtnBox, SIGNAL(rejected()), this, SLOT(reject()));

    mainLayout->addWidget(dialogBtnBox);
}

TranslateDialogt::~TranslateDialogt()
{
}

void TranslateDialogt::on_buttonBox_accepted()
{
    float transX = atof(this->xLineEdit->text().toUtf8().constData());
    float transY = atof(this->yLineEdit->text().toUtf8().constData());
    float transZ = atof(this->zLineEdit->text().toUtf8().constData());
    global_obj3D.translate(transX,transY,transZ);
    //std::cout<<"Translate : "<<transX<<" "<<transY<<" "<<transZ<<std::endl;

    this->close();
}
