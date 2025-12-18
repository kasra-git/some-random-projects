#ifndef TIMEINTERVAL_H
#define TIMEINTERVAL_H

#include "Time.hpp"
#include <iostream>

class TimeInterval {
private:
    Time start;
    Time end;

public:
    TimeInterval();
    TimeInterval(const Time& s, const Time& e);
    
    Time getStart() const;
    Time getEnd() const;
    
    bool isValid() const;
    
    bool overlaps(const TimeInterval& other) const;
    int duration() const;
    TimeInterval merge(const TimeInterval& other) const;
    
    bool canMerge(const TimeInterval& other) const;

    bool operator<(const TimeInterval& other) const;
    bool operator==(const TimeInterval& other) const;
    TimeInterval operator+(const TimeInterval& other) const;
    
    std::string toString() const;
    friend std::ostream& operator<<(std::ostream& os, const TimeInterval& interval);
};

#endif