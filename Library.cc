#include "Library.h"


Library::Library(){
  students = new Student*[MAX_SIZE];
  reservations = new Reservation*[MAX_SIZE];
  numReserv = 0;
  numStudents = 0;
  numRooms = 0;
}

Library::~Library(){
  for (int i = 0; i < numReserv; i++){
    delete reservations[i];
  }
  for (int i = 0; i < numStudents; i++){
    delete students[i];
  }
  for (int i = 0; i < numRooms; i++){
    delete rooms[i];
  }
  delete [] reservations;
  delete [] students;

}

bool Library::addStudent(const string& name, const string& number){
  if (numStudents >= MAX_SIZE){return false;}
  students[numStudents++] = new Student(name, number);
  return true;
}

bool Library::addRoom(const string& name, int capacity, int computers, bool whiteboard){
  if (numRooms >= MAX_SIZE){return false;}
  rooms[numRooms++] = new Room(name, capacity, computers, whiteboard);
  return true;
}
bool Library::getStudent(const string& name, Student** student){
  for (int i = 0; i < numStudents; i++){
    if (students[i]->getName() == name){
        *student = students[i];
        return true;
    }
  }
  return false;
}
bool Library::getRoom(const string& roomName, Room** room){
  for (int i = 0; i < numRooms; i++){
    if (rooms[i]->getName() == roomName){
      *room = rooms[i];
      return true;
    }
  }
  return false;
}

bool Library::isFree(const string& room, Date& d){
  Room* roomPtr;
  Reservation* rsrv;

  if (getRoom(room, &roomPtr) == false){ return false;}
  for (int i =0; i < numReserv; i++){
    rsrv = reservations[i];
    if (rsrv->getDate().overlaps(d) && rsrv->getRoom() == roomPtr){
      return false;
    }
  }
  return true;
}

void Library::print(){
  cout << "# Students: " << numStudents << " | # Rooms: " << numRooms << " | # Reservations: " << numReserv << endl;
}
void Library::printReservations(){
  for (int i = 0; i < numReserv; i++){
    reservations[i]->print();
  }
}
bool Library::makeReservation(const string& student, const string& room, Date& d){
  Student* stud;
  Room* rm;
  if (getStudent(student, &stud) == false || getRoom(room, &rm) == false){return false;}

  if (isFree(room, d) == false || numReserv >= MAX_SIZE){return false;}

  Reservation* rsv = new Reservation(stud, rm, d);
  reservations[numReserv++] = rsv;
  return true;
}
