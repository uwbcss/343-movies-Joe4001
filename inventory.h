#ifndef INVENTORY_H
#define INVENTORY_H

#include "movie.h"
#include <map>
#include <string>

class Inventory {
public:
    void addMovie(Movie* movie);
    Movie* searchMovie(const std::string& title) const;
    void printInventory() const;
    ~Inventory();

private:
    std::map<std::string, Movie*> movies; // Maps movie titles to Movie objects
};

#endif