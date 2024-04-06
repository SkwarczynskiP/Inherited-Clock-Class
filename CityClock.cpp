#include <iostream>
#include <iomanip>
#include <sstream>
#include "CityClock.h"
using namespace std;

//Default Constructor
CityClock::CityClock(){
    hours = 0;
    minutes = 0;
    seconds = 0;
    is24Hour = true;
    isAM = true;
    cityName = new char[strlen("Rochester, Michigan") + 1];
    strcpy(cityName, "Rochester, Michigan");
}

//Constructor that takes four arguments
CityClock::CityClock(const char* name, int h, int m, int s){
    is24Hour = true;
    isAM = true;
    if (h >= 0 && h <= 23 && m >= 0 && m <= 59 && s >= 0 && s <= 59) {
        hours = h;
        minutes = m;
        seconds = s;
    } else {
        cout << "Error: Invalid Input. Time set to 00:00:00" << endl;
        hours = 0;
        minutes = 0;
        seconds = 0;
    }
    cityName = new char[strlen(name) + 1];
    strcpy(cityName, name);
}

//Constructor that takes six arguments
CityClock::CityClock(const char* name, int h, int m, int s, bool format, bool am){
    is24Hour = format;
    isAM = am;
    if (is24Hour) {
        if (h >= 0 && h <= 23 && m >= 0 && m <= 59 && s >= 0 && s <= 59) {
            hours = h;
            minutes = m;
            seconds = s;
        } else {
            cout << "Error: Invalid Input. Time set to 00:00:00" << endl;
            hours = 0;
            minutes = 0;
            seconds = 0;
        }
    } else {
        if (h >= 1 && h <= 12 && m >= 0 && m <= 59 && s >= 0 && s <= 59) {
            hours = h;
            minutes = m;
            seconds = s;
        } else {
            cout << "Error: Invalid Input. Time set to 00:00:00" << endl;
            hours = 0;
            minutes = 0;
            seconds = 0;
        }
    }
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
    if (is24Hour) {
        if (hours >= 0 && hours <= 11) {
            if (hours == 0) {
                hours = 12;
            }
            isAM = true;
        } else {
            if (hours == 12) {
                hours = 12;
            } else {
                hours = hours - 12;
            }
            isAM = false;
        }
    } else {
        if (isAM && hours == 12) {
            hours = 0;
        } else if (!isAM && hours == 12) {
            hours = 12;
        } else if (!isAM) {
            hours = hours + 12;
        }
    }
    is24Hour = !is24Hour;
}

//Member function to display the time
void CityClock::show() {
    cout << cityName << " - ";
    if (is24Hour) {
        cout << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << endl;
    } else {
        cout << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds;
        if (isAM) {
            cout << " AM" << endl;
        } else {
            cout << " PM" << endl;
        }
    }
}

//Member function to advance the time by one second
void CityClock::tick() {
    seconds++;

    if (seconds == 60) {
        seconds = 0;
        minutes++;

        if (minutes == 60) {
            minutes = 0;
            hours++;

            if (hours == 24) {
                hours = 0;
            }
        }
    }
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
