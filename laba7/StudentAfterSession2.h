#ifndef STUDENTAFTERSESSION2
#define STUDENTAFTERSESSION2
#include <iostream>
#include "StudentAfterSession1.h"

class StudentAfterSession2 : public StudentAfterSession1 {
  public:
    StudentAfterSession2() = delete;
    StudentAfterSession2(char* name_, int courseNumber_, int groupNumber_, int reportCardNumber_, int grades[4], int grades2[5]);
    StudentAfterSession2(const StudentAfterSession2 &other);
    int getGrade2(int index);
    void setGrade2(int index, int grade);
    double countAverageGrade() override;
    friend std::ostream& operator<<(std::ostream &out, StudentAfterSession2 &student);
  protected:
    int grades2[5];
};

#endif //STUDENTAFTERSESSION1