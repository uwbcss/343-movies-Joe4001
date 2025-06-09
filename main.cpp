/**
 * Driver for starting movie store tests
 */

#include "command.h"
#include "customerTable.h"
#include "inventory.h"
#include <fstream>
#include <iostream>
#include <string>

void loadInventory(const std::string &filename, Inventory &inventory) {
    std::ifstream infile(filename);
    std::string line;
    while (std::getline(infile, line)) {
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
        Customer *customer = CustomerFactory::create(line);
        if (customer != nullptr) {
            customers.addCustomer(*customer);
            delete customer;
        } else {
            std::cout << "Discarding invalid customer entry: " << line << std::endl;
        }
    }
}

void executeCommands(const std::string &filename, Inventory &inventory, CustomerTable &customers) {
    std::ifstream infile(filename);
    std::string line;
    while (std::getline(infile, line)) {
        Command *cmd = CommandFactory::create(line);
        if (cmd != nullptr) {
            cmd->execute(inventory, customers);
            delete cmd;
        } else {
            std::cout << "Discarding invalid command: " << line << std::endl;
        }
    }
}

int main() {
    Inventory inventory;
    CustomerTable customers;
    loadInventory("data4movies.txt", inventory);
    loadCustomers("data4customers.txt", customers);
    executeCommands("data4commands.txt", inventory, customers);
    std::cout << "Done!" << std::endl;
    return 0;
}