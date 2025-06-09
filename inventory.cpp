#include "inventory.h"
#include <iostream>

void Inventory::addMovie(Movie *movie) { movies[movie->getKey()] = movie; }

Movie *Inventory::searchMovie(const std::string &key) const {
  auto it = movies.find(key);
  if (it != movies.end()) {
    return it->second;
  }
  return nullptr;
}

void Inventory::printInventory() const {
  for (const auto &movie : movies) {
    std::cout << movie.second->print() << std::endl;
  }
}

Inventory::~Inventory() {
  for (auto &movie : movies) {
    delete movie.second;
  }
}
