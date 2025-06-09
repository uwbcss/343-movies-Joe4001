#include "return.h"
#include "customerTable.h"
#include "inventory.h"
#include <iostream>
#include <sstream>

Return::Return(int customerId, char mediaType, char movieType,
               const std::string &movieKey)
    : customerId(customerId), movieType(1, movieType), movieKey(movieKey) {}

void Return::execute(Inventory &inventory, CustomerTable &manager) {
  Customer *customer = manager.getCustomer(customerId);
  if (customer == nullptr) {
    std::cout << "ERROR: Customer ID " << customerId << " not found."
              << std::endl;
    return;
  }
  Movie *movie = inventory.searchMovie(movieKey);
  if (movie == nullptr) {
    std::cout << "ERROR: Movie not found: " << movieKey << std::endl;
    return;
  }
  movie->increaseStock();
  customer->addTransaction("Returned: " + movie->print());

}

ReturnFactory::ReturnFactory() { registerType("R", this); }

Command *ReturnFactory::makeCommand(const std::string &data) const {
  std::istringstream ss(data);
  std::string commandType;
  int customerId;
  char mediaType;
  char movieType;
  std::string movieKey;

  ss >> commandType >> customerId >> mediaType >> movieType;
  std::getline(ss, movieKey);
  movieKey.erase(0, movieKey.find_first_not_of(" "));

  return new Return(customerId, mediaType, movieType, movieKey);
}

// Static instance to self-register
static ReturnFactory globalReturnFactory;