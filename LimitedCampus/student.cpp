#include "student.h"
#include <algorithm>

double calculateAverage(const QVector<int>& grades, bool dropLowest) {
    if (grades.isEmpty()) return 0.0;

    QVector<int> temp = grades;
    if (dropLowest && temp.size() > 1) {
        temp.removeOne(*std::min_element(temp.begin(), temp.end()));
    }

    double total = 0;
    for (int grade : temp) total += grade;
    return total / temp.size();
}
