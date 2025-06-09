#ifndef DRAMA_H
#define DRAMA_H

#include "movie.h"

class Drama : public Movie {
public:
  Drama() = default;
  explicit Drama(const MovieData &data);

  bool operator<(const Movie &other) const override;
  std::string print() const override;
  std::string getType() const override { return "D"; }
  std::string getKey() const {
    return movieData.director + ", " + movieData.title;
  }
};

class DramaFactory : public MovieFactory {
public:
  DramaFactory();
  Movie *makeMovie(const std::string &data) const override;
};

#endif