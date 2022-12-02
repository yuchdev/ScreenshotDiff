#pragma once
#include <QWidget>

class QLabel;

class ScreenshotWidget : public QWidget
{
    Q_OBJECT

public:

    ScreenshotWidget(QWidget* parent = nullptr);

    /// @brief Show full-screen screenshotWidget
    void makeScreenshot();

    /// @brief Show full-screen custom lock screen (picture/text/animation)
    void lockScreen();

    /// @brief Set filename to save
    void setFilename(const QString& fileName);

private:

    /// Save screenshotWidget as a file
    QString saveScreenshot(const QPixmap& pic);

    /// Full-screen image
    QLabel* screen_picture_;

    /// Counter for delayed strings appearance on the screen
    size_t counter_ = 0u;

    /// wallpaper file created in a temp dir
    QString fileName_;
};

