#include <iostream>
#include <string>
using namespace std;
class ContactManager
{
private:
    struct Contact
    {
        string name;
        string phoneNumber;
    };
    Contact *contacts; // Pointer to dynamic array of contacts
    int capacity;      // Current capacity of the dynamic array
    int size;          // Current number of contacts in the array
public:
    ContactManager()
    {
        capacity = 2;                     // Initial capacity
        size = 0;                         // No contacts initially
        contacts = new Contact[capacity]; // Allocate memory
    }
    ~ContactManager()
    {
        delete[] contacts; // Free allocated memory
    }
    void addContact()
    {
        string n, p;
        cout << "Enter name of the contact\n";
        cin >> n;
        cout << "Enter phone number of the contact\n";
        cin >> p;
        if (capacity == size)
        {
            capacity *= 2;
            Contact *temp = new Contact[capacity];
            for (int i = 0; i < size; i++)
            {
                temp[i] = contacts[i];
            }
            delete[] contacts;
            contacts = temp;
        }
        contacts[size].name = n;
        contacts[size].phoneNumber = p;
        size++;
    }
    void searchContact()
    {
        bool t=false;
        cout << "Enter name you want to search: ";
        string n;
        cin >> n;
        for (int i = 0; i < size; i++)
        {
            if (contacts[i].name == n)
            {
                cout << "Contact Found!\n";
                cout << "Name: " << contacts[i].name << "\nPhone Number: " << contacts[i].phoneNumber << endl;
                t=true;
                return;
            }
        }
        cout << "Contact not found\n"; 
    }
    void displayAllContacts()
    {
        for(int i=0;i<size;i++)
        {
            cout << "Name: " << contacts[i].name << endl;
            cout << "Phone Number: " << contacts[i].phoneNumber << endl;
        }
    }
};
int main()
{
    ContactManager cm;
    while (true)
    {
        cout << "\nChoices:" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Search Contact" << endl;
        cout << "3. Display All Contacts" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            cm.addContact();
        }
        if (choice == 2)
        {
            cm.searchContact();
        }
        if (choice == 3)
        {
            cm.displayAllContacts();
        }
    }
    return 0;
}