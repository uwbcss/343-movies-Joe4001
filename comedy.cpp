#include "comedy.h"
#include <iostream>
#include <sstream>

Comedy::Comedy(const MovieData &data) { movieData = data; }

bool Comedy::operator<(const Movie &other) const {
  // Sort by title, then year
  if (movieData.title != other.movieData.title) {
    return movieData.title < other.movieData.title;
  }
  return movieData.year < other.movieData.year;
}

std::string Comedy::print() const {
  std::ostringstream oss;
  oss << movieData.title << ", " << movieData.director << ", " << movieData.year
      << " "
      << "(" << movieData.stock << ")"
      << " - Comedy";
  return oss.str();
}

ComedyFactory::ComedyFactory() { registerType("F", this); }

Movie *ComedyFactory::makeMovie(const std::string &data) const {
  std::istringstream ss(data);
  char type;
  int stock;
  std::string director;
  std::string title;
  int year;

  // Parse type
  ss >> type;
  if (type != 'F') {
    return nullptr;
  }
  if (ss.peek() == ',') {
    ss.ignore();
  }
  if (ss.peek() == ' ') {
    ss.ignore();
  }

  // Parse stock
  ss >> stock;
  if (ss.peek() == ',') {
    ss.ignore();
  }
  if (ss.peek() == ' ') {
    ss.ignore();
  }

  // Parse director
  std::getline(ss, director, ',');
  if (!director.empty() && director[0] == ' ') {
    director = director.substr(1);
  }

  // Parse title
  std::getline(ss, title, ',');
  if (!title.empty() && title[0] == ' ') {
    title = title.substr(1);
  }

  // Parse year
  ss >> year;
  Movie::MovieData md;
  md.stock = stock;
  md.director = director;
  md.title = title;
  md.year = year;
  return new Comedy(md);
}

static ComedyFactory globalComedyFactory;