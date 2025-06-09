#include "customerTable.h"

using namespace std;

bool CustomerTable::addCustomer(Customer c) {
  customers.insert(c.getID(), c);
  return true;
}

Customer *CustomerTable::getCustomer(int id) { return customers.get(id); }