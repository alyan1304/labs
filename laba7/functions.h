#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <vector>
#include "Student.h"
#include "StudentAfterSession1.h"
#include "StudentAfterSession2.h"

double groupAverageGradeAfterSession1 (std::vector<Student*> allStudents, int groupNumber);
double groupAverageGradeAfterSession2 (std::vector<Student*> allStudents, int groupNumber);

#endif // FUNCTIONS_H