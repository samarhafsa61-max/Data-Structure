#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

// Function to create node
Node* createNode(int value)
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Initialize list from user input
void createList(int n)
{
    int value;
    Node* temp;

    for(int i=1;i<=n;i++)
    {
        cout<<"Enter marks "<<i<<": ";
        cin>>value;

        Node* newNode = createNode(value);

        if(head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }
}

// Display list
void display()
{
    Node* temp = head;

    cout<<"List: ";

    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<endl;
}

// b) Insert at beginning
void addBeginning(int value)
{
    Node* newNode = createNode(value);

    if(head != NULL)
        head->prev = newNode;

    newNode->next = head;
    head = newNode;
}

// c) Insert after value 45
void addAfter45(int value)
{
    Node* temp = head;

    while(temp != NULL && temp->data != 45)
        temp = temp->next;

    if(temp == NULL)
    {
        cout<<"45 not found in list\n";
        return;
    }

    Node* newNode = createNode(value);

    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// d) Delete at beginning
void deleteBeginning()
{
    if(head == NULL)
    {
        cout<<"List is empty\n";
        return;
    }

    Node* temp = head;
    head = head->next;

    if(head != NULL)
        head->prev = NULL;

    delete temp;
}

// e) Delete node after value 45
void deleteAfter45()
{
    Node* temp = head;

    while(temp != NULL && temp->data != 45)
        temp = temp->next;

    if(temp == NULL || temp->next == NULL)
    {
        cout<<"Deletion not possible\n";
        return;
    }

    Node* del = temp->next;

    temp->next = del->next;

    if(del->next != NULL)
        del->next->prev = temp;

    delete del;
}

int main()
{
    int n,value;

    cout<<"Enter number of nodes: ";
    cin>>n;

    createList(n);

    display();

    cout<<"Enter value to insert at beginning: ";
    cin>>value;
    addBeginning(value);
    display();

    cout<<"Enter value to insert after 45: ";
    cin>>value;
    addAfter45(value);
    display();

    deleteBeginning();
    cout<<"After deleting beginning node\n";
    display();

    deleteAfter45();
    cout<<"After deleting node after 45\n";
    display();

    return 0;
}
