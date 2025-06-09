#include "inventory.h"
#include <iostream>


void Inventory::addMovie(Movie* movie) {
    movies[movie->movieData.title] = movie;
}

void Inventory::removeMovie(const std::string& title) {
    movies.erase(title);
}

Movie* Inventory::searchMovie(const std::string& title) const {
    auto it = movies.find(title);
    if (it != movies.end()) return it->second;
    return nullptr;
}

void Inventory::printInventory() const {
    for (const auto& movie : movies) {
        std::cout << movie.second->print() << std::endl;
    }
}

Inventory::~Inventory() {
    for (auto& movie : movies) {
        delete movie.second;
    }
}
