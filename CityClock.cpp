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
CityClock::CityClock(const CityClock &other){
    hours = other.hours;
    minutes = other.minutes;
    seconds = other.seconds;
    is24Hour = other.is24Hour;
    isAM = other.isAM;
    cityName = new char[strlen(other.cityName) + 1];
    strcpy(cityName, other.cityName);
}

//Move Constructor
CityClock::CityClock(CityClock &&other){
    hours = other.hours;
    minutes = other.minutes;
    seconds = other.seconds;
    is24Hour = other.is24Hour;
    isAM = other.isAM;
    cityName = other.cityName;
    other.cityName = nullptr;
}

//Copy Assignment Operator
CityClock &CityClock::operator=(const CityClock &other){
    if (this != &other) {
        hours = other.hours;
        minutes = other.minutes;
        seconds = other.seconds;
        is24Hour = other.is24Hour;
        isAM = other.isAM;
        delete[] cityName;
        cityName = new char[strlen(other.cityName) + 1];
        strcpy(cityName, other.cityName);
    }
    return *this;
}

//Move Assignment Operator
CityClock &CityClock::operator=(CityClock &&other){
    if (this != &other) {
        hours = other.hours;
        minutes = other.minutes;
        seconds = other.seconds;
        is24Hour = other.is24Hour;
        isAM = other.isAM;
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
    os << clock.cityName << " - ";
    if (clock.is24Hour) {
        os << setw(2) << setfill('0') << clock.hours << ":" << setw(2) << setfill('0') << clock.minutes << ":" << setw(2) << setfill('0') << clock.seconds;
    } else {
        os << setw(2) << setfill('0') << clock.hours << ":" << setw(2) << setfill('0') << clock.minutes << ":" << setw(2) << setfill('0') << clock.seconds;
        if (clock.isAM) {
            os << " AM";
        } else {
            os << " PM";
        }
    }
    return os;
}
