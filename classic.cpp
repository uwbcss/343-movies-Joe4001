#include "classic.h"
#include <iostream>
#include <sstream>

// to output month for classics
std::string monthToString(int month) {
  static const char *months[] = {"Invalid", "January",   "February", "March",
                                 "April",   "May",       "June",     "July",
                                 "August",  "September", "October",  "November",
                                 "December"};
  if (month < 1 || month > 12) {
    return "Invalid";
  }
  return months[month];
}

Classic::Classic(const MovieData &data, int month,
                 const std::string &majorActor)
    : month(month), majorActor(majorActor) {
  movieData = data;
}

bool Classic::operator<(const Movie &other) const {
  if (movieData.year != other.movieData.year) {
    return movieData.year < other.movieData.year;
  }
  if (month != static_cast<const Classic &>(other).month) {
    return month < static_cast<const Classic &>(other).month;
  }
  return majorActor < static_cast<const Classic &>(other).majorActor;
}

std::string Classic::print() const {
  std::ostringstream oss;
  oss << movieData.title << ", " << movieData.director << ", " << movieData.year
      << " " << majorActor << ", " << monthToString(month) << ", "
      << "(" << movieData.stock << ")"
      << " - Classic";
  return oss.str();
}

std::string Classic::getKey() const {
  return std::to_string(month) + " " + std::to_string(movieData.year) + " " +
         majorActor;
}

ClassicFactory::ClassicFactory() { registerType("C", this); }

Movie *ClassicFactory::makeMovie(const std::string &data) const {
  std::istringstream ss(data);
  char type;
  int stock;
  std::string director;
  std::string title;
  std::string actorFirst;
  std::string actorLast;
  int month;
  int year;

  // Parse type
  ss >> type;
  if (type != 'C') {
    return nullptr;
  }
  if (ss.peek() == ',') {
    ss.ignore();
  }
  while (ss.peek() == ' ') {
    ss.ignore();
  }

  // Parse stock
  ss >> stock;
  if (ss.peek() == ',') {
    ss.ignore();
  }
  while (ss.peek() == ' ') {
    ss.ignore();
  }

  // Parse director
  std::getline(ss, director, ',');
  director.erase(0, director.find_first_not_of(" "));
  director.erase(director.find_last_not_of(" ") + 1);

  // Parse title
  std::getline(ss, title, ',');
  title.erase(0, title.find_first_not_of(" "));
  title.erase(title.find_last_not_of(" ") + 1);

  // Parse major actor, month, year
  ss >> actorFirst >> actorLast >> month >> year;
  std::string majorActor = actorFirst + " " + actorLast;

  Movie::MovieData md;
  md.stock = stock;
  md.director = director;
  md.title = title;
  md.year = year;

  return new Classic(md, month, majorActor);
}

// Static registration
static ClassicFactory globalClassicFactory;