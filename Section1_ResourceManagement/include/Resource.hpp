#ifndef RESOURCE_H
#define RESOURCE_H

#include "TimeInterval.hpp"
#include <string>
#include <vector>
#include <iostream>

class Resource {
private:
    int id;
    std::string name;
    std::string type;
    std::vector<TimeInterval> intervals;

public:
    Resource(int resourceId, const std::string& resourceName, const std::string& resourceType);
    
    int getId() const;
    std::string getName() const;
    std::string getType() const;
    const std::vector<TimeInterval>& getIntervals() const;
    
    bool addInterval(const TimeInterval& interval);
    bool hasConflict(const TimeInterval& interval) const;
    bool removeInterval(int index);
    
    void clearIntervals();
    
    void printSchedule() const;
    
    std::string getScheduleAsString() const;
    

    static std::string formatResourceType(const std::string& type);
    

    friend std::ostream& operator<<(std::ostream& os, const Resource& resource);
};

#endif 