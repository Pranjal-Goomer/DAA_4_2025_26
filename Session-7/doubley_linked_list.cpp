/*
Code to implement a doubly linked list with all its operations to insert, delete and traverse its nodes.

Name : Pranjal Goomer
UID : 24BCS10551
Date : 20-01-2026

*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    // IT WILL INSERT AT BEGINNING
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // IT WILL INSERT AT END
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);

        if (tail == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // IT WILL INSERT AT THE SPECIFIED POSITION 
    void insertAtPosition(int val, int pos) {
        if (pos == 1) {
            insertAtBeginning(val);
            return;
        }

        Node* temp = head;
        int count = 1;

        while (temp != NULL && count < pos - 1) {
            temp = temp->next;
            count++;
        }

        if (temp == NULL || temp->next == NULL) {
            insertAtEnd(val);
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    // IT WILL DELETE FROM BEGINNING
    void deleteFromBeginning() {
        if (head == NULL) return;

        Node* temp = head;
        head = head->next;

        if (head != NULL)
            head->prev = NULL;
        else
            tail = NULL;

        delete temp;
    }

    // IT WILL DELETE FROM END
    void deleteFromEnd() {
        if (tail == NULL) return;

        Node* temp = tail;
        tail = tail->prev;

        if (tail != NULL)
            tail->next = NULL;
        else
            head = NULL;

        delete temp;
    }

    // IT WILL DELETE FROM THE SPECIFIED POSITION 
    void deleteFromPosition(int pos) {
        if (pos == 1) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        int count = 1;

        while (temp != NULL && count < pos) {
            temp = temp->next;
            count++;
        }

        if (temp == NULL) return;

        if (temp == tail) {
            deleteFromEnd();
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    // TO TRAVERSE THE LINKED LIST WE ARE USING THIS FUNCTION
    void traverseForward() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList doubly;

    doubly.insertAtBeginning(10);
    doubly.insertAtEnd(20);
    doubly.insertAtEnd(30);
    doubly.insertAtPosition(15, 2);

    doubly.traverseForward();    // 10 15 20 30

    doubly.deleteFromBeginning();
    doubly.traverseForward();    // 15 20 30

    doubly.deleteFromEnd();
    doubly.traverseForward();    // 15 20

    doubly.deleteFromPosition(2);
    doubly.traverseForward();    // 15

    return 0;
}
