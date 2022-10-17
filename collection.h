#ifndef COLLECTION_H
#define COLLECTION_H
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Collection
{
private:
    vector<string> Movies;  // <-- Имя переменной не пишется с большой буквы. Имя переменной пишется с m_



public:
    Collection();
    string getMovie(long pos);
    void setMovie(string title);
    int numberOfMovies();
    void listMovies();
    string delMovie(long pos);
    void exportCollection(string fileName);
    string importCollection(string fileName);
};

#endif // COLLECTION_H
