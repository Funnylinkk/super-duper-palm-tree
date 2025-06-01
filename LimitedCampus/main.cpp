#include "mainwindow.h"

#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QPushButton *button = new QPushButton("Click Me", &w);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(button);



    w.show();
    return a.exec();
}
