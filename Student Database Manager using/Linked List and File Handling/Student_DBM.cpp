#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<iomanip>
using namespace std;
//Student Functions
void addStudent();
void deleteStudent();
void modifyStudent();
void searchStudent();
void listStudent();
void sortStudent();
//Scheme Functions
void addScheme();
void deleteScheme();
void modifyScheme();
void searchScheme();
void listScheme();
//Result Functions
void addResult();
void searchResult();
//Report Card Functions
void printReportCard();
void completeSemResult(); 
int main(void);
bool check = true;
const char separator = ' ';
const int nameWidth     = 15;
const int numWidth      = 8;
//Structure of Student Record
struct student_record    
{
 char student_fname[20],student_lname[20];
 char father_fname[20],father_lname[20];
 char rollNo[10];
 char semester[4];
 int dob_dd,dob_mm,dob_yyyy;
 int year_of_admission;
 student_record *next;
}*head,*lastptr;
//Structure of Scheme
struct scheme
{
	char subj_code[10],subj_title[40];
	int mm_sessional,mm_theory,mm_practical; char semester[4];
	scheme *next;
}*head1,*lastptr1;
//Structure of Result
struct result
{
	char roll_No[10];char semester[4];
	int year; float marks_awa_theory,marks_awa_Sessional,marks_awa_practical;
	result *next;
}*head2,*lastptr2;

void addStudent()    //Adds record of student
{
	student_record *p;
	student_record *newHead=NULL;
	ofstream fout("Student_Data.txt",ios::app);
	p=new student_record;
	cout<<"NOTE: DO NOT USE SPECIAL CHARACTERS "<<endl;
	cout<<"Enter First name of student: ";
	gets(p->student_fname); fout<<p->student_fname;
	fflush(stdin);
	cout<<"Enter Last name of student: ";
	gets(p->student_lname);  fout<<" "<<p->student_lname;
	fflush(stdin);
	cout<<"Enter father's First name of student:";
	gets(p->father_fname);  fout<<setw(20)<<p->father_fname;
	fflush(stdin);
	cout<<"Enter father's First name of student:";
	gets(p->father_lname);  fout<<" "<<p->father_lname;
	fflush(stdin);
	cout<<"Enter Roll Number of student: ";
	gets(p->rollNo); fout<<setw(15)<<p->rollNo;
	fflush(stdin);
	cout<<"Enter Semester: ";
	gets(p->semester);  fout<<setw(15)<<p->semester;
	fflush(stdin);
	cout<<"Enter Date of Birth:"<<endl;
	cout<<"Date-";  cin>>p->dob_dd; fout<<setw(15)<<p->dob_dd<<" "; fflush(stdin);
	cout<<"Month-";  cin>>p->dob_mm; fout<<p->dob_mm<<" "; fflush(stdin);
	cout<<"Year-";  cin>>p->dob_yyyy; fout<<p->dob_yyyy; fflush(stdin);
	cout<<"Year Of Admision:";  cin>>p->year_of_admission; fout<<setw(15)<<p->year_of_admission<<"\n"; fflush(stdin);
	p->next=NULL;

	if(check)
	{
	head = p;
	lastptr = p;
	check = false;
	}
	else
	{
	lastptr->next=p;
	lastptr=p;
	}
	fout.close();
	cout<<endl<<"Recored Entered"<<endl;
	char ch;
	cout<<"Do You Want to Add another Record?(Y/N)"<<endl;
	cout<<"Or Want to enter academic results of the semester?(PRESS R)"<<endl<<"Answer: ";
	cin>>ch;
	if(ch=='y'||ch=='Y')
	{
 	system("cls");
 	fflush(stdin);
 	addStudent();
	}
	else if(ch=='r'||ch=='R')
	{
 	system("cls");
 	fflush(stdin);
 	addResult();
	}
	else
	fflush(stdin);
	getch();
}

void modifyStudent()   //modifies record of student
{
	ifstream fin("Student_Data.txt");
	if(fin.is_open()){
	student_record * newHead = NULL;
	student_record *curr;
	while(!fin.eof())
	{
   	curr = newHead;
	 	//declare a new node to hold file data
   	student_record * newNode = new student_record;
   	//read in file data one node's worth at a time
   	fin >> newNode->student_fname >> newNode->student_lname >> newNode->father_fname >> newNode->father_lname >>  
   		newNode->rollNo >>  newNode->semester >>  newNode->dob_dd >>  newNode->dob_mm >>  newNode->dob_yyyy  >>  newNode->year_of_admission;
   	newNode->next = NULL;    
   	//and add to end new list
   	if(newHead == NULL)
   	newHead = newNode;
   	else
   	{
     	while(curr->next != NULL)
     	{
       	 curr = curr->next;
      	}
      	curr->next = newNode;
   	}
	}
 
	fin.close();
 	student_record *prev=NULL;
 	student_record *current=NULL;
 	char roll_no[10];
 	fflush(stdin);
 	cout<<"Enter Roll Number to Modify:"<<endl;
 	gets(roll_no);
 	prev=newHead;
 	current=newHead;
 	while(strcmp(current->rollNo,roll_no) != 0)
 	{
 		if(current->next == NULL)
 		{
 			cout<<"No Record Found"<<endl;
 			break;
		}
		else
 	 	prev=current;
  		current=current->next;
 	}
 	if(strcmp(current->rollNo,roll_no)==0)
 	{
 	system("cls");
 	curr=new student_record;
 	cout<<"\t\t\tCurrent Student Data";
 	cout<<"\nRoll No."<<current->rollNo;
 	cout<<"\nName: ";
 	cout<< current->student_fname <<" " <<current->student_lname;
 	cout<<"\nFather's Name: ";
 	cout<<current->father_fname<<" "<<current->father_lname;
 	cout<<"\nDate Of Birth:";
 	cout<<current->dob_dd<<"/"<<current->dob_mm<<"/"<<current->dob_yyyy;
 	cout<<"\nSemester: ";
 	puts(current->semester);
 	cout<<"\nYear Of Admission:";
 	cout<<current->year_of_admission<<endl;
 	cout<<"**********************************"<<endl;
 	fflush(stdin);
 	cout<<"NOTE: DO NOT USE SPECIAL CHARACTERS "<<endl<<endl;
 	cout<<"\t\t\tStudent New Record"<<endl<<endl;
 	cout<<"Enter first name of student: ";
 	gets(curr->student_fname);
 	fflush(stdin);
 	cout<<"Enter last name of student: ";
 	gets(curr->student_lname);
 	fflush(stdin);
 	cout<<"Enter father's first name of student: ";
 	gets(curr->father_fname);
 	fflush(stdin);
 	cout<<"Enter father's last name of student: ";
 	gets(curr->father_lname);
 	fflush(stdin);
 	cout<<"Enter Roll Number of student: ";
 	gets(curr->rollNo);
 	fflush(stdin);
 	cout<<"Enter Semester: ";
 	gets(curr->semester);
 	fflush(stdin);
 	cout<<"Enter Date of Birth:"<<endl;
 	cout<<"Date-";  cin>>curr->dob_dd;  fflush(stdin);
 	cout<<"Month-";  cin>>curr->dob_mm;  fflush(stdin);
 	cout<<"Year-";  cin>>curr->dob_yyyy;  fflush(stdin);
 	cout<<"Year Of Admision:";  cin>>curr->year_of_admission;  fflush(stdin);
 	prev->next=curr;
 	curr->next=current->next;
 	current->next=NULL;
 	delete current;
 	int r=0;curr=newHead;
 	while (curr)
	{
		curr = curr->next;
		r++;
	}
 	ofstream fout("Student_Data.txt",ios::out);
 	curr = newHead;
	for(int i=0;i<r;i++)
	{
   		fout << curr->student_fname<<" "<<curr->student_lname <<setw(20)<<curr->father_fname<<" "<<curr->father_lname
		   <<setw(15)<<curr->rollNo<<setw(15)<<curr->semester<<setw(15) <<curr->dob_dd<<" "<<curr->dob_mm
		   <<" "<<curr->dob_yyyy<<setw(15)<<curr->year_of_admission << endl;
   		curr = curr->next;
	}
	fout.close();
 
 	cout<<endl<<"Recored Modified"<<endl;
 	}
 	char ch;
 	cout<<"Do You Want to Modify another Record?(Y/N)"<<endl;
 	cin>>ch;
 	if(ch=='y'||ch=='Y')
 	{
 		system("cls");
 		fflush(stdin);
 		modifyStudent();
 	}
 	else
 	fflush(stdin);
	}
	else
	cout<<"File Doesn't Exist."<<endl;
 getch();
}

void searchStudent()   //searches record of student
{
	student_record *current=NULL;
 
	ifstream fin("Student_Data.txt");
	if(fin.is_open())
	{
	student_record * newHead = NULL;
	student_record *curr;
	while(!fin.eof())
	{
   	curr = newHead;
   	student_record * newNode = new student_record;
   	fin >> newNode->student_fname >> newNode->student_lname >> newNode->father_fname >> newNode->father_lname >> newNode->rollNo 
	   	>>  newNode->semester >>  newNode->dob_dd >>  newNode->dob_mm >>  newNode->dob_yyyy >>  newNode->year_of_admission;
   	newNode->next = NULL;
   	if(newHead == NULL)
   	newHead = newNode;
   	else
   	{
     while(curr->next != NULL)
     {
        curr = curr->next;
      }
      curr->next = newNode;
   	}
	}
 
	fin.close();
 
 	char roll_no[10];
 	fflush(stdin);
 	cout<<"Enter Roll Number to search:"<<endl;
 	gets(roll_no);
 	current=newHead;
 	while(strcmp(current->rollNo,roll_no) != 0)
 	{
 		
 		if(current->next == NULL)
 		{
 			cout<<"No Record Found"<<endl;
 			break;
		}
		else
  		current=current->next;	
 	}
 	if(strcmp(current->rollNo,roll_no)==0)
 	{
 	cout<<"\nRoll No."<<current->rollNo;
 	cout<<"\nName: ";
 	cout<< current->student_fname <<" " <<current->student_lname;
 	cout<<"\nFather's Name: ";
 	cout<<current->father_fname<<" "<<current->father_lname;
 	cout<<"\nDate Of Birth:";
 	cout<<current->dob_dd<<"/"<<current->dob_mm<<"/"<<current->dob_yyyy;
 	cout<<"\nSemester: ";
 	puts(current->semester);
 	cout<<"\nYear Of Admission:";
 	cout<<current->year_of_admission<<endl;
 	cout<<"**********************************"<<endl;
 	}
 	char ch;
 	cout<<"Do You Want to Search another Record?(Y/N)"<<endl;
 	cin>>ch;
 	if(ch=='y'||ch=='Y')
 	{
 		system("cls");
 		fflush(stdin);
 		searchStudent();
 	}
 	else
 	fflush(stdin);
	}
	else
	cout<<"File Doesn't Exist."<<endl;
	getch();
}

void deleteStudent()    //deletes record of a student
{
 	ifstream fin("Student_Data.txt");
 	if(fin.is_open())
 	{
		student_record * newHead = NULL;
		student_record *curr;
		while(!fin.eof())
		{
   			curr = newHead;
   			student_record * newNode = new student_record;
   			fin >> newNode->student_fname >> newNode->student_lname >> newNode->father_fname 
				>> newNode->father_lname  >>  newNode->rollNo >>  newNode->semester 
				>>  newNode->dob_dd >>  newNode->dob_mm >>  newNode->dob_yyyy
				>>  newNode->year_of_admission;
   			newNode->next = NULL;
   			if(newHead == NULL)
   			newHead = newNode;
   			else
   			{
     			while(curr->next != NULL)
     			{		
        			curr = curr->next;
      			}
      			curr->next = newNode;
   			}
		}	
 		fin.close();
	
 		student_record *prev=NULL;
		student_record *current=NULL;
 		char roll_no[10];
 		fflush(stdin);
 		cout<<"Enter Roll Number to Delete:"<<endl;
 		gets(roll_no);
 		prev=newHead;
 		current=newHead;
 		while(strcmp(current->rollNo,roll_no) != 0)
 		{
 			if(current->next == NULL)
 			{
 			cout<<"No Record Found"<<endl;
 			break;
			}
			else
  			prev=current;
  			current=current->next;
 		}
 		if(strcmp(current->rollNo,roll_no)==0)
 		{
 			cout<<"\t\t\tStudent Details"<<endl<<endl;
 			cout<<"\nRoll No."<<current->rollNo;
 			cout<<"\nName: ";
 			cout<< current->student_fname <<" " <<current->student_lname;
 			cout<<"\nFather's Name: ";
 			cout<<current->father_fname<<" "<<current->father_lname;
 			cout<<"\nDate Of Birth:";
 			cout<<current->dob_dd<<"/"<<current->dob_mm<<"/"<<current->dob_yyyy;
 			cout<<"\nSemester: ";
 			puts(current->semester);
 			cout<<"\nYear Of Admission:";
 			cout<<current->year_of_admission<<endl;
 			cout<<"**********************************"<<endl;
 			prev->next = current->next;
 			current->next=NULL;
 			delete current;
 			int r=0;
 			while (curr)
			{
			curr = curr->next;
			r++;
			}
 			ofstream fout("Student_Data.txt",ios::out);
 			curr = newHead;
			for(int i=0;i<r;i++)
			{
   			fout << curr->student_fname<<" "<<curr->student_lname <<setw(20)<<curr->father_fname<<" "<<curr->father_lname<<setw(15)<<curr->rollNo
			     <<setw(15)<<curr->semester<<setw(15)<<curr->dob_dd<<" "<<curr->dob_mm<<" "<<curr->dob_yyyy<<setw(10)
				 <<curr->year_of_admission << endl;
   			curr = curr->next;
			}
			fout.close();
			cout<<endl<<"Recored Deleted"<<endl;
		}
 		char ch;
 		cout<<"Do You Want to Delete another Record?(Y/N)"<<endl;
 		cin>>ch;
 		if(ch=='y'||ch=='Y')
 		{
 		system("cls");
 		fflush(stdin);
 		deleteStudent();
 		}
 		else
 		fflush(stdin);
		}
		else 
		cout<<"File Doesn't Exist."<<endl;
		fflush(stdin);
		getch();
}

void listStudent()  	//list all records 
{
	ifstream fin("Student_Data.txt",ios:: in);
    student_record * newHead = NULL;
	student_record *curr;
  	if(fin.is_open())
  	{
		while(!fin.eof())
		{
	
   			curr = newHead;
   			student_record * newNode = new student_record;
   			fin >> newNode->student_fname >> newNode->student_lname >> newNode->father_fname 
				>> newNode->father_lname>>  newNode->rollNo >>  newNode->semester 
				>>  newNode->dob_dd >>  newNode->dob_mm >>  newNode->dob_yyyy  
				>>  newNode->year_of_admission;
   			newNode->next = NULL;
   		if(newHead == NULL)
   		newHead = newNode;
   		else
   		{
     		while(curr->next != NULL)
     		{
        	curr = curr->next;
      		}
      		curr->next = newNode;
   		}
		}
		fin.close();
		int i=0,r=0;
		curr=newHead;
 		while (curr)
		{
		curr = curr->next;
		r++;
		}
		//display new list
	
		curr = newHead;
		cout << left << setw(1.2*nameWidth) << setfill(separator) << "Roll No.";
		cout << left << setw(2 * nameWidth) << setfill(separator) << "Student's Name";
		cout << left << setw(1.8 * nameWidth) << setfill(separator) << "Father's Name";
		cout << left << setw(1.2 * nameWidth) << setfill(separator) << "Semester";
		cout << left << setw(nameWidth) << setfill(separator) << "DOB";
		cout << left << setw(nameWidth) << setfill(separator) << "Year Of Admission"<<endl;
		cout << left << setw(0.8*nameWidth) << setfill(separator)<<" " ;
		cout << left << setw(nameWidth) << setfill(separator) << "First Name";
		cout << left << setw(nameWidth) << setfill(separator) << "Second Name";
		cout << left << setw(nameWidth) << setfill(separator) << "First Name";
		cout<<"Second Name"<<endl;
		cout<<"*********************************************************************************"
			<<"*********************************************"<<endl;
		while(i<r-1)
		{
		cout<< left << setw(1.5*numWidth) << setfill(separator) <<curr->rollNo;
		cout << left << setw(nameWidth) << setfill(separator) << curr->student_fname;
    	cout << left << setw(nameWidth) << setfill(separator) << curr->student_lname;
    	cout << left << setw(nameWidth) << setfill(separator) << curr->father_fname;
    	cout << left << setw(1.2 * nameWidth) << setfill(separator) << curr->father_lname;
    	cout << setw(nameWidth) << setfill(separator) << curr->semester;
    	if(curr->dob_dd < 10)
    	cout <<"0"<<curr->dob_dd;
    	else
    	cout<<curr->dob_dd;
    	cout <<"/"<< curr->dob_mm;
    	cout <<"/"<< left << setw(1.5 * numWidth) << setfill(separator) << curr->dob_yyyy;
    	cout << left << setw(numWidth) << setfill(separator) << curr->year_of_admission;
		cout<<endl;
		 i++;
   		curr=curr->next;
		}
 	}
 	else
 	{
 	cout << "File Doesn't Exist." << endl;
 	}
 	fflush(stdin); 
	getch();
}

void sortStudent()		//Sort Student Information 
{
	ifstream fin("Student_Data.txt",ios::in);
	student_record * newHead = NULL;
	student_record *curr;
	if(fin.is_open())
	{
	int r=0;
	while(!fin.eof())
	{
   	curr = newHead;
   	student_record * newNode = new student_record;
   	fin >> newNode->student_fname >> newNode->student_lname >> newNode->father_fname >> newNode->father_lname 
		>> newNode->rollNo >> newNode->semester>> newNode->dob_dd >> newNode->dob_mm >> newNode->dob_yyyy
		>> newNode->year_of_admission;
   	newNode->next = NULL;
   	if(newHead == NULL)
   	newHead = newNode;
   	else
   	{
     while(curr->next != NULL)
     {
        curr = curr->next;
      }
      curr->next = newNode;
   	}
   	r++;
	}
 
	fin.close();
	curr = newHead;
	char student_fname[20],student_lname[20];
 	char father_fname[20],father_lname[20];
 	char rollNo[10];
 	char semester[4];
 	int dob_dd,dob_mm,dob_yyyy;
 	int year_of_admission;
	int counter = 0;
	while (curr)
	{
		curr = curr->next;
		counter++;
	}
	curr = newHead;
	student_record *temp=NULL;
	student_record *ptr;
	for (int j=0; j<counter; j++)
	{
	curr = ptr = newHead; //set curr and ptr at the start node
    while (curr->next != NULL) 
	{ //for the rest of the elements in the list
      if (strcmp(curr->rollNo , curr->next->rollNo)>0)
	   { //compare curr and curr->next

        temp = curr->next; //swap pointers for curr and curr->next
        curr->next = curr->next->next;
        temp->next = curr;
        //now we need to setup pointers for ptr and possibly head
        if(curr == newHead) //this is the case of the first element swapping to preserve the head pointer
          newHead = ptr = temp;
        else //setup ptr correctly
          ptr->next = temp;
        curr = temp; //update curr to be temp since the positions changed
      }
      //advance pointers
      ptr = curr;
      curr = curr->next;
       
    }
	}
	
	curr=newHead;
	curr=curr->next;
	ofstream fout("Student_Data.txt",ios::out|ios::trunc);
	int i=0;
		cout << left << setw(1.2*nameWidth) << setfill(separator) << "Roll No.";
		cout << left << setw(2 * nameWidth) << setfill(separator) << "Student's Name";
		cout << left << setw(1.8 * nameWidth) << setfill(separator) << "Father's Name";
		cout << left << setw(1.2 * nameWidth) << setfill(separator) << "Semester";
		cout << left << setw(nameWidth) << setfill(separator) << "DOB";
		cout << left << setw(nameWidth) << setfill(separator) << "Year Of Admission"<<endl;
		cout << left << setw(0.8*nameWidth) << setfill(separator)<<" " ;
		cout << left << setw(nameWidth) << setfill(separator) << "First Name";
		cout << left << setw(nameWidth) << setfill(separator) << "Second Name";
		cout << left << setw(nameWidth) << setfill(separator) << "First Name";
		cout<<"Second Name"<<endl;
		cout<<"*************************************************************************"
			<<"*****************************************************"<<endl;
	while(i<r-1)
	{
		cout<< left << setw(numWidth) << setfill(separator) <<curr->rollNo;
		cout<< left << setw(nameWidth) << setfill(separator);
		cout << left << setw(nameWidth) << setfill(separator) << curr->student_fname;
    	cout << left << setw(nameWidth) << setfill(separator) << curr->student_lname;
    	cout << left << setw(nameWidth) << setfill(separator) << curr->father_fname;
    	cout << left << setw(1.2 * nameWidth) << setfill(separator) << curr->father_lname;
    	cout << setw(nameWidth) << setfill(separator) << curr->semester;
    	if(curr->dob_dd < 10)
    	cout <<"0"<<curr->dob_dd;
    	else
    	cout<<curr->dob_dd;
    	cout <<"/"<< curr->dob_mm;
    	cout <<"/"<< left << setw(1.5 * numWidth) << setfill(separator) << curr->dob_yyyy;
    	cout << left << setw(numWidth) << setfill(separator) << curr->year_of_admission;
		cout<<endl;
		
		fout << curr->student_fname <<" "<<curr->student_lname<<setw(25) << curr->father_fname<<" "<<curr->father_lname<<setw(15)
			 << curr->rollNo<<setw(10)<< curr->semester<<setw(10)<< curr->dob_dd<<" " << curr->dob_mm<<" " << curr->dob_yyyy<<setw(10)  
			<< curr->year_of_admission << endl;	
   		curr=curr->next;
   		i++;
	}
	}
	else
	cout<<"File Doesn't Exist."<<endl;
	fflush(stdin);
	getch();
	
}

void addScheme()    //Adds record of scheme
{
 scheme *p;
 scheme *newHead=NULL;
 p=new scheme;
 ofstream fout("Scheme_Data.txt",ios::app);
 cout<<"NOTE: DO NOT USE SPECIAL CHARACTERS "<<endl;
 cout<<"Enter Semester: ";gets(p->semester); fout<< p->semester; fflush(stdin);
 cout<<"Enter Subject Code: "; gets(p->subj_code); fout<<setw(15)<< p->subj_code; fflush(stdin);
 cout<<"Enter Subject Title: "; gets(p->subj_title); fout<<setw(25)<< p->subj_title; fflush(stdin);
 cout<<"Enter Theory Maximum Marks: ";  cin>>p->mm_theory; fout<<setw(15)<< p->mm_theory ;fflush(stdin);
 cout<<"Enter Sessional Maximum Marks: ";	cin>>p->mm_sessional; fout<<setw(15)<< p->mm_sessional; fflush(stdin);
 cout<<"Enter Practical Maximum Marks: "; cin>>p->mm_practical;	fout<<setw(15)<< p->mm_practical<<endl; fflush(stdin);
 p->next=NULL;

 if(check)
 {
  head1 = p;
  lastptr1 = p;
  check = false;
 }
 else
 {
  lastptr1->next=p;
  lastptr1=p;
 }
 
	fout.close();
 cout<<endl<<"Recored Entered"<<endl;
 char ch;
 cout<<"Do You Want to Add another Record?(Y/N)"<<endl;
 cin>>ch;
 if(ch=='y'||ch=='Y')
 {
 	system("cls");
 	addScheme();
 	fflush(stdin);
 }
 else
 fflush(stdin);
 getch();
}

void modifyScheme()   //modifies scheme
{
	ifstream fin("Scheme_Data.txt");
	if(fin.is_open())
	{
	scheme * newHead = NULL;
	scheme *curr;
 	while(!fin.eof())
 	{
   		curr = newHead;
   		scheme * newNode = new scheme;
   		fin >> newNode->semester >> newNode->subj_code >> newNode->subj_title >> newNode->mm_theory 
   			>> newNode->mm_sessional >> newNode->mm_practical;
   		newNode->next = NULL;    
   		if(newHead == NULL)
   		newHead = newNode;
   		else
   		{
     		while(curr->next != NULL)
     		{
        		curr = curr->next;
      		}
      		curr->next = newNode;
   		}
 	}
 	fin.close();
	 scheme *prev=NULL;
 	scheme *current=NULL;
 	char subjcode[10];
 	cout<<"Modify Subject Code :"<<endl;
 	cin>>subjcode;
 	prev=newHead;
 	current=newHead;
 	while(strcmp(current->subj_code , subjcode) != 0)
 	{
 		if(current->next == NULL)
 			{
 			cout<<"No Record Found"<<endl;
 			break;
			}
			else
  		prev=current;
  		current=current->next;
 	}
 	curr=new scheme;
 	fflush(stdin);
 	if(strcmp(current->subj_code , subjcode) != 0)
 	{
 	cout<<"NOTE: DO NOT USE SPECIAL CHARACTERS "<<endl;
 	cout<<"Enter Semester: ";gets(curr->semester); fflush(stdin);
 	cout<<"Enter Subject Code: "; gets(curr->subj_code); fflush(stdin);
 	cout<<"Enter Subject Title: "; gets(curr->subj_title); fflush(stdin);
 	cout<<"Enter Theory Maximum Marks: ";  cin>>curr->mm_theory; fflush(stdin);
 	cout<<"Enter Sessional Maximum Marks: ";	cin>>curr->mm_sessional; fflush(stdin);
 	cout<<"Enter Practical Maximum Marks: "; cin>>curr->mm_practical;
	prev->next=curr;
 	curr->next=current->next;
 	current->next=NULL;
 	delete current;
 	int r=0;
 	while (curr)
	{
		curr = curr->next;
		r++;
	}
 	ofstream fout("Scheme_Data.txt",ios::out);
 	curr = newHead;
	for(int i=0;i<r;i++)
	{
   		fout << curr->semester <<setw(15)<< curr->subj_code <<setw(25)<< curr->subj_title <<setw(15)
   			 << curr->mm_theory <<setw(15)<< curr->mm_sessional <<setw(15)<< curr->mm_practical <<endl;
   		curr = curr->next;
	}
	fout.close();
 	cout<<endl<<"Recored Modified"<<endl;
 	}
 	char ch;
 	cout<<"Do You Want to Modify another Record?(Y/N)"<<endl;
 	cin>>ch;
 	if(ch=='y'||ch=='Y')
	{
 	system("cls");
 	fflush(stdin);
 	modifyScheme();
 	}
 	else
 	fflush(stdin);
	}
	else
	cout<<"File Doesn't Exist."<<endl;
 getch();
}

void searchScheme()   //searches for a scheme
{
 scheme *prev=NULL;
 scheme *current=NULL;
 
 ifstream fin("Scheme_Data.txt");
 if(fin.is_open()){
	scheme * newHead = NULL;
	scheme *curr;
	while(!fin.eof())
	{
   	curr = newHead;
   	scheme * newNode = new scheme;
   	fin >> newNode->semester >> newNode->subj_code >> newNode->subj_title >> newNode->mm_theory 
   		>> newNode->mm_sessional >> newNode->mm_practical;
   	newNode->next = NULL;
   	if(newHead == NULL)
   	newHead = newNode;
   	else
   	{
     	while(curr->next != NULL)
     	{
        	curr = curr->next;
      	}
    	 curr->next = newNode;
   	}
	}
 
	fin.close();
 
 	char subjcode[10];
 	cout<<"Enter Subject Code to search: ";
 	cin>>subjcode;
 	prev=newHead;
 	current=newHead;
 	while(strcmp(current->subj_code , subjcode) != 0)
 	{
 			if(current->next == NULL)
 			{
 			cout<<"No Record Found"<<endl;
 			break;
			}
			else
  		prev=current;
  		current=current->next;
 	}
 	if(strcmp(current->subj_code,subjcode)==0)
 	{
	cout<<"Subject Code: " <<current->subj_code<<endl;
 	cout<<"Subject Title: "<<current->subj_title<<endl;
 	cout<<"Maximum Theory Marks: "<<current->mm_theory<<endl;
 	cout<<"Maximum Sessional Marks: "<<current->mm_sessional<<endl;
 	if(current->mm_practical == 0)
 	cout<<endl;
 	else
 	cout<<"Maximum Practical Marks: "<<current->mm_practical<<endl;
 	cout<<"****************************************"<<endl;
 	}
 	char ch;
 	cout<<"Do You Want to Search another Record?(Y/N)"<<endl;
	 cin>>ch;
 	if(ch=='y'||ch=='Y')
 	{
 		system("cls");
 		fflush(stdin);
 		searchScheme();
 	}
 	else
 	fflush(stdin);
	}
	else
	cout<<"File Doesn't Exist."<<endl;
 getch();
}

void deleteScheme()    //delete a scheme
{
 	ifstream fin("Scheme_Data.txt");
 	if(fin.is_open()){
	scheme * newHead = NULL;
	scheme *curr;
	while(!fin.eof())
	{
   	curr = newHead;
   	scheme * newNode = new scheme;
   	fin >> newNode->semester >> newNode->subj_code >> newNode->subj_title >> newNode->mm_theory 
   		>> newNode->mm_sessional >> newNode->mm_practical;
   	newNode->next = NULL;
   	if(newHead == NULL)
   	newHead = newNode;
   	else
   	{
     while(curr->next != NULL)
     {
        curr = curr->next;
      }
      curr->next = newNode;
   	}
	}
 
	fin.close();
	
 scheme *prev=NULL;
 scheme *current=NULL;
 char subjcode[10];
 cout<<"Enter Scheme Subject Code to Delete:"<<endl;
 cin>>subjcode;
 prev=newHead;
 current=newHead;
 while(strcmp(current->subj_code , subjcode) != 0)
 {
 	if(current->next == NULL)
 	{
 	cout<<"No Record Found"<<endl;
 	break;
	}
	else
  	prev=current;
  	current=current->next;
 }
 if(strcmp(current->subj_code,subjcode)==0)
 {
 	prev->next = current->next;
 	current->next=NULL;
 	delete current;
 	int r=0;
 	while (curr)
	{
		curr = curr->next;
		r++;
	}
 	ofstream fout("Scheme_Data.txt",ios::out);
 	curr = newHead;
	for(int i=0;i<r;i++)
	{
   		fout << curr->semester <<setw(15)<< curr->subj_code <<setw(25)<< curr->subj_title <<setw(15)
   			 << curr->mm_theory <<setw(15)<< curr->mm_sessional <<setw(15)<< curr->mm_practical <<endl;
   		curr = curr->next;
	}
	fout.close();
 cout<<endl<<"Recored Deleted"<<endl;
}
 char ch;
 cout<<"Do You Want to Delete another Record?(Y/N)"<<endl;
 cin>>ch;
 if(ch=='y'||ch=='Y')
  {
 	system("cls");
 	deleteScheme();
 }
 else
 fflush(stdin);
}
else
	cout<<"File Doesn't Exist."<<endl;
 getch();
}

void listScheme() 	//List all schemes
{
	ifstream fin("Scheme_Data.txt",ios::in|ios::binary);
	if(fin.is_open()){
	scheme * newHead = NULL;
	scheme *curr;
	while(!fin.eof())
	{
   	curr = newHead;
   	scheme *newNode = new scheme;
   	fin >> newNode->semester >> newNode->subj_code >> newNode->subj_title >> newNode->mm_theory 
   		>> newNode->mm_sessional >> newNode->mm_practical;
   	newNode->next = NULL;
   	if(newHead == NULL)
   	newHead = newNode;
   	else
   	{
     while(curr->next != NULL)
     {
        curr = curr->next;
      }
      curr->next = newNode;
   	}
	}
 
	fin.close();
	curr = newHead;
	char subj_code[10],subj_title[40];
	int mm_sessional,mm_theory,mm_practical; char semester[4];
	int counter = 0;
	while (curr)
	{
		curr = curr->next;
		counter++;
	}
	curr = newHead;
	for (int j=0; j<counter; j++)
	{
		while (curr->next)
		{
			if (strcmp(curr->semester , curr->next->semester) > 0)
			{
				mm_sessional = curr->mm_sessional;
				curr->mm_sessional = curr->next->mm_sessional;
				curr->next->mm_sessional = mm_sessional;
				
				mm_theory = curr->mm_theory;
				curr->mm_theory = curr->next->mm_theory;
				curr->next->mm_theory = mm_theory;
				
				mm_practical = curr->mm_practical;
				curr->mm_practical = curr->next->mm_practical;
				curr->next->mm_practical = mm_practical;
				
				strcpy(semester , curr->semester);	
				strcpy(curr->semester , curr->next->semester);	
				strcpy(curr->next->semester , semester);
				
				strcpy(subj_code , curr->subj_code);	
				strcpy(curr->subj_code , curr->next->subj_code);	
				strcpy(curr->next->subj_code , subj_code);
				
				strcpy(subj_title , curr->subj_title);	
				strcpy(curr->subj_title , curr->next->subj_title);	
				strcpy(curr->next->subj_title , subj_title);				
			}
			curr = curr->next;
		}	
		curr = newHead;
	}
	int r=0;
	curr = newHead;
 	while (curr)
	{
		curr = curr->next;
		r++;
	}
	curr=newHead;
	curr=curr->next;
	cout << left << setw(nameWidth) << setfill(separator) << "Semester";
	cout << left << setw(nameWidth) << setfill(separator) << "Subject Code";
	cout << left << setw(1.3*nameWidth) << setfill(separator) << "Subject Title";
	cout << left << setw(1.3*nameWidth) << setfill(separator) << "Theory Marks";
	cout << left << setw(1.3*nameWidth) << setfill(separator) << "Sessional Marks";
	cout << left << setw(nameWidth) << setfill(separator) << "Practical Marks"<<endl;
	cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
	for(int i=0;i<r-1;i++)
	{
		//Display Sorted List according to semester
		cout << left << setw(nameWidth) << setfill(separator)<<curr->semester;
		cout << left << setw(nameWidth) << setfill(separator)<<curr->subj_code;
		cout<< left << setw(2.8*numWidth) << setfill(separator)<<curr->subj_title;
		cout<< left << setw(2.5*numWidth) << setfill(separator)<<curr->mm_theory;
		cout<< left << setw(2.5*numWidth) << setfill(separator)<<curr->mm_sessional;
		if(curr->mm_practical == 0)
		cout<<endl;
		else
		cout<<curr->mm_practical<<endl<<endl;
   		curr=curr->next;
	}
	}
	else
	cout<<"File Doesn't Exist."<<endl;
	getch();
	
}

void addResult()    // Add a Student Academic Result
{
	result *p;
	result *newHeadp=NULL; 
	p=new result;
	scheme *current=NULL;
 	ifstream fin("Scheme_Data.txt");
 	if(fin.is_open())
 	{
		scheme * newHead = NULL;
		scheme *curr;
		while(!fin.eof())	
		{
   		curr = newHead;
   		scheme * newNode = new scheme;
   		fin >> newNode->semester >> newNode->subj_code >> newNode->subj_title >> newNode->mm_theory 
   			>> newNode->mm_sessional >> newNode->mm_practical;
   		newNode->next = NULL;
   		if(newHead == NULL)
   		newHead = newNode;
   		else
   			{
     			while(curr->next != NULL)
     			{
        			curr = curr->next;
      			}
      			curr->next = newNode;
   			}  
		}
 		fin.close();
 		int r=0,j=0;
 		char sem[4];
 		cout<<"Enter Student's current semester: "; gets(sem) ; fflush(stdin);
 		curr=newHead;
 		while(curr)
 		{
 		if(strcmp(sem , curr->semester) ==0)
		{
		r++;
		}
		curr=curr->next;
		j++;
		}
		system("cls");
 		ofstream fout("Result_Data.txt",ios::app);
 		curr=newHead;
 		cout<<"NOTE: DO NOT USE SPECIAL CHARACTERS "<<endl;
 		cout<<"Enter Student Roll No.: "; gets(p->roll_No); fflush(stdin);
	 	cout<<"Enter Current Semester: "; gets(p->semester); fflush(stdin);
	 	cout<<"Enter Student Current Year: "; cin>>p->year; fflush(stdin);
		 if(strcmp(sem , p->semester) ==0)
	 	{
	 		fout<< p->roll_No;fout<<setw(5)<<p->semester;fout<<setw(5)<<p->year;
	 		for(int i=0;i<j;i++)
	 		{
	 		if(strcmp(sem , curr->semester) ==0)
	 		{
	 			cout<<curr->subj_code<<setw(25)<<curr->subj_title<<endl;
	 			cout<<"Maximum Theory Marks: "<<curr->mm_theory<<endl;
		 		cout<<"Maximum Sessional Marks: "<<curr->mm_sessional<<endl;
		 		cout<<"Maximum Practical Marks: "<<curr->mm_practical<<endl;
		 		cout<<"Enter Awarded marks in Theory: ";cin>>p->marks_awa_theory;fout<<setw(5)<<p->marks_awa_theory;fflush(stdin);
		 		cout<<"Enter Awarded marks in Sessional: ";cin>>p->marks_awa_Sessional;fout<<setw(5)<<p->marks_awa_Sessional;fflush(stdin);
		 		cout<<"Enter Awarded marks in Practical: ";cin>>p->marks_awa_practical;fout<<setw(5)<<p->marks_awa_practical;fflush(stdin);
		 	}
		 	curr=curr->next;
		 	}
		  
		}
	 	fout<<endl;
	 	p->next=NULL;
		if(check)
 		{
  			head2 = p;
  			lastptr2 = p;
  			check = false;
 		}
 		else
 		{
  			lastptr2->next=p;
  			lastptr2=p;
 		}
		fout.close();
		char ch;
		cout<<"Do You Want add Another Result?(Y/N)"<<endl;
 		cout<<"Or Want to Add a New Student?(PRESS R)"<<endl<<"Answer: ";
		cin>>ch;
		if(ch=='y'||ch=='Y')
		{
 			system("cls");
 			fflush(stdin);
 			addResult();
 		}
 		else if(ch=='r'||ch=='R')
 		{
 			system("cls");
 			fflush(stdin);
 			addStudent();
	 	}
 		else
 		fflush(stdin);
 	}
 	else
	cout<<"File Doesn't Exist."<<endl;
	getch();
}

void searchResult()   //Searches a Student Academic Result
{
	ifstream fin("Scheme_Data.txt");
	scheme * newHead = NULL;
	scheme *curr;
	while(!fin.eof())
	{
   	curr = newHead;
   	scheme * newNode = new scheme;
   	fin >> newNode->semester >> newNode->subj_code >> newNode->subj_title >> newNode->mm_theory 
   		>> newNode->mm_sessional >> newNode->mm_practical;
   	newNode->next = NULL;
   	if(newHead == NULL)
   	newHead = newNode;
   	else
   	{
     while(curr->next != NULL)
     {
        curr = curr->next;
      }
      curr->next = newNode;
   	}
	}
	fin.close();
	int r=0;
	curr=newHead;
	while(curr)		//Counting No. of nodes
	{
		curr=curr->next;
		r++;
	}
	ifstream fin1("Result_Data.txt");
	fflush(stdin);
	if(fin1.is_open())
	{
	int j=0;
	char rollno[10];
	fflush(stdin);
	cout<<"Enter Roll Number to Search: ";
	gets(rollno);fflush(stdin);
	result *newhead=NULL,*current=NULL;
	result *p;
	p=new result;
	current=newhead;
	char sem[4];
	cout<<"Enter Student's Semester: "; gets(sem);fflush(stdin);
	curr=newHead;
	while(curr)
	{
		if(strcmp(sem,curr->semester)==0)
		{
			j++;
		}
		curr=curr->next;
		
	}
	current=newhead;
	int i;
	while(!fin1.eof())
	{
		
		p=newhead;
		result *newnode=new result;
		fin1>> newnode->roll_No>>newnode->semester>>newnode->year;
		current=newnode;
		if( strcmp(rollno , current->roll_No) != 0)
		{
			for(int i=0;i<j;i++)
		{
			fin1>> newnode->marks_awa_theory >> newnode->marks_awa_Sessional >>newnode->marks_awa_practical;
		}
			p=newnode=newhead=NULL;
		}
		else
		{
			curr=newHead;
			cout<<"Roll No."<<current->roll_No<<endl;
			cout<<"Semester: "<<current->semester<<endl<<"Year: "<<current->year<<endl;
		
			cout<<"MARKS-"<<endl;
			for(i=0;i<r;i++)
			{
				if(strcmp(sem,curr->semester)==0)
				{
					cout<<"Subject Code: "<<curr->subj_code<<endl;
					cout<<"Subject Title: "<<curr->subj_title<<endl;
					fin1>>newnode->marks_awa_theory;
					cout<<"Theory: "<<current->marks_awa_theory<<endl;
					fin1>>newnode->marks_awa_Sessional;
					cout<<"Sessional: "<<current->marks_awa_Sessional<<endl;
					fin1>>newnode->marks_awa_practical;
					if(current->marks_awa_practical == 0)
					cout<<endl;
					else
					cout<<"Practical: "<<current->marks_awa_practical<<endl;
				}
					curr=curr->next;
			}		
		} 		
	}
	
	fin1.close();
	fflush(stdin);
	cout<<"*********************************"<<endl;
	char ch;
 	cout<<"Do You Want to Search another Record?(Y/N)"<<endl;
 	cin>>ch;
 	if(ch=='y'||ch=='Y')
	{
 	system("cls");
 	fflush(stdin);
 	searchResult();
 	}
 	else
 	fflush(stdin);
	}
	else
	cout<<"File Doesn't Exist."<<endl;
	getch();
}

void printReportCard()		//Search Complete semester Result for a student
{	
	//Reading Student Data
	student_record *prevs=NULL;
 	student_record *currents=NULL;
 	ifstream fin2("Student_Data.txt");
	student_record * newHeads = NULL;
	student_record *currs;
	while(!fin2.eof())
	{
   	currs = newHeads;
   	student_record * newNodes = new student_record;
   	fin2 >> newNodes->student_fname >> newNodes->student_lname >> newNodes->father_fname >> newNodes->father_lname >>  
   		  newNodes->rollNo >>  newNodes->semester >>  newNodes->dob_dd >>  newNodes->dob_mm >>  newNodes->dob_yyyy 
		  >>  newNodes->year_of_admission;
   	newNodes->next = NULL;
    if(newHeads == NULL)
   	newHeads = newNodes;
   	else
   	{
     while(currs->next != NULL)
     {
        currs = currs->next;
     }
      currs->next = newNodes;
   	}
	} 
	fin2.close();
	//Reading Students Marksheet and Calculating no. of Schemes
	ifstream fin("Scheme_Data.txt");
	scheme * newHead = NULL;
	scheme *curr;
	while(!fin.eof())
	{
   	curr = newHead;
   	scheme * newNode = new scheme;
   	fin >> newNode->semester >> newNode->subj_code >> newNode->subj_title >> newNode->mm_theory 
   		>> newNode->mm_sessional >> newNode->mm_practical;
   	newNode->next = NULL;
   	if(newHead == NULL)
   	newHead = newNode;
   	else
   	{
     while(curr->next != NULL)
     {
        curr = curr->next;
      }
      curr->next = newNode;
   	}
	}
	fin.close();
	int r=0,j=0;
	curr = newHead;
	while(curr)		//Counting No. of nodes
	{
		curr=curr->next;
		r++;
	}
	curr = newHead;
	char rollno[10];
	fflush(stdin);
	cout<<"Enter Roll Number to Search: ";
	gets(rollno);fflush(stdin);
	
	prevs=newHeads;
 	currents=newHeads;
 	while(strcmp(currents->rollNo , rollno) != 0)
 	{
 			if(currents->next == NULL)
 			{
 			cout<<"No Record Found"<<endl;
 			break;
			}
			else
  		prevs=currents;
  		currents=currents->next;
 	}
 	if(strcmp(currents->rollNo,rollno)==0)
 	{
 	system("cls");
 	cout<<"\nRoll No."<<currents->rollNo;
 	cout<<"\nName: ";
 	cout<< currents->student_fname <<" " <<currents->student_lname;
 	cout<<"\nFather's Name: ";
 	cout<<currents->father_fname<<" "<<currents->father_lname;
 	cout<<"\nDate Of Birth:";
 	cout<<currents->dob_dd<<"/"<<currents->dob_mm<<"/"<<currents->dob_yyyy;
 	cout<<"\nSemester: ";
 	puts(currents->semester);
 	for(int a=0;a<r;a++)
 	{
 		if(strcmp(currents->semester,curr->semester)==0)
 		{
 			j++;
		 }
		 curr=curr->next;
		 
	 }
 	cout<<"\nYear Of Admission:";
 	cout<<currents->year_of_admission;
 	}
	result *newhead=NULL,*current=NULL;
	result *p;
	p=new result;
	ifstream fin1("Result_Data.txt");
	current=newhead;
	while(!fin1.eof())
	{
		p=newhead;
		result *newnode=new result;
		fin1>> newnode->roll_No>>newnode->semester>>newnode->year;
		current=newnode;
		if( strcmp(rollno , current->roll_No) != 0)
		{
			if(current->next == NULL)
 			{
 			cout<<"No Record Found"<<endl;
 			break;
			}
			else
			{
			for(int i=0;i<j;i++)
			{
			fin1>> newnode->marks_awa_theory >> newnode->marks_awa_Sessional >>newnode->marks_awa_practical;
			}
			p=newnode=newhead=NULL;
			}
		}
		if(strcmp(rollno,current->roll_No)==0)
		{
			curr=newHead;
			cout<<endl<<"Current Year: "<<current->year<<endl;
			cout<<"MARKS-"<<endl;
			for(int i=0;i<r;i++)
			{
				if(strcmp(currents->semester,curr->semester)==0)
				{
				cout<<"Subject Code: "<<curr->subj_code<<endl;
				cout<<"Subject Title: "<<curr->subj_title<<endl;
				fin1>>newnode->marks_awa_theory>>newnode->marks_awa_Sessional>>newnode->marks_awa_practical;
				cout<<"Theory: "<<current->marks_awa_theory<<endl;
				cout<<"Sessional: "<<current->marks_awa_Sessional<<endl;
				if(current->marks_awa_practical == 0)
				cout<<endl;
				else
				cout<<"Practical: "<<current->marks_awa_practical<<endl;
				}
				curr=curr->next;	
			}
		
		}
	}
	fin1.close();
	fflush(stdin);
	cout<<"\n*********************************"<<endl;
	char ch;
 cout<<"Do You Want to Search another Record?(Y/N)"<<endl;
 cin>>ch;
 if(ch=='y'||ch=='Y')
 {
 	system("cls");
 	fflush(stdin);
 	printReportCard();
 }
 else
	getch();
	
}

void completeSemResult()		//Academic Result of all students in sorted form
{	
	//Reading Student Data
	student_record *prevs=NULL;
 	student_record *currents=NULL;
 	ifstream fin2("Student_Data.txt");
	student_record * newHeads = NULL;
	student_record *currs;
	while(!fin2.eof())
	{
   	currs = newHeads;
   	student_record * newNodes = new student_record;
   	fin2 >> newNodes->student_fname >> newNodes->student_lname >> newNodes->father_fname >> newNodes->father_lname >>  
   		  newNodes->rollNo >>  newNodes->semester >>  newNodes->dob_dd >>  newNodes->dob_mm >>  newNodes->dob_yyyy 
		  >>  newNodes->year_of_admission;
   	newNodes->next = NULL;
    if(newHeads == NULL)
   	newHeads = newNodes;
   	else
   	{
     while(currs->next != NULL)
     {
        currs = currs->next;
     }
      currs->next = newNodes;
   	}
	} 
	fin2.close();
	//Reading Students Marksheet and Calculating no. of Schemes
	ifstream fin("Scheme_Data.txt");
	scheme * newHead = NULL;
	scheme *curr;
	while(!fin.eof())
	{
   	curr = newHead;
   	scheme * newNode = new scheme;
   	fin >> newNode->semester >> newNode->subj_code >> newNode->subj_title >> newNode->mm_theory 
   		>> newNode->mm_sessional >> newNode->mm_practical;
   	newNode->next = NULL;
   	if(newHead == NULL)
   	newHead = newNode;
   	else
   	{
     while(curr->next != NULL)
     {
        curr = curr->next;
      }
      curr->next = newNode;
   	}
	}
	fin.close();
	int r=0;
	curr=newHead;
	while(curr)		//Counting No. of nodes
	{
		curr=curr->next;
		r++;
	}
	int k=0;
	currs = newHeads;
	while(currs)
	{
		currs = currs->next;
		k++;
	}
	
	ofstream fout("REPORT-CARD.txt",ios::out|ios::trunc);
	currents = newHeads;
	for(int s=0;s<k-1;s++)
  {
  	ifstream fin1("Result_Data.txt");
  	int j=0;char rollno[10];
  	curr=newHead;
	strcpy(rollno , currents->rollNo);
 	cout<<"\nRoll No."<<currents->rollNo;
 	fout<<currents->rollNo<<setw(10);
 	cout<<"\nName: ";
 	cout<< currents->student_fname <<" " <<currents->student_lname;
 	fout<< currents->student_fname <<" " <<currents->student_lname<<setw(20);
 	cout<<"\nFather's Name: Mr.";
 	cout<<currents->father_fname<<" "<<currents->father_lname;
 	fout<<currents->father_fname<<" "<<currents->father_lname<<setw(20);
 	cout<<"\nDate Of Birth:";
 	cout<<currents->dob_dd<<"/"<<currents->dob_mm<<"/"<<currents->dob_yyyy;
 	fout<<currents->dob_dd<<" "<<currents->dob_mm<<" "<<currents->dob_yyyy<<setw(10);
 	cout<<"\nSemester: ";
 	puts(currents->semester);
 	fout<< currents->semester <<setw(10);
 	for(int a=0;a<r;a++)
 	{
 		if(strcmp(currents->semester,curr->semester)==0)
 		{
 			j++;
		 }
		 curr=curr->next;
		 
	 }
 	cout<<"\nYear Of Admission:";
 	cout<<currents->year_of_admission;
 	fout<<currents->year_of_admission<<setw(10);
	result *newhead=NULL,*current=NULL;
	result *p;
	p=new result;
	current=newhead;
	while(!fin1.eof())
	{
		p=newhead;
		result *newnode=new result;
		fin1>> newnode->roll_No>>newnode->semester>>newnode->year;
		current=newnode;
		if( strcmp(rollno , current->roll_No) != 0)
		{
			for(int i=0;i<j;i++)
			{
			fin1>> newnode->marks_awa_theory >> newnode->marks_awa_Sessional >>newnode->marks_awa_practical;
			}
			p=newnode=newhead=NULL;
		}
		if(strcmp(rollno,current->roll_No)==0)
		{
			curr=newHead;
			cout<<endl<<"Current Year: "<<current->year<<endl;
			fout<<current->year;
			cout<<"MARKS-"<<endl;
			for(int i=0;i<r-1;i++)
			{
				if(strcmp(curr->semester,currents->semester)==0)
				{
				cout<<"Subject Code: "<<curr->subj_code<<endl;
				cout<<"Subject Title: "<<curr->subj_title<<endl;
				fin1>>newnode->marks_awa_theory>>newnode->marks_awa_Sessional>>newnode->marks_awa_practical;
				cout<<"Theory: "<<current->marks_awa_theory<<endl;
				cout<<"Sessional: "<<current->marks_awa_Sessional<<endl;
				if(current->marks_awa_practical == 0)
				cout<<endl;
				else
				cout<<"Practical: "<<current->marks_awa_practical<<endl;
				fout<<setw(10)<< current->marks_awa_theory <<"   "<<current->marks_awa_Sessional
					<<"   "<<current->marks_awa_practical;
				}
				curr=curr->next;
			}
		}
	}
	cout<<"***************************************";
	currents = currents->next;
	fin1.close();
	fout<<endl;
 }
	
	fout.close();
	cout<<endl<<"SORTED SEMESTER CAN BE OBTAINED BY SORTING STUDENT INFO "<<endl
		<<"And AGAIN CHOOSE CURRENT OPTION."<<endl<<endl;
	char ch;
 	cout<<"Do You Want to Search A Specific Record?(Y/N)"<<endl;
 	cin>>ch;
 	if(ch=='y'||ch=='Y')
 	{
 		system("cls");
 		fflush(stdin);
 		printReportCard();
 	}
 	else
 	fflush(stdin);
	getch();
	
}

void student()
{
 system("cls");
 int i;
 cout<<endl<<endl<<endl<<endl;
 cout<<"\t\t\t\t     STUDENT "<<endl;
 cout<<"\t\t\t\t RECORD MANAGEMENT "<<endl;
 cout<<"\t\t\t\t     SYSTEM"<<endl<<endl;
 cout<<"\t\t\t\t1. Add Student"<<endl;
 cout<<"\t\t\t\t2. Search Student"<<endl;
 cout<<"\t\t\t\t3. Modify Student"<<endl;
 cout<<"\t\t\t\t4. Delete Student"<<endl;
 cout<<"\t\t\t\t5. List Student's"<<endl;
 cout<<"\t\t\t\t6. Sorted Student Record"<<endl;
 cout<<"\t\t\t\t7. Back To Main Menu"<<endl<<endl;
 cout<<"\t\t\t\tChoice No. ";
 cin>>i;
 if(i==1)
 {
 	system("cls");
 	fflush(stdin);
 	addStudent();
 }
 if(i==2)
 {
 	system("cls");
 	fflush(stdin);
 	searchStudent();
 }
 if(i==3)
 {
 	system("cls");
 	fflush(stdin);
 	modifyStudent();
 }
 if(i==4)
 {
 	system("cls");
 	fflush(stdin);
 	deleteStudent();
 }
 if(i==5)
 {
 	system("cls");
 	fflush(stdin);
 	listStudent();
 }
 
 if(i==6)
 {
 	system("cls");
 	fflush(stdin);
 	sortStudent();
 }
 if(i==7)
 {
 	system("cls");
 	fflush(stdin);
 	main();
 }
 if(i>7)
 {
 	cout<<"\n\t\t\t\tEnter Current Option.";
 }
 
 	fflush(stdin);
 	getch();
 	student();
}
void scheme()
{
	system("cls");
 int i;
 cout<<endl<<endl<<endl<<endl;
 cout<<"\t\t\t\t     STUDENT "<<endl;
 cout<<"\t\t\t\t RECORD MANAGEMENT "<<endl;
 cout<<"\t\t\t\t     SYSTEM"<<endl<<endl;
 cout<<"\t\t\t\t1. Add Scheme"<<endl;
 cout<<"\t\t\t\t2. Search Scheme"<<endl;
 cout<<"\t\t\t\t3. Modify Scheme"<<endl;
 cout<<"\t\t\t\t4. Delete Scheme"<<endl;
 cout<<"\t\t\t\t5. List All Scheme"<<endl;
 cout<<"\t\t\t\t6. Back To Main Menu"<<endl<<endl;
 cout<<"\t\t\t\tChoice No. ";
 cin>>i;
 if(i==1)
 {
 	system("cls");
 	addScheme();
 }
 if(i==2)
 {
 	system("cls");
 	searchScheme();
 }
 if(i==3)
 {
 	system("cls");
 	modifyScheme();
 }
 if(i==4)
 {
 	system("cls");
 	deleteScheme();
 }
 if(i==5)
 {
 	system("cls");
 	listScheme();
 }
 
 if(i==6)
 {
 	system("cls");
 	main();
 }
  if(i>6)
 {
 	cout<<"\t\t\t\tEnter Correct Option.";
 }
 fflush(stdin);
 getch();
 scheme();
}
void result()
{
	system("cls");
 int i;
 cout<<endl<<endl<<endl<<endl;
 cout<<"\t\t\t\t     STUDENT "<<endl;
 cout<<"\t\t\t\t RECORD MANAGEMENT "<<endl;
 cout<<"\t\t\t\t     SYSTEM"<<endl<<endl;
 cout<<"\t\t\t\t1. Add Result"<<endl;
 cout<<"\t\t\t\t2. Search Result"<<endl; 
 cout<<"\t\t\t\t3. Back To Main Menu"<<endl<<endl;
 cout<<"\t\t\t\tChoice No.";
 cin>>i;
 if(i==1)
 {
 	system("cls");
 	addResult();
 }
 if(i==2)
 {
 	system("cls");
 	searchResult();
 }
 if(i==3)
 {
 	system("cls");
 	main();
 }
 if(i>3)
 {
 	cout<<"\t\t\t\tEnter Correct Option.";
 }
 fflush(stdin);
 getch();
 result();
}
void report()
{
	system("cls");
 int i;
 cout<<endl<<endl<<endl<<endl;
 cout<<"\t\t\t\t     STUDENT "<<endl;
 cout<<"\t\t\t\t RECORD MANAGEMENT "<<endl;
 cout<<"\t\t\t\t     SYSTEM"<<endl<<endl;
 cout<<"\t\t\t\t1. Search Report Card"<<endl;
 cout<<"\t\t\t\t2. Complete Semester Result"<<endl; 
 cout<<"\t\t\t\t3. Back To Main Menu"<<endl<<endl;
 cout<<"\t\t\t\tChoice No.";
 cin>>i;
 if(i==1)
 {
 	system("cls");
 	printReportCard();
 }
 if(i==2)
 {
 	system("cls");
 	completeSemResult();
 }
 if(i==3)
 {
 	system("cls");
 	main();
 }	
 if(i>3)
 {
 	cout<<"\t\t\t\tEnter Correct Option.";
 }
 fflush(stdin);
 getch();
 report();
}
int main()
{
 int n;
 system("cls");
 fflush(stdin);
 cout<<endl<<endl<<endl;
 cout<<"\t\t\t\t      WELCOME "<<endl;
 cout<<"\t\t\t\t    TO STUDENT "<<endl;
 cout<<"\t\t\t\t RECORD MANAGEMENT "<<endl;
 cout<<"\t\t\t\t      SYSTEM"<<endl<<endl;
 cout<<"\t\t\t\t1. Student Menu"<<endl;
 cout<<"\t\t\t\t2. Scheme Menu"<<endl;
 cout<<"\t\t\t\t3. Result Menu"<<endl;
 cout<<"\t\t\t\t4. Report Card Menu"<<endl;
 cout<<"\t\t\t\t5. Exit"<<endl<<endl;
 cout<<"\t\t\t\tChoice No. ";
 cin>>n;
 if(n==1)
 {
	student();
 }
 if(n==2)
 {
 	scheme();
 }
 if(n==3)
 {
 	result();
 }
 if(n==4)
 {
 	report();
 }
 if(n==5)
 {
 	exit(0);
 }
 if(n>5)
 {
 cout<<"\t\t\t\tEnter Correct Option.";
 }
 getch();
 main();
}
