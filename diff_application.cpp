#include <QLayout>
#include <QMessageBox>
#include <QPushButton>
#include <QTabWidget>
#include "diff_application.h"
#include "screenshot_widget.h"
#include "diff_screenshot.h"

//static
const char* DiffApplication::firstFilename{"DD02FBA6-73FD-4171-B9CF-5F9F5CDB41AA.jpg"};

//static
const char* DiffApplication::secondFilename{"DD02FBA6-73FD-4171-B9CF-5F9F5CDB41BB.jpg"};

DiffApplication::DiffApplication(QWidget* parent /*= nullptr*/) :
    QWidget(parent)
{
    initWidgets();
    connect(makeScreenshotBtn_, &QPushButton::clicked, this, &DiffApplication::makeScreenshot);
    connect(diffScreenshotBtn_, &QPushButton::clicked, this, &DiffApplication::diffScreenshot);
}

void DiffApplication::initWidgets()
{
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(button_layout(this));
    layout->addWidget(tab_layout(this));
    layout->setMargin(3);

    this->setLayout(layout);
}

QWidget* DiffApplication::button_layout(QWidget* parent){

    QWidget* wgt = new QWidget(parent);

    makeScreenshotBtn_ = new QPushButton("Screenshot");
    diffScreenshotBtn_ = new QPushButton("Diff");

    QHBoxLayout* buttonLayout = new QHBoxLayout();
    buttonLayout->setMargin(5);
    buttonLayout->setSpacing(5);

    // Two buttons in horizontal
    buttonLayout->addWidget(makeScreenshotBtn_, 1);
    buttonLayout->addWidget(diffScreenshotBtn_, 2);

    wgt->setLayout(buttonLayout);

    return wgt;
}

void DiffApplication::makeScreenshot()
{
    active_picture_->makeScreenshot();
    if (active_picture_ == first_picture_){
        active_picture_ = second_picture_;
    }
    else {
        active_picture_ = first_picture_;
    }
}

QWidget* DiffApplication::tab_layout(QWidget* parent)
{
    QTabWidget* wnd = new QTabWidget;
    QVBoxLayout* box = new QVBoxLayout();
    first_picture_ = new ScreenshotWidget(this);
    second_picture_ = new ScreenshotWidget(this);

    wnd->addTab(screenshotWidget(this), "First Screenshot");
    wnd->addTab(screenshotWidget(this), "Second Screenshot");
    wnd->addTab(diff_screenshot(this), "Diff Screenshot");
    active_picture_ = first_picture_;

    wnd->setLayout(box);
    return wnd;
}

//
QWidget* DiffApplication::screenshotWidget(QWidget* parent)
{
    return new ScreenshotWidget(this);
}


//
QWidget* DiffApplication::diff_screenshot(QWidget* parent)
{
    return new DiffScreenshotWidget(this);
}

void DiffApplication::diffScreenshot()
{
    QImage imageOne;
    QImage imageTwo;
    QImage resultImage;

    int w = imageOne.width();
    int h = imageOne.height();

    for(int i=0; i<h; i++){
        QRgb *rgbLeft=(QRgb*)imageOne.constScanLine(i);
        QRgb *rgbRigth=(QRgb*)imageTwo.constScanLine(i);
        QRgb *rgbResult=(QRgb*)resultImage.constScanLine(i);
        for(int j=0;j<w;j++){
            rgbResult[j] = rgbLeft[j]-rgbRigth[j];
        }
    }
}

