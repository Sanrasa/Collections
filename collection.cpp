#include "collection.h"

Collection::Collection()
{

}

string Collection::getMovie(long pos)
{
    if (pos < 1 || pos > Movies.size())
    {
        string error = "error";
        return error;
    }
    else
        return Movies[pos - 1];
}

void Collection::setMovie(string title) {Movies.push_back(title);}

int Collection::numberOfMovies() {return Movies.size();}

void Collection::listMovies()
{
    int i = 1;
    for(string movie : Movies)
    {
        cout << i << ". " << movie << endl;
        i++;
    }
}

string Collection::delMovie(long pos)
{
    string title = getMovie(pos);
    if (title != "error")
    {
    string elem = getMovie(pos);
    Movies.erase(Movies.begin() + pos);
    return elem;
    }
    else
    return title;
}

void Collection::exportCollection(string fileName)
{
    ofstream file;
    file.open (fileName);
    for(string movie : Movies)
    {
        if (movie != Movies.back())
            file << movie << endl;
        else
            file << movie;
    }
    file.close();
}

string Collection::importCollection(string fileName)
{
      string movie;
      ifstream file (fileName);
      if (file.is_open())
      {
        Movies.clear();
        while ( getline (file, movie) )
        {
          Movies.push_back(movie);
        }
        file.close();
        return "File loaded.";
      }
      else
        return "Unable to open file.";

}
