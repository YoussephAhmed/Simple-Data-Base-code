#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


 int into_days(string datein)
     {
      int d,m,y;
      string DayS,MonthS,YearS;
float DayF,MonthF,YearF;
int q1,q2,start;

start=0;

q1=datein.find("/",start);
DayS=datein.substr(0,q1);
start=start+q1+1;
q2=datein.find("/",start);
MonthS=datein.substr(start,q2-q1-1);
YearS=datein.substr(q2+1,4);

DayF= atof(DayS.c_str());
MonthF= atof(MonthS.c_str());
YearF= atof(YearS.c_str());

d=DayF;
m=MonthF;
y=YearF;

     int days=0;
     int i;
     for(i=2000;i<y;i++)
     {

     if( ( i%4 == 0 && i%100 != 0 ) || i%400 == 0)
      days+=366;

     else
      days+=365;
     }

     for(i=1;i<m;i++)
     {
      if(i==2)
      {
           if( ( y%4 == 0 && y%100 != 0 ) || y%400 == 0)
           days+=29;

           else
           days+=28;
      }

     else if(i==4||i==6||i==9||i==11)
      days+=30;

     else
     days+=31;

     }

     days+=d;

     return days;
     }



class ExamDate
{

int day,month,year;

public:
    void setDay(int d)
    {
    day=d;
    }


     void setMonth(int m)
    {
    month=m;
    }


    void setYear(int y)
    {
    year=y;
    }

    int getDay()
    {
     return day;
    }

      int getMonth()
    {
     return month;
    }

      int getYear()
    {
     return year;
    }

     int into_days(int d,int m,int y)
     {
     int days=0;
     int i;
     for(i=2000;i<y;i++)
     {

     if( ( i%4 == 0 && i%100 != 0 ) || i%400 == 0)
      days+=366;

     else
      days+=365;
     }

     for(i=1;i<m;i++)
     {
      if(i==2)
      {
           if( ( y%4 == 0 && y%100 != 0 ) || y%400 == 0)
           days+=29;

           else
           days+=28;
      }

     else if(i==4||i==6||i==9||i==11)
      days+=30;

     else
     days+=31;

     }

     days+=d;

     return days;
     }

    int isGreater(ExamDate d)
    {
     if(year>d.year)
     return 1;

     if(d.year>year)
     return 0;

     if(month>d.month)
     return 1;

     if(d.month>month)
     return 0;

     if(day>d.day)
     return 1;

     if(d.day>day)
     return 0;
     }




      int isSmaller(ExamDate d)
    {
     if(year<d.year)
     return 1;

     if(d.year<year)
     return 0;

     if(month<d.month)
     return 1;

     if(d.month<month)
     return 0;

     if(day<d.day)
     return 1;

     if(d.day<day)
     return 0;

     }

     int isEqual(ExamDate d)
     {

         if(year==d.year&&month==d.month&&day==d.day)
         return 1;

         return 0;

     }

};

class Courses
{
public:
string code;
string name;
ExamDate date;
string hall;
};


class Students
{
public:
int id;
string name;
string Courses_of_student[10];
};



int number_of(int e, string s,string c)
{
int N=1;

for (int i=0;i<=e;i++)
    {
    if(s.substr(i,1)==c)
    N++;
    }
    return N;

}


int main()
{
int n1; // number of the first string's chars
int n2; // number of the second string's chars
int s_courses=14 ; //start of the courses array
int e_courses; //end of the courses array
int s_students=10 ; //start of the students array
int e_students; //end of the students array
int n_courses;
int n_students;
int t1,t2,t3,t4; // to find , or ; in every loop
int final_t; // to find ]
int y;
int s_comma=0;
int i;
string LINE;
string NEWLINE1;
string NEWLINE2;
string NEWLINE3;

string COURSES[100][4];
string STUDENTS[100][3];


getline(cin,LINE);
n1=LINE.length();
e_courses=n1-14;
NEWLINE1=LINE.substr(s_courses,e_courses);
n_courses = number_of(e_courses,NEWLINE1,";");


getline(cin,LINE);
n2=LINE.length();
e_students=n2-10;
NEWLINE2=LINE.substr(s_students,e_students);
n_students = number_of(e_students,NEWLINE2,";");


// related to substring the input
for(y=0;y<n_courses;y++)
{


t1 = NEWLINE1.find(",",s_comma);
t1=t1-s_comma;
COURSES[y][0]=NEWLINE1.substr(s_comma,t1);

t2 = NEWLINE1.find(",",t1+s_comma+1);
t2=t2-s_comma;
COURSES[y][1]=NEWLINE1.substr(t1+s_comma+1,t2-t1-1);

t3 = NEWLINE1.find(",",t2+s_comma+1);
t3=t3-s_comma;
COURSES[y][2]=NEWLINE1.substr(t2+s_comma+1,t3-t2-1);

   if(y==n_courses-1)
    {
    final_t=NEWLINE1.find("]",t3+s_comma+1);
    COURSES[y][3]=NEWLINE1.substr(t3+s_comma+1,final_t-s_comma-t3-1);
    }


    else
    {
    t4 = NEWLINE1.find(";",t3+s_comma+1);
    COURSES[y][3]=NEWLINE1.substr(t3+s_comma+1,t4-s_comma-t3-1);


    s_comma=t4+1;

     }

}


s_comma=0;

for(y=0;y<n_students;y++)
{

t1 = NEWLINE2.find(",",s_comma);
t1=t1-s_comma;
STUDENTS[y][0]=NEWLINE2.substr(s_comma,t1);

t2 = NEWLINE2.find(",",t1+s_comma+1);
t2=t2-s_comma;
STUDENTS[y][1]=NEWLINE2.substr(t1+s_comma+1,t2-t1-1);

   if(y==n_students-1)
    {
    final_t=NEWLINE2.find("]",t2+s_comma+1);
    STUDENTS[y][2]=NEWLINE2.substr(t2+s_comma+1,final_t-s_comma-t2-1);
    }


    else
    {
    t3 = NEWLINE2.find(";",t2+s_comma+1);
    STUDENTS[y][2]=NEWLINE2.substr(t2+s_comma+1,t3-s_comma-t2-1);
    s_comma=t3+1;

     }

}

// related to Date convert to float
ExamDate Dates[100];

string DayS,MonthS,YearS;
float DayF,MonthF,YearF;
int q1,q2,start;
for(y=0;y<n_courses;y++)
{
start=0;

q1=COURSES[y][2].find("/",start);
DayS=COURSES[y][2].substr(0,q1);
start=start+q1+1;
q2=COURSES[y][2].find("/",start);
MonthS=COURSES[y][2].substr(start,q2-q1-1);
YearS=COURSES[y][2].substr(q2+1,4);

DayF= atof(DayS.c_str());
MonthF= atof(MonthS.c_str());
YearF= atof(YearS.c_str());

Dates[y].setDay(DayF);
Dates[y].setMonth(MonthF);
Dates[y].setYear(YearF);

}


//related to save input Courses in one class

Courses C[100];
for(i=0;i<n_courses;i++)
{
C[i].code=COURSES[i][0];
C[i].name=COURSES[i][1];
C[i].date=Dates[i];
C[i].hall=COURSES[i][3];
}


//related to save input Students in one class
Students S[100];

//related to id convert to float
string idS;
float idF;

for(y=0;y<n_students;y++)
{
idS =STUDENTS[y][0];
idF= atof(idS.c_str());
S[y].id=idF;
}


for(y=0;y<n_students;y++)
{
S[y].name=STUDENTS[y][1];
}


//related to substring the courses of students and sent it to it's class
int n,j,t;
for(y=0;y<n_students;y++)
{
n=STUDENTS[y][2].length();
NEWLINE3=STUDENTS[y][2].substr(1,n-2);
j=number_of(n-2,NEWLINE3,",");
s_comma=0;

  for(i=0;i<j;i++)
  {
      if(i==j-1)
      {
      S[y].Courses_of_student[i]=NEWLINE3.substr(s_comma,n-s_comma-1);
      }

      else
      {
      t=NEWLINE3.find(",",s_comma);
      t=t-s_comma;
      S[y].Courses_of_student[i]=NEWLINE3.substr(s_comma,t);
      s_comma=t+1+s_comma;
      }
  }

}


//related to earliest and latest exam
ExamDate earliest;
earliest.setDay(Dates[0].getDay());
earliest.setMonth(Dates[0].getMonth());
earliest.setYear(Dates[0].getYear());

ExamDate latest;
latest.setDay(Dates[0].getDay());
latest.setMonth(Dates[0].getMonth());
latest.setYear(Dates[0].getYear());


for(i=0;i<n_courses;i++)
{
   if(Dates[i].isGreater(latest))
   latest=Dates[i];

}


for(i=0;i<n_courses;i++)
{
   if(Dates[i].isSmaller(earliest))
   earliest=Dates[i];
}
//related to number of days between exams
int days1,days2,days;
days1=earliest.into_days(earliest.getDay(),earliest.getMonth(),earliest.getYear());
days2=latest.into_days(latest.getDay(),latest.getMonth(),latest.getYear());
days=1+(days2 - days1);

//related to number of halls
int f, n_halls=n_courses;
string testing;
for(y=0;y<n_courses;y++)
{

  for(i=0;i<n_courses-1;i++)
  {
  testing =COURSES[y][3];
  f=COURSES[y+i+1][3].find(testing);
    if(f!=-1)
    {
    n_halls --;
    break;
    }
  }
}

//related to Max and Min id
int max_id=S[0].id;
int min_id=S[0].id;

for(i=0;i<n_students;i++)
{
if(S[i].id>max_id)
max_id=S[i].id;
}

for(i=0;i<n_students;i++)
{
if(S[i].id<min_id)
min_id=S[i].id;
}


//related to sort Dates,Courses and Halls


string sortDates[100];
string sortCourses[100];
string sortHalles[100];
int c,d;
string SWAPd,SWAPc,SWAPh;

for(i=0;i<n_courses;i++)
sortDates[i]=COURSES[i][2];

for(i=0;i<n_courses;i++)
sortCourses[i]=COURSES[i][0];

for(i=0;i<n_courses;i++)
sortHalles[i]=COURSES[i][3];


 for (c = 0;c<n_courses-1;c++)
  {
    for (d=0;d< n_courses-c-1;d++)
    {
      if (into_days(sortDates[d]) > into_days(sortDates[d+1]))
      {
        SWAPd=sortDates[d];
        sortDates[d]= sortDates[d+1];
        sortDates[d+1]=SWAPd;

        SWAPc=sortCourses[d];
        sortCourses[d]= sortCourses[d+1];
        sortCourses[d+1]=SWAPc;


        SWAPh=sortHalles[d];
        sortHalles[d]= sortHalles[d+1];
        sortHalles[d+1]=SWAPh;
      }
    }
  }




string operation;
do
{
getline(cin,operation);

    if(operation=="Number_Students")
    cout<<n_students<<endl;

    if(operation=="Number_Halls")
    cout<<n_halls<<endl;

    if(operation=="Number_Courses")
    cout<<n_courses<<endl;

    if(operation=="Student_ID_Min")
    cout<<min_id<<endl;

    if(operation=="Student_ID_Max")
    cout<<max_id<<endl;

    if(operation=="Students_Dropped_IDs")
    {

     //related to dropped ids
    int flag1,flag2=0;
    for(i=min_id+1;i<max_id;i++)
   {
    flag1=0;
      for(y=0;y<n_students;y++)
      {  if(i==S[y].id)
         {
         flag1=1;
         break;
         }
      }

     if(flag1==0)
     {
     cout<<i<<endl;
     flag2=1;
     }
   }
    if(flag2==0)
    cout<<"none"<<endl;

    }

  if(operation=="Exams_Start_Date")
  cout<<earliest.getDay()<<"/"<<earliest.getMonth()<<"/"<<earliest.getYear()<<endl;

  if(operation=="Exams_End_Date")
  cout<<latest.getDay()<<"/"<<latest.getMonth()<<"/"<<latest.getYear()<<endl;

  if(operation=="Exams_Period_InDays")
  cout<<days<<endl;


// level 1 is finished


  if(operation.substr(0,15)=="Student_Courses")
  {
  string CS=operation.substr(16,5);
  float FCS=atof(CS.c_str());

    for(i=0;i<n_students;i++)
    {
      if(FCS==S[i].id)
        break;
    }
    int CCS= STUDENTS[i][2].length();
    int NCS= number_of(CCS,STUDENTS[i][2],",");
    for(int j=0;j<NCS;j++)
    {
     cout<< S[i].Courses_of_student[j]<<endl;
    }
   }


   if(operation.substr(0,15)=="Course_Students")
   {
    int flag2=1;
    int L=operation.length();
    string testCourse=operation.substr(16,L-29);

    for(i=0;i<n_students;i++)
      {
        int L=STUDENTS[i][2].length();
        int N=number_of(L,STUDENTS[i][2],",");
        for(j=0;j<N;j++)
            if(S[i].Courses_of_student[j]==testCourse)
        {
            cout<<STUDENTS[i][0]<<endl;
            flag2=0;

        }


      }

     if(flag2==1)
        cout<<"none"<<endl;

   }


   if(operation.substr(0,20)=="List_Course_Students")
   {
     if(operation.substr(21,4)=="More")
     {
      int fix=operation.length();
      int flag2=1;
     string SM=operation.substr(26,fix-26);
     int M;
     M=atof(SM.c_str());
     int CountM=0;
      for(i=0;i<n_courses;i++)
      {
      int CountM=0;
        for(j=0;j<n_students;j++)
        {
        int L=STUDENTS[j][2].length();
        int N=number_of(L,STUDENTS[j][2],",");
           for(int k=0;k<N;k++)
           {
            if(C[i].code==S[j].Courses_of_student[k])
            CountM++;
           }
        }

      if(CountM>M)
      {cout<<C[i].code<<endl;flag2=0; }
     }
     if(flag2==1)
    cout<<"none"<<endl;
     }

if(operation.substr(21,4)=="Less")
     {
      int flag2=1;
     string SM=operation.substr(26,1);
     int M;
     M=atof(SM.c_str());
     int CountM=0;
      for(i=0;i<n_courses;i++)
      {
      int CountM=0;
        for(j=0;j<n_students;j++)
        {
        int L=STUDENTS[j][2].length();
        int N=number_of(L,STUDENTS[j][2],",");
           for(int k=0;k<N;k++)
           {
            if(C[i].code==S[j].Courses_of_student[k])
            CountM++;
           }
        }

      if(CountM<M)
      {cout<<C[i].code<<endl; flag2=0;}
     }
     if(flag2==1)
    cout<<"none"<<endl;
     }


if(operation.substr(21,5)=="Equal")
     {
     int flag2=1;
     string SM=operation.substr(27,1);
     int M;
     M=atof(SM.c_str());
     int CountM=0;
      for(i=0;i<n_courses;i++)
      {
      int CountM=0;
        for(j=0;j<n_students;j++)
        {
        int L=STUDENTS[j][2].length();
        int N=number_of(L,STUDENTS[j][2],",");
           for(int k=0;k<N;k++)
           {
            if(C[i].code==S[j].Courses_of_student[k])
            CountM++;
           }
        }

      if(CountM==M)
      {cout<<C[i].code<<endl;flag2=0;}
     }
     if(flag2==1)
    cout<<"none"<<endl;
     }


   }


if(operation.substr(0,20)=="List_Student_Courses")
{
    if(operation.substr(21,4)=="More")
    {
     int flag2=1;
    string SM=operation.substr(26,1);
    int M;
    M=atof(SM.c_str());
      for(i=0;i<n_students;i++)
      {
      int L=STUDENTS[i][2].length();
      int N=number_of(L,STUDENTS[i][2],",");
      if(N>M)
      cout<<S[i].id<<endl;
      }

    }

if(operation.substr(21,4)=="Less")
    {
     int flag2=1;
    string SM=operation.substr(26,1);
    int M;
    M=atof(SM.c_str());
      for(i=0;i<n_students;i++)
      {
      int L=STUDENTS[i][2].length();
      int N=number_of(L,STUDENTS[i][2],",");
      if(N<M)
      {cout<<S[i].id<<endl;flag2=0;}
      }
if(flag2==1)
    cout<<"none"<<endl;
    }

if(operation.substr(21,5)=="Equal")
    {
     int flag2=1;
    string SM=operation.substr(27,1);
    int M;
    M=atof(SM.c_str());
      for(i=0;i<n_students;i++)
      {
      int L=STUDENTS[i][2].length();
      int N=number_of(L,STUDENTS[i][2],",");
      if(N==M)
      {cout<<S[i].id<<endl;flag2=0;}
      }
if(flag2==1)
    cout<<"none"<<endl;
    }


}

  if(operation.substr(0,27)=="List_Hall_Students_InAnyDay")
   {
    int flag2=1;
    string testhall=operation.substr(28,5);
    int OUT[100];
    int countOUT=0;
     for(i=0;i<n_courses;i++)
     {
       if(COURSES[i][3]==testhall)
       {

        for(j=0;j<n_students;j++)
        {
        int L=STUDENTS[j][2].length();
        int N=number_of(L,STUDENTS[j][2],",");
        for(int k=0;k<N;k++)
         {
           if(C[i].code==S[j].Courses_of_student[k])
           {
           OUT[countOUT]=S[j].id;
           countOUT++;
           }
         }
        }
      }
    }
int testOUT[100];

  for(i=0;i<countOUT;i++)
  {
   int flag=1;
    for(j=0;j<countOUT;j++)
     if(OUT[i]==testOUT[j])
     flag=0;
    if(flag==1)
    {
    cout<<OUT[i]<<endl;
    flag2=0;
    testOUT[i]=OUT[i];
    }
  }
  if(flag2==1)
    cout<<"none"<<endl;
   }

if(operation.substr(0,28)=="List_Hall_Students_InAnyHall")
   {
    int flag2=1;
    int L=operation.length();
    string testdate=operation.substr(29,L-29);
    int OUT[100];
    int countOUT=0;
     for(i=0;i<n_courses;i++)
     {
       if(COURSES[i][2]==testdate)
       {

        for(j=0;j<n_students;j++)
        {
        int L=STUDENTS[j][2].length();
        int N=number_of(L,STUDENTS[j][2],",");
        for(int k=0;k<N;k++)
         {
           if(C[i].code==S[j].Courses_of_student[k])
           {
           OUT[countOUT]=S[j].id;
           countOUT++;
           }
         }
        }
      }
    }

int testOUT[100];

  for(i=0;i<countOUT;i++)
  {
   int flag=1;
    for(j=0;j<countOUT;j++)
     if(OUT[i]==testOUT[j])
     flag=0;
    if(flag==1)
    {
    cout<<OUT[i]<<endl;
    testOUT[i]=OUT[i];
    flag2=0;
    }
  }
  if(flag2==1)
    cout<<"none"<<endl;
for(i=0;i<countOUT;i++)
 {
  OUT[i]=0;
  testOUT[i]=0;
 }
   }

 if(operation.substr(0,19)=="List_Hall_Students ")
   {
   int flag2=1;
   string testhall=operation.substr(19,5);
   int L=operation.length();
   string testdate=operation.substr(26,L-26);
   int OUT[100];
   int countOUT=0;
     for(i=0;i<n_courses;i++)
     {
        if(COURSES[i][3]==testhall && COURSES[i][2]==testdate)
        break;
     }
     for(j=0;j<n_students;j++)
     {
     int L=STUDENTS[j][2].length();
     int N=number_of(L,STUDENTS[j][2],",");
        for(int k=0;k<N;k++)
        {
         if(C[i].code==S[j].Courses_of_student[k])
         {
         OUT[countOUT]=S[j].id;
         countOUT++;
         }
        }

     }


int testOUT[100];

  for(int i=0;i<countOUT;i++)
  {
   int flag=1;
    for(j=0;j<countOUT;j++)
     if(OUT[i]==testOUT[j])
     flag=0;
    if(flag==1)
    {
    cout<<OUT[i]<<endl;
    testOUT[i]=OUT[i];
    flag2=0;
    }
  }

if(flag2==1)
    cout<<"none"<<endl;

 for(i=0;i<countOUT;i++)
 {
  OUT[i]=0;
  testOUT[i]=0;
 }
     }

//Level 2 is finished !!!
//3ash ya JO^^



 if(operation.substr(0,10)=="List_Exams")
 {
  int  L=operation.length();
  string testdate=operation.substr(11,L-11);
  for(i=0;i<n_courses;i++)
   if(COURSES[i][2]==testdate)
   cout<<COURSES[i][0]<<endl;
 }

if(operation.substr(0,15)=="List_StudyDays ")
{
    string testID=operation.substr(15,5);
    int LENGTH=operation.length();
    string testCODE=operation.substr(21,LENGTH-21);

  for(i=0;i<n_students;i++)
    if(STUDENTS[i][0]==testID)
    break;

int L=STUDENTS[i][2].length();
int N=number_of(L,STUDENTS[i][2],",");
string sortCourses2[10];
int countSort=0;
string SWAP;

    for(y=0;y<N;y++)
    sortCourses2[y]=S[i].Courses_of_student[y];



    for(int k=0;k<n_courses;k++)
        for(int q=0;q<N;q++)
        if(sortCourses[k]==sortCourses2[q])
        {
         SWAP=sortCourses2[countSort];
        sortCourses2[countSort]=sortCourses2[q];
        sortCourses2[q]=SWAP;
        countSort++;
        }

    for(y=0;y<N;y++)
    if(sortCourses2[y]==testCODE)
        break;

    if(y==0)
     cout<<7<<endl;

    else
    {

     string date1,date2;
    for(j=0;j<n_courses;j++)
        if(COURSES[j][0]==sortCourses2[y])
        break;
    date1=COURSES[j][2];


    for(j=0;j<n_courses;j++)
        if(COURSES[j][0]==sortCourses2[y-1])
        break;
    date2=COURSES[j][2];
    int x=into_days(date1)-into_days(date2)-1;
    if(x!=-1)
    cout<<x<<endl;
    if(x==-1)
     cout<<0<<endl;
    }


}


if(operation.substr(0,30)=="List_StudyDays_ForEveryStudent")
{
    int Length=operation.length();
    string testCODE=operation.substr(31,Length-31);

    for(int z=0;z<n_students;z++)
    {
      int L1=STUDENTS[z][2].length();
      int N1=number_of(L1,STUDENTS[z][2],",");

        for(int v=0;v<N1;v++)
            if(S[z].Courses_of_student[v]==testCODE)
        {



  for(i=0;i<n_students;i++)
    if(STUDENTS[i][0]==STUDENTS[z][0])
    break;

int L=STUDENTS[i][2].length();
int N=number_of(L,STUDENTS[i][2],",");
string sortCourses2[10];
int countSort=0;
string SWAP;

    for(y=0;y<N;y++)
    sortCourses2[y]=S[i].Courses_of_student[y];



    for(int k=0;k<n_courses;k++)
        for(int q=0;q<N;q++)
        if(sortCourses[k]==sortCourses2[q])
        {
         SWAP=sortCourses2[countSort];
        sortCourses2[countSort]=sortCourses2[q];
        sortCourses2[q]=SWAP;
        countSort++;
        }

    for(y=0;y<N;y++)
    if(sortCourses2[y]==testCODE)
        break;

    if(y==0)
     cout<<S[z].id<<" "<<7<<endl;

    else
    {

     string date1,date2;
    for(j=0;j<n_courses;j++)
        if(COURSES[j][0]==sortCourses2[y])
        break;
    date1=COURSES[j][2];


    for(j=0;j<n_courses;j++)
        if(COURSES[j][0]==sortCourses2[y-1])
        break;
    date2=COURSES[j][2];

int x=into_days(date1)-into_days(date2)-1;
    if(x!=-1)
    cout<<S[z].id<<" "<<x<<endl;
    if(x==-1)
     cout<<S[z].id<<" "<<0<<endl;

    }


        }


    }

}


if(operation.substr(0,29)=="List_StudyDays_ForEveryCourse")
{
    string testID=operation.substr(30,5);

    for(int z=0;z<n_courses;z++)
    {


  for(i=0;i<n_students;i++)
    if(STUDENTS[i][0]==testID)
    break;

int L=STUDENTS[i][2].length();
int N=number_of(L,STUDENTS[i][2],",");
string sortCourses2[10];
int countSort=0;
string SWAP;

    for(y=0;y<N;y++)
    sortCourses2[y]=S[i].Courses_of_student[y];



    for(int k=0;k<n_courses;k++)
        for(int q=0;q<N;q++)
        if(sortCourses[k]==sortCourses2[q])
        {
         SWAP=sortCourses2[countSort];
        sortCourses2[countSort]=sortCourses2[q];
        sortCourses2[q]=SWAP;
        countSort++;
        }

    for(y=0;y<N;y++)
    if(sortCourses2[y]==COURSES[z][0])
    {



    if(y==0)
     cout<<C[z].code<<" "<<7<<endl;

    else
    {

     string date1,date2;
    for(j=0;j<n_courses;j++)
        if(COURSES[j][0]==sortCourses2[y])
        break;
    date1=COURSES[j][2];


    for(j=0;j<n_courses;j++)
        if(COURSES[j][0]==sortCourses2[y-1])
        break;
    date2=COURSES[j][2];


int x=into_days(date1)-into_days(date2)-1;
    if(x!=-1)
    cout<<C[z].code<<" "<<x<<endl;
    if(x==-1)
     cout<<C[z].code<<" "<<0<<endl;
    }

    }
}

}


if(operation.substr(0,30)=="List_Minimum_Student_StudyDays")
{
    string testID=operation.substr(31,5);
    int minStudyDaysC[100];
    int N,MARK,minStudyDays;
    int counterList=0;

    for(int z=0;z<n_courses;z++)
    {


  for(i=0;i<n_students;i++)
    if(STUDENTS[i][0]==testID)
    break;

int L=STUDENTS[i][2].length();
 N=number_of(L,STUDENTS[i][2],",");
string sortCourses2[10];
int countSort=0;
string SWAP;

    for(y=0;y<N;y++)
    sortCourses2[y]=S[i].Courses_of_student[y];



    for(int k=0;k<n_courses;k++)
        for(int q=0;q<N;q++)
        if(sortCourses[k]==sortCourses2[q])
        {
         SWAP=sortCourses2[countSort];
        sortCourses2[countSort]=sortCourses2[q];
        sortCourses2[q]=SWAP;
        countSort++;
        }

    for(y=0;y<N;y++)
    if(sortCourses2[y]==COURSES[z][0])
    {



    if(y==0)
     {minStudyDaysC[counterList]=7;
     counterList++;
     }


    else
    {

     string date1,date2;
    for(j=0;j<n_courses;j++)
        if(COURSES[j][0]==sortCourses2[y])
        break;
    date1=COURSES[j][2];


    for(j=0;j<n_courses;j++)
        if(COURSES[j][0]==sortCourses2[y-1])
        break;
    date2=COURSES[j][2];


int x=into_days(date1)-into_days(date2)-1;
    if(x!=-1)
    minStudyDaysC[counterList]=x;
    if(x==-1)
     minStudyDaysC[counterList]=0;
    counterList++;
    }

    }
    }
minStudyDays=minStudyDaysC[0];
for(int u=0;u<N;u++)
    if(minStudyDaysC[u]<minStudyDays)
    {minStudyDays=minStudyDaysC[u];
    MARK=u;}

cout<<C[MARK].code<<" "<<minStudyDays<<endl;

}




if(operation.substr(0,29)=="List_Minimum_Course_StudyDays")
{

    int Length=operation.length();
    string testCODE=operation.substr(30,Length-30);
    int minStudyDaysS[100];
    int N2;
    int counterList2=0;

    for(int z=0;z<n_students;z++)
    {
      int L1=STUDENTS[z][2].length();
      int N1=number_of(L1,STUDENTS[z][2],",");

        for(int v=0;v<N1;v++)
            if(S[z].Courses_of_student[v]==testCODE)
        {



  for(i=0;i<n_students;i++)
    if(STUDENTS[i][0]==STUDENTS[z][0])
    break;

        int L=STUDENTS[i][2].length();
        N2=number_of(L,STUDENTS[i][2],",");
        string sortCourses2[10];
        int countSort=0;
        string SWAP;

    for(y=0;y<N2;y++)
    sortCourses2[y]=S[i].Courses_of_student[y];



    for(int k=0;k<n_courses;k++)
        for(int q=0;q<N2;q++)
        if(sortCourses[k]==sortCourses2[q])
        {
         SWAP=sortCourses2[countSort];
        sortCourses2[countSort]=sortCourses2[q];
        sortCourses2[q]=SWAP;
        countSort++;
        }

    for(y=0;y<N2;y++)
    if(sortCourses2[y]==testCODE)
        break;

    if(y==0)
     {minStudyDaysS[counterList2]=7;
     counterList2++;
     }


    else
    {

     string date1,date2;
    for(j=0;j<n_courses;j++)
        if(COURSES[j][0]==sortCourses2[y])
        break;
    date1=COURSES[j][2];


    for(j=0;j<n_courses;j++)
        if(COURSES[j][0]==sortCourses2[y-1])
        break;
    date2=COURSES[j][2];



int x=into_days(date1)-into_days(date2)-1;
    if(x!=-1)
    minStudyDaysS[counterList2]=x;
    if(x==-1)
     minStudyDaysS[counterList2]=0;
    counterList2++;
    }


        }


 }


int minStudyDays2=minStudyDaysS[0];
for(int a=0;a<N2;a++)
    if(minStudyDaysS[a]<minStudyDays2)
    minStudyDays2=minStudyDaysS[a];
cout<<minStudyDays2<<endl;




}



if(operation.substr(0,22)=="List_Minimum_StudyDays")
{
int minStudyDays[100];
int counterList3=0;

  for(int s=0;s<n_students;s++)
  {
      int L3=STUDENTS[s][2].length();
      int N3=number_of(L3,STUDENTS[s][2],",");
     for(int t=0;t<N3;t++)
      {
          for(i=0;i<n_students;i++)
    if(STUDENTS[i][0]==STUDENTS[s][0])
    break;

int L=STUDENTS[i][2].length();
int N=number_of(L,STUDENTS[i][2],",");
string sortCourses2[10];
int countSort=0;
string SWAP;

    for(y=0;y<N;y++)
    sortCourses2[y]=S[i].Courses_of_student[y];



    for(int k=0;k<n_courses;k++)
        for(int q=0;q<N;q++)
        if(sortCourses[k]==sortCourses2[q])
        {
         SWAP=sortCourses2[countSort];
        sortCourses2[countSort]=sortCourses2[q];
        sortCourses2[q]=SWAP;
        countSort++;
        }

    for(y=0;y<N;y++)
    if(sortCourses2[y]==S[s].Courses_of_student[t])
        break;

    if(y==0)
     {
     minStudyDays[counterList3]=7;
     counterList3++;
     }

    else
    {

     string date1,date2;
    for(j=0;j<n_courses;j++)
        if(COURSES[j][0]==sortCourses2[y])
        break;
    date1=COURSES[j][2];


    for(j=0;j<n_courses;j++)
        if(COURSES[j][0]==sortCourses2[y-1])
        break;
    date2=COURSES[j][2];



int x=into_days(date1)-into_days(date2)-1;
    if(x!=-1)
    minStudyDays[counterList3]=x;
    if(x==-1)
     minStudyDays[counterList3]=0;
    counterList3++;

    }



      }
  }


int MIN=minStudyDays[0];

for(i=0;i<counterList3;i++)
    if(minStudyDays[i]<MIN)
    MIN=minStudyDays[i];


cout<<MIN<<endl;

}

if(operation.substr(0,20)=="List_Exam_InSameDay ")
{
    int flag2=1;
    string testID=operation.substr(20,5);
    for(i=0;i<n_students;i++)
        if(STUDENTS[i][0]==testID)
         break;

  int L=STUDENTS[i][2].length();
  int N=number_of(L,STUDENTS[i][2],",");

string D[10];
string c[10];
int countDC=0;

 for(y=0;y<N;y++)
    for(int g=0;g<n_courses;g++)
        if(COURSES[g][0]==S[i].Courses_of_student[y])
        {
        D[countDC]=COURSES[g][2];
        c[countDC]=COURSES[g][0];
        countDC++;
        }


    for(y=0;y<N;y++)
    {
       string testDate=D[y];

         for(int k=0;k<N;k++)
         if(k!=y && D[k]==testDate)
         {
         cout<<c[k]<<endl;
         flag2=0;
         }
    }

if(flag2==1)
    cout<<"none"<<endl;

}

if(operation.substr(0,35)=="List_Exam_InSameDay_ForEveryStudent")
{
 string Save[10];
 int countSave=0;
for(int v=0;v<n_students;v++)
{

    int flag2=1;
    for(i=0;i<n_students;i++)
        if(STUDENTS[i][0]==STUDENTS[v][0])
         break;

  int L=STUDENTS[i][2].length();
  int N=number_of(L,STUDENTS[i][2],",");

string D[10];
string c[10];
int countDC=0;

 for(y=0;y<N;y++)
    for(int g=0;g<n_courses;g++)
        if(COURSES[g][0]==S[i].Courses_of_student[y])
        {
        D[countDC]=COURSES[g][2];
        c[countDC]=COURSES[g][0];
        countDC++;
        }


    for(y=0;y<N;y++)
    {
       string testDate=D[y];

         for(int k=0;k<N;k++)
         if(k!=y && D[k]==testDate)
         {

         Save[countSave]=c[k];
         countSave++;
         flag2=0;

         }



   }

   if(flag2==0)
   {

         cout<<STUDENTS[v][0];
         for(f=0;f<countSave;f++)
         cout<<" "<<Save[f];
         cout<<endl;
   }
  if(flag2==1)
        cout<<STUDENTS[v][0]<<" none"<<endl;

  }
}

if(operation.substr(0,21)=="List_Exam_InSameHall ")
{
    int flag2=1;
    int Length=operation.length();
    string testDate=operation.substr(21,Length-21);



string H[100];
string codes[100];
int countTH=0;

    for(int g=0;g<n_courses;g++)
        if(COURSES[g][2]==testDate)
        {
        codes[countTH]=COURSES[g][0];
        H[countTH]=COURSES[g][3];
        countTH++;
        }


    for(y=0;y<countTH;y++)
    {
       string testHall=H[y];

         for(int k=0;k<countTH;k++)
         if(k!=y && H[k]==testHall)
         {
         cout<<codes[k]<<endl;
         flag2=0;
         }
    }
if(flag2==1)
    cout<<"none"<<endl;

}


if(operation.substr(0,44)=="List_Exam_InSameHall_Simultaneously_InAnyDay")
{
 string Save2[100];
 int countSave2=0;
for(int v=0;v<n_courses;v++)
{

    int flag2=1;


string H[100];
string codes[100];
int countTH=0;

    for(int g=0;g<n_courses;g++)
        if(COURSES[g][2]==sortDates[v])
        {
        H[countTH]=COURSES[g][3];
        codes[countTH]=COURSES[g][0];
        countTH++;
        }


    for(y=0;y<countTH;y++)
    {
       string testHall=H[y];

         for(int k=0;k<countTH;k++)
         if(k!=y && H[k]==testHall)
         {

         Save2[countSave2]=codes[k];
         countSave2++;
         flag2=0;

         }



   }

   if(flag2==0)
   {

         cout<<sortDates[v];
         for(f=0;f<countSave2;f++)
         cout<<" "<<Save2[f];
         cout<<endl;
   }
  if(flag2==1)
        cout<<sortDates[v]<<" none"<<endl;

  }
}


//level 3 is finished!


if(operation.substr(0,43)=="Reschedule_Course_InSameDay_InDifferentHall")
{
int flag2=1;
int L=operation.length();
string testcode=operation.substr(44,L-44);


for(i=0;i<n_courses;i++)
if(COURSES[i][0]==testcode)
    break;

    string testDate=COURSES[i][2];
    int countT=0;
    string testHall[100];
    for(i=0;i<n_courses;i++)
    {
        if(COURSES[i][2]==testDate)
        {
        testHall[countT]=COURSES[i][3];
        countT++;
        }
    }
  for(i=0;i<n_courses;i++)
  {
      int flag=1;
    for(j=0;j<countT;j++)
    if(COURSES[i][3]==testHall[j])
      flag=0;
   if(flag==1)
     {cout<<COURSES[i][3]<<endl;
     flag2=0;
      break;
     }
  }

  for(j=0;j<countT;j++)
    testHall[j]="";


if(flag2==1)
    cout<<"none"<<endl;
}






}
while(operation!="Quit");

cout<<"Thanks!"<<endl;

return 0;

}
