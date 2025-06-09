#include "hashtable.h"
#include <functional>

using namespace std;

template <typename Key, typename Value>
Hashtable<Key, Value>::Hashtable() : buckets(100) {} // Fixed initialization

template <typename Key, typename Value>
size_t Hashtable<Key, Value>::hash(const Key &k) const {
  return std::hash<Key>{}(k) % buckets.size(); // Explicitly use std::hash
}

template <typename Key, typename Value>
void Hashtable<Key, Value>::insert(const Key key, const Value value) {
  size_t index = hash(key);
  for (auto &pair : buckets[index]) {
    if (pair.first == key) {
      return;
}
  }
  buckets[index].emplace_back(key, value);
}

template <typename Key, typename Value>
Value *Hashtable<Key, Value>::get(const Key &key) {
  size_t index = hash(key);
  for (auto &pair : buckets[index]) {
    if (pair.first == key) {
      return &pair.second;
}
  }
  return nullptr;
}

template class Hashtable<int, Customer>;