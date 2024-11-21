#include "Student.h"
#include "StudentAfterSession1.h"
#include "StudentAfterSession2.h"
#include "functions.h"

int main() {
// task 5
Student *student1Ptr = new Student("Alina", 1, 4, 42513);
int gradesPetya[] = {8, 7, 9, 10};
Student *student2Ptr = new StudentAfterSession1("Petya", 2, 4, 54234, gradesPetya);
int gradesVasya1[] = {6, 3, 9, 10};
int gradesVasya2[] = {4, 2, 8, 7, 6};
Student *student3Ptr = new StudentAfterSession2("Vasya", 3, 4, 42409, gradesVasya1, gradesVasya2);

Student *students[] = {student1Ptr, student2Ptr, student3Ptr};
int counter = 0;
double gradeSum = 0;
for (Student *student: students) {
    if (student->countAverageGrade() != 0) {
    gradeSum+=student->countAverageGrade();
    counter++;
    }
}

double totalAverage;
if (counter != 0) {
    totalAverage = gradeSum / counter;
} else {
    totalAverage = 0;
}
std::cout << totalAverage << std::endl;



//task 4
std::vector<Student*> allStudents = {student1Ptr, student2Ptr, student3Ptr};
std::cout << groupAverageGradeAfterSession1(allStudents, 4) << std::endl;
std::cout << groupAverageGradeAfterSession2(allStudents, 4) << std::endl;


for (Student *student: students) {
    delete student;
}

return 0;
}