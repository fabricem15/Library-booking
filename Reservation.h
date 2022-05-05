#ifndef RESERV_H
#define RESERV_H
#include "Date.h"
#include "Room.h"
#include "Student.h"
#include <iostream>
#include <string>
using namespace std;


class Reservation {
  public:

    Reservation(Student*, Room*, Date&);

    // getters
    Student* getStudent();
    Room* getRoom();
    Date getDate();

    // functions
    bool lessThan(Reservation& res);
    bool overlaps(const string& r, Date& d);
    void print();
  private:
    Student* student;
    Room* room;
    Date date;
};
#endif
