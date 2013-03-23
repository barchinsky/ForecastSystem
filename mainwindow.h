#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTabWidget>
#include <QListWidget>
#include <fstream>
#include <QString>
#include <QFileInfo>
#include <vector>
#include <QPixmap>
#include "StormInfoTab.h"
#include "TabDialog.h"
#include "GeneralTab.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Ui::MainWindow* getUi();
    QTabWidget* getTab();
    std::vector<std::string> getPlaneList();
    std::vector<std::string> getPlanesInfo();
    QPushButton* getPlaneListBtn();


public slots:
        void fillPlaneList(std::vector<std::string>);
        void setPlaneInfo();

    
private:
    Ui::MainWindow *ui;
    QListWidget* planeList;
    std::vector<std::string> vectorPlanesInfo;
    int planesNum;
    QPixmap tempgraph,windmap,stormmap;
};

#endif // MAINWINDOW_H
