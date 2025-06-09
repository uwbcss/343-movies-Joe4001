#include "drama.h"
#include <sstream>
#include <iostream>

Drama::Drama(const MovieData& data) {
    movieData = data;
}

bool Drama::operator<(const Movie& other) const {
    // Sort by director, then title
    if (movieData.director != other.movieData.director)
        return movieData.director < other.movieData.director;
    return movieData.title < other.movieData.title;
}

std::string Drama::print() const {
    std::ostringstream oss;
    oss << "D, " << movieData.stock << ", " << movieData.director << ", "
        << movieData.title << ", " << movieData.year;
    return oss.str();
}

DramaFactory::DramaFactory() {
    registerType("D", this);
}

Movie* DramaFactory::makeMovie(const std::string& data) const {
    std::istringstream ss(data);
    char type;
    int stock;
    std::string director, title;
    int year;

    // Parse type
    ss >> type;
    if (type != 'D') return nullptr;
    if (ss.peek() == ',') ss.ignore();
    if (ss.peek() == ' ') ss.ignore();

    // Parse stock
    ss >> stock;
    if (ss.peek() == ',') ss.ignore();
    if (ss.peek() == ' ') ss.ignore();

    // Parse director
    std::getline(ss, director, ',');
    if (!director.empty() && director[0] == ' ') director = director.substr(1);

    // Parse title
    std::getline(ss, title, ',');
    if (!title.empty() && title[0] == ' ') title = title.substr(1);

    // Parse year
    ss >> year;
    Movie::MovieData md;
    md.stock = stock;
    md.director = director;
    md.title = title;
    md.year = year;
    return new Drama(md);
}

static DramaFactory globalDramaFactory;