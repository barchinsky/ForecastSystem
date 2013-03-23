#include "StormInfoTab.h"

StormInfoTab::StormInfoTab(QWidget *parent)
{
    QLabel* ml = new QLabel("Olo");

    QHBoxLayout* layout = new QHBoxLayout;

    layout->addWidget(ml);

    setLayout(layout);
}
