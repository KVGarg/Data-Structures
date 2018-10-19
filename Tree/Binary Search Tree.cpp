#include<iostream>
#include<conio.h>
#include<cstring>
#include<string>
using namespace std;
struct bst
{
	char data[20];
	struct bst* left;
	struct bst* right;
}*root,*New,*temp;
void create();
void display();
void inorder(bst *);
void insert(bst *, bst *);
int main(void);
//CREATE
void create()
{
struct bst *New = new bst();
New -> left = NULL;
New -> right = NULL;
cout << "Enter a meaningful word:";
cin >> New -> data;
if (root == NULL)
root = New;
else
insert(root,New);

fflush(stdin);
getch();
main();
}
//insert word Func.
void insert(bst *root, bst *New)
{
int d;
d = strcmp(New -> data,root -> data);
if(d < 0)
{
if (root -> left == NULL)
root -> left = New;
else
insert(root -> left,New);
}
if(d > 0)
{
if(root -> right == NULL)
root -> right = New;
else
insert(root -> right,New);
}
fflush(stdin);
getch();
main();
}
//display Func.
void display()
{
if(root==NULL)
{
cout << "\nDictionary not yet created!";
}
else
{
cout << "The dictionary is : \n";
inorder(root);
}
fflush(stdin);
getch();
main();
}
//inorder Func.
void inorder(bst *temp)
{
if(temp != NULL)
{
	if(temp->left!=NULL)
inorder(temp -> left);

cout<<temp -> data << "\n";

	if(temp->right!=NULL)
inorder(temp -> right);
}
}

//main Func.
int main(void)
{
	system("cls");
	cout<<"1. Enter a word"<<endl<<"2. Display"<<endl<<"3. Exit"<<endl;
	int choice;
	cin>>choice;
	switch(choice)
	{
		case 1:
			system("cls");
			fflush(stdin);
			create();
		case 2:
			system("cls");
			fflush(stdin);
			display();
		case 3:
			break;
		default:
			cout<<"Enter a correct option";
			fflush(stdin);
			
	}
}

