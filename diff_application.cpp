#include <QLayout>
#include <QMessageBox>
#include "diff_application.h"

const char* DiffApplication::wallpaperFileName = "DD02FBA6-73FD-4171-B9CF-5F9F5CDB41A9.jpg";

DiffApplication::DiffApplication(QWidget* parent /*= nullptr*/) :
    QWidget(parent)
{
}

void DiffApplication::initWidgets()
{
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(screen_picture_);
    layout->setMargin(0);

    this->setLayout(layout);
}
