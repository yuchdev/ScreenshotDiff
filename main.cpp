#include <ctime>
#include <QApplication>
#include <QtGui>
#include <QWidget>
#include <QStackedWidget>
#include <QScrollArea>
#include <QLayout>
#include <QPushButton>
#include "diff_application.h"


int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    DiffApplication wnd;
    wnd.setMinimumWidth(500);
    wnd.show();

    return app.exec();
}