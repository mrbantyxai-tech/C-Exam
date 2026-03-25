#include<iostream>
#include<string>
#include<limits>

using namespace std;

class Movie{
    public:
        string title;
        string genre;
        int releasedYear;
};
int main(){

    int n;
    cout << "Enter The Number of Movies :- ";
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    Movie* movies = new Movie[n];
    
    for(int i = 0; i < n; i++){
        cout << "Enter Details for Movie " << i+1 << ":-" << endl;
        cout << "Title :- ";
        getline(cin, movies[i].title);
        cout << "Genre :- ";
        getline(cin, movies[i].genre);
        cout << "Released Year :- ";
        cin >> movies[i].releasedYear;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }
    
    cout << "\nMovie Details:-" << endl;
    for(int i = 0; i < n; i++){
        cout << "Title: " << movies[i].title << endl;
        cout << "Genre: " << movies[i].genre << endl;
        cout << "Released Year: " << movies[i].releasedYear << endl;
        cout << endl;
    }
    
    delete[] movies;
    return 0;
}