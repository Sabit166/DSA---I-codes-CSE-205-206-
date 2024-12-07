/*
 *   author: brownFalcon
 */
#include <iostream>
using namespace std;

class Node
{
public:
  int val;
  Node *next;
  Node *previous;
  Node()
  {
    next = nullptr;
    previous = nullptr;
  }
};
Node *head = nullptr, *tail = nullptr;

bool enqueue(int val)
{
  Node *newNode = new Node;
  if (head == nullptr)
  {
    head = tail = newNode;
    newNode->val = val;
  }
  else
  {
    tail->next = newNode;
    newNode->val = val;
    newNode->previous = tail;
    tail = tail->next;
  }
  cout << "Value inserted to Queue\n";
  return true;
}
bool isEmpty()
{
  return head == nullptr;
}
int peek()
{
  if (head != nullptr)
    cout << "The front value of the Queue is " << head->val << endl;
  else
    cout << "The Queue is empty\n";
}
int dequeue()
{
  if (isEmpty())
  {
    cout << "The Queue is empty!\n";
    return false;
  }
  Node *toDelete = new Node;
  toDelete = head;
  if (head != tail)
  {
    head = head->next;
    head->previous = nullptr;
    delete toDelete;
    toDelete = nullptr;
  }
  else
  {
    delete head;
    head = nullptr;
  }
  cout << "Front value of the Queue Deleted! \n";
  return true;
}
bool isFull()
{
  return false;
}
void clear()
{
  if (isEmpty())
  {
    cout << "The Queue is empty!\n";
    return;
  }
  Node *temp = new Node;
  Node *nextNode = nullptr;
  temp = head;
  while (temp != nullptr)
  {
    nextNode = temp->next;
    delete temp;
    temp = nullptr;
    temp = nextNode;
  }
  head=nullptr;
  cout << "The Queue is cleared \n";
}

int main()
{

  while (1)
  {
    cout << "Select an option: " << endl;
    cout << "1. Enqueue" << endl;
    cout << "2. IsEmpty" << endl;
    cout << "3. Peek" << endl;
    cout << "4. Dequeue" << endl;
    cout << "5. IsFull" << endl;
    cout << "6. Clear" << endl;
    cout << "7. Exit" << endl;

    int x;
    cin >> x;
    if (x == 1)
    {
      cout << "Enter the value: ";
      int val;
      cin >> val;
      if (enqueue(val))
      {
        cout << "The value has been successfully inserted into the queue." << endl;
      }
      else
      {
        cout << "Queue is Full!!" << endl;
      }
    }
    else if (x == 2)
    {
      if (isEmpty())
        cout << "The queue is empty!!!" << endl;
      else
        cout << "The queue is not empty!!!" << endl;
    }
    else if (x == 3)
    {
      if (isEmpty())
        cout << "The queue is empty!!!" << endl;
      else
      {
        int val = peek();
      }
    }
    else if (x == 4)
    {
      if (isEmpty())
        cout << "The queue is empty!!!" << endl;
      else
      {
        int val = dequeue();
      }
    }
    else if (x == 5)
    {
      if (isFull())
        cout << "The queue is full!!!" << endl;
      else
        cout << "The queue is not full!!!" << endl;
    }
    else if (x == 6)
    {
      clear();
      cout << "The queue has been cleared!!!" << endl;
    }
    else if (x == 7)
      break;
    else
      cout << "Invalid option!!!" << endl;
  }

  return 0;
}