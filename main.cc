#include <iostream>
#include <string>
using namespace std;

#include "Library.h"
#include "a1-global.cc"

int main(){

  // testing library functions
  Library lib;
  populate(lib);
  testReservations(lib);
  lib.print();


  cout << "\n\n" << "*****************************************" << endl;

  cout << "Testing Student functions...\n" << endl;
  // testing student functions
  Student* bob;
  Student* alice;
  lib.getStudent("Bob", &bob);
  lib.getStudent("Alice", &alice);
  bob->print();
  alice->print();
  cout << "Alice's student number is less than Bob's: " << alice->lessThan(*bob) << endl; // should be false



  cout << "\n\n" << "******************************************" << endl;
  cout << "Testing Date functions..." << endl;


  // (a) different days but same time: should not overlap
  Date d3(2021, 2, 24, 8, 3);
  Date d4(2021, 2, 23, 8, 3);
  testDate(d3, d4, false);

  // (b) same date, time difference is >=3: should not overlap
  Date d9(2021, 2, 24, 8, 3);
  Date d10(2021, 2, 24, 12, 1);
  testDate(d9, d10, false);

  // (c) Time difference is 1, earlier date duration is 1: should not overlap
  Date d7(2021, 2, 24, 8, 3);
  Date d8(2021, 2, 24, 7, 1);
  testDate(d7, d8, false);

  // (d) hours are 2 apart, time duration causes them to overlap
  Date d1(2021, 1, 24, 8, 3);
  Date d2(2021, 1, 24, 6, 3);
  testDate(d1, d2, true);

  // (e) same time and date, they should overlap
  Date d5(2021, 2, 24, 8, 3);
  Date d6(2021, 2, 24, 8, 3);
  testDate(d5, d6, true);

  return 0;
}
