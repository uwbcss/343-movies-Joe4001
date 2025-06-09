// #include "classic.h"
// #include <sstream>
// #include <iostream>
// #include <algorithm>

// Classic::Classic(const MovieData& data, const std::string& majorActor, int month)
// {
//     movieData = data;
//     this->majorActor = majorActor;
//     this->month = month;
// }

// // Only use month and majorActor for comparison
// bool Classic::operator<(const Movie& other) const {
//     if (getType() != other.getType()) return getType() < other.getType();
//     const Classic* o = dynamic_cast<const Classic*>(&other);
//     if (!o) return false;
//     if (movieData.year != o->movieData.year)
//         return movieData.year < o->movieData.year;
//     if (month != o->month)
//         return month < o->month;
//     return majorActor < o->majorActor;
// }

// // Only use month and majorActor for printing
// std::string Classic::print() const {
//     std::ostringstream oss;
//     oss << "C, " << movieData.stock << ", " << movieData.director << ", "
//         << movieData.title << ", " << majorActor << " " << month << " " << movieData.year;
//     return oss.str();
// }

// // Factory registration
// ClassicFactory::ClassicFactory() {
//     registerType("C", this);
// }

// // Parse: C, 10, George Cukor, Holiday, Katherine Hepburn 9 1938
// Movie* ClassicFactory::makeMovie(const std::string& data) const {
//     std::istringstream ss(data);
//     char type;
//     int stock;
//     std::string director, title, majorActorFirst, majorActorLast;
//     int month, year;

//     // Parse type
//     ss >> type;
//     if (type != 'C')
//         return nullptr;
//     if (ss.peek() == ',') ss.ignore();
//     if (ss.peek() == ' ') ss.ignore();

//     // Parse stock
//     ss >> stock;
//     if (ss.peek() == ',') ss.ignore();
//     if (ss.peek() == ' ') ss.ignore();

//     // Parse director
//     std::getline(ss, director, ',');
//     if (!director.empty() && director[0] == ' ') director = director.substr(1);

//     // Parse title
//     std::getline(ss, title, ',');
//     if (!title.empty() && title[0] == ' ') title = title.substr(1);

//     // Now the rest: major actor (first and last), month, year
//     ss >> majorActorFirst >> majorActorLast >> month >> year;
//     if (majorActorFirst.empty() || majorActorLast.empty() || month <= 0 || year <= 0)
//         return nullptr;

//     Movie::MovieData md;
//     md.stock = stock;
//     md.director = director;
//     md.title = title;
//     md.year = year;

//     return new Classic(md, majorActorFirst + " " + majorActorLast, month);
// }

// Movie* ClassicFactory::makeMovie(const Movie::MovieData& data) const {
//     // You can return nullptr or throw, since you only use the string version
//     return nullptr;
// }

// // Static instance for self-registration
// static ClassicFactory globalClassicFactory;