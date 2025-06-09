#ifndef BORROW_H
#define BORROW_H

#include "command.h"

class Borrow : public Command {
public:
    Borrow(int customerId, char mediaType, char movieType, const std::string& movieKey);
    void execute(Inventory& inventory, CustomerTable& customers) override;

private:
    int customerId;
    char mediaType;
    char movieType;
    std::string movieKey;
};

class BorrowFactory : public CommandFactory {
public:
    BorrowFactory();
    Command* makeCommand(const std::string& data) const override;
};

#endif