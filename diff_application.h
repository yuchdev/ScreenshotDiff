#pragma once
#include <QWidget>

class QLabel;
class QPushButton;
class ScreenshotWidget;

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

    /// @brief Display picture with 'diffFilename' in 'diffPicture_' label
    void displayDiffImage();

    ///
    QPushButton* makeScreenshotBtn_ = nullptr;
    QPushButton* diffScreenshotBtn_ = nullptr;
    QLabel* diffPicture_ = nullptr;

    QString firstFilenamePath_;
    QString secondFilenamePath_;
    QString diffFilenamePath_;


    QWidget* buttonLayout(QWidget* parent);
    QWidget* tabLayout(QWidget* parent);

    ScreenshotWidget* firstPictureWgt_ = nullptr;
    ScreenshotWidget* secondPictureWgt_ = nullptr;
    ScreenshotWidget* active_picture_ = nullptr;

    static const char* firstFilename;
    static const char* secondFilename;
    static const char* diffFilename;
};
