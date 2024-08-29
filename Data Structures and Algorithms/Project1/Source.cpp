#include <iostream>
using namespace std;


class String
{
private:
	int curr_length=0;
	int size=0;
	char* words = new char[size];
public:
	String(string user)
	{
		for (int i = 0; i < user.length(); i++)
		{
			words[i] = user[i];
			curr_length++;
			size++;

		}
	}
/*	String(String& copy) {
		for (int i = 0; i < size; i++) {
			words[i] = copy.words[i];
		}
	}*/

	int Length()
	{
		return size;
	}
	void toString()
	{
		for (int i = 0; i < size;i++)
		{
			cout << words[i];
		}
	}
	void concat(String x)
	{
		int newSize = size * 2;
		char* newWords = new char[newSize];
		for (int i = 0; i < size;i++)	//Big O is O(n)
		{
			newWords[i] = words[i];
		}
		for (int i = 0; i < x.size;i++)	//Big O is O(n)
		{
			newWords[i + size] = x.words[i];
		}
		
		for (int i = 0; i < newSize;i++)	//Big O is O(n)

		{
			cout << newWords[i];
		}
		

	}
	void substringRange(int x, int y)
	{
		for (int i = x;i <= y;i++)
		{
			cout << words[i];
		}
	}
	void substring(int x)
	{
		for (int i = x;i < size;i++)
		{
			cout << words[i];
		}
	}
	/*bool equals(String x)
	{
		for (int i = 0; i < size;i++)
		{
			if (words[i] != x[i])
			{
				return false;
			}
		}
		return true;
	}*/
	/*int compareTo()
	{
		
	}*/
	char get(int x)
	{
		return words[x];
	}
	void toUpper()
	{
		for (int i = 0;i < size;i++)
		{
			if (words[i] >= 65 && words[i] <= 122)
			{
				words[i] = words[i] - 32;
			}
		}
	}
	void toLower()
	{
		for (int i = 0;i < size;i++)
		{
			if (words[i] >=65 && words[i]<=97)
			{
				words[i] = words[i]+32;
			}
			
		}
	}
	
	int lastIndexOf(char x)
	{
		for (int i = size-1;i >= 0;i--)
		{
			if (words[i] == x)
			{
				return i;
			}
		}
		return -1;
	}
	int indexOf(char x)
	{
		for (int i = 0;i < size;i++)
		{
			if (words[i]== x)
				{
						return i;
				}
		}
			return -1;
	}

};
int main()
{
	String string0("HELLO");
	String string1("world");
	cout << "String 0 is: ";
	string0.toString();
	cout << endl;
	cout << "There are " << string0.Length() << " characters in string0" << endl;
	cout << "String 1 is: ";
	string1.toString();
	cout << endl;
	cout << "There are " << string1.Length() << " characters in string1" << endl;
	int index = string0.indexOf('L');
	if (index == -1)
	{
		cout << "The character was not found";
	}
	else {
		cout << "The character was found at index: "<<index;
	}
	cout << endl;
	int lastIndex = string1.lastIndexOf('d');
	if (lastIndex == -1)
	{
		cout << "The character was not found";
	}
	else {
		cout << "The character was found at index: " << lastIndex;
	}
	cout << endl;
	
	string0.toLower();
	string0.toString();
	cout << endl;
	string1.toUpper();
	string1.toString();
	cout << endl;
	cout<<string0.get(0);
	cout << endl;
	string0.substring(2);
	cout << endl;
	string1.substringRange(1, 3);
	cout << endl;
	cout << "The combination of the two strings is: ";
	string0.concat(string1);
	cout<<endl;
	


	


}