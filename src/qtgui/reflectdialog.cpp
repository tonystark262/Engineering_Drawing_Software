#include "reflectdialog.h"
#include "display.h"

#include <stdlib.h>
#include <iostream>

#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDialogButtonBox>

ReflectDialog::ReflectDialog(QWidget *parent) : QDialog(parent){
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QHBoxLayout *layout1 = new QHBoxLayout();
    QLabel *headingLabel = new QLabel("Enter Plane Equation Ax + By + Cz + D = 0");
    layout1->addWidget(headingLabel);

    QHBoxLayout *layout2 = new QHBoxLayout();
    QHBoxLayout *layout3 = new QHBoxLayout();

    QLabel *aLabel = new QLabel("A : ");
    QLabel *bLabel = new QLabel("B : ");
    QLabel *cLabel = new QLabel("C : ");
    QLabel *dLabel = new QLabel("D : ");

    aLineEdit = new QLineEdit("0.0");
    bLineEdit = new QLineEdit("0.0");
    cLineEdit = new QLineEdit("0.0");
    dLineEdit = new QLineEdit("0.0");

    layout2->addWidget(aLabel);
    layout2->addWidget(aLineEdit);
    layout2->addWidget(bLabel);
    layout2->addWidget(bLineEdit);

    layout3->addWidget(cLabel);
    layout3->addWidget(cLineEdit);
    layout3->addWidget(dLabel);
    layout3->addWidget(dLineEdit);

    QDialogButtonBox *dialogBtnBox = new QDialogButtonBox((QDialogButtonBox::Ok | QDialogButtonBox::Cancel));

    connect(dialogBtnBox, SIGNAL(accepted()), this, SLOT(on_buttonBox_accepted()));
    connect(dialogBtnBox, SIGNAL(rejected()), this, SLOT(reject()));

    mainLayout->addLayout(layout1);
    mainLayout->addLayout(layout2);
    mainLayout->addLayout(layout3);
    mainLayout->addWidget(dialogBtnBox);

}

ReflectDialog::~ReflectDialog()
{
    delete aLineEdit;
    delete bLineEdit;
    delete cLineEdit;
    delete dLineEdit;
}

void ReflectDialog::on_buttonBox_accepted()
{
    float a = atof(this->aLineEdit->text().toUtf8().constData());
    float b = atof(this->bLineEdit->text().toUtf8().constData());
    float c = atof(this->cLineEdit->text().toUtf8().constData());
    float d = atof(this->dLineEdit->text().toUtf8().constData());
    global_obj3D.reflect(plane(a, b, c, d));
    //std::cout<<"Reflect : "<<a<<" "<<b<<" "<<c<<" "<<d<<std::endl;

    this->close();
}
