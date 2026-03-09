#include <iostream>
using namespace std;

struct Node
{
    string name;
    int score;
    Node* next;
    Node* prev;
};

Node* head = NULL;

// Create Node
Node* createNode(string name, int score)
{
    Node* newNode = new Node();
    newNode->name = name;
    newNode->score = score;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Insert player in sorted order (ascending score)
void addPlayer(string name, int score)
{
    Node* newNode = createNode(name, score);

    if(head == NULL || score < head->score)
    {
        newNode->next = head;
        if(head != NULL)
            head->prev = newNode;
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL && temp->next->score < score)
        temp = temp->next;

    newNode->next = temp->next;

    if(temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
    newNode->prev = temp;
}

// Delete player by name
void deletePlayer(string name)
{
    Node* temp = head;

    while(temp != NULL && temp->name != name)
        temp = temp->next;

    if(temp == NULL)
    {
        cout<<"Player not found\n";
        return;
    }

    if(temp == head)
        head = head->next;

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    if(temp->prev != NULL)
        temp->prev->next = temp->next;

    delete temp;

    cout<<"Player deleted\n";
}

// Display all players
void display()
{
    Node* temp = head;

    cout<<"\nPlayers List\n";

    while(temp != NULL)
    {
        cout<<temp->name<<" - "<<temp->score<<endl;
        temp = temp->next;
    }
}

// Display lowest score
void lowestScore()
{
    if(head != NULL)
        cout<<"Lowest Score Player: "<<head->name<<" Score: "<<head->score<<endl;
}

// Display players with same score
void sameScore(int score)
{
    Node* temp = head;
    bool found = false;

    while(temp != NULL)
    {
        if(temp->score == score)
        {
            cout<<temp->name<<" - "<<temp->score<<endl;
            found = true;
        }

        temp = temp->next;
    }

    if(!found)
        cout<<"No players with this score\n";
}

// Display backward from a player
void displayBackward(string name)
{
    Node* temp = head;

    while(temp != NULL && temp->name != name)
        temp = temp->next;

    if(temp == NULL)
    {
        cout<<"Player not found\n";
        return;
    }

    cout<<"Players behind "<<name<<":\n";

    temp = temp->prev;

    while(temp != NULL)
    {
        cout<<temp->name<<" - "<<temp->score<<endl;
        temp = temp->prev;
    }
}

int main()
{
    int choice, score;
    string name;

    do
    {
        cout<<"\n1 Add Player";
        cout<<"\n2 Delete Player";
        cout<<"\n3 Display All Players";
        cout<<"\n4 Display Lowest Score";
        cout<<"\n5 Display Players with Same Score";
        cout<<"\n6 Display Backward From Player";
        cout<<"\n0 Exit";
        cout<<"\nEnter choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"Enter Player Name: ";
                cin>>name;
                cout<<"Enter Score: ";
                cin>>score;
                addPlayer(name, score);
                break;

            case 2:
                cout<<"Enter Player Name to Delete: ";
                cin>>name;
                deletePlayer(name);
                break;

            case 3:
                display();
                break;

            case 4:
                lowestScore();
                break;

            case 5:
                cout<<"Enter Score: ";
                cin>>score;
                sameScore(score);
                break;

            case 6:
                cout<<"Enter Player Name: ";
                cin>>name;
                displayBackward(name);
                break;
        }

    }while(choice != 0);

    return 0;
}
