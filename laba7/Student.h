#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cstdlib>
#include <ctime>

class Student {
  public:
    Student() = delete;
    Student(char* name_, int courseNumber_, int groupNumber_, int reportCardNumber_);
    Student(const Student &other);
    Student& operator=(const Student &other);
    ~Student();
    void setName(char* name);
    void setCourseNumber(int courseNumber);
    void setGroupNumber(int groupNumber);
    int getId();
    char* getName();
    int getCourseNumber();
    int getGroupNumber();
    int getReportCardNumber();
    virtual double countAverageGrade();
    friend std::ostream& operator<<(std::ostream &out, Student &student);
  protected:
    int id;
    char* name;
    int courseNumber;
    int groupNumber;
    int reportCardNumber;
};








#endif // STUDENT_H