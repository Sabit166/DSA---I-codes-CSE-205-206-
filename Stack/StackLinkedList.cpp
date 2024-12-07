#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;

    Node(){
        next = NULL;
    }
};

int size=0;

class Stack{
private:
    Node *top;
    int SIZE;
public:
    Stack(){
        top = NULL;
        SIZE = 0;
    }

    void push(int n){
        Node *newNode=new Node;
        newNode->val= n;
        if(top==nullptr) top=newNode;
        else{
            newNode->next=top;
            top=newNode;
        }
        SIZE++;
    }

    bool isEmpty(){
        return top==nullptr;
    }

    void showTop(){
        if(!isEmpty()) cout << "Top value of the Stack is: " << top->val << endl;
        else cout << "The Stack is empty\n";
    }

    void pop(){
        if(top==nullptr)
        {
            cout<<"Stack is empty"<<endl;
            return;
        }
        Node *delNode=top;
        if(top->next) top=top->next;
        delete delNode;
        cout << "Item popped\n";
        SIZE--;
        if(SIZE==0) top=nullptr;
    }

    int size(){
        return SIZE;
    }

    void displaystack(){
        if(top==nullptr)
        {
            cout << "The stack is empty\n";
            return;
        }
        Node *temp=top;
        cout << "The Stack: ";
        while(temp!=nullptr)
        {
            cout << temp->val << ' ';
            temp=temp->next;
        }
        cout << "\n\n";
    }
};


int main(){
    Stack s;
    int choice;
    bool x=true;

    while(x)
    {
        cout<<"0 - Exit."<<endl;
        cout<<"1 - Push Item."<<endl;
        cout<<"2 - Pop Item."<<endl;
        cout<<"3 - View Top Item."<<endl;
        cout<<"4 - Size of Stack."<<endl;
        cout<<"5 - Display Items (Print STACK)."<<endl;

        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 0:
                x=false;
                break;

            case 1:
                cout << "\nEnter value to be pushed: ";
                int val;
                cin >> val;
                s.push(val);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.showTop();
                break;

            case 4:
            cout << "\nSize of Stack: " << s.size() << endl;
                break;

            case 5:
            s.displaystack();
                break;

            default:
                cout<<"An Invalid choice."<<endl;
        }

        cout<<endl<<endl;
    }


    return 0;
}
