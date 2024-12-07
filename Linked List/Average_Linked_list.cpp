#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *previous;

    Node()
    {
        next = nullptr;
        previous = nullptr;
    }
};

class LinkedList
{
public:
    Node *head;
    Node *tail;
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    void createList(int n)
    {
        int value;
        for (int i = 0; i < n; i++)
        {
            Node *newNode = new Node;
            cin >> value;
            if (head == nullptr)
            {
                head = newNode;
                tail = newNode;
                newNode->data = value;
            }
            else
            {
                tail->next = newNode;
                newNode->previous = tail;
                newNode->data = value;
                tail = newNode;
            }
        }
    }
};

int main()
{
    LinkedList list1, list2, list3;

    int size1, size2, value;
    cout << "Size of list 1: ";
    cin >> size1;
    cout << "\nItems in list 1: ";
    list1.createList(size1);

    cout << "\nSize of list 2: ";
    cin >> size2;
    cout << "\nItems in list 2: ";
    list2.createList(size2);

    Node *temp1 = list1.head;
    Node *temp2 = list2.head;
    Node *temp3 = new Node;
    list3.head = temp3;
    list3.tail = list3.head;

    cout << "\nOutput: ";
    for (int i = 0; i < max(size1, size2); i++)
    {
        int a = 0, b = 0;
        if (temp1 != nullptr)
        {
            a = temp1->data;
            temp1 = temp1->next;
        }
        if (temp2 != nullptr)
        {
            b = temp2->data;
            temp2 = temp2->next;
        }
        temp3->data = (a + b) / 2;
        Node *temporary = new Node;
        temp3->next = temporary;
        temp3 = temp3->next;
    }
    temp3 = list3.head;
    for (int i = 0; i < max(size1, size2); i++)
    {
        cout << temp3->data << ' ';
        temp3 = temp3->next;
    }
}