// Jordan Scott 
// CST-201 
// Project 6 
// Binary Search Tree 
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "BST.h"
using namespace std;

int main()
{
    // Binat search tree 

    BST<int> nola;
    int nolaS;
    int poboy;
    int beans;
    ifstream file("bst.txt");
    cout << endl;

    while (file >> nolaS)
    {
        nola.Newinsert(nolaS);
    }
    nola.inOrder();
    cout << endl;
    // cout<< nolaS<<endl;
    // while (poboy != "-1")
    // {
    //   cout<< "Enter string, enter -1 to quit:"<< endl;
    //   cin >>poboy;
    //   cout << nola.searchHelp(poboy)<<endl;
    // }
    // cout<< "Enter string to remove:"<<endl;
    // cin >> beans;
    nola.deleteVal2(1);
    cout << endl;
    nola.inOrder();
    cout << endl;
    return 0;
    // issue with code: 
    // delete method replcae the value and creates an duplicate of the value. 
    // think my search is broke now since adding the while loop. << its not broke just did not have information 
    // inorder does not work no more. < does not work when try to put in the orginal text 

}