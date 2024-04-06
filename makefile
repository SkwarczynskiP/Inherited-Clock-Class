all: main

main: main.o CityClock.o
	g++ main.o CityClock.o -o main

main.o: main.cpp
	g++ -c main.cpp

Clock.o: CityClock.cpp
	g++ -c CityClock.cpp

clean:
	del CityClock.o
	del main.o
	del main.exe

run: main
	./main