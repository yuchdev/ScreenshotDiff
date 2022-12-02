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

ScreenshotWidget::ScreenshotWidget(QWidget* parent /*= nullptr*/) :
    QWidget(parent)
{
    screen_picture_ = new QLabel(this);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(screen_picture_);
    layout->setMargin(0);
    setLayout(layout);
}

void ScreenshotWidget::setFilename(const QString& fileName)
{
    fileName_ = fileName;
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
    screen_picture_->setMinimumSize(pwgt->size());
    screen_picture_->setPixmap(pic.scaled(screen_picture_->size()));    
}

QString ScreenshotWidget::saveScreenshot(const QPixmap& pic)
{
    QStringList tempPaths = QStandardPaths::standardLocations(QStandardPaths::TempLocation);

    if (tempPaths.isEmpty()) {
        return QString{};
    }

    QString wallpaperPath = QDir(tempPaths[0]).filePath(fileName_);
    QFile file(wallpaperPath);
    file.open(QIODevice::WriteOnly);

    // write screenshotWidget file
    pic.save(&file, "jpg");
    file.close();
}
