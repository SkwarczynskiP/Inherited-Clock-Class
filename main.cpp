#include "Clock.h"
#include "CityClock.h"
#include <iostream>
using namespace std;

int main() {
    // Clock Object Using Default Constructor
    cout << endl << "Clock Object Using Default Constructor:" << endl;
    Clock defaultClock;
    defaultClock.show();

    cout << endl << "Incrementing Time by One Second:" << endl;
    defaultClock.tick();
    defaultClock.show();

    cout << endl << "Switching Time Format:" << endl;
    defaultClock.toggleFormat();
    defaultClock.show();


    // Clock Object Using Constructor with Three Arguments
    cout << endl << "Clock Object Using Constructor with Three Arguments:" << endl;
    Clock customClock(12, 45, 35);
    customClock.show();

    cout << endl << "Incrementing Time by One Second:" << endl;
    customClock.tick();
    customClock.show();

    cout << endl << "Switching Time Format:" << endl;
    customClock.toggleFormat();
    customClock.show();


    // CityClock Object Using Default Constructor
    cout << endl << "CityClock Object Using Default Constructor:" << endl;
    CityClock defaultCityClock;
    defaultCityClock.show();

    cout << endl << "Incrementing Time by One Second:" << endl;
    defaultCityClock.tick();
    defaultCityClock.show();

    cout << endl << "Switching Time Format:" << endl;
    defaultCityClock.toggleFormat();
    defaultCityClock.show();


    // CityClock Object Using Constructor with Four Arguments
    cout << endl << "CityClock Object Using Constructor with Four Arguments:" << endl;
    CityClock customCityClock("Auburn Hills, Michigan", 2, 45, 35);
    customCityClock.show();

    cout << endl << "Incrementing Time by One Second:" << endl;
    customCityClock.tick();
    customCityClock.show();

    cout << endl << "Switching Time Format:" << endl;
    customCityClock.toggleFormat();
    customCityClock.show();


    // New CityClock Object for Demonstrating Remaining Features
    cout << endl << "Create New CityClock Object:" << endl;
    CityClock clock1("Troy, Michigan", 6, 30, 45);
    clock1.show();

    cout << endl << "Demonstrating the Overloaded Addition Operator:" << endl;
    CityClock clock2 = clock1 + 3675; // Adding One Hour and One Minute and 15 Seconds
    clock2.show();

    cout << endl << "Demonstrating the Copy Constructor:" << endl;
    CityClock clock3(clock2);
    clock3.show();

    cout << endl << "Demonstrating the Move Constructor:" << endl;
    CityClock clock4(move(clock3));
    clock4.show();

    cout << endl << "Demonstrating the Copy Assignment Operator:" << endl;
    CityClock clock5;
    clock5 = clock4;
    clock5.show();

    cout << endl << "Demonstrating the Move Assignment Operator:" << endl;
    CityClock clock6;
    clock6 = move(clock5);
    clock6.show();

    cout << endl << "Demonstrating the Type Conversion Function:" << endl;
    string stringOne = clock6;
    cout << stringOne << endl;

    cout << endl << "CityClock Destructor is Automatically Called for Each Object" << endl;
    return 0;
}