#include "../include/TimeInterval.hpp"
#include <stdexcept>
#include <sstream>

TimeInterval::TimeInterval() : start(Time()), end(Time()) {}

TimeInterval::TimeInterval(const Time& s, const Time& e) : start(s), end(e) {
    if (!isValid()) {
        start = Time();
        end = Time();
    }
}

Time TimeInterval::getStart() const { return start; }
Time TimeInterval::getEnd() const { return end; }

bool TimeInterval::isValid() const {
    return start.isValid() && end.isValid() && start < end;
}

bool TimeInterval::overlaps(const TimeInterval& other) const {
    if (!isValid() || !other.isValid()) return false;
    
    return !(end <= other.start || other.end <= start);
}

int TimeInterval::duration() const {
    if (!isValid()) return 0;
    return end - start; 
}

TimeInterval TimeInterval::merge(const TimeInterval& other) const {
    if (!canMerge(other)) {
        throw std::invalid_argument("Cannot merge non-overlapping or non-consecutive intervals");
    }
    
    Time newStart = start < other.start ? start : other.start;
    Time newEnd = end > other.end ? end : other.end;
    
    return TimeInterval(newStart, newEnd);
}

bool TimeInterval::canMerge(const TimeInterval& other) const {
    if (!isValid() || !other.isValid()) return false;
    
    if (overlaps(other)) return true;
    
    if (end == other.start || other.end == start) return true;
    
    return false;
}

bool TimeInterval::operator<(const TimeInterval& other) const {
    if (start != other.start) return start < other.start;
    return end < other.end;
}

bool TimeInterval::operator==(const TimeInterval& other) const {
    return start == other.start && end == other.end;
}

TimeInterval TimeInterval::operator+(const TimeInterval& other) const {
    return merge(other);
}

std::string TimeInterval::toString() const {
    std::ostringstream oss;
    oss << start.toString() << " - " << end.toString() 
        << " (" << duration() << " minutes)";
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const TimeInterval& interval) {
    os << interval.toString();
    return os;
}