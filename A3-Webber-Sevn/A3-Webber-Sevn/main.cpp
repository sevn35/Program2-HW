#include <iostream>
#include <string>
#include <iomanip>
#include "movie_class.h"

using namespace std;

int main() {
    //Creates new movies
    string info[3][2]= {{"TERMINATOR 2", "R"}, {"The Lion King", "G"},{"Spider-Man", "PG-13"}};

    int size = 3;
    Movie* s[size];
    for(int i =0; i<3; i++){
        s[i] = new Movie();
        s[i]->setName(info[i][0]);
        s[i]->setMpaaRating(info[i][1]);
        for(int j=0; j<5; j++){
            s[i]->addRating((rand()%5)+1); //rand number between 1 and 5
        }
    }

    // output of reveiws on selected movies for customer 
    cout << "---------------------------------------------" << endl;
    cout << left << setw(15) <<"Name" << setw(15) << "MPAA Rating" << setw(10) << "Average Rating"<< endl;
    cout << "---------------------------------------------" << endl;
    for(int i =0; i<3; i++){
        cout << left << setw(15) << s[i]->getName() << setw(15) << s[i]->getMpaaRating()<< setw(10)<< s[i]->getAvg() << endl;
    }
    cout << "---------------------------------------------" << endl;

    for(int i =0; i<3; i++){
        s[i]->~Movie();
    }
}