#include "dialogorthoinput.h"
#include "orthofunctionsdialog.h"
#include"display.h"

#include <iostream>
#include <fstream>

#include <QFileDialog>

dialogOrthoInput::dialogOrthoInput(QWidget *parent) : QDialog(parent)
{
    this->resize(800, 500);
    QVBoxLayout *qvb = new QVBoxLayout(this);
    QHBoxLayout *fileSelectLayout = new QHBoxLayout();

    QPushButton *fileSelectBtn = new QPushButton();
    fileSelectBtn->setText("Open File");
    connect(fileSelectBtn, SIGNAL(clicked()), this, SLOT(on_openFileOrthoBtn_clicked()));

    fileNameDisplay = new QTextBrowser();
    fileNameDisplay->setGeometry(1, 1, 50, 50);

    fileSelectLayout->addWidget(fileNameDisplay);
    fileSelectLayout->addWidget(fileSelectBtn);

    QPushButton *proceedFileBtn = new QPushButton();
    proceedFileBtn->setText("Proceed");
    connect(proceedFileBtn, SIGNAL(clicked()), this, SLOT(on_proceedOrthoFileBtn_clicked()));

    QVBoxLayout *interactiveInputLayout = new QVBoxLayout();

    interactiveInputTextEdit = new QPlainTextEdit();

    QPushButton *proceedInteractiveBtn = new QPushButton();
    proceedInteractiveBtn->setText("Proceed");
    connect(proceedInteractiveBtn, SIGNAL(clicked()), this, SLOT(on_proceedOrthoBtn_clicked()));

    interactiveInputLayout->addWidget(interactiveInputTextEdit);
    interactiveInputLayout->addWidget(proceedInteractiveBtn);

    qvb->addLayout(fileSelectLayout);
    qvb->addWidget(proceedFileBtn);
    qvb->addLayout(interactiveInputLayout);
}

dialogOrthoInput::~dialogOrthoInput()
{

}

void dialogOrthoInput::on_openFileOrthoBtn_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), "../", "Text File (*.txt)");
    this->fileNameDisplay->setText(filename);
}


void dialogOrthoInput::on_proceedOrthoFileBtn_clicked()
{
    QString qfilename = this->fileNameDisplay->toPlainText();
    std::string filename = qfilename.toUtf8().constData();
    //std::cout<<filename<<std::endl;

    if(filename.compare("") != 0){
    global_orthoObj.inputFromFile(filename);

    // open orthographic functions window
    this->hide();
    OrthoFunctionsDialog orthoDialog;
    orthoDialog.setModal(true);
    orthoDialog.exec();
    }
}

void dialogOrthoInput::on_proceedOrthoBtn_clicked()
{
    QString commands = this->interactiveInputTextEdit->toPlainText();
    std::string input_string = commands.toUtf8().constData();
    char *filename = "temp.txt";

    std::ofstream out(filename);
    out<<input_string;
    out.close();
    global_orthoObj.inputFromFile(filename);
    // open orthographic functions window
    this->hide();
    OrthoFunctionsDialog orthoDialog;
    orthoDialog.setModal(true);
    orthoDialog.exec();

}
