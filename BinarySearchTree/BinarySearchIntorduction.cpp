#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int val;
    Node *left;
    Node *right;
    Node() { left=right=NULL; }
    Node(int val) { this->val=val,left=right=NULL; }
};

class BinarySearchTree
{
    Node *root;
    public:
    BinarySearchTree(){root=NULL;}

    void insert(int num)
    {
        Node *newNode=new Node(num);
        if(!root)
        {
            root=newNode;
            return;
        }
        Node *temp=root;
        while((temp->left && num<temp->val) || (temp->right && num>temp->val))
        {
            if(num<temp->val) temp=temp->left;
            else temp=temp->right;
        }
        if(num<temp->val) temp->left=newNode;
        else temp->right=newNode;
    }

    void traverse()
    {
        stack<Node*>st;
        Node *cur=root;
        while(!st.empty() || cur)
        {
            if(cur)
            {
                st.push(cur);
                cur=cur->left;
            }
            else
            {
                cur=st.top();
                cout << cur->val << ' ';
                st.pop();
                cur=cur->right;
            }
        }
        cout << endl;
    }
};

int main()
{
    BinarySearchTree tree;
    int choice,num;
    while(true)
    {
        cout << "\nChoose options: \n1.Insert Node: \n2. Level Order Traversal: \n";
        cin >> choice;
        if(choice==1)
        {
            cout << "\nEnter Node Value: ";
            cin >> num;
            tree.insert(num);
        }
        else if(choice==2)
        {
            tree.traverse();
        }
    } 
}