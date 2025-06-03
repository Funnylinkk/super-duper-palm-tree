#ifndef STUDENT_H
#define STUDENT_H

#include <QString>
#include <QVector>

struct Student {
    int id;
    QString name;
    QVector<int> grades;
};

double calculateAverage(const QVector<int>& grades, bool dropLowest = false);

#endif // STUDENT_H
