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
    Node *head;
    Node *tail;

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void CreateList(int n)
    {
        int value;
        for (int i = 0; i < n; i++)
        {
            Node *newNode = new Node;
            cout << "\nEnter the value of node " << i + 1 << ": ";
            cin >> value;
            if (head == nullptr)
            {
                head = newNode;
                tail = newNode;
                head->data = value;
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

    LinkedList concatelist(LinkedList l1, LinkedList l2)
    {
        LinkedList list3;
        Node *temp1 = l1.head;
        while (temp1 != nullptr)
        {
            Node *newNode = new Node;
            if (list3.head == nullptr)
            {
                list3.head = newNode;
                list3.tail = newNode;
                list3.head->data = temp1->data;
                temp1 = temp1->next;
            }
            else
            {
                list3.tail->next = newNode;
                newNode->previous = list3.tail;
                newNode->data = temp1->data;
                temp1 = temp1->next;
                list3.tail = newNode;
            }
        }
        Node *temp2 = l2.head;
        while (temp2 != nullptr)
        {
            Node *newNode = new Node;
            list3.tail->next = newNode;
            newNode->previous = list3.tail;
            newNode->data = temp2->data;
            temp2 = temp2->next;
            list3.tail = newNode;
        }
        return list3;
    }

    void sortList()
    {
        Node *temp1=new Node;
        Node *temp2=new Node;
        temp1=head;

        while(temp1!=nullptr)
        {
            temp2=head;
            while(temp2!=nullptr)
            {
                if(temp2->data>temp1->data)
                {
                    int temp=temp1->data;
                    temp1->data=temp2->data;
                    temp2->data=temp;
                }
                temp2=temp2->next;
            }
            temp1=temp1->next;
        }
    }

    void PrintList()
    {
        cout << "\nThe concated list is given below: ";
        Node *temp=new Node;
        temp=head;
        while(temp!=nullptr)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList list1, list2;

    int size1, size2;
    cout << "\nEnter the size of list 1: ";
    cin >> size1;
    list1.CreateList(size1);

    cout << "\nEnter the size of list 2: ";
    cin >> size2;
    list2.CreateList(size2);

    LinkedList list3=list1.concatelist(list1, list2);

    list3.sortList();

    list3.PrintList();
}