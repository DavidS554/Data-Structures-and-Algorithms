#pragma once
#ifndef MYSTACK_H
#define MYSTACK_H
#include <string>
#include <iostream>
using namespace std;
template<class T>

class myStack
{
private:
	int size;
public:
	struct node
	{
		T data;
		node* next;
	};
	struct node* head = NULL;
	myStack()
	{

	}
	void push(T data)//O(1)
	{
		struct node* newNode = new node;
		newNode->data = data;
		newNode->next = head;
		head = newNode;
		size++;
	}
	int Size()const//O(1)
	{
		return size;
	}
	bool empty()const
	{
		if (head == NULL)//O(1)
		{
			cout << "The stack is empty" << endl;
			return true;
		}
		else 
		{
			cout << "The stack is not empty" << endl;
			return false;
		}
	}
	T top()const//O(1)
	{
		return head->data;
	}
	void pop()//O(1)
	{
		struct node* temp = head;
		head = temp->next;
		delete temp;	
		size--;
	}

};
#endif