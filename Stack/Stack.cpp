#include<iostream>
#include<cstdlib>
#include<conio.h>
using namespace std;
int SIZE ;
int popSize;
struct stack
{
	int data;
	stack *next;
}*head,*headPeep;
void createStack();
void push();
void stackFull();
void stackEmpty();
void pop();
void peep();
void disp();
int main();
void disp()
{
	stack *ptr=new stack();
	ptr=head;
	cout<<"\nStack: ";
	while(ptr)
	{
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
}
void stackEmpty()
{
	system("cls");
	stack *temp=new stack();
	temp=head;
	int j=1;
	for(int i=0;i<SIZE;i++)
	{
		if(temp==NULL)
		cout<<"Stack Is Empty";
		if(temp->next != NULL)
		{
		temp=temp->next;
		j++;
		}
		if(temp->next==NULL && j<SIZE )
		cout<<"Space Present For More Elements.";		
	}
	getch();
	main();
}
void createStack()
{
	system("cls");
	int n;
	cout<<"Enter Number Of Elements: ";
	cin>>n;
	::SIZE=n;
	::popSize=n;
	cout<<"Stack Is Created"<<endl;;
	fflush(stdin);
	getch();	
	main();
}
void push()
{	
	system("cls");
	int a,i;
	stack *temp=new stack();
	if(head == NULL)
	{
		for(int i=0;i<SIZE;i++)
		{
		stack *newnode=new stack();
		cout<<"Enter Element: ";
		cin>> newnode->data;
		newnode->next = head;
		head=newnode;
		}
		disp();
	}
	if(head!=NULL)
	{
		int count=1;
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
			count++;
		}
		if(count<SIZE)
		{
			stack *newnode=new stack();
			cout<<"Enter Element: ";
			cin>> newnode->data;
			newnode->next = head;
			head=newnode;
			disp();
		}
		else
		cout<<"\nStack is FULL.";
	}
	fflush(stdin);
	getch();
	main();
	
}
void pop()
{
	system("cls");
	stack *temp=new stack();
	temp=head;
	cout<<"Element "<<temp->data<<" is popped."<<endl;
	head=temp->next;
	disp();
	fflush(stdin);
	getch();
	main();
}
void peep()
{
	system("cls");
	disp();
	stack* temp = head;
	stack *temp1=NULL;
	 int n,count = 0;
	 cout<<"\nEnter Element: ";
	 cin>>n;
	 while(temp->data !=n)
	 {
		 count++;
		 //Pushing elements to a new stack
		 stack *newnode=new stack();
			newnode->data=temp->data;
			newnode->next = headPeep;
			headPeep=newnode;
			temp1=headPeep;
			cout<<temp1->data<<" ";
		//Popping elements	
		 temp = temp->next;
		 head=temp;
		 if((count)==SIZE)
		 {cout<<"Element not Found";
		 fflush(stdin);getch();main();}
	 }
	 if(temp->data==n)
	 cout<<"Element Found at Index "<<count<<" = "<<n<<endl;
	 //popping elemnts back to orihginal stack
	temp1=headPeep;
	while(temp1)
	{
		stack *newNode=new stack();
			newNode->data=temp1->data;
			newNode->next = head;
			head=newNode;
			temp=head;
			temp1=temp1->next;
	}
	fflush(stdin);getch();main();
}


void stackFull()
{
	system("cls");
	stack *temp=new stack();
	temp=head;
	int j;
	while(temp)
	{
		temp=temp->next;
		j++;
	}
	if(j=SIZE)
	cout<<"STACK IS FULL";
	else
	cout<<"Stack ISN'T FULL";
	fflush(stdin);
	getch();
	main();
}
int main()
{
	system("cls");
	cout<<endl<<endl<<endl;
	cout<<"\t\t\tSTACK MENU"<<endl<<endl;
	cout<<"\t\t\t1. Is Stack Empty?";
	cout<<"\n\t\t\t2. Is Stack Full?";
	cout<<"\n\t\t\t3. Push Element";
	cout<<"\n\t\t\t4. Pop Element";
	cout<<"\n\t\t\t5. Create Stack";
	cout<<"\n\t\t\t6. Peep Operation";
	cout<<"\n\t\t\t Enter Choice: ";
	int n;
	cin>>n;
	if(n==1)
	{
		stackEmpty();
	}
	if(n==2)
	{
		stackFull();
	}
	if(n==3)
	{
		push();
	}
	if(n==4)
	{
		pop();
	}
	if(n==5)
	{
		createStack();
	}
	if(n==6)
	{
		peep();
	}
	if(n>6)
	{
	cout<<"Enter Correct Option";
	fflush(stdin);
	getch();
	main();
	}
}


