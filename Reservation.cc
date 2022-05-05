#include "Reservation.h"

Reservation::Reservation(Student* stud, Room* r, Date& d){
  this->student = stud;
  this->room = r;
  this->date.setDate(d);
}

Student* Reservation::getStudent(){
  return student;
}
Room* Reservation::getRoom(){
  return room;
}
Date Reservation::getDate(){
  return date;
}

void Reservation::print(){
  cout << "Reservation for: ";
  student->print();
  cout << "On ";
  date.print();
  cout << "In ";
  room->print();
  cout << endl;

}
bool Reservation::lessThan(Reservation& res){
  return this->date.lessThan(res.date);
}
