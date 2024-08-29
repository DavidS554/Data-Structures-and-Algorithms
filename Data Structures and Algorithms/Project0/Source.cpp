#include <iostream>
#include <fstream>
using namespace std;

string* sort(string Array[])
{
    //sort begin
    string temp;
    for (int i = 0;i < 15;i++)               //Big O is O(n)
    {
        for (int j = 1;j < (15 - i);j++)       //Big O is O(n)
        {
            if (Array[j - 1] > Array[j])        // Combined Big O is O(n^2)
            {
                temp = Array[j - 1];
                Array[j - 1] = Array[j];
                Array[j] = temp;
            }
        }
    }
    for (int j = 0; j < 15; j++)
    {
        cout << Array[j] << " ";
    }
    cout << endl;
    //sort 
    return Array;
}
void search(string Array[])
{
    bool found = false;
    while(true)
  {
 cout << "What word do you want? 0 is quit" << endl;
 string key;
 cin >> key;
        //  search begin
        int bottomHalf = 0;
        int len = 15;
        int topHalf = len - 1;
        
        while (bottomHalf <= topHalf)
        {

            int mid = bottomHalf + (topHalf - bottomHalf) / 2;
            if (Array[mid] == key)
            {
                cout << key << " is in the text at index " <<mid<< endl;//put in index
               // search(Array);
                found = true;

            }
            if (key > Array[mid])
            {
                bottomHalf = mid + 1;
            }
            else
            {
                topHalf = mid - 1;
            }
        }
        if (key == "0")
        {
            break;
        }
        if (found==false)
        { 
            cout << "Word is not in the list" << endl;
            return;
        }
        found = false;
    }

}

int main()
{
    fstream myFile;
    myFile.open("text.txt");
    string Array[15];
    int x = 0;
    while (!myFile.eof())
    {
        myFile >> Array[x];
        x++;
    }
    myFile.close();
    for (int j = 0; j < 15; j++)
    {
        cout << Array[j] << " ";
    }
    cout << endl;
    sort(Array);
    search(Array);

}




