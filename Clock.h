#ifndef CLOCK_H
#define CLOCK_H
using namespace std;

class Clock {
protected:
    int hours;
    int minutes;
    int seconds;
    bool is24Hour;
    bool isAM;

public:
    Clock(); //Default Constructor
    Clock(int, int, int); // Constructor that takes three arguments
    virtual void toggleFormat(); // Function to Switch Time Format
    virtual void show(); // Function to Display Time
    virtual void tick(); // Function to Increment Time
};

#endif
