#include "functions.h"
#include <vector>

double groupAverageGradeAfterSession1 (std::vector<Student*> allStudents, int groupNumber) {
    int counter = 0;
    double sumAverage = 0;
    for (Student *student: allStudents) {
        if (student->getGroupNumber() == groupNumber) {
            StudentAfterSession1* studentAfterSession1 = dynamic_cast<StudentAfterSession1*>(student);
            if (studentAfterSession1) {
                double gradeSum = 0;
                for (int i = 0; i < 4; i++) {
                    gradeSum += studentAfterSession1->getGrade(i);
                }
            sumAverage += gradeSum / 4;
            counter++;
            }
        }
    }
    if (counter != 0) {
        return sumAverage / counter;
    }
    return 0;
    }

double groupAverageGradeAfterSession2 (std::vector<Student*> allStudents, int groupNumber) {
    int counter = 0;
    double sumAverage = 0;
    for (Student *student: allStudents) {
        if (student->getGroupNumber() == groupNumber) {
            StudentAfterSession2* studentAfterSession2 = dynamic_cast<StudentAfterSession2*>(student);
            if (studentAfterSession2) {
                sumAverage += studentAfterSession2->countAverageGrade();
                counter++;
            }
        }
    }
    if (counter != 0) {
        return sumAverage / counter;
    }
    return 0;
}