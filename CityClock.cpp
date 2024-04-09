#include <iostream>
#include <iomanip>
#include <sstream>
#include "CityClock.h"
using namespace std;

//Default Constructor
CityClock::CityClock() : Clock() {
    cityName = new char[strlen("Rochester, Michigan") + 1];
    strcpy(cityName, "Rochester, Michigan");
}

//Constructor that takes four arguments
CityClock::CityClock(const char* name, int h, int m, int s) : Clock(h, m, s) {
    cityName = new char[strlen(name) + 1];
    strcpy(cityName, name);
}

//Copy Constructor
CityClock::CityClock(const CityClock &other) : Clock(other) {
    cityName = new char[strlen(other.cityName) + 1];
    strcpy(cityName, other.cityName);
}

//Move Constructor
CityClock::CityClock(CityClock &&other) : Clock(move(other)) {
    cityName = other.cityName;
    other.cityName = nullptr;
}

//Copy Assignment Operator
CityClock &CityClock::operator=(const CityClock &other){
    if (this != &other) {
        Clock::operator=(other);
        delete[] cityName;
        cityName = new char[strlen(other.cityName) + 1];
        strcpy(cityName, other.cityName);
    }
    return *this;
}

//Move Assignment Operator
CityClock &CityClock::operator=(CityClock &&other){
    if (this != &other) {
        Clock::operator=(move(other));
        delete[] cityName;
        cityName = other.cityName;
        other.cityName = nullptr;
    }
    return *this;
}

//Destructor
CityClock::~CityClock(){
    delete[] cityName;
}

//Member function to switch the time format
void CityClock::toggleFormat() {
    Clock::toggleFormat();
}

//Member function to display the time
void CityClock::show() {
    cout << cityName << " - ";
    Clock::show();
}

//Member function to advance the time by one second
void CityClock::tick() {
    Clock::tick();
}

//Type Conversion Function
CityClock::operator string() const {
    stringstream timeFormat;
    if (is24Hour) {
        timeFormat << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds;
    } else {
        timeFormat << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds;
        if (isAM) {
            timeFormat << " AM";
        } else {
            timeFormat << " PM";
        }
    }
    return string(cityName) + " - " + timeFormat.str();
}

//Overloaded Addition Operator
CityClock CityClock::operator+(int sec) const {
    CityClock newClock(*this);
    newClock.seconds += sec;

    while (newClock.seconds >= 60) {
        newClock.seconds -= 60;
        newClock.minutes++;
    }

    while (newClock.minutes >= 60) {
        newClock.minutes -= 60;
        newClock.hours++;
    }

    while (newClock.hours >= 24) {
        newClock.hours -= 24;
    }

    return newClock;
}

//Overloaded Ostream Insertion Operator
ostream& operator<<(ostream& os, const CityClock& clock) {
    os << static_cast<string>(clock);
    return os;
}
