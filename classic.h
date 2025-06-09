// #ifndef CLASSIC_H
// #define CLASSIC_H

// #include "movie.h"
// #include <string>

// class Classic : public Movie {
// public:
//     Classic(const MovieData& data, const std::string& majorActor, int month);

//     // Only use month and majorActor for comparison and printing
//     bool operator<(const Movie& other) const override;
//     std::string print() const override;
//     std::string getType() const override { return "C"; }
// std::string Classic::getKey() const {
//     // Example: "3 1971 Ruth Gordon"
//     return std::to_string(month) + " " + std::to_string(movieData.year) + " " + majorActor;
// }

// private:
//     std::string majorActor;
//     int month;
// };

// class ClassicFactory : public MovieFactory {
// public:
//     ClassicFactory();
//     Movie* makeMovie(const Movie::MovieData& data) const override; // matches base
//     Movie* makeMovie(const std::string& data) const; // overload, no override
// };

// #endif