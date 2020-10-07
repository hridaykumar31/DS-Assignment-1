#include<bits/stdc++.h>
#define MAX 3
using namespace std;
class Course{
private:
    double credits;
    double Grade;
public:
    void set_credit()
    {
        cin>>credits;
    }
    double get_credit()
    {
        return credits;
    }
    void set_grade(double grade)
    {
        Grade=grade;
    }
    double get_grade()
    {
        return Grade;
    }
};
class Student{
private:

    Course total_number_of_course[MAX];
    int student_ID;
    double grade;
    double CGPA;
    int merit_position;
public:
   void get_merit(Student student[],int N);
    double getcgpa()
    {
      return CGPA;
    }
    int get_ID()
    {
        return student_ID;
    }
    int get_merit_position()
    {
        return merit_position;
    }
    void get_student_information()
    {
        double total_credit=0.00;
        double total_earn_credit=0.00;
      cout<<"Enter the Student ID:"<<endl;
      cin>>student_ID;
      for(int i=0;i<MAX;i++)
      {
        cout<<"course:"<<i+1<<endl;
        cout<<"Grade:"<<endl;
        cin>>grade;
        total_number_of_course[i].set_grade(grade);
        cout<<"Credits:"<<endl;
        total_number_of_course[i].set_credit();
        total_credit+=total_number_of_course[i].get_credit();
        total_earn_credit+=total_number_of_course[i].get_credit()*grade;
      }
       CGPA= total_earn_credit/total_credit;
    }
};
 void Student:: get_merit(Student student[],int N){
    for(int i=0;i<N;i++){
        int merit=1;
        for(int j=0;j<N;j++){
            if(student[i].getcgpa()<student[j].getcgpa()) merit++;
        }student[i].merit_position=merit;
    }
 }
void result(Student student[],int Student_Number,int i)
{
    cout<<"Student ID Number is:"<<student[i].get_ID()<<endl;
  cout<<"Student CGPA:"<<fixed<<setprecision(2)<<student[i].getcgpa()<<endl;
  cout<<"Merit Position:"<<student[i].get_merit_position()<<endl;
}

int main(){
    cout<<"Enter the total number of Student: ";
    int Student_Number;
    cin>>Student_Number;
     Student *student=new Student[Student_Number];
    for(int i=0;i<Student_Number;i++)
        {
       student[i].get_student_information();
       student[i].get_merit(student,Student_Number);
        }

    for(int i=0;i<Student_Number;i++)
    {
       result(student,Student_Number,i);
    }


    return 0;
}
