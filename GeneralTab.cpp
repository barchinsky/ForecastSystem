#include "GeneralTab.h"


GeneralTab::GeneralTab(QWidget *parent)
    : QWidget(parent)
{

    QLabel *pathLabel = new QLabel(tr("Path:"));


    QVBoxLayout *mainLayout = new QVBoxLayout;

    mainLayout->addWidget(pathLabel);

    mainLayout->addStretch(1);
    setLayout(mainLayout);
}
