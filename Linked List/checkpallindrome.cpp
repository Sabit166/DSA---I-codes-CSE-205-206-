#include <bits/stdc++.h>
using namespace std;

int n;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        next = NULL;
    }
};

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void createlist()
    {
        int value;
        for (int i = 0; i < n; i++)
        {
            cout << "\nEnter the value of the node: ";
            cin >> value;
            Node *newNode = new Node,*temp=new Node;
            newNode->data = value;
            if (head == NULL)
            {
                head = newNode;
                temp=newNode;
            }
            else
            {
                newNode=temp->next;
                temp=temp->next;
            }
        }
    }

    bool checkPallindrome()
    {
        Node *temp1=head;
        
    }

    void printList()
    {
        Node *temp = head;
        cout << "\n";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main()
{
    cout << "Enter the number of Nodes: ";
    cin >> n;
    LinkedList list;
    list.createlist();
    if(list.checkPallindrome()) cout << "The given list is a pallindrome\n";
    else cout << "The given list is not a pallindrome\n";
}