#include "rotatedialog.h"
#include "display.h"

#include <stdlib.h>
#include <iostream>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QDialogButtonBox>

RotateDialog::RotateDialog(QWidget *parent) : QDialog(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QHBoxLayout *layout1 = new QHBoxLayout();

    QLabel *angleLabel = new QLabel();
    angleLabel->setText("Angle of Rotation");

    angleLineEdit = new QLineEdit();
    angleLineEdit->setText("0.0");

    layout1->addWidget(angleLabel);
    layout1->addWidget(angleLineEdit);

    QHBoxLayout *layout2 = new QHBoxLayout();

    QLabel *directionLabel = new QLabel();
    directionLabel->setText("Direction Ratios");

    layout2->addWidget(directionLabel);

    QHBoxLayout *layout3 = new QHBoxLayout();

    QLabel *lLabel = new QLabel("l");
    lDirection = new QLineEdit();

    QLabel *mLabel = new QLabel("m");
    mDirection = new QLineEdit();

    QLabel *nLabel = new QLabel("n");
    nDirection = new QLineEdit();

    layout3->addWidget(lLabel);
    layout3->addWidget(lDirection);
    layout3->addWidget(mLabel);
    layout3->addWidget(mDirection);
    layout3->addWidget(nLabel);
    layout3->addWidget(nDirection);

    QDialogButtonBox *dialogBtnBox = new QDialogButtonBox((QDialogButtonBox::Ok | QDialogButtonBox::Cancel));

    connect(dialogBtnBox, SIGNAL(accepted()), this, SLOT(on_buttonBox_accepted()));
    connect(dialogBtnBox, SIGNAL(rejected()), this, SLOT(reject()));

    mainLayout->addLayout(layout1);
    mainLayout->addLayout(layout2);
    mainLayout->addLayout(layout3);
    mainLayout->addWidget(dialogBtnBox);
}

RotateDialog::~RotateDialog()
{
}

void RotateDialog::on_buttonBox_accepted()
{
    float theta = atof(this->angleLineEdit->text().toUtf8().constData());
    float l = atof(this->lDirection->text().toUtf8().constData());
    float m = atof(this->mDirection->text().toUtf8().constData());
    float n = atof(this->nDirection->text().toUtf8().constData());
    global_obj3D.rotate(theta,line(l,m,n));
    //std::cout<<"Rotate : "<<theta<<" "<<l<<" "<<m<<" "<<n<<std::endl;

    this->close();
}
