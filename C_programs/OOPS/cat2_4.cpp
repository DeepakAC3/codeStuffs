#include<iostream>
using namespace std;
class Student{
    public:
    int ID;
    string name;
    double GPA;
    static int cnt;
    static void tot_no_of_students(){
        cout<<"no. of students created: "<<cnt<<endl;
    }
    Student(string inp_name,double inp_GPA){
        name=inp_name;
        GPA=inp_GPA;
        cnt++;
        ID=cnt+2356;
    }
    ~Student(){
        cout<<"Class is being destroyed...."<<endl;
    }
};
int Student::cnt=0;
int main(){
    Student s1("Amit",3.5);
    Student s2("Bruh", 20.8);
    Student s3("Saurabh", 4.5);
    s1.tot_no_of_students();
    cout<<s1.ID<<s2.ID<<s3.ID;
}