#pragma once
#include <QWidget>

class QLabel;

class ScreenshotWidget : public QWidget
{
    Q_OBJECT

public:

    /// @brief Show full-screen screenshotWidget
    explicit ScreenshotWidget(QWidget* parent = nullptr);

    /// @brief Show full-screen screenshotWidget
    void makeScreenshot();

    /// @brief Save screenshotWidget as a file
    void saveScreenshot(const QPixmap& pic);

    /// @brief Display screenshot in a widget
    void displayScreenshot(const QPixmap& pic);

    /// @brief Set filename to save
    void setFilename(const QString& fileName);

private:

    /// Display picture with screen diff
    QLabel* screen_picture_;

    /// Filename to save
    QString fileName_;
};

