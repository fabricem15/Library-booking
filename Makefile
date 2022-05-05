OBJ=Date.o Reservation.o Room.o Library.o Student.o main.o


a1: Date.o Reservation.o Room.o Student.o Library.o main.o
	g++ -o a1 $(OBJ)

Date.o: Date.h Date.cc
	g++ -c Date.cc

main.o: main.cc a1-global.cc Library.o
	g++ -c main.cc
Student.o: Student.cc
	g++ -c Student.cc

Room.o: Room.h Room.cc
	g++ -c Room.cc

Reservation.o: Reservation.h Reservation.cc
	g++ -c Reservation.cc
Library.o: Library.h Library.cc
	g++ -c Library.cc
clean:
		rm -v $(OBJ) a1
