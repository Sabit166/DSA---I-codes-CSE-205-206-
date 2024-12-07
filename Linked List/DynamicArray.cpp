#include <bits/stdc++.h>
using namespace std;

class DynamicArray
{
    int *arr;
    int capacity;
    int size;

public:
    DynamicArray(int Cap)
    {
        capacity = Cap;
        size = 0;
        arr = new int[capacity];
    }

    void add(int num)
    {
        if (size == capacity)
        {
            cout << "Size of the array is being doubled\n";
            capacity *= 2;
            int *temp = new int[capacity];
            for (int i = 0; i < size; i++)
                temp[i] = arr[i];
            delete[] arr;
            arr = temp;
        }
        arr[size] = num;
        size++;
    }

    void delete_element(int position)
    {
        for (int i = position; i < size; i++)
            arr[i] = arr[i + 1];
        size--;
        if (size == capacity / 2)
        {
            cout << "Size of the array is being halved" << endl;
            capacity /= 2;
            int *temp = new int[capacity];
            for (int i = 0; i < size; i++)
                temp[i] = arr[i];
            delete[] arr;
            arr = temp;
        }
    }

    void insert_element(int num, int pos)
    {
        if (pos < 0 || pos > size)
        {
            cout << "Invalid position to insert number\n";
            return;
        }
        if (size == capacity)
        {
            cout << "Size of the array is being doubled" << endl;
            capacity *= 2;
            int *temp=new int[capacity];
            for (int i = 0; i < size; i++)
                temp[i] = arr[i];
            delete[] arr;
            arr = temp;
        }
        for (int i = size; i > pos; i--)
            arr[i] = arr[i - 1];
        arr[pos] = num;
        size++;
    }

    void delmatch(int num)
    {
        for (int i = 0; i < size; i++) if (arr[i] == num)
        {
            delete_element(i);
            i--;
        }
    }

    void replace(int num,int rep)
    {
        for(int i=0;i<size;i++) if(arr[i]==num) arr[i]=rep;
    }

    void display()
    {
        for(int i=0;i<size;i++) cout << arr[i] << ' ';
        cout << endl;
    }

    ~DynamicArray()
    {
        delete[] arr;
    }
};

int main()
{
    cout << "Dynamic Array implementation:\n";
    int choice,capacity;
    cout << "Enter Your choice:\n";
    cout << "1.Add an element\n";
    cout << "2.See current element:\n";
    cout << "3.Delete element from a particular position:\n";
    cout << "4.Insert at a particular position:\n";
    cout << "5.Delete matching element:\n";
    cout << "6.Replace matching values:\n\n\n";

    cout << "Please enter the initial capacity of the Array\n\n" << endl;
    cin >> capacity;
    DynamicArray arr(capacity);

    while (true)
    {
        cin >> choice;
        int num,pos,rep;
        switch (choice)
        {
        case 1:
            cout << "Select number to add\n";
            cin >> num;
            arr.add(num);
            break;
        case 2:
            arr.display();
            break;
        case 3:
            cout << "Select position to delete\n";
            cin >> pos;
            arr.delete_element(pos);
            break;
        case 4:
            cout << "Select position to insert\n";
            cin >> pos;
            cout << "Select number to insert\n";
            cin >> num;
            arr.insert_element(num, pos);
            break;
        case 5:
            cout << "Select number to delete\n";
            cin >> num;
            arr.delmatch(num);
            break;
        case 6:
            cout << "Select matching number\n";
            cin >> num;
            cout << "Select number to replace\n";
            cin >> rep;
            arr.replace(num, rep);
            break;
        default:
            cout << "You have selected default";
            break;
        }
    }
}