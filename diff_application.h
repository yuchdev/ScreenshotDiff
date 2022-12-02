#pragma once
#include <QWidget>

class QLabel;

class DiffApplication : public QWidget
{
    Q_OBJECT

public:

    DiffApplication(QWidget* parent = nullptr);

    /// @brief Show full-screen screenshot
    void initWidgets();

private:

    /// Counter for delayed strings appearance on the screen
    size_t counter_ = 0u;

    /// wallpaper file created in a temp dir
    static const char* wallpaperFileName;
};

