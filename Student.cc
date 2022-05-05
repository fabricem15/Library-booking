#include "Student.h"

Student::Student(){
    name = "Marge Simpson";
    number = "101101011";
}
Student::Student(string n, string num){
  name = n;
  number = num;
}
Student::Student(Student& student){
  this->name = student.name;
  this->number = student.number;
}

string Student::getName(){
  return this->name;
}
string Student::getNumber(){
  return this->number;
}

void Student::print(){
  cout << name << " (" << number << ")" << endl;
}
bool Student::lessThan(Student& s){
  return this->number < s.number;
}
