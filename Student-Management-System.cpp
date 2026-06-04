//Student Management System
#include<bits/stdc++.h>
using namespace std;

//Global vector
struct student
{
    int id;
    string name;
    float marks;
};
vector<student>vec;

//addition
void addst()
{
student s;
cout<<" Enter the student ID : ";
cin>>s.id;
cout<<" Enter the name of the student : ";
cin>>s.name;
cout<<" Enter the marks of the student : ";
cin>>s.marks;
vec.push_back({s.id,{s.name,s.marks}});
cout<<" Student added successfully !";
}

//display
void dispst()
{
    vector<student>::iterator it;
    for(it=vec.begin();it!=vec.end();it++)
    {
        cout<<(*it).id<<" "<<(*it).name<<" "<<(*it).marks<<endl;
    }
}

//searching
void searchst()
{   int Id;
    cout<<"Enter the Student ID to be searched : ";
    cin>>Id;
    if(Id<=0)
    cout<<"Enter the correct student ID ";
    vector<student>::iterator it;
    for(it=vec.begin();it!=vec.end();it++)
    {
       if (Id==(*it).id)
       {
        cout<<(*it).id<<endl<<(*it).name<<endl<<(*it).marks<<endl;
        break;
       }
       else
       {
       cout<<"Student not found ";
       }
    }
    
}

//deletion
void delst()
{   int Id;
    cout<<"Enter the Student ID to be searched : ";
    cin>>Id;
    if(Id<=0)
    cout<<"Enter the correct student ID ";
    vector<student>::iterator it;
    for(it=vec.begin();it!=vec.end();it++)
    {
       if (Id==(*it).id)
       { 
         vec.erase(it);
         cout<<"Student data deleted successfully ";
         break;
       }
       else 
       {
       cout<<"Student not found ";
       }
    }
    
}

int main()
{
    int n;
    cout<<"===== STUDENT MANAGEMENT SYSTEM ====="<<endl<<endl;
    while(true)
    {
    cout<<endl;
    cout<<" 1. Add Student \n 2. Display Students \n 3. Search Student \n 4. Delete Student \n 5. Exit "<<endl<<endl;
    cout<<"Enter your choice by typing the number : ";
    cin>>n;
    if(n==1)
    {
        addst();
    }
    else if(n==2)
    {
        dispst();
    }
    else if(n==3)
    {
        searchst();
    }
    else if(n==4)
    {
        delst();
    }
    else
    {
    cout<<" Thankyou...Visit us again ";
    exit(0);
    }
}
    return 0;
}