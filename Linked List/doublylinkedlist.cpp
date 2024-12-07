#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *previous;

    Node()
    {
        next=nullptr;
        previous=nullptr;
    }
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void createList(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            Node *newNode = new Node;
            int val;
            cout << "Node " << i << ": ";
            cin >> val;
            newNode->data = val;
            if(head == NULL)
            {
                head = newNode;
                tail=head;
            }
            else
            {
                tail->next=newNode;
                newNode->previous=tail;
                tail=newNode;
            }
        }
        cout << "\n\n";
    }

    void insertFirst(int val)
    {
        Node *newNode = new Node;
        newNode->data = val;
        newNode->next = head;
        head->previous=newNode;
        head = newNode;
        cout << "Successfully inserted!\n\n";
    }

    void insertLast(int val)
    {
        Node *newNode = new Node;
        newNode->data = val;
        tail->next=newNode;
        newNode->previous=tail;
        tail = newNode;
        cout << "Successfully inserted!\n\n";
    }

    void insertAt(int pos, int val)
    {
        if (pos == 1)
            insertFirst(val);
        else
        {
            Node *newNode = new Node;
            newNode->data = val;
            Node *temp = head;
            for (int i = 2; i < pos; i++)
            {
                if (temp == nullptr)
                {
                    cout << "Insertion not possible\n";
                    return;
                }
                temp = temp->next;
            }
            if(temp==tail) insertLast(val);
            newNode->next = temp->next;
            temp->next->previous=newNode;
            temp->next = newNode;
            newNode->previous=temp;
            cout << "Successfully inserted!\n\n";
        }
    }

    void deleteFirst()
    {
        if (head == nullptr)
        {
            cout << "No list is created!\n";
        }
        else if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            cout << "Successfully Deleted!\n\n";
        }
        else
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            cout << "Successfully Deleted!\n\n";
        }
    }

    void deleteLast()
    {
        if (head == nullptr)
        {
            cout << "No list is created!\n";
        }
        else if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            cout << "Successfully Deleted!\n\n";
        }
        else
        {
            cout << tail->data << endl;
            Node *temp = tail;
            tail=tail->previous;
            tail->next=nullptr;
            delete temp;
            cout << "Successfully Deleted!\n\n";
        }
    }

    void deleteAt(int pos)
    {
        if (head == nullptr)
        {
            cout << "No list exists!\n";
            return;
        }
        if (pos == 1)
        {
            deleteFirst();
            return;
        }
        Node *temp = head;
        for (int i = 2; i < pos; i++)
        {
            if (temp->next == nullptr)
            {
                cout << "Deletion not possible\n";
                return;
            }
            temp = temp->next;
        }
        if(temp==tail) deleteLast();
        Node *toDelete = temp->next;
        temp->next = temp->next->next;
        toDelete->next->previous=temp;
        delete toDelete;
        cout << "Successfully Deleted!\n\n";
    }

    void printList()
    {
        if (head == nullptr)
        {
            cout << "No list!!\n";
        }
        else
        {
            cout << "List: ";
            Node *temp = head;
            while (temp != nullptr)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << "\n\n";
        }
    }

    int search(int val)
    {
        if (head == nullptr)
        {
            return -1;
        }
        else
        {
            Node *temp = head;
            int index = 1;
            while (temp != nullptr)
            {
                if (temp->data == val)
                {
                    return index;
                }
                index++;
                temp = temp->next;
            }
            return 0;
        }
    }

    void freeTheList()
    {
        Node *temp = head;
        while (head != nullptr)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    cout << "Enter the number of elements in the list: ";
    int n;
    cin >> n;
    cout << "Create the list\n";
    DoublyLinkedList list;
    list.createList(n);
    list.printList();
    cout << "A singly linked list is being created!\n";

    while (true)
    {
        cout << "1. Insert First\n";
        cout << "2. Insert Last\n";
        cout << "3. Insert At\n";
        cout << "4. Delete First\n";
        cout << "5. Delete Last\n";
        cout << "6. Delete At\n";
        cout << "7. Search\n";
        cout << "8. Print List\n";
        cout << "9. Exit\n";
        cout << "Enter Choice: ";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter the element: ";
            int val;
            cin >> val;
            list.insertFirst(val);
        }
        else if (choice == 2)
        {
            cout << "Enter the element: ";
            int val;
            cin >> val;
            list.insertLast(val);
        }
        else if (choice == 3)
        {
            cout << "Enter the position: ";
            int pos;
            cin >> pos;
            cout << "Enter the element: ";
            int val;
            cin >> val;
            list.insertAt(pos, val);
        }
        else if (choice == 4)
            list.deleteFirst();
        else if (choice == 5)
            list.deleteLast();
        else if (choice == 6)
        {
            cout << "Enter the position: ";
            int pos;
            cin >> pos;
            list.deleteAt(pos);
        }
        else if (choice == 7)
        {
            cout << "Enter the value: ";
            int val;
            cin >> val;
            int pos = list.search(val);
            if (pos == -1)
                cout << "No list exists!\n";
            else if (pos)
                cout << "Position: " << pos << "\n\n";
            else
                cout << "Item not found in the list\n";
        }
        else if (choice == 8)
            list.printList();
        else if (choice == 9)
            break;
        else
            cout << "Wrong Choice Input!!\n\n";
    }
    list.freeTheList();
    return 0;
}
