#include "customer.h"
#include <sstream>

using namespace std;

Customer::Customer(int i, const string &last, const string &first) {
  id = i;
  lastName = last;
  firstName = first;
}

int Customer::getID() const { return id; }

void Customer::addTransaction(const string &transaction) {
  transactionHistory.push_back(transaction);
}

void Customer::printHistory() {
  cout << "History for: " + firstName + " " + lastName << endl;
  cout << "==================" << endl;
  if (transactionHistory.empty()) {
    cout << "  No transactions" << endl;
    return;
  }
  for (const auto &i : transactionHistory) {
    cout << " " << i << endl;
  }
}

const vector<string> &Customer::history() const { return transactionHistory; }

Customer *CustomerFactory::create(const std::string &line) {
  std::istringstream ss(line);
  int id;
  std::string last;
  std::string first;
  if (!(ss >> id >> last >> first)) {
    return nullptr;
  }
  return new Customer(id, last, first);
}