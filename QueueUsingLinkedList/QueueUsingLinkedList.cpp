// QueueUsingLinkedList.cpp 
//Queue data structure implemented using linked list

#include <iostream>

using namespace std;


struct Node
{
	int data;
	struct Node* next;
	
}*front =NULL,*rear=NULL;


bool IsFull();
bool IsEmpty();
void enqueue( int );
void display();


void dequeue()
{
	if (!front)
	{
		cout << " Queue is empty ." << endl;
		return;
	}

	struct Node* p =front;
	front = front->next;
	cout << "The value -> " << p->data << " deleted from the queue ." << endl;
	delete p;
}


void display()
{
	if (front == NULL)
	{
		cout << "Queue is empty ." << endl;
		return;
	}
	struct Node* p = front;
	while (p)
	{
		cout << p->data<<" ";
		p = p->next;
	}
	cout << endl;
}


void enqueue(int x)
{
	if (IsFull())
	{
		cout << "Queue is full ..Insertion of -> " << x << " not possible ." << endl;
		return;
	}
	struct Node* p = new Node;
	p->data = x;
	p->next = NULL;
	cout << "The value -> " << x << " inserted into the queue." << endl;
	if (!front)
	{
		front = rear = p;
		return;
	}

	rear->next = p;
	rear = p;
}


bool IsEmpty()
{
	return front == NULL ? 1 : 0;
}


bool IsFull()
{
	struct Node* temp = new Node;
	if (temp == NULL)
	{
		delete temp;
		return 1;
	}
	return 0;
}


int main()
{
	display();
	enqueue( 10);
	enqueue( 20);
	enqueue( 30);
	enqueue(40);
	enqueue(50);
	enqueue(60);

	display();
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	display();

}
