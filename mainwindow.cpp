#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    planeList = ui->listWidget;

    fillPlaneList(getPlaneList());

    vectorPlanesInfo = getPlanesInfo();

    stormmap = QPixmap("media/stormmap.png");
    windmap = QPixmap("media/windmap.png");

    ui->label_4->setPixmap(stormmap);
    ui->label_5->setPixmap(windmap);

    //ui->tabWidget->addTab(new GeneralTab(),tr("myTab"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QTabWidget* MainWindow::getTab()
{
    return ui->tabWidget;
}

std::vector<std::string> MainWindow::getPlaneList()
{
    std::vector<std::string> vectorPlaneList;
    std::ifstream file("planelist");
    std::string bufstring;

    while(!file.eof())
    {
        getline(file,bufstring);
        vectorPlaneList.push_back(bufstring);
    }

    planesNum=vectorPlaneList.size();

    return vectorPlaneList;
}

QPushButton* MainWindow::getPlaneListBtn()
{

}

void MainWindow::fillPlaneList(std::vector<std::string> vectorPlaneList)
{
    for(int i=0; i < (int)vectorPlaneList.size();++i)
    {
        planeList->addItem(new QListWidgetItem(QString::fromUtf8(vectorPlaneList[i].c_str())));
    }
}

void MainWindow::setPlaneInfo()
{
    for(int i=0; i < (int)vectorPlanesInfo.size(); ++i)
        if(planeList->currentRow() == i)    ui->textEdit->setText(QString::fromUtf8(vectorPlanesInfo[i].c_str()));
}

std::vector<std::string> MainWindow::getPlanesInfo()
{
    std::ifstream file("planesinfo");
    std::string bufstring;

    while(!file.eof())
    {
        getline(file,bufstring);
        vectorPlanesInfo.push_back(bufstring);
    }

    return vectorPlanesInfo;

}
