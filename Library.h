#ifndef LIBRARY_H
#define LIBRARY_H
#include <iostream>
#include <string>
#include "Reservation.h"
using namespace std;

#define MAX_SIZE 100

class Library {

  public:
    Library();
    ~Library();
    // functions
    bool addStudent(const string& name, const string& number);
    bool addRoom(const string&, int=1, int=0, bool=false);
    bool getStudent(const string& name, Student ** student);
    bool getRoom(const string& roomName, Room ** room);
    bool isFree(const string& room, Date&);
    bool makeReservation(const string& student, const string& room, Date&);
    void printReservations();
    void print();
  private:
    Student** students; // dynamically allocate
    Reservation** reservations; // dyn
    Room* rooms[MAX_SIZE];
    int numStudents;
    int numReserv;
    int numRooms;

};
#endif
