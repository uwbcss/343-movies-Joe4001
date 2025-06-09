#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <map>

class Movie {
public:
    struct MovieData {
        int stock;
        std::string director;
        std::string title;
        int year;
    };

    Movie() = default;
    virtual ~Movie() = default;

    int getStock() const { return movieData.stock; }
    void increaseStock() { ++movieData.stock; }
    void decreaseStock() { --movieData.stock; }

    virtual bool operator<(const Movie& other) const = 0;
    virtual std::string print() const = 0;
    virtual std::string getType() const = 0;
    virtual std::string getKey() const = 0;

    MovieData movieData;
};

class MovieFactory {
public:
    virtual Movie* makeMovie(const std::string& data) const = 0;
    static Movie* create(const std::string& data);

protected:
    static void registerType(const std::string& type, MovieFactory* factory);

private:
    static std::map<std::string, MovieFactory*>& getMap();
};

#endif