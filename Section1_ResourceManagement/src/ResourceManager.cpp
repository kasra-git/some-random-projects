#include "../include/ResourceManager.hpp"
#include <algorithm>
#include <iomanip>

int ResourceManager::totalResources = 0;

ResourceManager::ResourceManager() {}

ResourceManager::~ResourceManager() { clearAllResources(); }

bool ResourceManager::addResource(const Resource& resource) {
    if (!isResourceIdUnique(resource.getId())) {
        return false;
    }
    
    resources.push_back(resource);
    totalResources++;
    return true;
}

bool ResourceManager::addResource(int id, const std::string& name, const std::string& type) {
    if (!isResourceIdUnique(id))
        return false;
    
    resources.emplace_back(id, name, type);
    totalResources++;
    return true;
}

bool ResourceManager::removeResource(int id) {
    auto it = std::find_if(resources.begin(), resources.end(),
        [id](const Resource& r) { return r.getId() == id; });
    
    if (it != resources.end()) {
        resources.erase(it);
        return true;
    }
    
    return false;
}

Resource* ResourceManager::findResource(int id) {
    auto it = std::find_if(resources.begin(), resources.end(),
        [id](const Resource& r) { return r.getId() == id; });
    
    return (it != resources.end()) ? &(*it) : nullptr;
}

const Resource* ResourceManager::findResource(int id) const {
    auto it = std::find_if(resources.begin(), resources.end(),
        [id](const Resource& r) { return r.getId() == id; });
    
    return (it != resources.end()) ? &(*it) : nullptr;
}

std::vector<Resource*> ResourceManager::findResourcesByName(const std::string& name) {
    std::vector<Resource*> result;
    for (auto& resource : resources) {
        if (resource.getName() == name) {
            result.push_back(&resource);
        }
    }
    return result;
}

std::vector<Resource*> ResourceManager::findResourcesByType(const std::string& type) {
    std::vector<Resource*> result;
    for (auto& resource : resources) {
        if (resource.getType() == type) {
            result.push_back(&resource);
        }
    }
    return result;
}

bool ResourceManager::addIntervalToResource(int resourceId, const TimeInterval& interval) {
    Resource* resource = findResource(resourceId);
    if (!resource) return false;
    
    return resource->addInterval(interval);
}

bool ResourceManager::hasResourceConflict(int resourceId, const TimeInterval& interval) const {
    const Resource* resource = findResource(resourceId);
    if (!resource) return false;
    
    return resource->hasConflict(interval);
}

void ResourceManager::printAllResources() const {
    std::cout << "\n All Resources in System \n";
    std::cout << std::left << std::setw(5) << "ID" 
              << std::setw(20) << "Name" 
              << std::setw(15) << "Type" 
              << std::setw(10) << "Intervals" 
              << "\n";
    std::cout << std::string(50, '-') << "\n";
    
    for (const auto& resource : resources) {
        std::cout << std::left << std::setw(5) << resource.getId()
                  << std::setw(20) << resource.getName()
                  << std::setw(15) << resource.getType()
                  << std::setw(10) << resource.getIntervals().size()
                  << "\n";
    }
}

void ResourceManager::printResourceSchedule(int resourceId) const {
    const Resource* resource = findResource(resourceId);
    if (resource) {
        resource->printSchedule();
    } else {
        std::cout << "Resource with ID " << resourceId << " not found.\n";
    }
}

void ResourceManager::printSystemReport() const {
    std::cout << "\n System Report \n";
    std::cout << "Total Resources in Manager: " << resources.size() << "\n";
    std::cout << "Total Resources Created: " << totalResources << "\n";
    std::cout << "\nResource Distribution by Type:\n";
    
    
    std::cout << "\nDetailed Resource Information:\n";
    for (const auto& resource : resources) {
        std::cout << "  - " << resource << "\n";
    }
}

int ResourceManager::getResourceCount() const {
    return static_cast<int>(resources.size());
}

int ResourceManager::getTotalResourcesCreated() {
    return totalResources;
}

void ResourceManager::clearAllResources() {
    resources.clear();
}

bool ResourceManager::isResourceIdUnique(int id) const {
    return findResource(id) == nullptr;
}

const std::vector<Resource>& ResourceManager::getAllResources() const {
    return resources;
}