#include <QLabel>
#include <QLayout>
#include <QScreen>
#include <QDesktopWidget>
#include <QApplication>
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

void ScreenshotWidget::saveScreenshot(const QPixmap& pic)
{
    QFile file(fileName_);
    file.open(QIODevice::WriteOnly);
    pic.save(&file, "jpg");
    file.close();
}

void ScreenshotWidget::displayScreenshot(const QPixmap &pic)
{
    screen_picture_->setPixmap(pic.scaled(screen_picture_->size(), Qt::KeepAspectRatio));
}
