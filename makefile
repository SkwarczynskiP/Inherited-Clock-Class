all: main

main: main.o Clock.o CityClock.o
	g++ main.o Clock.o CityClock.o -o main

main.o: main.cpp CityClock.h Clock.h
	g++ -c main.cpp

Clock.o: Clock.cpp Clock.h
	g++ -c Clock.cpp

CityClock.o: CityClock.cpp CityClock.h Clock.h
	g++ -c CityClock.cpp

clean:
	del Clock.o
	del CityClock.o
	del main.o
	del main.exe

run: main
	./main