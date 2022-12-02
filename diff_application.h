#pragma once
#include <QWidget>

class QLabel;
class QPushButton;
class ScreenshotWidget;
class DiffScreenshotWidget;

class DiffApplication : public QWidget
{
    Q_OBJECT

public:

    explicit DiffApplication(QWidget* parent = nullptr);

    /// @brief Show full-screen screenshotWidget
    void initWidgets();

public slots:

    //
    void makeScreenshot();
    void diffScreenshot();

private:

    QPushButton* makeScreenshotBtn_ = nullptr;
    QPushButton* diffScreenshotBtn_ = nullptr;

    QWidget* button_layout(QWidget* parent);
    QWidget* tab_layout(QWidget* parent);
    QWidget* screenshotWidget(QWidget* parent);
    QWidget* diff_screenshot(QWidget* parent);

    ScreenshotWidget* first_picture_ = nullptr;
    ScreenshotWidget* second_picture_ = nullptr;
    ScreenshotWidget* active_picture_ = nullptr;

    static const char* firstFilename;
    static const char* secondFilename;
};
