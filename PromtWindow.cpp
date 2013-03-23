#include <QtGui>

#include "PromptWindow.h"

PromptWindow::PromptWindow(MainWindow* _mw,QWidget* parent) : QDialog(parent), mw(_mw)
{
    label = new QLabel("Enter password");
    confirmBtn = new QPushButton("Confirm");
    userType = new QComboBox;

    userType->addItem("Select user");
    userType->addItem("Administrator");
    userType->addItem("Dispetcher");

    confirmBtn->setDefault(true);
    confirmBtn->setEnabled(false);

    passwd = new QLineEdit;

    //constPasswd = "1";
    okPasswd = false;

    QObject::connect(passwd,SIGNAL(textChanged(QString)),this,SLOT(enableConfirmButton(QString)));
    QObject::connect(confirmBtn,SIGNAL(clicked()),this,SLOT(checkPasswd()));
    QObject::connect(userType,SIGNAL(highlighted(int)),this,SLOT(choosenUser(int)));

    QHBoxLayout* layout = new QHBoxLayout;

    layout->addWidget(userType);
    layout->addWidget(label);
    layout->addWidget(passwd);
    layout->addWidget(confirmBtn);

    setLayout(layout);

}

void PromptWindow::enableConfirmButton(const QString &text)
{
    confirmBtn->setEnabled(true);
}

void PromptWindow::checkPasswd()
{
    if(passwd->text() == constPasswd)
    {
        this->close();
        mw->setEnabled(true);
    }
    else passwd->setText("Wrong Pass");
}

void PromptWindow::choosenUser(int userId)
{
    if(userId == 1)
        constPasswd = "admin";
     else if(userId==2)
        constPasswd="disp";

}
