/*
================================================================================================
Tree

Data structure that is organized with hierarchy structure.

In-Order: Left, Root, Right
Pre-Order: Root, Left, Right
Post-Order: Left, Right, Root
================================================================================================
*/

#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

node* root_A = NULL;

void addNode(node** root, int value) {
    
    node* test = new node;
    test = *root;

    if(*root == NULL) {
        node* n = new node;
        n -> data = value;
        n -> left = NULL;
        n -> right = NULL;
        *root = n;
    }
    else if (value < test -> data) {
        addNode(&test -> left, value);
    }
    else {
        addNode(&test -> right, value);
    }
}

void inOrder(node* root, int& total, int& smallNum, float& avgNum) {
    if(root != NULL) {
        if (root -> data < smallNum) {
            smallNum = root -> data;
        }
        avgNum += root -> data;
        inOrder(root -> left, total, smallNum, avgNum);
        cout << root -> data << " ";
        inOrder(root -> right, total, smallNum, avgNum);
    }
}

int main() {
    system("cls");
    int arrSize;

    cout << "Masukkan total masukkan angka: ";
    cin >> arrSize;

    int* listAngka = new int[arrSize];

    for (int i = 0; i < arrSize; i++) {
        cout << "Masukkan angka ke-" << i+1 << ": ";
        cin >> listAngka[i];
        addNode(&root_A, listAngka[i]);
    }

    int smallNum = root_A -> data;
    float avgNum = 0;

    cout << "In-Order Traversal: "; 
    inOrder(root_A, arrSize, smallNum, avgNum);
    cout << "small: " << smallNum << endl;
    cout << "avg: " << avgNum << endl;
    cout << endl;

    return 0;
}