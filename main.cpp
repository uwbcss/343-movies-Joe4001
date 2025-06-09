/**
 * Driver for starting movie store tests
 */
#include "command.h"
#include "customerTable.h"
#include "inventory.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// forward declaration, implementation in store_test.cpp
void testAll();

void loadCommand(string commandFileName, Inventory &inventory,
                 CustomerTable &customers) {
  std::ifstream commandFile("data4commands.txt");
  std::string line;
  while (getline(commandFile, line)) {
    Command *cmd = CommandFactory::create(line);
    if (cmd != nullptr) {
      cmd->execute(inventory, customers);
      delete cmd;
    }
  }
}
void loadInventory(const std::string &filename, Inventory &inventory) {
  std::ifstream infile(filename);
  std::string line;
  while (std::getline(infile, line)) {
    Movie *movie = MovieFactory::create(line);
    if (movie != nullptr) {
      inventory.addMovie(movie);
    } else {
      std::cout << "Invalid movie entry: " << line << std::endl;
    }
  }
}

void loadCustomers(const string &filename, CustomerTable &customers) {
  std::ifstream infile(filename);
  std::string line;
  while (std::getline(infile, line)) {
    Customer *customer = CustomerFactory::create(line);
    if (customer != nullptr) {
      customers.addCustomer(*customer);
    } else {
      std::cout << "Invalid customer entry: " << line << std::endl;
    }
  }
}

void testMovie(){
  std::ifstream infile("data4movies.txt");
    std::string line;
    std::vector<Movie*> movies;

    while (std::getline(infile, line)) {
        Movie* movie = MovieFactory::create(line);
        if (movie && movie->getType() == "F") { // Only add Comedy
            movies.push_back(movie);
        } else if (movie) {
            delete movie; // Clean up non-comedy movies
        }
    }

    std::cout << "All Comedy Movies:\n";
    for (const auto& m : movies) {
        std::cout << m->print() << std::endl;
    }

    // Clean up
    for (auto m : movies) {
        delete m;
    }
}


int main() {
  //Inventory inventory;
  //CustomerTable customers;
  testMovie();
  //loadInventory("data4movies.txt", inventory);
  //loadCustomers("data4customers.txt", customers);
  //loadCommand("data4commands.txt", inventory, customers);
  testAll();
  return 0;
}
