#include <QLayout>
#include <QLabel>
#include <QPushButton>
#include <QTabWidget>
#include <QStandardPaths>
#include <QDir>
#include <QDebug>
#include <iostream>
#include "diff_application.h"
#include "screenshot_widget.h"

//static
const char* DiffApplication::firstFilename{"DD02FBA6-73FD-4171-B9CF-5F9F5CDB41AA.jpg"};

//static
const char* DiffApplication::secondFilename{"DD02FBA6-73FD-4171-B9CF-5F9F5CDB41BB.jpg"};

//static
const char* DiffApplication::diffFilename{"DD02FBA6-73FD-4171-B9CF-5F9F5CDB41CC.jpg"};

DiffApplication::DiffApplication(QWidget* parent /*= nullptr*/) :
    QWidget(parent)
{
    initWidgets();
    QStringList appLocalPath = QStandardPaths::standardLocations(QStandardPaths::HomeLocation);
    firstFilenamePath_ = QDir(appLocalPath[0]).filePath(firstFilename);
    secondFilenamePath_ = QDir(appLocalPath[0]).filePath(secondFilename);
    diffFilenamePath_ = QDir(appLocalPath[0]).filePath(diffFilename);

    qDebug() << "firstFilenamePath: " << firstFilenamePath_;
    qDebug() << "secondFilenamePath: " << secondFilenamePath_;
    qDebug() << "diffFilenamePath: " << diffFilenamePath_;

    connect(makeScreenshotBtn_, &QPushButton::clicked, this, &DiffApplication::makeScreenshot);
    connect(diffScreenshotBtn_, &QPushButton::clicked, this, &DiffApplication::diffScreenshot);
}

void DiffApplication::initWidgets()
{
    auto* layout = new QVBoxLayout;
    layout->addWidget(buttonLayout(this));
    layout->addWidget(tabLayout(this));
    layout->setMargin(3);

    this->setLayout(layout);
}

QWidget* DiffApplication::buttonLayout(QWidget* parent){

    auto* wgt = new QWidget(parent);

    makeScreenshotBtn_ = new QPushButton("Screenshot");
    diffScreenshotBtn_ = new QPushButton("Diff");

    auto* buttonLayout = new QHBoxLayout();
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
    if (active_picture_ == firstPictureWgt_){
        active_picture_ = secondPictureWgt_;
    }
    else {
        active_picture_ = firstPictureWgt_;
    }
}

QWidget* DiffApplication::tabLayout(QWidget*)
{
    auto* wnd = new QTabWidget;
    auto* box = new QVBoxLayout();
    firstPictureWgt_ = new ScreenshotWidget(this);
    secondPictureWgt_ = new ScreenshotWidget(this);
    firstPictureWgt_->setFilename(firstFilename);
    secondPictureWgt_->setFilename(secondFilename);

    auto* pictureTab = new QWidget;
    auto* pictureLayout = new QVBoxLayout;
    diffPicture_ = new QLabel;
    pictureLayout->addWidget(diffPicture_);
    pictureTab->setLayout(pictureLayout);

    wnd->addTab(firstPictureWgt_, "First Screenshot");
    wnd->addTab(secondPictureWgt_, "Second Screenshot");
    wnd->addTab(pictureTab, "Diff Screenshot");
    active_picture_ = firstPictureWgt_;

    wnd->setLayout(box);
    return wnd;
}

//

void DiffApplication::diffScreenshot()
{
    QImage imageOne(firstFilenamePath_);
    QImage imageTwo(secondFilenamePath_);
    QImage resultImage(imageOne.size(), QImage::Format_RGB32);

    int w = imageOne.width();
    int h = imageOne.height();
    qDebug() << "w = " << w << ", h = " << h;

    for(int i=0; i<h; i++){
        QRgb *rgbLeft=(QRgb*)imageOne.constScanLine(i);
        QRgb *rgbRigth=(QRgb*)imageTwo.constScanLine(i);
        QRgb *rgbResult=(QRgb*)resultImage.constScanLine(i);

        for(int j=0; j<w; j++){
            rgbResult[j] = rgbLeft[j]-rgbRigth[j];
        }
    }

    // Save resultImage as a file with name diffFilename
    if(resultImage.save(diffFilenamePath_)){
        qDebug() << "Diff image saved as " << diffFilenamePath_;
    }
    else {
        qDebug() << "Diff image not saved";
    }
    displayDiffImage();
}

void DiffApplication::displayDiffImage()
{
    QPixmap pic(diffFilenamePath_);
    diffPicture_->setPixmap(pic.scaled(pic.size() / 2));
}

