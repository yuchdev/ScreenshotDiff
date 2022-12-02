#include <ctime>
#include <QApplication>
#include <QtGui>
#include <QWidget>
#include <QStackedWidget>
#include <QScrollArea>
#include <QLayout>
#include <QPushButton>
#include "full_screen.h"

QWidget* button_layout(QWidget* parent){

    QWidget* wgt = new QWidget(parent);

    QPushButton* btn1 = new QPushButton("Make Screenshot");
    QPushButton* btn2 = new QPushButton("Diff Screenshot");

    QHBoxLayout* hbox = new QHBoxLayout();
    hbox->setMargin(5);
    hbox->setSpacing(5);

    // Two buttons in horizontal
    hbox->addWidget(btn1, 1);
    hbox->addWidget(btn2, 2);

    wgt->setLayout(gbox);
    return wgt;
}


QWidget* tab_layout(QWidget* parent)
{
    QTabWidget* wnd = new QTabWidget;
    QVBoxLayout* box = new QVBoxLayout();

    wnd->addTab(first_screenshot(&wnd), "First Screenshot");
    wnd->addTab(second_screenshot(&wnd), "Second Screenshot");
    wnd->addTab(diff_screenshot(&wnd), "Diff Screenshot");

    wnd->setLayout(box);
    return wnd;
}


//
QWidget* first_screenshot(QWidget* parent)
{
}

//
QWidget* second_screenshot(QWidget* parent)
{
}

//
QWidget* diff_screenshot(QWidget* parent)
{
}


int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QWidget wnd;
    QVBoxLayout box;
    box.addLayout(button_layout(&wnd));
    box.addLayout(tab_layout(&wnd));
    wnd.setLayout(&box);


    wnd.setMinimumWidth(500);
    wnd.show();

    return app.exec();
}