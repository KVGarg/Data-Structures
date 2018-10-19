#include <iostream>
#include<iomanip> 
#include<string.h> 
using namespace std;

struct student
{
     int roll_no;
     char name[20];
     char father_name[20];
     int day_of_birth;
     int month_of_birth;
     int year_of_birth;
     int day_of_joining;
     int month_of_joining;
     int year_of_joining;
     char address[30];
}
record[60],temp;

void add_main(int i , int n )  ;
void add_record();
void print_reord(int , int);
void delete_record();
void list_record(int);
void sorting_record(int);
void print_sort();
void update_record();

int countt=1 , option;;

void print_sort()
{
   cout<<"ROLL NO\t";
   cout<<"NAME\t";
   cout<<"FATHER'S NAME\t";
   cout<<"DATE OF BIRTH\t";
   cout<<"DATE OF JOINING THE COLLEGE\t";
   cout<<"ADDRESS"<<endl;

   for(int i=countt-2;i>=0;i--)
   {
    cout<<record[i].roll_no<<"\t";
    cout<<record[i].name<<"\t";
    cout<<record[i].father_name<<"\t";
    cout<<record[i].day_of_birth<<"/"<<record[i].month_of_birth<<"/"<<record[i].year_of_birth<<"\t";
    cout<<record[i].day_of_joining<<"/"<<record[i].month_of_joining<<"/"<<record[i].year_of_joining<<"\t";
    cout<<record[i].address<<endl;
   }
}

void add_main(int i , int n )
    {
            record[i].roll_no=(i+1);
         cout<<"Roll No. : " << record[i].roll_no  << endl;
        again :
        cout<<endl<<"Enter student's name : ";
         fflush(stdin);
        gets(record[i].name);

	     for(int j = 0 ; j< strlen(record[i].name);  j++)
         {
             if((  record[i].name[j] <= ('z') && record[i].name[j] >= ('a') ^ (record[i].name[j] == ' ')  ) || ( record[i].name[j] <= ('Z') && record[i].name[j] >= ('A') ^ (record[i].name[j] == ' ') ) ){

                             /// exclusive or eg. false * true = true   , true * true = false
             }
             else{
                    cout << "Error : no special keywords allowed " << endl;
                goto again;
             }
         }
       again1 :
            cout<<"Enter father's name : ";
          fflush(stdin);
	     gets(record[i].father_name);

	      for(int j = 0 ; j< strlen(record[i].father_name);  j++)
         {
             if(( (record[i].father_name[j] <= ('z') && record[i].father_name[j] >= ('a')) ^ record[i].father_name[j] == ' ') || ((record[i].father_name[j] <= ('Z') && record[i].father_name[j] >= ('A')) ^ (record[i].father_name[j] == ' ')  ) ){


             }
             else{

                    cout << "Error : no special keywords allowed " << endl;
                goto again1;
             }
         }
       again2:
	        cout<<"Enter birth day : ";
            cin>>record[i].day_of_birth;

            if((record[i].day_of_birth<=31)&&(record[i].day_of_birth>=1))
            {


            }
            else
            {
                cout<<" Date not valid : ";
                goto again2 ;
            }
    	again3 :
             	cout<<"Enter birth month : ";
                cin>>record[i].month_of_birth;
                if((record[i].month_of_birth<=12)&&(record[i].month_of_birth>=1))
                {


                }
            else
            {
                cout<<" Month not valid : ";
                goto again3 ;
            }
		again4 :
            cout<<"Enter year of your birth : ";
                    cin>>record[i].year_of_birth;
                    if(record[i].year_of_birth<=1992)
                  {
                      cout << " You are too old for this college\n do it again " ;
                      goto again4 ;
                  }
                   else if(record[i].year_of_birth >= 1999)
                  {
                      cout << " You are too young for this college\n do it again " ;
                      goto again4 ;
                  }
		 again5 :
            cout<<"Enter joining date : ";
           cin>>record[i].day_of_joining;
            if((record[i].day_of_joining<=31)&&(record[i].day_of_joining>=1))
            {
			}
            else
            {
                cout<<"Date not valid "<<endl;
                goto again5;
            }
		 again6 :
            cout<<"Enter joining month : ";
                cin>>record[i].month_of_joining;
                if((record[i].month_of_joining<=12)&&(record[i].month_of_joining>=1))
                 {

                 }
            else
            {
                cout<<" Month not valid : ";
                goto again6 ;
            }
		again7 :
            cout<<"Enter joining date : ";
                    cin>>record[i].year_of_joining;
                    if((record[i].year_of_joining>2017))
                    {
                        cout<<"Year not valid"<<endl;
                        goto again7 ;
                    }
            cout<<"address : ";
            fflush(stdin);
            gets(record[i].address);
             countt+=1;
         }

void add_record()
{
    cout<<"Enter number of students to store : ";
         int n;
         cin>>n;
    for(int i=0;i<n;i++)
    {
         add_main(i , n);
    }
}

void update_record()
{
      pppp:
      cout<<"Enter student's no. to update : ";
        int i;
        cin>>i;
        if( i < countt){
        add_main(i-1, i);
        countt--;
        }
        else
        {
            cout << "Student not available : ";
            goto pppp;
        }
 }
 
void print_record(int n , int pp)
{
   cout<<setw(20)<<"ENROLLMENT NUMBER\t";
   cout<<setw(20)<<"NAME\t";
   cout<<setw(20)<<"FATHER'S NAME\t";
   cout<<setw(20)<<"DATE OF BIRTH\t";
   cout<<setw(20)<<"DATE OF JOINING THE COLLEGE\t";
   cout<<setw(20)<<"ADDRESS"<<endl;

for(int i=n;i<pp-1;i++)
{
   cout<<setw(20)<<record[i].roll_no<<"\t";
   cout<<setw(20)<<record[i].name<<"\t";
   cout<<setw(20)<<record[i].father_name<<"\t";
   cout<<setw(20)<<record[i].day_of_birth<<"/"<<record[i].month_of_birth<<"/"<<record[i].year_of_birth<<"\t";
   cout<<setw(20)<<record[i].day_of_joining<<"/"<<record[i].month_of_joining<<"/"<<record[i].year_of_joining<<"\t";
   cout<<setw(20)<<record[i].address<<endl;
}

}

void sorting(int a)
{
   switch(a)
{
  case 1:
	for(int i=0;i<countt;i++)
	if(strcmp(record[i].name,record[i+1].name) < 0)
	{
      temp=record[i];
      record[i]=record[i+1];
   	  record[i+1]=temp;
	}
    print_sort();
	break;
  
  case 2:
	for(int i=0;i<countt-1;i++)
	if(strcmp(record[i].father_name,record[i+1].father_name) < 0)
	{
    	temp=record[i];
        record[i]=record[i+1];
        record[i+1]=temp;
	}
    print_sort();
	break;
	
	default:
    	cout<<"Enter Correct Option";
}
}

void list_record(int i)
{
   print_record(i-1 , i+1);
}

void delete_record()
{
 PEW :
	cout<<"Enter the roll no. to delete : ";
    int n;
    cin>>n;
    if( n < countt)
    {
      for(int p = n ; p < countt-1 ; p++)
	  {record[p-1] = record[p];
       }
		countt--;
    }
    else{
	      cout << "Student not available : ";
          goto PEW;
    }

}

int main()
{
    while(1)
    {
  	cout << endl << endl ;
    cout << "================= STUDENT MANAGEMENT SYSTEM ==========================="  << endl << endl;

    cout<<"\t\t\t1. Add Student"<<endl;
    cout<<"\t\t\t2. Delete Student"<<endl;
    cout<<"\t\t\t3. Update Student"<<endl;
    cout<<"\t\t\t4. Display All"<<endl;
    cout<<"\t\t\t5. Display Specific Record"<<endl;
    cout<<"\t\t\t6. Sort  Record"<<endl;
    cout<<"\t\t\t7. Exit"<<endl;

    cout<<"\n\t\t\tSELECT OPTION : ";
    cin>>option;

    switch(option)
    {
       case 1:
         system("cls");
         add_record();
         break;

       case 2:
           system("cls");
           delete_record();
	        break;

       case 3:
        system("cls");
        update_record();
        break;

       case 4:
            system("cls");
            cout<<"THE RECORDS ARE AS FOLLOWING:"<<endl;
            print_record(0 , countt);
            break;

       case 5:
            system("cls");
            rdf :
 	        cout<<"Enter roll no : ";
    	    int roll;
        	cin>>roll;
        	if(roll < countt){
        	list_record(roll);}
        else{
            cout << "Student not available : ";
            goto rdf;
        }
        break;

       case 6:
           {
             system("cls");
             cout<<"---->   1. Sort by names"<<endl;
             cout<<"---->   2. Sort by father names"<<endl;
             int opt;
             cout<<"Enter your option";
             cin>>opt;
             sorting(opt);
             break;}

       case 7:
         {
             exit(0);
		}
	}
}

return 0;
}

