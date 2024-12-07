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
    void push(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else if (head->data > value)
        {
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                if (temp->next->data < value)
                    temp = temp->next;
                else
                {
                    temp->next->previous = newNode;
                    newNode->next = temp->next;
                    temp->next = newNode;
                    newNode->previous = temp;
                    break;
                }
            }

            if (temp->next == nullptr)
            {
                tail->next = newNode;
                newNode->previous = tail;
                tail = newNode;
            }
        }
        display();
    }

    void display()
    {
        Node *temp = head;
        cout << "\nThe List: ";
        while (temp != nullptr)
        {
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList list;

    while (true)
    {
        cout << "\nEnter a number: ";
        int value;
        cin >> value;
        list.push(value);
    }
}