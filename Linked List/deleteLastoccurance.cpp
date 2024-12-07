#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node()
    {
        next = nullptr;
    }
};

class DoublyLinkedList
{
    Node *head;

public:
    DoublyLinkedList()
    {
        head = nullptr;
    }
    void create(int n)
    {
        int data;
        Node *temp = new Node;
        for (int i = 0; i < n; i++)
        {
            cout << "\nEnter the value of the node " << i + 1 << ": ";
            cin >> data;
            Node *newNode = new Node;
            newNode->val = data;
            if (head == nullptr)
            {
                head = newNode;
                temp = head;
            }
            else
            {
                temp->next = newNode;
                temp = newNode;
            }
        }
    }

    void deleteLastoccurance(int num)
    {
        Node *temp = head;
        Node *temp2 = head;
        while (temp != nullptr)
        {
            if (temp->val == num)
                temp2 = temp;
            temp = temp->next;
        }
        Node *temp3 = head;
        while (temp3->next != temp2)
        {
            temp3 = temp3->next;
        }
        if (temp2 == head)
        {
            if(head->next!=nullptr) head = head->next;
            delete temp2;
            temp2 = nullptr;
        }
        else
        {
            if (temp2->next != nullptr)
                temp3->next = temp2->next;
            delete temp2;
            temp2 = nullptr;
        }
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->val << ' ';
            temp = temp->next;
        }
        cout << "\n";
    }
};
int main()
{
    int n, index;
    cout << "Enter the number of nodes: ";
    cin >> n;
    DoublyLinkedList dll;
    dll.create(n);

    cout << "\nEnter the number whose last occurance is to be deleted: ";
    cin >> index;
    dll.deleteLastoccurance(index);
    dll.display();
}
