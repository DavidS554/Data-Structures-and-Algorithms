#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct tree {
	string data;
	tree* left;
	tree* right;
};

class BST
{
private:

public:

	BST()//O(h)
	{

	}
	struct tree* insert(struct tree* node, string data)
	{
		if (node == NULL)
		{
			struct tree* newNode = new struct tree;
			newNode->data = data;
			newNode->left = NULL;
			newNode->right = NULL;
			return newNode;
		}
		else
		{
			if (node->data > data)
			{
				node->left = insert(node->left, data);
			}
			else if(node->data<data)
			{
				node->right = insert(node->right, data);
			}
			else
			{
				return node;
			}
			return node;
		}
	}
	void display(struct tree* node)
	{
		if (node == NULL)
		{
			return;
		}
		else//LPR
		{
			display(node->left);
			cout << node->data << " ";
			display(node->right);
		}
	}
	int search(struct tree* node, string found, int &i)
	{
		if (node == NULL)
		{
			return -1;
		}
		else if (node->data == found)
		{
			//cout << found;
			return i;
		}
		else if (node->data > found)
		{
			i++;
			return search(node->left, found, i);
		}
		else
		{
			i++;
			return search(node->right, found, i);
		}
	}
	struct tree* deleteNode(struct tree* node, string word)
	{
		if (node == NULL)
		{
			return node;
		}
		else if (node->data > word)
		{
			node->left = deleteNode(node->left, word);
		}
		else if (node->data < word)
		{
			node->right = deleteNode(node->right, word);
		}
		else
		{
			if (node->left == NULL && node->right == NULL)
			{
				delete node;
				node = NULL;
			}
			else if (node->left == NULL)
			{
				struct tree* temp = node->right;
				delete(node);
				return temp;
			}
			else if (node->right == NULL)
			{
				struct tree* temp = node->left;
				delete(node);
				return temp;
			}
		
			else
			{
				struct tree* temp = minValue(node->right);
				node->data = temp->data;
				node->right = deleteNode(node->right, word);
			}
	    }
		return node;
	}
	tree* minValue(struct tree* node)
	{
		struct tree* temp = node;
		while (temp && temp->left != NULL)
		{
			temp = temp->left;

		}
		return temp;

	}
};

int main()
{
	BST bst;
	struct tree* begin = NULL;
	ifstream file("bst.txt");
	string word;
	while (file >> word)
	{
		begin = bst.insert(begin, word);
	}
	bst.display(begin);
	cout << endl<<endl;

	while (true)
	{
		int i = 0;
		string input;
		cout << "Enter a word you want to search for, -1 to quit" << endl;
		cin >> input;
		if (input == "-1")
		{
			break;
		}
		//cout << i;
		if (bst.search(begin, input, i) != -1)
		{
			cout << "Found " << input << " after " << i << " iterations." << endl;
		}
		else
		{
			cout << input << " not found." << endl;
		}
	}
	string input;
	cout << "Enter a word you want to delete" << endl;
	cin >> input;
	bst.display(begin);
	cout << endl;
	bst.deleteNode(begin, input);
	bst.display(begin);


	
	
	return 0;
}