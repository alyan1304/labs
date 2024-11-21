#include "StudentAfterSession1.h"

StudentAfterSession1::StudentAfterSession1(char* name_, int courseNumber_, int groupNumber_, int reportCardNumber_, int grades[4]) : 
Student(name_, courseNumber_, groupNumber_, reportCardNumber_) {
        for (int i = 0; i < 4; i++) {
            this->grades[i] = grades[i];
        }
    }

StudentAfterSession1::StudentAfterSession1(const StudentAfterSession1 &other) : Student(other) {
    for (int i = 0; i < 4; i++) {
            this->grades[i] = other.grades[i];
        }
}

int StudentAfterSession1::getGrade(int index) {
    return grades[index];
}

void StudentAfterSession1::setGrade(int index, int grade) {
    grades[index] = grade;
}

double StudentAfterSession1::countAverageGrade() {
    double sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += grades[i];
    }
    return sum/4;
}

std::ostream& operator<<(std::ostream &out, StudentAfterSession1 &student) {
    out << "ID: " << student.id << std::endl;
    out << "Name: " << student.name << std::endl;
    out << "Course: " << student.courseNumber << std::endl;
    out << "Group: " << student.groupNumber << std::endl;
    out << "Report card: " << student.reportCardNumber << std::endl;
    out << "Grades: ";
    for (int i = 0; i < 4; i++) {
        out << student.grades[i] << "\t";
    }
    return out;
}