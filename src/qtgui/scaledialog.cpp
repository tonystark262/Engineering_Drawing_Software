#include "scaledialog.h"

#include <stdlib.h>
#include <iostream>
#include "display.h"

#include <QDialogButtonBox>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

ScaleDialog::ScaleDialog(QWidget *parent) : QDialog(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QHBoxLayout *layout1 = new QHBoxLayout();

    QLabel *xLabel = new QLabel();
    xLabel->setText(tr("Scale in X : "));

    xLineEdit = new QLineEdit();
    xLineEdit->setText("1.0");

    layout1->addWidget(xLabel);
    layout1->addWidget(xLineEdit);

    QHBoxLayout *layout2 = new QHBoxLayout();

    QLabel *yLabel = new QLabel();
    yLabel->setText(tr("Scale in Y : "));

    yLineEdit = new QLineEdit();
    yLineEdit->setText("1.0");

    layout2->addWidget(yLabel);
    layout2->addWidget(yLineEdit);

    QHBoxLayout *layout3 = new QHBoxLayout();

    QLabel *zLabel = new QLabel();
    zLabel->setText(tr("Scale in Z : "));

    zLineEdit = new QLineEdit();
    zLineEdit->setText("1.0");

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

ScaleDialog::~ScaleDialog()
{
}

void ScaleDialog::on_buttonBox_accepted()
{
    float scaleX = atof(this->xLineEdit->text().toUtf8().constData());
    float scaleY = atof(this->yLineEdit->text().toUtf8().constData());
    float scaleZ = atof(this->zLineEdit->text().toUtf8().constData());
    global_obj3D.scale(scaleX,scaleY,scaleZ);
    //std::cout<<"Scale : "<<scaleX<<" "<<scaleY<<" "<<scaleZ<<std::endl;

    this->close();
}
