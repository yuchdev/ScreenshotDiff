#pragma once
#include <QWidget>
#include "full_screen.h"

class QLabel;
class QPushButton;

class DiffApplication : public QWidget
{
    Q_OBJECT

public:

    DiffApplication(QWidget* parent = nullptr);

    /// @brief Show full-screen screenshotWidget
    void initWidgets();

public slots:

    //
    void makeScreenshot();

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

    /// Counter for delayed strings appearance on the screen
    size_t counter_ = 0u;
};

