#include<iostream>
using namespace std;

int main(){
    string color, pluralnoun, celeb;
    cout<<"Enter a color";
    getline(cin,color);
    cout<<"Enter a pluralnoun";
    getline(cin,pluralnoun);
    cout<<"Enter a celebrity";
    getline(cin,celeb);


    cout<<"Roses are "<< color<<endl;
    cout<<pluralnoun<<"are Blue"<<endl;
    cout<<"I love"<<celeb<<endl;
    return 0;
}