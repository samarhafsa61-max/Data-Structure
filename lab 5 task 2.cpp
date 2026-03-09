#include <iostream>
using namespace std;

struct Node
{
    float rain;
    Node* prev;
    Node* next;
};

Node* head = NULL;

// create node
Node* createNode(float value)
{
    Node* newNode = new Node();
    newNode->rain = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// insert at end
void insertEnd(float value)
{
    Node* newNode = createNode(value);

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// display rainfall
void display()
{
    Node* temp = head;
    int day = 1;

    while(temp != NULL)
    {
        cout<<"Day "<<day<<" Rainfall: "<<temp->rain<<endl;
        temp = temp->next;
        day++;
    }
}

// calculations
void calculate()
{
    Node* temp = head;

    float total = 0;
    float max = head->rain;
    float min = head->rain;

    int day = 1;
    int maxDay = 1;
    int minDay = 1;

    while(temp != NULL)
    {
        total += temp->rain;

        if(temp->rain > max)
        {
            max = temp->rain;
            maxDay = day;
        }

        if(temp->rain < min)
        {
            min = temp->rain;
            minDay = day;
        }

        temp = temp->next;
        day++;
    }

    cout<<"\nTotal Rainfall = "<<total<<endl;
    cout<<"Average Rainfall = "<<total/7<<endl;
    cout<<"Highest Rainfall on Day "<<maxDay<<" = "<<max<<endl;
    cout<<"Lowest Rainfall on Day "<<minDay<<" = "<<min<<endl;
}

// rainfall after 5th node
void rainfallAfter5th()
{
    Node* temp = head;

    int count = 1;

    while(temp != NULL && count < 6)
    {
        temp = temp->next;
        count++;
    }

    if(temp != NULL)
        cout<<"Rainfall after 5th node (Day 6) = "<<temp->rain<<endl;
    else
        cout<<"No node after 5th"<<endl;
}

int main()
{
    float rain;

    cout<<"Enter rainfall for 7 days\n";

    for(int i=1;i<=7;i++)
    {
        do
        {
            cout<<"Day "<<i<<": ";
            cin>>rain;

            if(rain < 0)
                cout<<"Negative rainfall not allowed. Enter again.\n";

        } while(rain < 0);

        insertEnd(rain);
    }

    cout<<"\nRainfall Data\n";
    display();

    calculate();

    rainfallAfter5th();

    return 0;
}
