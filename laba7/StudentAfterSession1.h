#ifndef STUDENTAFTERSESSION1
#define STUDENTAFTERSESSION1
#include <iostream>
#include "Student.h"

class StudentAfterSession1 : public Student {
  public:
    StudentAfterSession1() = delete;
    StudentAfterSession1(char* name_, int courseNumber_, int groupNumber_, int reportCardNumber_, int grades[4]);
    StudentAfterSession1(const StudentAfterSession1 &other);
    int getGrade(int index);
    void setGrade(int index, int grade);
    double countAverageGrade() override;
    friend std::ostream& operator<<(std::ostream &out, StudentAfterSession1 &student);
  protected:
    int grades[4];
};

#endif //STUDENTAFTERSESSION1