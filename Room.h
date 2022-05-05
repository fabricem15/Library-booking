#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <string>
using namespace std;

class Room {
  public:
    Room(string name, int capacity, int computers, bool whiteboard);
    Room(Room& r);

    // getters
    bool hasWhiteBoard();
    string getName();
    int getCapacity();
    int numComputers();

    // functions
    bool meetsCriteria(int, int, bool);
    bool lessThan(Room& r);
    void print();

  private:
    string name;
    int capacity;
    int computers;
    bool whiteboard;
};
#endif
