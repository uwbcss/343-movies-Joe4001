#ifndef CLASSIC_H
#define CLASSIC_H

#include "movie.h"

class Classic : public Movie {
public:
    Classic(const MovieData& data, int month, const std::string& majorActor);

    bool operator<(const Movie& other) const override;
    std::string print() const override;
    std::string getType() const override { return "C"; }
    std::string getKey() const override;

private:
    int month;
    std::string majorActor;
};

class ClassicFactory : public MovieFactory {
public:
    ClassicFactory();
    Movie* makeMovie(const std::string& data) const override;
};

#endif