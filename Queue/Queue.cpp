#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;
int MAXSIZE ;
struct queue
{
	int data;
	queue *link;
}*front,*rear;
void qfull();
void qinsert();
void qdelete();
void qempty();
void disp();
void qcreate();
int main()
{
	system("cls");
	fflush(stdin);
	cout<<endl<<endl<<endl;
	cout<<"\n\t\t\tQUEUE MENU"<<endl;
	cout<<"\t\t\t1. Is Queue Full?"<<endl;
	cout<<"\t\t\t2. Insert Queue"<<endl;
	cout<<"\t\t\t3. Delete Queue"<<endl;
	cout<<"\t\t\t4. Is Queue Empty?"<<endl;
	cout<<"\t\t\t5. Create Queue"<<endl;
	int choice;
	cout<<"\t\t\tCHOICE: ";
	choice=getch();
	switch(choice)
	{
		case '1':
			system("cls");
			fflush(stdin);
			qfull();
		case '2':
			system("cls");
			fflush(stdin);
			qinsert();
		case '3':
			system("cls");
			fflush(stdin);
			qdelete();
		case '4':
			system("cls");
			fflush(stdin);
			qempty();
		case '5':
			system("cls");
			fflush(stdin);
			qcreate();
		default: 
			cout<<"\n\t\t\tENTER CORRECT CHOICE NO.";
			main();			
	}	
	getch();
}
//Create Queue
void qcreate()
{
	system("cls");
	fflush(stdin);
	int n;
	cout<<"Enter number of elements you want in QUEUE: ";
	cin>>n;
	::MAXSIZE=n;
	fflush(stdin);
	getch();
	main();
}
//Display Queue
void disp()
{
	struct queue *node=new queue();
	node=front;
	cout<<"QUEUE: ";
	while(node)
	{	
		cout<<" "<<node->data;
		node=node->link;
	}
}
//Is Queue Full?
void qfull()
{
	system("cls");
	fflush(stdin);
	struct queue *curr=new queue();
	curr=front;
	int count=1;
	while(curr)
	{
		count++;
		curr=curr->link;
	}
	if(count<MAXSIZE)
	{
		cout<<"\nNumber of elements in queue "<<count-1<<"."<<endl<<(MAXSIZE-count+1)<<" ELEMENT(s) can be inserted.";
	}
	else
	{cout<<"\nQueue is full";disp();}
	fflush(stdin);
	getch();
	main();
}
//Insert an Item
void qinsert()
{
	system("cls");
	fflush(stdin);
	struct queue *node=new queue();
	node=front;
	int count=1;
	while(node)
	{
		count++;
		node=node->link;
	}
	if(count==MAXSIZE)
	cout<<"\nNO MORE SPACE LEFT IN QUEUE";
	else
	{
		int value;
		cout<<"Enter Value: ";
		cin >> value;
		struct queue *newnode=new queue();
   		newnode->data=value;
   		newnode -> link = NULL;
   		if(front == NULL)
      	front = rear = newnode;
   		else
	   	{
      	rear -> link = newnode;
      	rear = newnode;
   		}
   		cout<<"\n Value "<<value <<" Insertion is Success!!!\n";
   		disp();
	}
	fflush(stdin);
	getch();
	main();
}
//Is Queue Empty?
void qempty()
{
	system("cls");
	if(front==NULL && rear == NULL)
	{
		cout<<"QUEUE IS EMPTY";
	}
	else
	cout<<"STACK ISN'T EMPTY";
	fflush(stdin);
	getch();
	main();
}
//Delete an item
void qdelete()
{
	system("cls");
	if(front == NULL)
      cout<<"Queue is empty";
   else
   {
	queue *temp=new queue();
	temp=front;
	cout<<"Element "<<temp->data<<" is deleted."<<endl;
	front=temp->link;
	disp();
   }
   
   fflush(stdin);
   getch();
   main();
}
