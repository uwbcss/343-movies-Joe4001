#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Customer {
protected:
  int id;
  string firstName;
  string lastName;
  vector<string> transactionHistory;

public:
  Customer(int id, const string &last, const string &first);

  int getID() const;
  const vector<string> &history() const;

  void addTransaction(const string &t);
  void printHistory();
};

class CustomerFactory {
public:
    static Customer* create(const std::string& line);
};

#endif