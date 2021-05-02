#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct Bank{
	char name[100];
	int adhar;
	char profession[100];
	char address[1000];
	int balance;
	int fix;
	int ac;
	struct Bank *next;
	}node;

node *start=NULL;

node* createnode()
{
	node *n=new node;
	return(n);
}


void insert()
{
	node *temp,*prev;
	temp=createnode();
	int value1;
	char ch[100];
	cout<<"\n\t\tEnter the name:- ";
	cin>>temp->name;
	cout<<"\n\t\tEnter the Adahar no.:- ";
	cin>>value1;

	int flag=0;
	node *search;
	search=start;
	if(start==NULL)
	{
		flag=0;
	}
	else
	{
		while(search!=NULL)
		{
			if(value1==search->adhar)
			{
				flag=1;
				cout<<"\n\t\tId already exists\n\n";
				break;
			}
			else
			{
				search=search->next;
			}
		}
	}

	if(flag==0)
	{
		temp->adhar=value1;
		cout<<"\n\t\tEnter the profession:- ";
		cin>>temp->profession;

		cout<<"\n\t\tEnter the address:- ";
		cin>>temp->address;

		cout<<"\n\t\t1000 diposited in this account\n ";
		temp->balance=1000;
		cout<<"\n\t\tEnter the fix diposit:- ";
		cin>>temp->fix;
		if(temp->fix<0)
		{
			temp->fix=0;
		}
		int acc=rand()%997;
		cout<<"\n\t\tUnique bank acount id. = "<<acc<<endl<<endl;
		temp->ac=acc;
		temp->next=NULL;
		if(start==NULL)
		{
			start=temp;
		}
		else
		{
			node *t;
			t=start;
			while(t->next!=NULL)
				t=t->next;
			t->next=temp;
	}
	}
}

void widraw()
{
	int value1;
	cout<<"\n\t\tEnter the Adahar no.:- ";
	cin>>value1;

	int flag=0;
	node *search;
	search=start;
	if(start==NULL)
	{
		flag=0;
	}
	else
	{
		while(search!=NULL)
		{
			if(value1==search->adhar)
			{
				flag=1;
				break;
			}
			else
			{
				search=search->next;
			}
		}
	}

	if(flag==1)
	{
		node *t=search;
		int limit;
		cout<<"\n\t\tEnter the amount";
		cin>>limit;
		if(limit>0 && limit<t->balance)
		{
			t->balance-=limit;
			cout<<"\n\t\t"<<limit<<" debited from account no. "<<t->ac;
			cout<<"\n\t\tYour current balance is "<<t->balance;
		}
		else
			cout<<"\n\t\tEnter a valid limit\n";

	}
	else
	{
		cout<<"\n\t\tNo id exists\n\n";
	}
}

void deposit()
{
	int value1;
	cout<<"\n\t\tEnter the Adahar no.:- ";
	cin>>value1;

	int flag=0;
	node *search;
	search=start;
	if(start==NULL)
	{
		flag=0;
	}
	else
	{
		while(search!=NULL)
		{
			if(value1==search->adhar)
			{
				flag=1;
				break;
			}
			else
			{
				search=search->next;
			}
		}
	}

	if(flag==1)
	{
		node *t=search;
		int limit;
		cout<<"\n\t\tEnter the amount ";
		cin>>limit;
		if(limit>0)
		{
			t->balance+=limit;
			cout<<"\n\t\t"<<limit<<" credited in account no "<<t->ac;
			cout<<"\n\t\tYour current balance is "<<t->balance;
		}
		else
			cout<<"\n\t\tEnter a valid limit\n";

	}
	else
	{
		cout<<"\n\t\tNo id. exists\n\n";

	}
}

void fix()
{
		int value1;
	cout<<"\n\t\tEnter the Adahar no.:- ";
	cin>>value1;

	int flag=0;
	node *search;
	search=start;
	if(start==NULL)
	{
		flag=0;
	}
	else
	{
		while(search!=NULL)
		{
			if(value1==search->adhar)
			{
				flag=1;
				break;
			}
			else
			{
				search=search->next;
			}
		}
	}
	if(flag==1)
	{
		node *t=search;
		int limit;
		cout<<"\n\t\tEnter the amount:- ";
		cin>>limit;
		if(limit>0)
		{
			t->fix+=limit;
			cout<<"\n\t\t"<<limit<<"deposited in account no "<<t->ac;
		}
		else
			cout<<"\n\t\tEnter a valid limit\n";
	}
	else
	{
		cout<<"\nNo id. exists\n\n";
	}
}

void viewlist()
{
	node *view;
	int count=1;
	if(start==NULL)
	{
		cout<<"\n\t\tList is empty.\n\n";
	}

	else
	{
		view=start;
		while(view!=NULL)
		{
		cout<<"\n\t\t[*Information of Client no. "<<count<<" ]";
		cout<<"\n\t\tName :- ";
		cout<<view->name;
		cout<<"\n\t\tAdhar No. :- ";
		cout<<view->adhar;
		cout<<"\n\t\tAccount number:- ";
		cout<<view->ac;
		cout<<"\n\t\tProfession:- ";
		cout<<view->profession;
		cout<<"\n\t\tAddress:- ";
		cout<<view->address,
		cout<<"\n\t\tBalace:- ";
		cout<<view->balance,
		cout<<"\n\t\tFixed Diposit:- ";
		cout<<view->fix<<endl;
		count++;
		view=view->next;
		}
		count--;
		cout<<"\n\n\t\tNo of accounts = "<<count<<endl<<endl;
	}
}

void view()
{
	int value1;
	cout<<"\n\t\tEnter the Adahar no.:- ";
	cin>>value1;

	int flag=0;
	node *search;
	search=start;
	if(start==NULL)
	{
		flag=0;
	}
	else
	{
		while(search!=NULL)
		{
			if(value1==search->adhar)
			{
				flag=1;
				break;
			}
			else
			{
				search=search->next;
			}
		}
	}

	if(flag==1)
	{
		node *view=search;
		cout<<"\n\t\tName :- ";
		cout<<view->name;
		cout<<"\n\t\tAdhar No. :- ";
		cout<<view->adhar;
		cout<<"\n\t\tAccount number:- ";
		cout<<view->ac;
		cout<<"\n\t\tProfession:- ";
		cout<<view->profession;
		cout<<"\n\t\tAddress:- ";
		cout<<view->address;
		cout<<"\n\t\tBalace:- ";
		cout<<view->balance;
		cout<<"\n\t\tFixed Diposit:- ";
		cout<<view->fix<<endl<<endl;
	}
	else
	{
		cout<<"\nNo account exists\n";
	}
}

void close()
{
    int value1;
	cout<<"\n\t\tEnter the Adahar no.:- ";
	cin>>value1;

	node *search;
	search=start;
	node* temp = search;
	node* prev = NULL;

	if (temp != NULL && temp->adhar == value1)
	{
		temp = temp->next;
		delete temp;
		cout<<"\n\t\tAccount deleted\n";
		return;
	}


	while (temp != NULL && temp->adhar != value1)
	{
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL)
		{
		    cout<<"\n\t\tNo such account exists.\n\n";
		    return;
		}

	prev->next = temp->next;
          search=temp;
	delete search;
	cout<<"\n\t\tAccount deleted\n";
}


int menu()
{
	int choice;
	cout<<"\n1: Register an account\n";
	cout<<"\n2: Withdraw money\n";
	cout<<"\n3: Deposit money\n";
	cout<<"\n4: Fixed Diposit\n";
	cout<<"\n5: Close account\n";
	cout<<"\n6: Get statements (account)\n";
	cout<<"\n7: View All account\n";
	cout<<"\n0: Close application\n";
	cout<<"\n\t\tENTER YOUR CHOICE:- ";
	cin>>choice;
	return(choice);
}

int main()
{
	cout<<"\n|*****************->Banking System<-*****************|\n\n";
	while(1)
	{
		switch(menu())
		{
			case 1:
				insert();
				break;
			case 2:
				widraw();
				break;
			case 3:
				deposit();
				break;
			case 4:
				fix();
				break;
			case 5:
				close();
				break;
			case 6:
				view();
				break;
			case 7:
				viewlist();
				break;
			case 0:
				exit(1);
				break;
			default:
				cout<<"\nENTER A VALID CHOICE";
		}
	}
	return(0);
}
