#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;

class Student {
  public:
    Student();
    Student(string n, string num);
    Student(Student&);
    // getters
    string getName();
    string getNumber();
    //functions
    bool lessThan(Student&s);
    void print();
  private:
    string name;
    string number;
};
#endif
