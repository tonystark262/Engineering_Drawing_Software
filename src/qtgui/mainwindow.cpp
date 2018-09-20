#include "mainwindow.h"
#include "dialog3dinput.h"
#include "dialogorthoinput.h"

#include <QMenuBar>
#include <QMenu>
#include <QPlainTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QKeyEvent>
#include <QPushButton>
#include <QDesktopWidget>
#include <QApplication>

#include <string>
#include <fstream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->resize(800, 800);

    QWidget *wdg = new QWidget(this);
    QHBoxLayout *vLayout = new QHBoxLayout(wdg);
    QPushButton *input3DSelectBtn = new QPushButton("3D Input");
    QPushButton *orthoSelectBtn = new QPushButton("Orthographic Input");

    vLayout->addWidget(input3DSelectBtn);
    vLayout->addWidget(orthoSelectBtn);

    connect(input3DSelectBtn, SIGNAL(clicked()), this, SLOT(on_input3DSelectBtn_clicked()));
    connect(orthoSelectBtn, SIGNAL(clicked(bool)), this, SLOT(on_orthoInputSelectBtn_clicked()));

    wdg->setLayout(vLayout);
    wdg->move(600,600);
    setCentralWidget(wdg);
}

void MainWindow::on_input3DSelectBtn_clicked()
{
    this->hide();
    Dialog3DInput dialog3DInput;
    dialog3DInput.setModal(true);
    dialog3DInput.exec();
}

void MainWindow::on_orthoInputSelectBtn_clicked()
{
    this->hide();
    dialogOrthoInput orthoInput;
    orthoInput.setModal(true);
    orthoInput.exec();
}
