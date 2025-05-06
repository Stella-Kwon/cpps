#pragma once

#include <string>
#include <vector>
#include "ATarget.hpp"

class TargetGenerator {
    private:
        std::unordered_map<std::string, ATarget*> _targets;
        TargetGenerator(const TargetGenerator& other);
        TargetGenerator& operator=(const TargetGenerator& other);
    public:
        TargetGenerator();
        ~TargetGenerator();

        void learnTargetType(ATarget *target);
        void forgetTargetType(const std::string &targetType);
        ATarget *createTarget(const std::string &targetType);
};