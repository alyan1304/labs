#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Student.h"

int randomId() {
    std::srand(std::time(0));
    return std::rand()^std::time(0);
}
int nextId = randomId();

Student::Student(char* name_, int courseNumber_, int groupNumber_, int reportCardNumber_) {
id = nextId;
nextId++;
name = new char[strlen(name_)+1];
strcpy(name, name_);
courseNumber = courseNumber_;
groupNumber = groupNumber_;
reportCardNumber = reportCardNumber_;
}
Student::Student(const Student &other){
    id = other.id;
    name = new char[strlen(other.name)+1];
    strcpy(name, other.name);
    courseNumber = other.courseNumber;
    groupNumber = other.groupNumber;
    reportCardNumber = other.reportCardNumber;
};
Student& Student::operator=(const Student &other){
    if (this != &other) { 
        delete[] name;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        id = other.id;
        courseNumber = other.courseNumber;
        groupNumber = other.groupNumber;
        reportCardNumber = other.reportCardNumber;
    }
    return *this;
};
Student::~Student() {
    delete[] name;
}
void Student::setName(char* name) {
    strcpy(this->name, name);
};
void Student::setCourseNumber(int courseNumber) {
    this->courseNumber = courseNumber;
};
void Student::setGroupNumber(int groupNumber){
    this->groupNumber = groupNumber;
};
int Student::getId(){
    return id;
};
char* Student::getName(){ // нормальео?
    return name;
};
int Student::getCourseNumber() {
    return courseNumber;
};
int Student::getGroupNumber() {
    return groupNumber;
};
int Student::getReportCardNumber() {
    return reportCardNumber;
};
double Student::countAverageGrade(){
    return 0;
};
std::ostream& operator<<(std::ostream &out, Student &student) {
    out << "ID: " << student.id << std::endl;
    out << "Name: " << student.name << std::endl;
    out << "Course: " << student.courseNumber << std::endl;
    out << "Group: " << student.groupNumber << std::endl;
    out << "Report card: " << student.reportCardNumber << std::endl;
    return out;
}

