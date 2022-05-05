#include "Room.h"

Room::Room(string name, int capacity, int computers, bool whiteboard){
   this->name = name;
   this->capacity = capacity;
   this->computers = computers;
   this->whiteboard = whiteboard;
}
Room::Room(Room& r){
  this->name = r.name;
  this->capacity = r.capacity;
  this->computers = r.computers;
  this->whiteboard = r.whiteboard;
}

bool Room::hasWhiteBoard(){
  return whiteboard;
}
string Room::getName(){
  return name;
}
int Room::getCapacity(){
  return capacity;
}
int Room::numComputers(){
  return computers;
}

bool Room::lessThan(Room& r){
  return this->name < r.name;
}

void Room::print(){
  cout << "Room: " << name << " | Capacity: " << capacity << " | Computers: "<< computers << " | Whiteboard: "
  << whiteboard<<endl;
}

bool Room::meetsCriteria(int capacity, int computers = 0, bool whiteboard = false){
  if (whiteboard == false && this->capacity >= capacity && this->computers >= computers){
    return true;
  }
  else if (whiteboard == true && this->capacity >= capacity && this->computers >= computers && this->whiteboard == true){
    return true;
  }
  return false;
}
