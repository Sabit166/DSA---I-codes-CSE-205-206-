#include <iostream>
#include <stdio.h>
using namespace std;
class DynamicArray
{
    int *d_array;
    int max_size;
    int length;

public:
    DynamicArray()
    {
        max_size = 2;
        d_array = new int[max_size];
        length = 0;
    }
    void add(int item)
    {
        if (max_size == length)
        {
            cout << "Max size doubled" << endl;
            max_size *= 2;
            int *temp_array = new int[max_size];
            for (int i = 0; i < length; i++)
            {
                temp_array[i] = d_array[i];
            }
            delete[] d_array;
            d_array = temp_array;
        }
        d_array[length] = item;
        length++;
    }
    void del(int position)
    {
        if (length == 0)
        {
            cout << "The array list is currently empty."
                 << "\n\n";
        }
        else
        {
            if (position >= length || position < 0)
            {
                cout << "Not possible" << endl;
            }
            else
            {

                for (int i = position; i < length; i++)
                {
                    d_array[i] = d_array[i + 1];
                }
                length--;
            }
        }
        if (length <= max_size / 2)
        {
            cout << "Max size reduced." << endl;
            int *temp_array = new int[max_size / 2];
            max_size = max_size / 2;
            for (int i = 0; i < length; i++)
            {
                temp_array[i] = d_array[i];
            }
            delete[] d_array;
            d_array = temp_array;
        }
    }
    void inst(int val, int position)
    {
        if (position < 0 && position >= length)
        {
            cout << "Not Possible" << endl;
        }
        else
            d_array[position] = val;
    }
    void match(int val)
    {
        for (int i = 0; i < length; i++)
        {
            if (val == d_array[i])
            {
                del(i);
            }
        }
    }
    void rep(int val, int r)
    {
        for (int i = 0; i < length; i++)
        {
            if (d_array[i] == val)
            {
                d_array[i] = r;
            }
        }
    }
    void printd_array()
    {
        for (int i = 0; i < length; i++)
            cout << d_array[i] << " ";
        cout << endl;
    }
    ~DynamicArray()
    {
        delete[] d_array;
    }
};


int main()
{
    DynamicArray dal;

    int a, choice;
    cout << "\t\tDynamic Array d_array Implementation using Template Class.\n\t\t\tDo menu options 3-7 on your own.";

    while (1)
    {

        cout << "\n1.Add an element\n2.See current Elements";
        cout << "\n3.Delete element from a particular position\n4.Insert at a particular position\n5.Delete matching values\n6.Replace matching values\n\nPress any other key to terminate the program. ";
        cout << "\n\nEnter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "\nEnter a num to add: ";
            cin >> a;
            dal.add(a);

            cout << "The current dynamic array is: ";
            dal.printd_array();
        }

        else if (choice == 2)
        {
            cout << "The current dynamic array is: ";
            dal.printd_array();
        }

        else if (choice == 3)
        {
            cout << "\nEnter the position from where you want to delete: ";
            cin >> a;
            dal.del(a);

            cout << "The current dynamic array is: ";
            dal.printd_array();
        }

        else if (choice == 4)
        {
            int a, pos;
            cout << "Enter the value : " << endl;
            cin >> a;
            cout << "Enter the position : " << endl;
            cin >> pos;
            dal.inst(a, pos);
            dal.printd_array();
            // do by yourself
            // Let the user insert a value into a particular position in the DAL.
        }
        else if (choice == 5)
        {
            // do by yourself
            // Delete ALL matching values. Resize the Dynamic array as per the algorithm shown in class
            // think when it ll be resized carefully
            int a;
            cout << "Enter the value : " << endl;
            cin >> a;
            dal.match(a);
            dal.printd_array();
        }
        else if (choice == 6)
        {
            // do by yourself
            // Replace ALL matching values.

            // There may be two cases as shown in the sample input-output.
            int a, b;
            cout << "Enter the value : " << endl;
            cin >> a;
            cout << "Enter the replace value : " << endl;
            cin >> b;
            dal.rep(a, b);
            dal.printd_array();
        }
        else
        {
            printf("\n\t\tProgram Terminated\n\n");
            break;
        }
    }

    return 0;
}