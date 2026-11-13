#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct node {
    int value;
    node *next;
};

node *head = NULL;
node *tail = NULL;

void insertLast(int n) {
    node *newNode = new node;
    newNode -> value = n;
    newNode -> next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = head;
    }
    else {
        tail -> next = newNode;
        tail = newNode;
    }
}

void traverse() {
    stack<int> multiple_3;
    queue<int> notMultiple;

    node *temp = head;
    while (temp != NULL) {
        if (temp -> value % 3 == 0) {
            multiple_3.push(temp -> value);
        }
        else {
            notMultiple.push(temp -> value);
        }
        temp = temp -> next;
    }

    // Stack
    cout << "Output Stack : ";
    do {
        cout << multiple_3.top() << " ";
        multiple_3.pop();
    } while (multiple_3.size() != 0);

    cout << "\n";

    // Queue
    cout << "Output Queue : ";
    do {
        cout << notMultiple.front() << " ";
        notMultiple.pop();
    } while (notMultiple.size() != 0);
}

int main() {
    system("cls");
    int num;

    cout << "Masukkan lima angka: " << endl;
    for (int i = 1; i <= 5; i++) {
        cout << "Angka ke-" << i << ": ";
        cin >> num;

        insertLast(num);
    }

    traverse();

    return 0;
}