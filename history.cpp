#include "history.h"
#include <iostream>
#include <sstream>

History::History(int customerId) : customerId(customerId) {}

void History::execute(Inventory & inv, CustomerTable &manager) {
  Customer *customer = manager.getCustomer(customerId);
  if (customer == nullptr) {
    std::cout << "ERROR: Customer ID " << customerId << " not found."
              << std::endl;
    return;
  }
  std::cout << "Transaction history for customer " << customerId << ":\n";
  customer->printHistory();
}

HistoryFactory::HistoryFactory() { registerType("H", this); }

Command *HistoryFactory::makeCommand(const std::string &data) const {
  std::istringstream ss(data);
  std::string commandType;
  int customerId;
  ss >> commandType >> customerId;
  return new History(customerId);
}

static HistoryFactory globalHistoryFactory;