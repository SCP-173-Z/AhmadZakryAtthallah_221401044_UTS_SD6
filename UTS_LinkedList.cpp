/*
================================================================================================
Linked List

Linear Data Structure that uses Node struct, containing value and pointer reference to the
next node.
================================================================================================
*/

#include <iostream>
using namespace std;

struct node {
    string name;
    int KPI;
    node *next;
};

node *head = NULL;
node *tail = NULL;

void insertHead(string name, int KPI) {
    node *newNode = new node;
    newNode -> name = name;
    newNode -> KPI = KPI;
    newNode -> next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode -> next = head;
        head = newNode;
    }
}

void insertTail(string name, int KPI) {
    node *newNode = new node;
    newNode -> name = name;
    newNode -> KPI = KPI;
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

void option_1() {
    string nameInsert;
    int KPI_Insert;
    
    cout << "Masukkan nama karyawan: ";
    cin >> nameInsert;
    do {
        cout << "Masukkan KPI karyawan (0 - 100): ";
        cin >> KPI_Insert;

    } while (KPI_Insert < 0 || KPI_Insert > 100);

    insertTail(nameInsert, KPI_Insert);
}

void option_2() {
    string nameInsert;
    int KPI_Insert;
    
    cout << "Masukkan nama karyawan: ";
    cin >> nameInsert;
    do {
        cout << "Masukkan KPI karyawan (0 - 100): ";
        cin >> KPI_Insert;

    } while (KPI_Insert < 0 || KPI_Insert > 100);

    insertHead(nameInsert, KPI_Insert);
}

void deleteTail() {
    if (head == NULL) {
        cout << "List Kosong!";
        return;
    }

    if (head == tail) {
        delete head;
        head = tail = NULL;
        return;
    }

    node *p = head;
    while (p -> next != tail) {
        p = p -> next;
    }

    delete tail;
    tail = p;
    tail -> next = NULL;

    cout << "Removed data at tail..." << endl;
}

void displayPerfect() {
    node *temp = head;
    int num = 1;

    cout << "List karyawan yang sempurna: " << endl;
    while (temp != NULL) {
        if (temp -> KPI == 100) {
            cout << num << ". " << temp -> name << endl;
            num++;
        }
        temp = temp -> next;
    }
}

int main() {
    int option;

    system("cls");

    do {
        cout << "===== MENU =====" << endl;
        cout << "1. Insert Tail" << endl;
        cout << "2. Insert Head" << endl;
        cout << "3. Delete Tail" << endl;
        cout << "4. Show perfect employee" << endl;
        cout << "Input option: ";
        cin >> option;

        system("cls");

        switch (option) {
            case 1 : 
                option_1();
                break;
            case 2 : 
                option_2();
                break;
            case 3 : 
                deleteTail();
                break;
            case 4 : 
                break;
        }

    } while (option != 4);

    displayPerfect();
    system("pause");

    return 0;
}