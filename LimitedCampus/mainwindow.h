#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QSet>
#include "student.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addStudent();
    void saveToFile();
    void loadFromFile();
    void displayStudents();

private:
    Ui::MainWindow *ui;
    QMap<int, Student> students;
    QSet<int> usedIds;
};

#endif // MAINWINDOW_H
