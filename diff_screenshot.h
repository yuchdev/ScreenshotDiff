#pragma once
#include <QWidget>

class QLabel;

class DiffScreenshotWidget : public QWidget
{
    Q_OBJECT

public:

    /// 
    DiffScreenshotWidget(QWidget* parent = nullptr);

    /// @brief Show full-screen screenshotWidget
    void diffScreenshot(const QString& fileNameOne, const QString& fileNameTwo);

private:

    /// wallpaper file created in a temp dir
    QString fileName_;
};

