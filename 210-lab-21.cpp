#include <iostream>
#include <cstdlib>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class DoublyLinkedList
{
private:
    class Goat
    { // Replace node struct with Goat class.
        int age;
        string name;
        string color;
        string names[15] {"Billy", "Nanny", "Gruff",
             "Daisy", "Charlie", "Luna", "Max", "Bella",
             "Rocky", "Molly", "Jack", "Lucy", "Toby", "Sophie", "Oscar"};
        string colors[15] {"White", "Black", "Brown", "Gray", "Spotted",
             "Striped", "Golden", "Cream", "Red", "Blue",
             "Green", "Yellow", "Purple", "Pink", "Orange"};
        public: // Public members of the Goat class. Allows 
        Goat *prev; // Previous pointer
        Goat *next; // Next pointer
        Goat(Goat *p = nullptr, Goat *n = nullptr)
        { // Default constructor to initialize a Goat with random attributes.
            age = rand() % 20 + 1; // Random age between 1 and 20.
            name = names[rand() % 15]; // Random name from the list.
            color = colors[rand() % 15]; // Random color from the list.
            prev = p;
            next = n;
        }
        Goat(int a, string n, string c, Goat *p = nullptr, Goat *nxt = nullptr)
        {// Parameter constructor to initialize a Goat with specific attributes.
            age = a;
            name = n;
            color = c;
            prev = p;
            next = nxt;
        }
    };

    Goat *head; // Head pointer
    Goat *tail; // Tail pointer

public:
    // constructor
    DoublyLinkedList() // Initializes an empty list by setting head and tail to nullptr.
    {
        head = nullptr;
        tail = nullptr;
    }
// Replacing all functions with versions that handle Goat objects instead of integers.
    void push_back(Goat g)
    {
        Goat *newGoat = new Goat(g);
        if (!tail) // if there's no tail, the list is empty
            head = tail = newGoat;
        else
        {
            tail->next = newGoat;
            newGoat->prev = tail;
            tail = newGoat;
        }
    }

    void push_front(Goat g)
    {
        Goat *newGoat = new Goat(g);
        if (!head) // if there's no head, the list is empty
            head = tail = newGoat;
        else
        {
            newGoat->next = head;
            head->prev = newGoat;
            head = newGoat;
        }
    }

    void insert_after(Goat g, int position)
    {
        if (position < 0) // Validates the position input to ensure it's non-negative.
        {
            cout << "Position must be >= 0." << endl;
            return;
        }

        Goat *newGoat = new Goat(g);
        if (!head)
        {
            head = tail = newGoat;
            return;
        }

        Goat *temp = head;
        for (int i = 0; i < position && temp; ++i) // Traverses the list to find the node after which the new node will be inserted.
            temp = temp->next;

        if (!temp) // If position exceeds list size, insert at the end.
        {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newGoat;
            return;
        }

        newGoat->next = temp->next;
        newGoat->prev = temp;
        if (temp->next) // If there's a node after temp, update its prev pointer to the new node.
            temp->next->prev = newGoat;
        else // If temp is the tail, update the tail pointer to the new node.
            tail = newGoat; // Inserting at the end.
        temp->next = newGoat;
    }

    void delete_node(Goat )
    {
        if (!head)
            return; // Empty list

        Node *temp = head;
        while (temp && temp->data != value)
            temp = temp->next;

        if (!temp)
            return; // Value not found

        if (temp->prev)
        {
            temp->prev->next = temp->next;
        }
        else
        {
            head = temp->next; // Deleting the head
        }

        if (temp->next)
        {
            temp->next->prev = temp->prev;
        }
        else
        {
            tail = temp->prev; // Deleting the tail
        }

        delete temp;
    }

    void print()
    {
        Node *current = head;
        if (!current)
            return;
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse()
    {
        Node *current = tail;
        if (!current)
            return;
        while (current)
        {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    ~DoublyLinkedList()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Driver program
int main()
{
    DoublyLinkedList list;
    int size = rand() % (MAX_LS - MIN_LS + 1) + MIN_LS;

    for (int i = 0; i < size; ++i)
        list.push_back(rand() % (MAX_NR - MIN_NR + 1) + MIN_NR);
    cout << "List forward: ";
    list.print();

    cout << "List backward: ";
    list.print_reverse();

    cout << "Deleting list, then trying to print.\n";
    list.~DoublyLinkedList();
    cout << "List forward: ";
    list.print();

    return 0;
}