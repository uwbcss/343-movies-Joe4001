#ifndef CTABLE_H
#define CTABLE_H
#include "customer.h"
#include "hashtable.h"

class CustomerTable {
private:
  Hashtable<int, Customer> customers;

public:
  bool addCustomer(Customer c);
  Customer *getCustomer(int id);
};

#endif