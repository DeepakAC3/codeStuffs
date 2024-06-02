#include<iostream>
using namespace std;

class Movie{
    private:
    string rating;
    public:
    string title;
    string director;
    Movie(string title,string director,string rating){
            this->title=title;
            this->director=director;
            setRating(rating);
    }


    void setRating(string rating){
        if(rating == "G" || rating == "PG-13" || rating == "PG" || rating == "R"){
            this->rating=rating;
        }
        else{
            this->rating="NR";
        }
    }

    string getRating(){
        return this->rating;
    }
};




int main(){
    Movie mov("aveng","joss","pg-13");
    mov.setRating("Dog");
    cout<<mov.getRating();
    return 0;
}