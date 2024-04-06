#include "CityClock.h"
#include <iostream>
using namespace std;

int main() {

    cout << "CityClock Object Using Default Constructor:" << endl;
    CityClock clock1;
    clock1.show();

    cout << endl << "CityClock Object Using Constructor with Four Arguments:" << endl;
    CityClock clock2("Auburn Hills, Michigan", 12, 45, 35);
    clock2.show();

    cout << endl << "Incrementing Time by One Second:" << endl;
    clock1.tick();
    clock1.show();

    clock2.tick();
    clock2.show();

    cout << endl << "Switching Time Format:" << endl;
    clock1.toggleFormat();
    clock1.show();

    clock2.toggleFormat();
    clock2.show();

    cout << endl << "Create New CityClock Object:" << endl;
    CityClock clock3("Troy, Michigan", 6, 30, 45);
    clock3.show();

    cout << endl << "Demonstrating the Overloaded Addition Operator:" << endl;
    CityClock clock4 = clock3 + 3675; // Adding One Hour and One Minute and 15 Seconds
    clock4.show();

    cout << endl << "Demonstrating the Copy Constructor:" << endl;
    CityClock clock5(clock4);
    clock5.show();

    cout << endl << "Demonstrating the Move Constructor:" << endl;
    CityClock clock6(move(clock5));
    clock6.show();

    cout << endl << "Demonstrating the Copy Assignment Operator:" << endl;
    CityClock clock7;
    clock7 = clock6;
    clock7.show();

    cout << endl << "Demonstrating the Move Assignment Operator:" << endl;
    CityClock clock8;
    clock8 = move(clock7);
    clock8.show();

    cout << endl << "Demonstrating the Type Conversion Function:" << endl;
    string stringOne = clock8;
    cout << stringOne << endl;

    cout << endl << "CityClock Destructor is Automatically Called for Each Object" << endl;
    return 0;
}