

/*
 *   author: brownFalcon
 */
#include<iostream>
using namespace std;

const int capacity = 5;
int queue[capacity];

int front = -1;
int rear = -1;

bool enqueue(int val)
{
    if(front==-1)
    {
        ///Queue empty
        front=rear=0;
        queue[rear]=val;
        return true;
    }
    else if(rear==capacity-1)
    {
        ///Queue full
        return false;
    }
    else
    {
        ///normal case
        rear++;
        queue[rear]=val;
        return true;
    }
}
bool isEmpty()
{
    if(front==-1 || rear==-1)
    {
        return true;
    }
    else
    {
        false;
    }
}
int peek()

{
    return queue[front];
}
int dequeue()
{
    int temp=queue[front];
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        front++;
    }
    return temp;
}

bool isFull()
{
    if(rear-front==capacity-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void clear()
{  front=-1;
rear=-1;
}
void print()
{
    if(front==-1)
        cout<<"Queue is empty!!"<<"\n";
    else
    {
        for(int i=front; i<=rear; i++)
        {
            cout<<queue[i]<<" ";
        }
        cout<<"\n";
    }
}


int main()
{
    cout<<"The capacity of the queue is "<<capacity<<endl;;

    while(1)
    {
        cout<<"Select an option: "<<endl;
        cout<<"1. Enqueue"<<endl;
        cout<<"2. IsEmpty"<<endl;
        cout<<"3. Peek"<<endl;
        cout<<"4. Dequeue"<<endl;
        cout<<"5. IsFull"<<endl;
        cout<<"6. Clear"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"8. Print"<<endl;

        int x;
        cin>>x;
        if(x == 1)
        {
            cout<<"Enter a number:";
            int val;
            cin>>val;
            if(enqueue(val)==true)
            {
                cout<<"Inserted"<<"\12";
            }
            else
            {
                cout<<"Queue is full!!"<<"\n";
            }
        }
        else if(x == 2)
        {
            if(isEmpty()==true)
            {
                cout<<"Empty queue!!"<<"\n";
            }
            else
            {
                cout<<"Queue is not empty!!"<<"\n";
            }
        }
        else if(x == 3)
        {
            if(isEmpty()==true)
            {
                cout<<"Empty queue!!\n";
            }
            else
            {
                int val=peek();
                cout<<"First element :"<<val<<"\n";
            }
        }
        else if(x == 4)
        {
            if(isEmpty()==true)
            {
                cout<<"Queue is empty!!"<<"\n";
            }
            else
            {
                int val=dequeue();
                cout<<"First element is :"<<val<<"\n";
            }
        }
        else if(x == 5)
        {
            if(isFull()==true)
            {
                cout<<"Queue is full!!"<<"\n";
            }
            else
            {
                cout<<"Queue is not full!!"<<"\n";
            }
        }
        else if(x == 6)
        {
           clear();
        }
        else if(x == 7)
            break;
        else if(x==8)
            print();
        else
            cout<<"Invalid option!!!"<<endl;
    }

    return 0;

}


