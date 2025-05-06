#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){};
TargetGenerator::~TargetGenerator(){
    for (auto& map : _targets)
        delete map.second;
    _targets.clear();
};

void TargetGenerator::learnTargetType(ATarget *target) {
    auto it = _targets.find(target->getType());
    if (it != _targets.end())
    {
      delete it->second;
      it->second = target->clone();
    }
    else 
        _targets.emplace(target->getType(), target->clone());
};

void TargetGenerator::forgetTargetType(const std::string &targetType){
    auto it = _targets.find(targetType);
    if(it != _targets.end())
    {
        delete it->second;
        _targets.erase(it);
    }
};

ATarget* TargetGenerator::createTarget(const std::string &targetType){
    auto it = _targets.find(targetType);
    if (it != _targets.end())
    {
        return (it->second->clone());
    }
    else
        return nullptr;
};