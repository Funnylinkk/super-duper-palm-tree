#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::addStudent);
    connect(ui->saveButton, &QPushButton::clicked, this, &MainWindow::saveToFile);
    connect(ui->loadButton, &QPushButton::clicked, this, &MainWindow::loadFromFile);
    connect(ui->displayButton, &QPushButton::clicked, this, &MainWindow::displayStudents);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::addStudent() {
    int id = ui->idInput->text().toInt();
    if (usedIds.contains(id)) {
        QMessageBox::warning(this, "Error", "Duplicate ID!");
        return;
    }

    Student s;
    s.id = id;
    s.name = ui->nameInput->text();

    QStringList gradeList = ui->gradesInput->text().split(' ', Qt::SkipEmptyParts);
    for (QString g : gradeList) s.grades.append(g.toInt());

    students[id] = s;
    usedIds.insert(id);

    QMessageBox::information(this, "Added", "Student added successfully!");
}

void MainWindow::saveToFile() {
    QFile file("data.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Failed to open file for writing");
        return;
    }

    QTextStream out(&file);
    for (const Student& s : students) {
        out << s.id << " " << s.name;
        for (int grade : s.grades)
            out << " " << grade;
        out << "\n";
    }

    file.close();
}

void MainWindow::loadFromFile() {
    QFile file("data.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Failed to open file for reading");
        return;
    }

    QTextStream in(&file);
    students.clear();
    usedIds.clear();


    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(' ');
        if (parts.size() < 2) continue;

        Student s;
        s.id = parts[0].toInt();
        s.name = parts[1];
        for (int i = 3; i < parts.size(); ++i)
            s.grades.append(parts[i].toInt());

        students[s.id] = s;
        usedIds.insert(s.id);
    }

    file.close();
    QMessageBox::information(this, "Loaded", "Data loaded successfully!");
}

void MainWindow::displayStudents() {



    ui->outputArea->clear();
    for (const Student& s : students) {
        std::string gradesString;

        for (int grade: s.grades) {
            gradesString += std::to_string(grade) + " ";
        }

        ui->outputArea->append(
            QString("ID: %1, Name: %2, %3, Average: %4")
                .arg(s.id)
                .arg(s.name)
                .arg(gradesString)
                .arg(calculateAverage(s.grades))
            );
    }
}
