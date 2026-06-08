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

//load data
void load_data()
{
    ifstream fin("students.txt");
    student s;
    while(fin>>s.id>>s.name>>s.marks)
    {
        vec.push_back(s);
    }
    fin.close();
}

//updatefile
void upfile()
{
    ofstream fout("students.txt");
    vector<student>::iterator it;
    for(it=vec.begin();it!=vec.end();it++)
    fout<<(*it).id<<" "<<(*it).name<<" "<<(*it).marks<<endl;
    fout.close();
}

//addition
void addst()
{
    student s;
    cout<<" \nEnter the student ID : ";
    cin>>s.id;
    cout<<"Enter the name of the student : ";
    cin>>s.name;    
    cout<<"Enter the marks of the student : ";
    cin>>s.marks;
    vec.push_back(s);
    ofstream fout("students.txt",ios::app);
    fout<<s.id<<" "<<s.name<<" "<<s.marks<<endl;
    fout.close();
    cout<<"Student added successfully !";
    cout<<"\n"<<"\n";
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
{   int Id,flag=0;
    cout<<"Enter the Student ID to be searched : ";
    cin>>Id;
    while(Id<=0)
    {
    cout<<"Enter the correct student ID : ";
    cin>>Id;
    }
    vector<student>::iterator it;
    for(it=vec.begin();it!=vec.end();it++)
    {
       if (Id==(*it).id)
       {
        flag=1;
        cout<<"ID : "<<(*it).id<<endl<<"Name : "<<(*it).name<<endl<<"Marks : "<<(*it).marks<<endl;
        break;
       }
       
    }
    if(flag==0) cout<<" Student not found ";
    
}

//deletion
void delst()
{   int Id,flag=0;
    cout<<"Enter the Student ID to be searched : ";
    cin>>Id;
    while(Id<=0)
    {
    cout<<"Enter the correct student ID ";
    cin>>Id;
    }
    vector<student>::iterator it;
    for(it=vec.begin();it!=vec.end();it++)
    {
       if (Id==(*it).id)
       { 
         vec.erase(it);
         flag=1;
         cout<<"Student data deleted successfully ";
         break;
       }
    }
    if(flag==0) cout<<" Student not found \n ";
    upfile();
    cout<<endl;
}

int main()
{
    int n;
    load_data();
    cout<<endl;
    cout<<"===== STUDENT MANAGEMENT SYSTEM ====="<<endl;;
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