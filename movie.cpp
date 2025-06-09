#include "movie.h"
#include <algorithm>
#include <iostream>
#include <sstream>

std::map<std::string, MovieFactory *> &MovieFactory::getMap() {
  static std::map<std::string, MovieFactory *> factories;
  return factories;
}

void MovieFactory::registerType(const std::string &type,
                                MovieFactory *factory) {
  getMap()[type] = factory;
}

Movie *MovieFactory::create(const std::string &data) {
  std::istringstream ss(data);
  std::string movieType;
  std::getline(ss, movieType, ',');
  movieType.erase(0, movieType.find_first_not_of(" \t"));
  movieType.erase(movieType.find_last_not_of(" \t") + 1);

  if (getMap().count(movieType) == 0) {
    // std::cout << "Do not know how to create movie: " << movieType <<
    // std::endl;
    return nullptr;
  }
  // std::cout<< "Movie: " << data << " added " << std::endl;
  return getMap().at(movieType)->makeMovie(data);
}