#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        next = nullptr;
    }
};

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void createlist(int n)
    {
        int value;
        Node *temp = new Node;
        for (int i = 0; i < n; i++)
        {
            cout << "\nEnter the value of the node: ";
            cin >> value;
            Node *newNode = new Node;
            if (head == nullptr)
            {
                head = newNode;
                temp = head;
                head->data = value;
            }
            else
            {
                temp->next = newNode;
                newNode->data = value;
                temp = temp->next;
            }
            temp->next=nullptr;
        }
    }

    void reverseList()
    {
        Node *next=nullptr,*previous=nullptr,*current=head;
        while(current!=nullptr)
        {
            next=current->next;
            current->next=previous;
            previous=current;
            current=next;
        }
        head=previous;
    }
    
    void printList()
    {
        Node *temp = head;
        cout << "\n";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main()
{
    LinkedList list;

    int n, pos;
    cout << "\nEnter the number of Nodes of list: ";
    cin >> n;

    list.createlist(n);

    list.reverseList();

    list.printList();
}