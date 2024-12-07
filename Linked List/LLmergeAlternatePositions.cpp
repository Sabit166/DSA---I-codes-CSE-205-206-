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

    LinkedList mergeList(LinkedList list2)
    {
        LinkedList list3;
        Node *temp = head,*temp1=list2.head;
        Node *temp2=new Node;
        list3.head=temp2;

        while(temp!=nullptr || temp1!=nullptr)
        {
            if(temp!=nullptr)
            {
                Node *newNode=new Node;
                temp2->next=newNode;
                temp2->data=temp->data;
                temp=temp->next;
                temp2=temp2->next;
            }

            if(temp1!=nullptr)
            {
                Node *newNode=new Node;
                temp2->next=newNode;
                temp2->data=temp1->data;
                temp1=temp1->next;
                temp2=temp2->next;
            }
        }
        return list3;
    }

    void printList()
    {
        Node *temp = head;
        cout << "\n";
        while (temp->next != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main()
{
    LinkedList list1, list2,list3;

    int n, pos;
    cout << "\nEnter the number of Nodes of list 1: ";
    cin >> n;
    list1.createlist(n);

    cout << "\nEnter the number of Nodes of list 2: ";
    cin >> n;
    list2.createlist(n);

    list3=list1.mergeList(list2);

    list3.printList();
}