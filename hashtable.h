#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "customer.h"
#include <vector>

using namespace std;

template <typename Key, typename Value> class Hashtable {
public:
  Hashtable();
  void insert(Key key, Value value);
  Value *get(const Key &key);

private:
  vector<vector<pair<Key, Value>>> buckets;
  size_t hash(const Key &key) const;
};

extern template class Hashtable<int, Customer>;

#endif