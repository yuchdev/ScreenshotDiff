#include <QLabel>
#include <QLayout>
#include <QScreen>
#include <QDesktopWidget>
#include <QStandardPaths>
#include <QApplication>
#include <QDir>
#include <QFile>
#include "screenshot_widget.h"

ScreenshotWidget::ScreenshotWidget(QWidget* parent /*= nullptr*/) :
    QWidget(parent)
{
    screen_picture_ = new QLabel(this);
    screen_picture_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    auto* layout = new QVBoxLayout;
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
    QDesktopWidget* desktop = QApplication::desktop();
    screen_picture_->setMinimumSize(desktop->size() / 2);

    QScreen *screen = QGuiApplication::primaryScreen();
    if (!screen) {
        // we can't do anything
        return;
    }

    QPixmap pic = screen->grabWindow(0);
    displayScreenshot(pic);
    saveScreenshot(pic);
}

QString ScreenshotWidget::saveScreenshot(const QPixmap& pic)
{
    QStringList appLocalPath = QStandardPaths::standardLocations(QStandardPaths::HomeLocation);

    if (appLocalPath.isEmpty()) {
        return QString{};
    }

    QString picturePath = QDir(appLocalPath[0]).filePath(fileName_);
    QFile file(picturePath);
    file.open(QIODevice::WriteOnly);

    // write screenshotWidget file
    pic.save(&file, "jpg");
    file.close();
    return picturePath;
}

void ScreenshotWidget::displayScreenshot(const QPixmap &pic)
{
    screen_picture_->setPixmap(pic.scaled(screen_picture_->size(), Qt::KeepAspectRatio));
}
