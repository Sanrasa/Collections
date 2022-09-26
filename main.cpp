#include <iostream>
#include "collection.h"

using namespace std;

int main()
{

    char menu;
    Collection mycollection;
        do {
            system ("CLS");
            puts ("1. Add movie");
            puts ("2. Get movie");
            puts ("3. List of movies");
            puts ("4. Number of movies");
            puts ("5. Remove movie");
            puts ("6. Export collection");
            puts ("7. Import collection");
            puts ("8. Exit");
            cout << endl << "select menu item: ";
            menu = getchar();
            cout << endl;
            switch (menu)
            {
            case '1': //Add movie
            {
                cout << "enter movie title: ";
                string title;
                cin >> title;
                mycollection.setMovie(title);
                cout << endl << "Movie \"" << title << "\" has added to collection." << endl << endl;
                system ("PAUSE");
                break;
            }
            case '2': //Get movie
            {
                long pos;
                cout << "Inter position of the movie: ";
                cin >> pos;
                string title = mycollection.getMovie(pos);
                if (title != "error")
                    cout << endl << "Movie title is \"" << title << "\"" << endl << endl;
                else
                    cout << endl << "That number not exist in collection" << endl << endl;
                system ("PAUSE");
                break;
            }
            case '3': //List of movies
            {
                system ("CLS");
                mycollection.listMovies();
                cout << endl;
                system ("PAUSE");
                break;
            }
            case '4': //Number of movies
            {
                cout << "Collection have " << mycollection.numberOfMovies() << " movies." << endl << endl;
                system ("PAUSE");
                break;
            }
            case '5': //Remove movie
            {
                long pos;
                cout << "Type position of movie which you want to delete: ";
                cin >> pos;
                string title = mycollection.delMovie(pos);
                if (title != "error")
                    cout << endl << "Movie \"" << title << "\"" << " successfuly deleted from collection." << endl << endl;
                else
                    cout << endl << "That number not exist in collection" << endl << endl;
                system ("PAUSE");
                break;
            }
            case '6': //export collection
            {
                string fileName;
                cout << endl << "How to name your file?" << endl << endl << ">";
                cin >> fileName;
                mycollection.exportCollection(fileName);
                cout << endl << "File successfuly created." << endl << endl;
                system ("PAUSE");
                break;
            }
            case '7': //import collection
            {
                string fileName;
                string status;
                cout << endl << "What is the name of the file?" << endl << endl << ">";
                cin >> fileName;
                status = mycollection.importCollection(fileName);
                if (status != "Unable to open file.")
                    cout << endl << "File successfuly loaded." << endl << endl;
                else
                    cout << endl << status << endl << endl;
                system ("PAUSE");
                break;
            }
            }
        } while (menu!='8'); //Exit

    return 0;
}
