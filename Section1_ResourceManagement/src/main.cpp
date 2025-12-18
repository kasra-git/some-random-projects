#include <iostream>
#include "../include/ResourceManager.hpp"

int main() {
    std::cout << "\n Resource Management System \n";
    
    ResourceManager manager;
    

    TimeInterval lab1(Time(8, 0), Time(10, 0));
    TimeInterval lab2(Time(10, 0), Time(12, 0));
    TimeInterval lab3(Time(13, 0), Time(15, 0));
    TimeInterval conflict(Time(9, 30), Time(11, 0));
    
    manager.addResource(1, "Computer Lab A", "Laboratory");
    manager.addResource(2, "Conference Room", "Meeting");
    manager.addResource(3, "Physics Lab", "Laboratory");
    
    manager.addIntervalToResource(1, lab1);
    manager.addIntervalToResource(1, lab2);
    manager.addIntervalToResource(1, lab3);
    

    if (manager.addIntervalToResource(1, conflict)) {
        std::cout << "Interval added successfully.\n";
    } else {
        std::cout << "Failed to add interval due to conflict.\n";
    }
    
    manager.addIntervalToResource(2, TimeInterval(Time(14, 0), Time(16, 0)));
    manager.addIntervalToResource(3, TimeInterval(Time(9, 0), Time(11, 0)));
    
    manager.printAllResources();
    

    std::cout << "\n";
    manager.printResourceSchedule(1);
    

    manager.printSystemReport();
    

    std::cout << "\n Time Operations Demo \n";
    Time t1(9, 30);
    Time t2(11, 45);
    std::cout << "t1: " << t1 << "\n";
    std::cout << "t2: " << t2 << "\n";
    std::cout << "t1 < t2: " << (t1 < t2) << "\n";
    std::cout << "t2 - t1: " << (t2 - t1) << " minutes\n";
    
    std::cout << "\n TimeInterval Operations Demo \n";
    TimeInterval interval1(Time(8, 0), Time(10, 0));
    TimeInterval interval2(Time(9, 30), Time(11, 0));
    TimeInterval interval3(Time(10, 0), Time(12, 0));
    
    std::cout << "Interval 1: " << interval1 << "\n";
    std::cout << "Interval 2: " << interval2 << "\n";
    std::cout << "Interval 3: " << interval3 << "\n";
    std::cout << "Interval 1 overlaps Interval 2: " << interval1.overlaps(interval2) << "\n";
    std::cout << "Interval 1 overlaps Interval 3: " << interval1.overlaps(interval3) << "\n";
    std::cout << "Interval 1 duration: " << interval1.duration() << " minutes\n";
    
    return 0;
}