#include "../include/Time.hpp"
#include <iomanip>
#include <sstream>

Time::Time() : hour(0), minute(0) {}

Time::Time(int h, int m) : hour(h), minute(m) {
    if (!isValid()) {
        hour = 0;
        minute = 0;
    }
}

int Time::getHour() const { return hour; }
int Time::getMinute() const { return minute; }

bool Time::isValid() const {
    return (hour >= 0 && hour < 24) && (minute >= 0 && minute < 60);
}

bool Time::operator<(const Time& other) const {
    if (hour != other.hour) 
        return hour < other.hour;
    return minute < other.minute;
}

bool Time::operator==(const Time& other) const {
    return (hour == other.hour) && (minute == other.minute);
}

bool Time::operator!=(const Time& other) const {
    return !(*this == other);
}

int Time::operator-(const Time& other) const {
    int thisMinutes = hour * 60 + minute;
    int otherMinutes = other.hour * 60 + other.minute;
    return thisMinutes - otherMinutes;
}

std::string Time::toString() const {
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << hour << ":" << std::setw(2) << std::setfill('0') << minute;
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Time& time) {
    os << time.toString();
    return os;
}