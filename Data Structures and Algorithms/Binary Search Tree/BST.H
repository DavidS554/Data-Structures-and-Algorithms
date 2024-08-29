// Jordan Scott 
// CST-201 
// ----------------------------------------------------------------
#ifndef BST_H
#define BST_H
#include <iostream>
using namespace std;
template<class T>

class BST
{
private:
    int count = 0;

public:

    struct node
    {
        T data;
        struct node* right;
        struct node* left;
    };
    struct node* root = NULL;
    BST()
    {

    }
    // helper method  
    void Newinsert(T val)
    {
        root = insert(root, val);
    }
    // insert 

    struct node* insert(struct node* root, T val)
    {
        // base case if NULL , checking to see if the root is null 
        if (root == NULL)
        {
            struct node* root = new (struct node);
            root->data = val;
            root->right = NULL;
            root->left = NULL;
            return root;
        }
        else
        {
            // LPR 
            // want to check the values againt each other then move left or right. 
            if (val < root->data)
            {
                // going left then print 
                root->left = insert(root->left, val);
            }
            else if (val == root->data)
            {
                return root;
            }
            else
            {
                root->right = insert(root->right, val);
                // going right 
            }
            return root;
        }

    }
    // helper method for inOrder
    void inOrder()
    {
        inorder(root);
    }


    //Have the strings put in the correct order 
    void inorder(struct node* root)
    {
        if (root != NULL)
        {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    // helper method for search
    string searchHelp(T val)
    {
        struct node* temp = search(root, val);
        if (temp != NULL)
        {
            return "found it";
        }
        else
        {
            return "sorry not found";
        }

    }
    // // search 
    struct node* search(node* root, T val)
    {
        if (root == NULL || root->data == val) {
            return root;
        }
        if (val < root->data)
        {
            return search(root->left, val);
            count++;
            //cout << count<<endl;
        }
        return search(root->right, val);
        count++;
    }

    // helper method for delete 
    void deleteVal2(T val)
    {
        root = deleteVal(root, val);
    }
    // delete selected data
    node* deleteVal(node* root, T val)
    {
        // Base case 
        if (root == NULL)
        {
            return root;
        }
        else
        {
            // recursive calls 
            if (val < root->data)
            {
                root->left = deleteVal(root->left, val);
            }
            else if (val > root->data)
            {
                root->right = deleteVal(root->right, val);
            }
            else
            {
                // checking to see if they had childern 
                // if a single parent 
                if (root->left == NULL) // root->left== NULL && root->right== NULL
                {
                    struct node* temp = root->right;
                    delete root;
                    return temp;
                }
                else if (root->right == NULL)
                {
                    struct node* temp = root->right;
                    delete root;
                    return temp;
                }
                // no kids 
                else if (root->left == NULL && root->right == NULL)
                {
                    delete root;
                    root = NULL;
                }
                else
                {
                    // when right and left is not equal to NULL So two kids
                    cout<<root->data<<" " << root->left->data << " " << root->right->data << endl;
                    struct node* temp = root;
                    cout << temp->data << endl;
                    while (temp->left != NULL)
                    {
                        cout << temp->left->data << endl;
                        temp = temp->left;
                    }
                   root->data = temp->data;
                   cout << temp->data;
                   cout<<"Root: " << root->data;
                   root->right = deleteVal(root->right, val);
                }
            }
        }
        return root;

    }

};
#endif