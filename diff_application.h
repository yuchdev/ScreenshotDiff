#pragma once
#include <QWidget>

class QLabel;
class QPushButton;
class ScreenshotWidget;

class DiffApplication : public QWidget
{
    Q_OBJECT
public:

    /// @brief Application constructor, create paths and connects
    explicit DiffApplication(QWidget* parent = nullptr);

    /// @brief Show full-screen screenshotWidget
    void initWidgets();

public slots:

    /// @brief Slot for making screenshot and switch active widget
    void makeScreenshot();

    /// @brief Diff screenshot and show result
    void diffScreenshot();

protected:
    /// Create button layout
    QWidget* buttonLayout(QWidget* parent);

    /// Create tab layout
    QWidget* tabLayout(QWidget* parent);

private:

    /// Display picture with screen diff
    void displayDiffImage();

    /// Create buttons layout
    QPushButton* makeScreenshotBtn_ = nullptr;
    QPushButton* diffScreenshotBtn_ = nullptr;
    QLabel* diffPicture_ = nullptr;

    /// Paths of two pictures to compare and diff picture
    QString firstFilenamePath_;
    QString secondFilenamePath_;
    QString diffFilenamePath_;

    /// Two picture widgets to compare
    /// Active widget to keep track of which one is active
    /// to make more than one compare
    ScreenshotWidget* firstPictureWgt_ = nullptr;
    ScreenshotWidget* secondPictureWgt_ = nullptr;
    ScreenshotWidget* active_picture_ = nullptr;

    /// Filenames are meaningless GUID to avoid attention
    static const char* firstFilename;
    static const char* secondFilename;
    static const char* diffFilename;
};
