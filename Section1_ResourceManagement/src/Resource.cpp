#include "../include/Resource.hpp"
#include <algorithm>
#include <iomanip>
#include <sstream>

Resource::Resource(int resourceId, const std::string& resourceName, const std::string& resourceType) : id(resourceId), name(resourceName), type(resourceType) {}

int Resource::getId() const { return id; }
std::string Resource::getName() const { return name; }
std::string Resource::getType() const { return type; }
const std::vector<TimeInterval>& Resource::getIntervals() const { return intervals; }

bool Resource::addInterval(const TimeInterval& interval) {
    if (!interval.isValid()) 
        return false;
    
    if (hasConflict(interval)) 
        return false;
    
    intervals.push_back(interval);
    
    std::sort(intervals.begin(), intervals.end());
    return true;
}

bool Resource::hasConflict(const TimeInterval& interval) const {
    if (!interval.isValid()) 
        return true;
    
    for (const auto& existing : intervals) {
        if (existing.overlaps(interval))
            return true;
    }
    return false;
}

bool Resource::removeInterval(int index) {
    if (index < 0 || index >= static_cast<int>(intervals.size()))
        return false;
    
    intervals.erase(intervals.begin() + index);
    return true;
}

void Resource::clearIntervals() {
    intervals.clear();
}

void Resource::printSchedule() const {
    std::cout << getScheduleAsString();
}

std::string Resource::getScheduleAsString() const {
    std::ostringstream oss;
    oss << "\n Schedule for Resource: " << name << " (ID: " << id << ", Type: " << type << ") \n";
    
    if (intervals.empty()) {
        oss << "No scheduled intervals.\n";
    } else {
        oss << std::left << std::setw(5) << "No." 
            << std::setw(15) << "Start" 
            << std::setw(15) << "End" 
            << std::setw(10) << "Duration" 
            << "\n";
        oss << std::string(45, '-') << "\n";
        
        for (size_t i = 0; i < intervals.size(); ++i) {
            const TimeInterval& interval = intervals[i];
            oss << std::left << std::setw(5) << i + 1
                << std::setw(15) << interval.getStart().toString()
                << std::setw(15) << interval.getEnd().toString()
                << std::setw(10) << interval.duration() << " min\n";
        }
    }
    return oss.str();
}

std::string Resource::formatResourceType(const std::string& type) {
    std::string formatted = type;
    if (!formatted.empty()) {
        formatted[0] = toupper(formatted[0]);
    }
    return formatted;
}

std::ostream& operator<<(std::ostream& os, const Resource& resource) {
    os << "Resource[ID=" << resource.id 
       << ", Name=\"" << resource.name 
       << "\", Type=\"" << resource.type 
       << "\", Intervals=" << resource.intervals.size() << "]";
    return os;
}