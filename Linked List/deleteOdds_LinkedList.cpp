#include <bits/stdc++.h>
using namespace std;

int deletecount = 0;
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
    Node *head, *tail;

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void addItem(int val)
    {
        Node *newNode = new Node;
        newNode->data = val;
        if (head == nullptr)
        {
            head = tail = newNode;
            head->data = val;
        }
        else
        {
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
            newNode->data = val;
        }
    }

    Node *deleteFirst()
    {
        Node *toDelete = new Node;
        toDelete = head;
        if (head == tail)
        {
            delete toDelete;
            head = nullptr;
            tail = nullptr;
            return nullptr;
        }
        else
        {
            head = head->next;
            delete toDelete;
            toDelete = nullptr;
            head->previous = nullptr;
            return head;
        }
    }

    Node *deleteLast()
    {
        Node *toDelete = new Node;
        toDelete = tail;
        if (head == tail)
        {
            delete toDelete;
            head = nullptr;
            tail = nullptr;
            return nullptr;
        }
        else
        {
            tail = tail->previous;
            delete toDelete;
            toDelete = nullptr;
            tail->next = nullptr;
            return nullptr;
        }
    }

    Node *deleteMiddle(Node *toDelete)
    {
        Node *temp = new Node;
        temp = head;
        while (temp->next != toDelete)
            temp = temp->next;
        toDelete->next->previous = temp;
        temp->next = toDelete->next;
        delete toDelete;
        toDelete = nullptr;
        return temp->next;
    }

    Node *countODD()
    {
        Node *temp = new Node;
        temp = head;
        while (temp != nullptr)
        {
            if (temp->data % 2 == 1)
            {
                deletecount++;
                if (temp == head)
                    temp = deleteFirst();
                else if (temp == tail)
                    temp=deleteLast();
                else
                    temp = deleteMiddle(temp);
            }
            else
                temp = temp->next;
        }
        return head;
    }

    void printList()
    {
        Node *temp = new Node;
        temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main()
{
    cout << "Enter the number of items to be added in the list: ";
    int n;
    cin >> n;
    LinkedList list;
    for (int i = 0; i < n; i++)
    {
        int val;
        cout << "\nEnter item to be added: ";
        cin >> val;
        list.addItem(val);
    }

    Node *node = list.countODD();

    cout << "Number of items left: " << n - deletecount << "\n";
    if (node == nullptr)
        cout << "NONE\n";
    else
        list.printList();
}