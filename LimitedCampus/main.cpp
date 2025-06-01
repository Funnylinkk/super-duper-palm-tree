#include "mainwindow.h"

#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QPixmap>


struct Student {

    int id;
    std::string name;
    std::vector<int> grades;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Limited Campus");

    QWidget *banner = new QWidget;
    banner->setFixedHeight(60);
    banner->setStyleSheet("background-color: green;");

    QHBoxLayout *bannerLayout = new QHBoxLayout;
    bannerLayout->setContentsMargins(10, 5, 10, 5);

    QLabel *logoLabel = new QLabel;
    QPixmap logoPixmap(":/logo.png");
    logoLabel->setPixmap(logoPixmap.scaled(90, 90, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    bannerLayout->addWidget(logoLabel);

    banner->setLayout(bannerLayout);

    QLabel *content = new QLabel("Main content goes here");
    content->setAlignment(Qt::AlignCenter);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setSpacing(0);
    mainLayout->addWidget(banner);
    mainLayout->addWidget(content);

    window.setLayout(mainLayout);
    window.resize(400, 200);
    window.show();

    return app.exec();
}

