#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
using namespace std;



const int sizeNum = 43;
const int hashNum = 43;

struct node
{
	string data;
	node* next;
};

vector<node*> bucket(sizeNum);
 
int convert(string x)
{
	int total = 0;
	for (int i = 0; i < x.length();i++)
	{
		total += x[i];
	}
	return total;
}

void insert(string data)//O(n)
{
	struct node* temp = new struct node;
	int converted = convert(data);
	temp->data = data;
	temp->next = bucket[converted % hashNum];
	bucket[converted % hashNum] = temp;
}
void display()//O(n+m)
{
	struct node* temp = new struct node;
	for (int i = 0;i < sizeNum;i++)
	{
		temp = bucket[i];
		cout << i<<". ";
		while (temp != NULL)
		{
			
			cout << temp->data<<" ";
			temp = temp->next;
		}
		cout << endl;
	}
}
void lookup(string data)//O(n)
{
	int i = 0;
	struct node* temp = new struct node;
	int converted = convert(data);
	int x = converted % hashNum;
	temp = bucket[x];
	if (bucket[x] == NULL)
	{
		
		cout<< data << " Not found " << endl;
		return;
	}
	else if (bucket[x]->data == data)
	{
		
		cout << "Found "<< data<<" at index "<<x<< " and it took 0 iterations" << endl;
		return;
	}
	else
	{
		while (temp != NULL)
		{
			if (temp->data == data)
			{
				cout << "Found " << data << " at index "<<x<<" and it took " << i << " iterations" << endl;
				return;
			}
			i++;
			temp = temp->next;
		}
		cout <<data<< " Not found ";
		return;
	}


}

int main()
{
	
	ifstream file("hash.txt");
	string word;
	while (file >> word)
	{
		insert(word);
	}
	display();
	
	while (true)
	{
		string search;
		cout << "Enter -1 to quit or Enter a word a to find: ";
		cin >> search;
		if (search == "-1")
		{
			break;
		}
		lookup(search);
		cout << endl;
	}
	
	return 0;
}