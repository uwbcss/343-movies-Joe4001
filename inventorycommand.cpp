#include "inventorycommand.h"
#include <iostream>

void InventoryCommand::execute(Inventory &inventory, CustomerTable & /*manager*/) {
  inventory.printInventory();
}

InventoryCommandFactory::InventoryCommandFactory() { registerType("I", this); }

Command *InventoryCommandFactory::makeCommand(const std::string & /*data*/) const {
  return new InventoryCommand();
}

static InventoryCommandFactory globalInventoryCommandFactory;