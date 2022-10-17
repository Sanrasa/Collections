#include "collection.h"

// Замечания:
//  1. удаление объекта, нет проверки на количество
//              при количестве элементов N, если мы удаляем элемент позицией N, программа падает\ъ
//  2. файл без расширения
//  3. Возможность сохранить файл не в текущую папку?
//  4. Можно загрузить любой файл и нет проверки. поэтому импорт нужно делать более интелектуальный, как и экспорт, сохранять например не в текстовый файл, в бинарный.
//      Добавлять какие элементы, при проверке которых будет точно ясно что этот файл является коллекцией

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
    for(string movie : Movies) // <-- в данном случае лучше использовать
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
