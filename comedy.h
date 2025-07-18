#ifndef COMEDY_H
#define COMEDY_H

#include "movie.h"

class Comedy : public Movie {
public:
  Comedy() = default;
  explicit Comedy(const MovieData &data);

  bool operator<(const Movie &other) const override;
  std::string print() const override;
  std::string getType() const override { return "F"; }
  std::string getKey() const {
    return movieData.title + ", " + std::to_string(movieData.year);
  }
};

class ComedyFactory : public MovieFactory {
public:
  ComedyFactory();
  Movie *makeMovie(const std::string &data) const override;
};

#endif