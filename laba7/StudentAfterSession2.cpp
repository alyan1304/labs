#include "StudentAfterSession2.h"

StudentAfterSession2::StudentAfterSession2(char* name_, int courseNumber_, int groupNumber_, int reportCardNumber_, int grades[4], int grades2[5]) : 
StudentAfterSession1(name_, courseNumber_, groupNumber_, reportCardNumber_, grades) {
        for (int i = 0; i < 5; i++) {
            this->grades2[i] = grades2[i];
        }
    }

StudentAfterSession2::StudentAfterSession2(const StudentAfterSession2 &other) : StudentAfterSession1(other) {
    for (int i = 0; i < 5; i++) {
            this->grades2[i] = other.grades2[i];
        }
}

int StudentAfterSession2::getGrade2(int index) {
    return grades2[index];
}

void StudentAfterSession2::setGrade2(int index, int grade) {
    grades2[index] = grade;
}

double StudentAfterSession2::countAverageGrade() {
    double sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += grades2[i];
    }
    for (int i = 0; i < 4; i++) {
        sum += grades[i];
    }
    return sum/9;
}

std::ostream& operator<<(std::ostream &out, StudentAfterSession2 &student) {
    out << "ID: " << student.id << std::endl;
    out << "Name: " << student.name << std::endl;
    out << "Course: " << student.courseNumber << std::endl;
    out << "Group: " << student.groupNumber << std::endl;
    out << "Report card: " << student.reportCardNumber << std::endl;
    out << "Grades: ";
    for (int i = 0; i < 4; i++) {
        out << student.grades[i] << "\t";
    }
    out << std::endl;
    for (int i = 0; i < 5; i++) {
        out << student.grades2[i] << "\t";
    }
    return out;
}