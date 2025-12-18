#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "Resource.hpp"
#include <vector>

class ResourceManager {
private:
    std::vector<Resource> resources;
    static int totalResources;
    
public:
    ResourceManager();
    ~ResourceManager();
    

    bool addResource(const Resource& resource);
    bool addResource(int id, const std::string& name, const std::string& type);
    bool removeResource(int id);
    

    Resource* findResource(int id);
    const Resource* findResource(int id) const;
    std::vector<Resource*> findResourcesByName(const std::string& name);
    std::vector<Resource*> findResourcesByType(const std::string& type);
    

    bool addIntervalToResource(int resourceId, const TimeInterval& interval);
    bool hasResourceConflict(int resourceId, const TimeInterval& interval) const;
    

    void printAllResources() const;
    void printResourceSchedule(int resourceId) const;
    void printSystemReport() const;
    

    int getResourceCount() const;
    static int getTotalResourcesCreated();
    
    void clearAllResources();
    bool isResourceIdUnique(int id) const;
    
    const std::vector<Resource>& getAllResources() const;
};

#endif 