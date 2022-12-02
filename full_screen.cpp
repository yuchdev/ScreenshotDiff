#include <QLabel>
#include <QLayout>
#include <QScreen>
#include <QDesktopWidget>
#include <QStandardPaths>
#include <QApplication>
#include <QDir>
#include <QTimer>
#include <QTime>
#include <QFile>
#include <QMessageBox>
#include "full_screen.h"

const char* ScreenshotWidget::wallpaperFileName = "DD02FBA6-73FD-4171-B9CF-5F9F5CDB41A9.jpg";

ScreenshotWidget::ScreenshotWidget(QWidget* parent /*= nullptr*/) :
    QWidget(parent)
{
    screen_picture_ = new QLabel;
    
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(screen_picture_);
    layout->setMargin(0);

    setLayout(layout);
}

void ScreenshotWidget::makeScreenshot()
{
    QDesktopWidget* pwgt = QApplication::desktop();
    QScreen *screen = QGuiApplication::primaryScreen();
    if (!screen) {
        // we can't do anything
        return;
    }
    
    QPixmap pic = screen->grabWindow(0);

    showFullScreen();
    screen_picture_->setMinimumSize(pwgt->size());
    screen_picture_->setPixmap(pic.scaled(screen_picture_->size()));    
    wallpaperScreenshot(pic);
}

void ScreenshotWidget::lockScreen()
{
    showFullScreen();

    QDesktopWidget* pwgt = QApplication::desktop();
    QScreen *screen = QGuiApplication::primaryScreen();
    if (!screen) {
        // we can't do anything
        return;
    }

    screen_picture_->setMinimumSize(pwgt->size());
}

QString ScreenshotWidget::saveScreenshot(const QPixmap& pic)
{
    QStringList tempPaths = QStandardPaths::standardLocations(QStandardPaths::TempLocation);

    if (tempPaths.isEmpty()) {
        return;
    }

    QString wallpaperPath = QDir(tempPaths[0]).filePath(wallpaperFileName);
    QFile file(wallpaperPath);
    file.open(QIODevice::WriteOnly);

    // write screenshot file
    pic.save(&file, "jpg");
    file.close();
    makeWallpaper(wallpaperPath);
}
