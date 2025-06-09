#include "command.h"
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

inline std::string trim(const std::string& s) {
    auto start = s.find_first_not_of(" \t\r\n");
    auto end = s.find_last_not_of(" \t\r\n");
    return (start == std::string::npos) ? "" : s.substr(start, end - start + 1);
}

std::map<std::string, CommandFactory*>& CommandFactory::getMap() {
    static std::map<std::string, CommandFactory*> factories;
    return factories;
}

void CommandFactory::registerType(const std::string& type, CommandFactory* factory) {
    getMap()[type] = factory;
}

Command* CommandFactory::create(const std::string& data) {
    std::istringstream ss(data);
    std::string commandType;
    ss >> commandType;
    commandType = trim(commandType);

    if (getMap().count(commandType) == 0) {
        std::cout << "Do not know how to create command: " << commandType << std::endl;
        return nullptr;
    }
    return getMap().at(commandType)->makeCommand(data);
}
