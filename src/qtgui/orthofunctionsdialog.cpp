#include "orthofunctionsdialog.h"
#include "object3dfunctionswindow.h"
#include"display.h"

OrthoFunctionsDialog::OrthoFunctionsDialog(QWidget *parent) : QDialog(parent)
{
    this->resize(300,400);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QPushButton *reconstructBtn = new QPushButton();
    reconstructBtn->setText("Reconstruct 3D Object");

    QPushButton *renderOrthoBtn = new QPushButton();
    renderOrthoBtn->setText("Render Orthographic Projections");

    connect(reconstructBtn, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
    connect(renderOrthoBtn, SIGNAL(clicked()), this, SLOT(on_pushButton_2_clicked()));

    mainLayout->addWidget(reconstructBtn);
    mainLayout->addWidget(renderOrthoBtn);
}

OrthoFunctionsDialog::~OrthoFunctionsDialog()
{
}

void OrthoFunctionsDialog::on_pushButton_clicked()
{
    global_obj3D=object3D(global_orthoObj);
    this->hide();
    object3DFunctionsWindow obj3DWindow;
    obj3DWindow.setModal(true);
    obj3DWindow.exec();
}

void OrthoFunctionsDialog::on_pushButton_2_clicked()
{
    // render orthographic
    makeOrthographic(global_orthoObj);
}
