#ifndef OBJECT3DFUNCTIONSWINDOW_H
#define OBJECT3DFUNCTIONSWINDOW_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

class object3DFunctionsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit object3DFunctionsWindow(QWidget *parent = 0);
    ~object3DFunctionsWindow();

private slots:
    void on_scaleBtn_clicked();

    void on_translateBtn_clicked();

    void on_rotateBtn_clicked();

    void on_planeProjectBtn_clicked();

    void on_reflectBtn_clicked();

    void on_orthographic3DBtn_clicked();

    void on_isometric3DBtn_clicked();

    void on_renderBtn_clicked();

    void on_renderSolidBtn_clicked();

};

#endif // OBJECT3DFUNCTIONSWINDOW_H
