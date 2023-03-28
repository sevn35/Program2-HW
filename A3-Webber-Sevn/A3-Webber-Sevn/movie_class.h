#include <iostream>
#include <string>

using namespace std;

class Movie {

private:
    int* ratingCount;
    string name;
    string mpaaRating;

public:
   
   //defualt constructor
    Movie() {
        name = "";
        mpaaRating = "";
        ratingCount = new int[5]{0};
    }

    //constructor
    Movie(string x, string y){
        name = x;
        mpaaRating = y;
        ratingCount = new int[5]{0};
    }

    //destructor
    ~Movie() {
            cout << "Memory deallocated" << endl;
            delete[] ratingCount;
    }

  
    //Gets the movies name
    string getName() const;
    //Gets the movies rating
    string getMpaaRating() const ;

    //gets the the number of ratings
    int getRatingCount(int rating) const;

    //sets the name
    void setName(string name);

    //sets the rating
    void setMpaaRating(string mpaaRating) ;

    // function to add up all ratings
    void addRating(int rating) ;

    // function for rating
    float getAvg() const ;

};