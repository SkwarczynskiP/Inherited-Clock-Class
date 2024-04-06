#ifndef CITYCLOCK_H
#define CITYCLOCK_H
#include <cstring>
#include <string>
using namespace std;

class CityClock{
private:
    int hours;
    int minutes;
    int seconds;
    bool is24Hour;
    bool isAM;
    char* cityName;

public:
    CityClock(); //Default Constructor
    CityClock(const char*, int, int, int); //Constructor that takes four arguments
    CityClock(const char*, int, int, int, bool, bool); //Constructor that takes six arguments
    CityClock(const CityClock&); //Copy Constructor
    CityClock(CityClock&&); //Move Constructor
    CityClock& operator=(const CityClock&); //Copy Assignment Operator
    CityClock& operator=(CityClock&&); //Move Assignment Operator
    void toggleFormat(); //Function to Switch Time Format
    void show(); //Function to Display Time
    void tick(); //Function to Increment Time
    operator string() const; //Type Conversion Function
    CityClock operator+(int) const; //Overloaded Addition Operator
    friend ostream& operator<<(ostream&, const CityClock&);  //Overloaded Ostream Insertion Operator
    ~CityClock(); //Destructor
};

#endif
