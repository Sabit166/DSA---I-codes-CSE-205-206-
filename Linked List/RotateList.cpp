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

    void rotateList(int k)
    {
        Node *temp=head;
        Node *temp1=head;
        for(int i=1;i<k;i++)
        {
            if(temp==nullptr)
            {
                cout << "Invalid position";
                return;
            }
            if(temp==nullptr)
            {
                cout << "Incorrect position to rotate";
                return;
            }
            temp=temp->next;
        }

        while(temp1->next!=nullptr) temp1=temp1->next;

        temp1->next=head;
        head=temp->next;
        temp->next=nullptr;
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
    cout << "\nEnter the number of Nodes of list 1: ";
    cin >> n;
    list.createlist(n);

    cout << "\nEnter position to rotate the List: ";
    cin >> pos;

    list.rotateList(pos);

    list.printList();
}