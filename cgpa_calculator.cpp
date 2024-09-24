#include<iostream>
using namespace std;

int main()
 {
     int num_of_course;
     double grade, total_point=0,total_credit=0;

     cout<<"\n\tEnter the number of courses : ";
     cin>>num_of_course;
     
     for(int i=1; i<=num_of_course; i++)     //loop
     {
        int credit_hours;
        double grade_point;

        cout<<"\n\tThe credit hours for courses :"<<i<<":";
        cin>>credit_hours;

        cout<<"\n\tEnter the grade points of the course :"<<i<<":";
        cin>>grade_point;

        total_point += (grade_point*credit_hours); 
        total_credit += credit_hours;

     }

    double CGPA= total_point / total_credit;
    cout<<"\n\t***Your CGPA is : "<<CGPA<<endl;

    return 0;
 }