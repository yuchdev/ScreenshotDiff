#include <QApplication>
#include <QtGui>
#include <QWidget>
#include <QDesktopWidget>
#include "diff_application.h"


int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    DiffApplication wnd;

    // Get screen size, and make window twice as smaller
    QRect screen = QGuiApplication::screens()[0]->geometry();
    wnd.resize(screen.width() / 2, screen.height() / 2);
    wnd.show();
    return QApplication::exec();
}