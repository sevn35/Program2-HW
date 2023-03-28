#include <iostream>
#include <string>
#include "movie_class.h"
    
    
    
string Movie::getName() const {
    return name;
}

//Gets the movies rating
string Movie::getMpaaRating() const {
    return mpaaRating;
}

//gets the the number of ratings
int Movie::getRatingCount(int rating) const {
    return ratingCount[rating - 1];
}

//sets the name
void Movie::setName(string name) {
    this->name = name;
}

//sets the rating
void Movie::setMpaaRating(string mpaaRating) {
    mpaaRating = mpaaRating;
}

// function to add up all ratings
void Movie::addRating(int rating) {
    if (rating >= 1 && rating <= 5) {
        ratingCount[rating - 1]++; //Adds the rating to correct spot in array
    }
}

// function for rating
float Movie::getAvg() const {
    int totalRatings = 0;
    int Count = 0;

    for (int i = 0; i < 5; i++) {
        totalRatings += (i + 1) * ratingCount[i];
        Count += ratingCount[i];
    }
    return (float)(totalRatings) / Count;
}