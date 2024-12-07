#include <iostream>
using namespace std;

class linkedList
{
public:
    int data;
    linkedList *next;
    linkedList *previous;
};

int main()
{
    linkedList *head = new linkedList();
    linkedList *tail = new linkedList();
    head->next = nullptr;
    tail->previous = nullptr;
    linkedList *temp = head;
    int element_count, data;
    cout << "Please enter the number of elements\n";
    cin >> element_count;
    cout << "Please enter the datas:\n";
    for (int i = 0; i < element_count; i++)
    {
        linkedList *ptr = new linkedList();
        cin >> data;
        ptr->data = data;
        temp->next = ptr;
        ptr->previous = temp;
        if (i == 0)
            ptr->previous = nullptr;
        temp = ptr;
        temp->next = nullptr;
    }
    tail->previous = temp;

    cout << "The elements of the linked list are as follows:\n";

    temp = tail->previous;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->previous;
    }
    cout << "\n\n";

    int index1, index2;
    cout << "Enter the two nodes to be swapped\n";
    cin >> index1 >> index2;
    linkedList *node1 = head;
    linkedList *node2 = head;
    for (int i = 0; i < index1; i++)
    {
        node1 = node1->next;
    }
    for (int i = 0; i < index2; i++)
    {
        node2 = node2->next;
    }

    linkedList *temp1 = node1->next;
    linkedList *temp2 = node1->previous;
    node1->next = node2->next;
    node1->previous = node2->previous;
    node2->next = temp1;
    node2->previous = temp2;

    if (node1->next != nullptr)
        node1->next->previous = node1;
    else
        tail->previous = node1;
    if (node1->previous != nullptr)
        node1->previous->next = node1;
    else
        head->next = node1;
    if (node2->next != nullptr)
        node2->next->previous = node2;
    else
        tail->previous = node2;
    if (node2->previous != nullptr)
        node2->previous->next = node2;
    else
        head->next = node2;
    temp = head->next;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    temp = head;
    while (temp != nullptr)
    {
        linkedList *nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    return 0;
}
