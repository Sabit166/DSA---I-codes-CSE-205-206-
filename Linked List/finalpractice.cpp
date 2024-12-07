#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int val;
    Node* next;
    Node* prev;
    Node()
    {
        next = NULL;
        prev = NULL;
    }
    Node(int n)
    {
        val = n;
        next = NULL;
        prev = NULL;
    }
};

class LL
{
    public:
    Node *head;
    Node *tail;
    LL()
    {
        head = NULL;
        tail = NULL;
    }

    void insert(int n)
    {
        Node *newNode = new Node(n);
        if(!head)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev=tail;
        tail=newNode;
    }

    void delet(int pos)
    {
        if(!head)
        {
            cout << "\nLinked List is empty.";
            return;
        }

        Node* temp = head;
        if(temp == head)
        {
            if(!head->next)
            {
                delete head;
                head = NULL;
                tail = NULL;
            }

            head = head->next;
            delete temp;
            temp = NULL;
            return;
        }




        for(int i=0;i<pos-2;i++)
        {
            temp = temp->next;

            if(!temp->next)
            {
                cout << "\nInvalid position";
                return;
            }
        }


        
        Node* del = temp->next;

        if(del == tail)
        {
            tail = tail->prev;
            delete del;
            del = NULL;
        }

        del->next->prev= temp;
        temp->next = del->next;

        delete del;
        del = NULL;
    }

    void sorted_concate(LL list)
    {
        Node* temp1 = head, *temp2 = list.head;
        while(temp2)
        {
            Node *newNode = new Node(temp2->val);
            if(!head) head = newNode;
            else if(!head->next)
            {
                if(temp2->val<head->val)
                {
                    newNode->next = head;
                    head->prev = newNode;
                    head = newNode;
                }
                else
                {
                    head->next = newNode;
                    newNode->prev = head;
                }
            }
            else
            {
                while(temp1->next)
                {
                    if(temp2->val<temp1->next->val)
                    {
                        temp1->next->next->prev = newNode;
                        newNode->next = temp1->next;
                        temp1->next = newNode;
                        newNode->prev = temp1;
                        return;
                    }
                    temp1->next = newNode;
                    newNode->prev = temp1;
                    temp1=temp1->next;
                }
            }
            temp2=temp2->next;
        }
    }
};

int main()
{

}