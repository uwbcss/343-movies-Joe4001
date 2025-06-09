#ifndef COMMAND_H
#define COMMAND_H

#include "customerTable.h"
#include "inventory.h"
#include <map>
#include <string>

class Command {
public:
  virtual ~Command() = default;
  virtual void execute(Inventory &inventory, CustomerTable &customers) = 0;
};

class CommandFactory {
public:
  virtual Command *makeCommand(const std::string &data) const = 0;
  static Command *create(const std::string &data);

protected:
  static void registerType(const std::string &type, CommandFactory *factory);

private:
  static std::map<std::string, CommandFactory *> &getMap();
};

#endif