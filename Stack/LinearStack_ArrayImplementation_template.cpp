#include<bits/stdc++.h>

using namespace std;

class Stack{
    int top;
    int capacity;
    int *arr;
public:
    Stack(int n){
        top=-1;
        capacity=n;
        arr=new int[capacity];
    }
    bool isStackFull(){
        return top==capacity-1;
    }

    bool isStackEmpty(){
        return top==-1;
    }

    void push(int value){
        if(isStackFull())
        {
            cout << "Stack is full\n";
            return;
        }
        arr[++top]=value;
        cout << "Element pushed.\n";
    }

    void pop(){
        if(isStackEmpty())
        {
            cout << "Stack is empty\n";
            return;
        }
        top--;
    }

    void sizeofStack(){
        cout << "Size of stack is " << top+1 << endl;
    }

    void printStack(){
        cout << "The stack: ";
        for(int i=top;i>=0;i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void peek()
    {
        if(isStackEmpty())
        {
            cout << "Stack is empty\n";
            return;
        }
        cout << "The top element is " << arr[top] << endl;
    }
};



int main(){

    int choice, n, value;
    bool x=true;
    cout<<"Enter the size of Stack: ";
    cin>>n;
    Stack stk(n);
    while(x){

    cout<<endl;
    cout<<"0 - Exit."<<endl;
    cout<<"1 - Push Item."<<endl;
    cout<<"2 - Pop Item."<<endl;
    cout<<"3 - Count Number of Items."<<endl;
    cout<<"4 - Display Items (Print STACK)."<<endl;
    cout<<"5 - Peek Item." << endl; 
    cout<<"Enter your choice: ";
    cin>>choice;

    switch(choice){
            case 0:
                x=false;
                break;

            case 1:
                cout<<"Enter Value:";
                cin>>value;
                stk.push(value);
                break;

            case 2:
                stk.pop();
                break;

            case 3:
                stk.sizeofStack();
                break;

            case 4:
                stk.printStack();
                break;

            case 5:
                stk.peek();
                break;
            
            default:
                cout<<"An Invalid choice."<<endl;
        }
    }

    return 0;
}
