#include <iostream>
using namespace std;

struct node {
	int data;
	node* next;
};

class SLL
{
private:
	int size;
public:
	struct node* head = NULL;
	struct node* tail = NULL;
	SLL()
	{
		size = 0;
	}

	int front()//O(1)
	{
		return head->data;
	}
	int back()//O(1)
	{
		return tail->data;
	}
	void display()//O(n)
	{
		struct node* temp;
		temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	int Size()//O(1)
	{
		return size;
	}
	void insert(int x)//O(n)
	{

		node* newNode = new node;
		newNode->data = x;
		newNode->next = NULL;

		if (head == NULL)
		{
			head = newNode;
			tail = newNode;

		}
		else if (head->data > newNode->data)
		{
			newNode->next = head;
			head = newNode;

		}

		else
		{
			node* temp = head;
			node* previous = NULL;

			while (temp != NULL)
			{
				if (temp->data > newNode->data)
				{
					break;
				}
				// insert middle 
				previous = temp;
				temp = temp->next;
			}

			previous->next = newNode;
			newNode->next = temp;
			if (temp == NULL)
			{
				tail = newNode;
			}
		}
		size++;
	}
	void popFront()//O(1)
	{
		head = head->next;
		size--;
	}
	void reverse(node* head)//O(n)
	{
		if (head == NULL)
		{
			return;
		}
		reverse(head->next);
		cout<<head->data<<" ";
	}	
	void empty()//O(1)
	{
		if (head == NULL)
		{
			cout << "The list is empty" << endl;
		}
		else
		{
			cout << "The list is not empty" << endl;
		}
	}
	void popBack()//O(n)
	{
		struct node* temp = head;
		while (temp->next != tail)
		{
			temp = temp->next;
		}
		temp->next = NULL;
		size--;
	}
	void merge(SLL sll)//O(n^2)
	{
		{
			node* temp = sll.head;
			while (temp != NULL)
			{
				this->insert(temp->data);
				temp = temp->next;
			}
		}
	}	
};

int main()
{
	SLL sll;
	cout << "List 1 is: ";
	sll.insert(7);
	sll.insert(2);
	sll.insert(5);
	sll.insert(10);
	sll.insert(6);
	sll.display();
	cout << endl;
	cout << "List 2 is: ";
	SLL sll2;
	sll2.insert(99);
	sll2.insert(3);
	sll2.insert(11);
	sll2.display();
	cout << endl;
	cout << "Combined is: ";
	sll.merge(sll2);
	sll.display();
	cout << endl;
	cout<<"The size of the list is: " << sll.Size()<<endl;
	sll.empty();
	cout << "Front element is: "<<sll.front() << endl;
	cout << "Back element is: " <<sll.back() << endl;
	//sll.display();
	cout<<endl<<"The reverse is: ";
	sll.reverse(sll.head);
	cout << endl<<"Removing front element: ";
	sll.popFront();
	sll.display();
	cout << endl<<"Removing the back element: ";
	sll.popBack();
	sll.display();

	return 0;
	
}