#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;




bool Slip(string str, int i)//O(n)
{
	if (str[i] == 'D' ||str[i]== 'E')
	{
		i++;
		if (str[1] != 'F')
		{
			//cout << "False";
			return false;
		}
		while (str[i] == 'F')
		{
			i++;
			
		}
		if (str[i] == 'G'&&str[i-1]=='F'&&str.back()=='G')
		{
			//cout << "True";
			return true;
		}
		else if(str[i] == 'D' || str[i] == 'E')
		{
		  Slip(str, i);
		}
		else 
		{
			//cout << "False";
			return false;
		}
		//Slip(str, i);
		//return false;
	}
	else
	{
		//cout << "False";
		return false;
	}
}

bool Slap(string str)//Big O (n)
{
	int i = 0;
	//cout << str << endl;
	if (str[i] == 'A' && str[i + 1] == 'H')
	{

		//cout << "True";
		return true;
	}
	else if (str[i] == 'A' && str[i + 1] == 'B' && str.back() == 'C')
	{
		i=i+2;
		//cout << str.substr(i, str.length() - i - 2) << endl;
		//Slap(str.substr(i, str.length() - 1));
		Slap(str.substr(i, str.length() - i ));

		//cout << str << endl;
		
	}
	else if (str[i] == 'A' && (str[i + 1] == 'D' || str[i + 1] == 'E') && str.back() == 'C')
	{
		//cout << i<<endl;
		if (Slip(str.substr(i++, str.length()-i), i++))
		{
			//cout << "True";
			return true;
		}
		else
		{
			//cout << str << endl;
			//cout << "False";
			return false;
		}
	}
	else
	{
		//cout << "False";
		return false;
	}
}
void Slop(string str)//O(n)
{
	for (int i = 0; i < str.length(); i++)
	{
		//cout << str[i] << endl;
		if (str[0]=='A'&&(str[i] == 'C' || str[i] == 'H') && (str[i + 1] == 'D' || str[i + 1] == 'E'))
		{
			//cout << str << endl;
			//cout << str[i++] << endl;
			string str1 = str.substr(0, i+1);
			//cout << str1 << endl;
			string str2 = str.substr(i+1, str.length()-1);
			//cout << str2 << endl;
			if (Slap(str1) && Slip(str2, 0))
			{
				cout << "YES"<<endl;
				return;
			}
			else
			{
				cout << "NO"<<endl;
				return;
			}
		}
	}
	cout << "NO"<<endl;
}

int main()
{
	cout << "SLOPS OUTPUT" << endl;
	ifstream file("Recursive.txt"); 
	string line; 
	int num;
	file >> num;
	for (int i = 0; i < num;i++)
	{
		file >> line;
		Slop(line);
	}
	cout << "END OF OUTPUT";
	//int num2 = 0;
	//string str = "AHDFG";
	//Slop(str);
	return 0;
}
//string str = "DFG";
/*if (Slip(str, num))
{
	cout << "True";
}
else
{
	cout << "False";
}*/
//string str1 = "ADFGC";
//Slap(str1);