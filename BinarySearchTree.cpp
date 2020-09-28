// Serial Number : 32 //
// Author : Erik Pantoja
// Due Date: 1 May 2019
// Optional Program . //
// Spring 2019 - CS 3358 - 253 //
// Instructor: Husain Gholoom. //
// <Program that uses a binary search tree>

//Included Libararies
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include <ctime>
#include <iomanip>
#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>

using namespace std;

class BinarySearchTree
{
private:
    struct treeNode
    {
        treeNode* left;
        treeNode* right;
        int data;
    };
    treeNode* root;
public:
    BinarySearchTree()
    {
        root = NULL;
    }
    
    bool isEmpty() const
    {
        return root == NULL;
    }
    
    void preOrder();
    void preorder(treeNode*);
    void postOrder();
    void postorder(treeNode*);
    void insert(int);
    void characters(char[]);
    void printChar(char[]);
    void display(int j);
    void displayRSR();
    void displayLSR();
    void displayLeafValues();
    int treeLeafsCount(treeNode*);
    int treeLeafsCount1();
};


//Main Program
int main() {
    BinarySearchTree tree; // Creating object tree of the class
    char c[13], tmp;       // Creating an array
    tree.characters(c);    // adding to array
    cout << "Binary Search Tree By Erik Pantoja.\n\n";
    cout << "The Character array is  ";
    tree.printChar(c);     // Displaying the array
    cout << "\n\nInserting Nodes.\n\n";
    for(int i = 0; i <= 12; i++) // Cycing through the array
    {
        tmp = c[i];
        tree.insert(tmp); //inserting the array elements into the tree
    }
    cout << "Building BST is completed.\n\n";
    int j = 1;
    cout << "Values of the Binary Search tree.\n\n";
    tree.display(j);     //displaying the tree
    // Pre-Order Traversal .
    cout << "Pre-Order Traversal of the BST :\n\n";
    tree.preOrder(); //Preorder display
    cout <<endl<<endl;
    // Post-Order Traversal .
    cout << "Post-Order Traversal of the BST :\n\n";
    tree.postOrder(); //Postorder display
    cout <<endl<<endl;
    // All right sub root values.
    cout << "Here are all right sub root values for the BST:\n\n";
    //displayRSR();//not implelmented yet
    // All left sub root values.
    cout << "\n\nHere are all left sub root values for the BST :\n\n";
    //displayLSR(); //not implemented yet
    // Counting Number of Leafs .
    cout << " \n\nNumber of Leafs  = " ;
    int x = tree.treeLeafsCount1(); // counting leaves function
    cout << x;
    // Display the leaf values.
    cout << "\n\nHere are the leaf values in the BST:\n\n"; //displayLeafValues();
    cout << "\n\n\nErik Pantoja – May 1 ,2019\n\n";
    return 0;
}


//Function Definitions
void BinarySearchTree::preorder(treeNode* p) // Displays in preorder
{
    if(p != NULL)
    {
        char b;
        b = p -> data;
        cout <<" "<< b << " " <<endl;
        if (p->left) preorder (p->left); //Using recurrsion to call array
        if (p->right) preorder (p->right);
    }
    else return;
}
void BinarySearchTree::preOrder()
{
    preorder(root);
}

 int BinarySearchTree::treeLeafsCount1() // prints out the leaves
{
    return treeLeafsCount(root);
}

int BinarySearchTree::treeLeafsCount(treeNode* p){
    if (p == NULL) // Returning if NULL
        return 0;
    if (p->left == NULL && p->right == NULL)
        return 1;  //Returning of both NULL
    else           //returning count of both
        return treeLeafsCount (p -> left) + treeLeafsCount (p-> right);
}

void BinarySearchTree::postOrder() //Printing postorder
{
    postorder(root);
}

void BinarySearchTree::postorder(treeNode* p)
{ //Using Recurrsion to call the function
    if(p != NULL)
    {
        char b;
        if(p->left) postorder(p->left);
        if(p->right) postorder(p->right);
        b = p->data;
        cout << " " << b << " " <<endl; //Displaying
    }
    else return;
}

void BinarySearchTree::characters(char ca[])
{
    int i;
    srand (time(NULL)); //To keep random
    for (i = 0; i < 13; i++){
        char c = 'A' + rand() % 26;
        for(int g = 0; g < 13; g++){ //Check for duplicates
            if (ca[g] == c){
               c = 'A' + rand() % 26;
            }
        }
        ca[i] = c;
    }
}

void BinarySearchTree::printChar(char c[])
{
    for(int i = 0; i <= 12; i++) //Printing out the char array
    {
        cout << c[i] << " ";
    }
    cout << endl;
}

void BinarySearchTree::display(int j){
    for (int k=0;k<13;k++){
    cout << j <<":"  << endl; j++;
    }
    cout <<endl; cout <<endl;
}

void BinarySearchTree::displayRSR(){
    cout << "\n\n --In the display RSR function--\n\n";
    //Not implemented yet
}

void BinarySearchTree::displayLSR(){
    cout << "\n\n --In the display LSR function--\n\n";
    // Not implemented yet
}

void BinarySearchTree::displayLeafValues(){
    cout << "\n\n--In the display leaf values function--\n\n";
    //Not implemented yet
}


void BinarySearchTree::insert(int d) //Inserting into the tree
{
    treeNode* t = new treeNode; //Creating object
    treeNode* parentN; //creating parent
    t->data = d;
    t->left = NULL; //left is null
    t->right = NULL; //right is null
    parentN = NULL;
    if(isEmpty()) root = t;
    else
    {
        treeNode* current;
        current = root;
        while(current) // looping
        {
            parentN = current;
            if(t->data > current ->data) current = current ->right;
            else current = current ->left;
        }
        if(t->data < parentN ->data)
            parentN ->left = t;
        else
            parentN ->right = t;
    }
}
