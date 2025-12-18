#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <string>

class Time {
private:
    int hour;
    int minute;

public:
    Time();
    Time(int h, int m);
    
    int getHour() const;
    int getMinute() const;
    
    bool isValid() const;
    
    bool operator<(const Time& other) const;
    bool operator==(const Time& other) const;
    bool operator>(const Time& other) const;
    bool operator!=(const Time& other) const;
    int operator-(const Time& other) const;
    
    std::string toString() const;
    
    friend std::ostream& operator<<(std::ostream& os, const Time& time);
};

#endif