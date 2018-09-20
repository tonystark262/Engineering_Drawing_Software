#include "dialog3dinput.h"
#include "object3dfunctionswindow.h"
#include "display.h"

#include <QFileDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>


#include <fstream>
#include <iostream>

Dialog3DInput::Dialog3DInput(QWidget *parent) : QDialog(parent)
{
    this->resize(800, 500);
    QVBoxLayout *qvb = new QVBoxLayout(this);
    QHBoxLayout *fileSelectLayout = new QHBoxLayout();


    QPushButton *fileSelectBtn = new QPushButton();
    fileSelectBtn->setText("Open File");
    connect(fileSelectBtn, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));

    fileNameDisplay = new QTextBrowser();
    fileNameDisplay->setGeometry(1, 1, 50, 50);

    fileSelectLayout->addWidget(fileNameDisplay);
    fileSelectLayout->addWidget(fileSelectBtn);

    QPushButton *proceedFileBtn = new QPushButton();
    proceedFileBtn->setText("Proceed");
    connect(proceedFileBtn, SIGNAL(clicked()), this, SLOT(on_proceedFileBtn_clicked()));

    QVBoxLayout *interactiveInputLayout = new QVBoxLayout();

    interactiveInputTextEdit = new QPlainTextEdit();

    QPushButton *proceedInteractiveBtn = new QPushButton();
    proceedInteractiveBtn->setText("Proceed");
    connect(proceedInteractiveBtn, SIGNAL(clicked()), this, SLOT(on_proceed3DBtn_clicked()));

    interactiveInputLayout->addWidget(interactiveInputTextEdit);
    interactiveInputLayout->addWidget(proceedInteractiveBtn);

    qvb->addLayout(fileSelectLayout);
    qvb->addWidget(proceedFileBtn);
    qvb->addLayout(interactiveInputLayout);   
}

Dialog3DInput::~Dialog3DInput()
{
    
}

void Dialog3DInput::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), "../", "Text File (*.txt)");
    this->fileNameDisplay->setText(filename);
}


void Dialog3DInput::on_proceedFileBtn_clicked()
{
    QString qfilename = this->fileNameDisplay->toPlainText();
    std::string filename = qfilename.toUtf8().constData();
    //std::cout<<filename<<std::endl;
    if(filename.compare("") != 0){
        global_obj3D.inputFromFile(filename);

        this->hide();
        object3DFunctionsWindow window3D;
        window3D.setModal(true);
        window3D.exec();
    }
 }

void Dialog3DInput::on_proceed3DBtn_clicked()
{
    QString commands = this->interactiveInputTextEdit->toPlainText();
    std::string input_string = commands.toUtf8().constData();
    char *filename = "temp.txt";

    std::ofstream out(filename);
    out<<input_string;
    out.close();
    global_obj3D.inputFromFile(filename);

    this->hide();
    object3DFunctionsWindow window3D;
    window3D.setModal(true);
    window3D.exec();
}

