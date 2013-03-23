#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QPushButton>
#include <QTableWidget>
#include <QImage>
#include <QListWidget>
#include <QListWidgetItem>

#include "PromptWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    PromptWindow* prompt = new PromptWindow(&w);


    w.show();
    w.setEnabled(false);

    prompt->show();


    return a.exec();
}
