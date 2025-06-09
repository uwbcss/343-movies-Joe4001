/**
 * Testing ass4 movie store functions
 *
 * @author Yusuf Pisan
 * @date 19 Jan 2019
 */

#include "command.h"
#include "customerTable.h"
#include "inventory.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

void loadInventory(const std::string &filename, Inventory &inventory) {
  std::ifstream infile(filename);
  std::string line;
  while (std::getline(infile, line)) {
    if (line.empty()) {
      continue;
    }
    Movie *movie = MovieFactory::create(line);
    if (movie != nullptr) {
      inventory.addMovie(movie);
    } else {
      std::cout << "Discarding invalid movie entry: " << line << std::endl;
    }
  }
}

void loadCustomers(const std::string &filename, CustomerTable &customers) {
  std::ifstream infile(filename);
  std::string line;
  while (std::getline(infile, line)) {
    if (line.empty()) {
      continue;
    }
    Customer *customer = CustomerFactory::create(line);
    if (customer != nullptr) {
      customers.addCustomer(*customer);
      delete customer;
    } else {
      std::cout << "Discarding invalid customer entry: " << line << std::endl;
    }
  }
}

void executeCommands(const std::string &filename, Inventory &inventory,
                     CustomerTable &customers) {
  std::ifstream infile(filename);
  std::string line;
  while (std::getline(infile, line)) {
    if (line.empty()) {
      continue;
    }
    Command *cmd = CommandFactory::create(line);
    if (cmd != nullptr) {
      cmd->execute(inventory, customers);
      delete cmd;
    } else {
      std::cout << "Discarding invalid command: " << line << std::endl;
    }
  }
}

void testStore1() {
  cout << "Start testStore1" << endl;
  // Should do something more, but lets just read files
  // since each implementation will
  string cfile = "testcommands-1.txt";
  stringstream out;
  ifstream fs(cfile);
  assert(fs.is_open());
  char commandType;
  string discard;
  while (fs >> commandType) {
    out << commandType;
    getline(fs, discard);
  }
  fs.close();
  string result = "IHHBRIBBIH";
  assert(out.str() == result);
  cout << "End testStore1" << endl;
}

// test using my files, use same movie base
void testStore2() {
  cout << "Start testStore2" << endl;
  CustomerTable customers;
  Inventory inventory;
  loadInventory("data4movies.txt", inventory);
  loadCustomers("my-customer-data.txt", customers);
  executeCommands("my-command-data.txt", inventory, customers);
  cout << "End testStore2" << endl;
}

void testStoreFinal() {
  cout << "Start testStoreFinal" << endl;
  CustomerTable customers;
  Inventory inventory;
  loadInventory("data4movies.txt", inventory);
  loadCustomers("data4customers.txt", customers);
  executeCommands("data4commands.txt", inventory, customers);
  cout << "End testStoreFinal" << endl;
}

void testAll() {
  testStore1();
  testStore2();
  testStoreFinal();
}
