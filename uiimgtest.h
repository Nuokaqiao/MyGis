#ifndef UIIMGTEST_H
#define UIIMGTEST_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include "mapcanvas.h"
#include <QHBoxLayout>

class MapCanvas;

namespace Ui {
class UIImgTest;
}

class UIImgTest : public QMainWindow
{
    Q_OBJECT

public:
    explicit UIImgTest(QWidget *parent = 0);
    ~UIImgTest();
public slots:
    void PickOpenFile();
    void Exit();
    void ShowFileListWindow();
    void ShowInforWindow();

private:
    Ui::UIImgTest *ui;
    MapCanvas* myMap;
};

#endif // UIIMGTEST_H
