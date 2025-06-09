#include "borrow.h"
#include "customerTable.h"
#include "inventory.h"
#include <iostream>
#include <sstream>

Borrow::Borrow(int customerId, char mediaType, char movieType, const std::string& movieKey)
    : customerId(customerId), mediaType(mediaType), movieType(movieType), movieKey(movieKey) {}

void Borrow::execute(Inventory& inventory, CustomerTable& customers) {
    std::cout << "Executing Borrow Command for " << customers.getCustomer(customerId)
              << ", Media Type: " << mediaType 
              << ", Movie Type: " << movieType 
              << ", Movie Key: " << movieKey << std::endl;
    Customer* customer = customers.getCustomer(customerId);
    if (!customer) {
        std::cout << "ERROR: Customer ID " << customerId << " not found." << std::endl;
        return;
    }
    Movie* movie = inventory.searchMovie(movieKey);
    if (!movie) {
        std::cout << "ERROR: Movie not found: " << movieKey << std::endl;
        return;
    }
    if (movie->getStock() > 0) {
        movie->decreaseStock();
        customer->addTransaction("Borrowed: " + movie->print());
    } else {
        std::cout << "ERROR: Movie out of stock: " << movieKey << std::endl;
    }
}

BorrowFactory::BorrowFactory() {
    registerType("B", this);
}

Command* BorrowFactory::makeCommand(const std::string& data) const {
    std::istringstream ss(data);
    std::string commandType;
    int customerId;
    char mediaType, movieType;
    std::string movieKey;

    ss >> commandType >> customerId >> mediaType >> movieType;
    std::getline(ss, movieKey);
    movieKey.erase(0, movieKey.find_first_not_of(" "));
    //
    while (!movieKey.empty() && (movieKey.back() == ',' || movieKey.back() == ' '))
    movieKey.pop_back();

    return new Borrow(customerId, mediaType, movieType, movieKey);
}

// Static registration
static BorrowFactory globalBorrowFactory;