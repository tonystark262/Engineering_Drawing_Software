#include "object3dfunctionswindow.h"
#include "scaledialog.h"
#include "translatedialogt.h"
#include "rotatedialog.h"
#include "projectiondialog.h"
#include "reflectdialog.h"
#include "orthofunctionsdialog.h"
#include "object3D.h"
#include "display.h"

object3DFunctionsWindow::object3DFunctionsWindow(QWidget *parent) : QDialog(parent)
{
    this->resize(600, 300);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QHBoxLayout *layout1 = new QHBoxLayout();

    QPushButton *translateBtn = new QPushButton("Translate");
    QPushButton *scaleBtn = new QPushButton("Scale");
    QPushButton *rotateBtn = new QPushButton("Rotate");
    QPushButton *projectBtn = new QPushButton("Project");
    QPushButton *reflectBtn = new QPushButton("Reflect");

    connect(translateBtn, SIGNAL(clicked(bool)), this, SLOT(on_translateBtn_clicked()));
    connect(scaleBtn, SIGNAL(clicked(bool)), this, SLOT(on_scaleBtn_clicked()));
    connect(rotateBtn, SIGNAL(clicked(bool)), this, SLOT(on_rotateBtn_clicked()));
    connect(projectBtn, SIGNAL(clicked(bool)), this, SLOT(on_planeProjectBtn_clicked()));
    connect(reflectBtn, SIGNAL(clicked(bool)), this, SLOT(on_reflectBtn_clicked()));

    layout1->addWidget(translateBtn);
    layout1->addWidget(scaleBtn);
    layout1->addWidget(rotateBtn);
    layout1->addWidget(projectBtn);
    layout1->addWidget(reflectBtn);

    QHBoxLayout *layout2 = new QHBoxLayout();

    QPushButton *orthographicBtn = new QPushButton("OrthoGraphic");
    QPushButton *isometricBtn = new QPushButton("Isometric");

    connect(orthographicBtn, SIGNAL(clicked(bool)), this, SLOT(on_orthographic3DBtn_clicked()));
    connect(isometricBtn, SIGNAL(clicked(bool)), this, SLOT(on_isometric3DBtn_clicked()));

    layout2->addWidget(orthographicBtn);
    layout2->addWidget(isometricBtn);

    QHBoxLayout *layout3 = new QHBoxLayout();

    QPushButton *renderWireFrameBtn = new QPushButton("Render WireFrame");
    QPushButton *render3DSolidBtn = new QPushButton("Render Solid Model");

    connect(renderWireFrameBtn, SIGNAL(clicked(bool)), this, SLOT(on_renderBtn_clicked()));
    connect(render3DSolidBtn, SIGNAL(clicked(bool)), this, SLOT(on_renderSolidBtn_clicked()));

    layout3->addWidget(renderWireFrameBtn);
    layout3->addWidget(render3DSolidBtn);

    mainLayout->addLayout(layout1);
    mainLayout->addLayout(layout2);
    mainLayout->addLayout(layout3);

}

object3DFunctionsWindow::~object3DFunctionsWindow()
{
}

void object3DFunctionsWindow::on_scaleBtn_clicked() {
    ScaleDialog scaleDialog;
    scaleDialog.setModal(true);
    scaleDialog.exec();
}

void object3DFunctionsWindow::on_translateBtn_clicked() {
    TranslateDialogt transDialog;
    transDialog.setModal(true);
    transDialog.exec();
}

void object3DFunctionsWindow::on_rotateBtn_clicked()
{
    RotateDialog rotateDialog;
    rotateDialog.setModal(true);
    rotateDialog.exec();
}

void object3DFunctionsWindow::on_planeProjectBtn_clicked()
{
    ProjectionDialog projectionDialog;
    projectionDialog.setModal(true);
    projectionDialog.exec();

    // makeWireFrame(global_obj2D);
}

void object3DFunctionsWindow::on_reflectBtn_clicked()
{
    ReflectDialog reflectDialog;
    reflectDialog.setModal(true);
    reflectDialog.exec();
}

void object3DFunctionsWindow::on_orthographic3DBtn_clicked()
{
    //display orthographic projections
    global_orthoObj=global_obj3D.orthographic_projection();
    this->hide();
    OrthoFunctionsDialog orthoDialog;
    orthoDialog.setModal(true);
    orthoDialog.exec();
}

void object3DFunctionsWindow::on_isometric3DBtn_clicked()
{
//     // display isometric projection
    makeIsometric(global_obj3D.isometric_projection());
}

void object3DFunctionsWindow::on_renderBtn_clicked()
{
//     // render the object
    makeWireFrame(global_obj3D);
}

void object3DFunctionsWindow::on_renderSolidBtn_clicked()
{
    makeSolid(global_obj3D);
}
