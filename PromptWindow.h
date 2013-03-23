#ifndef PROMPTWINDOW_H
#define PROMPTWINDOW_H

#include <QtGui/QApplication>
#include <QWidget>
#include <QDialog>
#include <QHBoxLayout>

#include "mainwindow.h"

class QLineEdit;
class QPushButton;
class QLabel;
class QComboBox;

class PromptWindow : public QDialog
{
    Q_OBJECT

public:
    PromptWindow(MainWindow* _mw,QWidget *parent=0);

signals:
    void confirm();

private slots:
    void enableConfirmButton(const QString& text);
    void checkPasswd();
    void choosenUser(int);

private:
    MainWindow* mw;
    QLabel* label;
    QLineEdit* passwd;
    QPushButton* confirmBtn;
    QComboBox* userType;
    QString constPasswd;
    QString user;

public:
    bool okPasswd;

};

#endif // PROMPTWINDOW_H
