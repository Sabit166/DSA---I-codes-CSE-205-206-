#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *l;
    Node *r;
    Node(int n)
    {
        val = n;
        l = NULL;
        r = NULL;
    }
};

class BinaryTree
{
    Node *root;
    queue<Node *> tree;

public:
    BinaryTree()
    {
        root = NULL;
    }

    void insert(int n)
    {
        Node *newNode = new Node(n), *current;
        if (!root)
        {
            root = newNode;
            tree.push(newNode);
            return;
        }
        if (tree.front()->r)
            tree.pop();
        current = tree.front();
        if (!current->l)
        {
            current->l = newNode;
            tree.push(newNode);
            return;
        }
        if (!current->r)
        {
            current->r = newNode;
            tree.push(newNode);
            return;
        }
    }

    void LevelOrderTraversal()
    {
        queue<Node *> tree1;
        if (root)
            tree1.push(root);
        Node *temp;
        while (!tree1.empty())
        {
            temp = tree1.front();
            tree1.pop();
            cout << temp->val << ' ';
            if (temp->l)
                tree1.push(temp->l);
            if (temp->r)
                tree1.push(temp->r);
        }
        cout << endl;
    }

    void InorderTraversal(Node *temp = NULL)
    {
        if (!root)
        {
            cout << "Tree not Formed\n";
            return;
        }
        if (!temp)
            return;
        InorderTraversal(temp->l);
        cout << temp->val << ' ';
        InorderTraversal(temp->r);
    }

    void PreorderTraversal(Node *temp)
    {
        if (!root)
        {
            cout << "Tree Not Formed\n";
            return;
        }
        if (!temp)
            return;
        cout << temp->val << ' ';
        PreorderTraversal(temp->l);
        PreorderTraversal(temp->r);
    }

    void PostorderTraversal(Node *temp)
    {
        if (!root)
        {
            cout << "Tree Not Created\n";
            return;
        }
        if (!temp)
            return;
        PostorderTraversal(temp->l);
        PostorderTraversal(temp->r);
        cout << temp->val << ' ';
    }

    Node *findNode(int n)
    {
        queue<Node *> qu;
        Node *temp = NULL;
        if (root)
            qu.push(root);
        while (!qu.empty())
        {
            temp = qu.front();
            qu.pop();
            if (temp->val == n)
                return temp;
            if (temp->l)
                qu.push(temp->l);
            if (temp->r)
                qu.push(temp->r);
        }
        return NULL;
    }

    int height(int node, Node *temp = NULL, int mx = 0)
    {
        if (mx == 0)
            temp = findNode(node);
        if (!temp)
            return mx - 1;
        return max(max(mx, height(node, temp->l, mx + 1)), max(mx, height(node, temp->r, mx + 1)));
    }

    int depth(int num, Node *temp = NULL, int mx = 0)
    {
        if (!findNode(num))
            return -1;
        if (mx == 0)
            temp = root;
        if (!temp)
            return 0;
        if (temp->val == num)
            return mx;
        return max(depth(num, temp->l, mx + 1), depth(num, temp->r, mx + 1));
    }

    void EulerOrderTraversal(Node *temp)
    {
        if (!root)
        {
            cout << "Tree not Formed\n";
            return;
        }
        if (!temp)
            return;
        cout << temp->val << ' ';
        EulerOrderTraversal(temp->l);
        if (temp->l)
            cout << temp->val << ' ';
        EulerOrderTraversal(temp->r);
        if (temp->r)
            cout << temp->val << ' ';
    }

    Node *getRoot() { return root; }
};

int main()
{
    BinaryTree tree;
    int choice, val;
    while (true)
    {
        cout << "Choose options\n1. insert tree value\n2. Level Order Traversal: \n3. Inorder Traversal: \n4. Preorder Traversal: \n5. postOrder Traversal: \n6. Find Height of a Node: \n7. Find level of a Node: \n8. Euler Order Traversal: \n\n";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter Node value\n";
            cin >> val;
            tree.insert(val);
        }
        else if (choice == 2)
        {
            tree.LevelOrderTraversal();
        }
        else if (choice == 3)
        {
            tree.InorderTraversal(tree.getRoot());
            cout << endl;
        }
        else if (choice == 4)
        {
            tree.PreorderTraversal(tree.getRoot());
            cout << endl;
        }
        else if (choice == 5)
        {
            tree.PostorderTraversal(tree.getRoot());
            cout << endl;
        }
        else if (choice == 6)
        {
            int node, x;
            cout << "Enter The Node you want to determine the Height: \n";
            cin >> node;
            x = tree.height(node);
            if (x == -1)
                cout << "Height Determination failed\n";
            else
                cout << "\nHeight of the node is " << x << "\n\n";
        }
        else if (choice == 7)
        {
            int node, x;
            cout << "Enter The Node you want to determine the Depth: \n";
            cin >> node;
            x = tree.depth(node);
            if (x == -1)
                cout << "Depth Determination failed\n";
            else
                cout << "\nDepth of the node is " << x << "\n\n";
        }
        else if (choice == 8)
        {
            tree.EulerOrderTraversal(tree.getRoot());
            cout << endl;
        }
        else
            break;
    }
}