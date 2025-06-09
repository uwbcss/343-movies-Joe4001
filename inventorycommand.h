#include "command.h"

class InventoryCommand : public Command {
public:
  InventoryCommand() = default;
  void execute(Inventory &inventory, CustomerTable &manager) override;
};

class InventoryCommandFactory : public CommandFactory {
public:
  InventoryCommandFactory();
  Command *makeCommand(const std::string &data) const override;
};