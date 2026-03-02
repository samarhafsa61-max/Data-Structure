#include <iostream>
using namespace std;

// ================= PROFILE CLASS =================
class Profile {
private:
    int id;
    string name;
    string gender;
    int age;
    string email;
    string interest;
    string dob;

public:
    // Constructor
    Profile(int i = 0, string n = "", string g = "", int a = 0,
            string e = "", string in = "", string d = "") {
        id = i;
        name = n;
        gender = g;
        age = a;
        email = e;
        interest = in;
        dob = d;
    }

    // Setters
    void setProfile(int i, string n, string g, int a,
                    string e, string in, string d) {
        id = i;
        name = n;
        gender = g;
        age = a;
        email = e;
        interest = in;
        dob = d;
    }

    void updateProfile(string n, string g, int a,
                       string e, string in, string d) {
        name = n;
        gender = g;
        age = a;
        email = e;
        interest = in;
        dob = d;
    }

    // Getters
    int getID() { return id; }
    string getName() { return name; }

    // Display Function
    void display() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Gender: " << gender << endl;
        cout << "Age: " << age << endl;
        cout << "Email: " << email << endl;
        cout << "Interest: " << interest << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "---------------------------\n";
    }
};

// ================= PORTAL CLASS (Linked List) =================
class Portal {
private:
    struct Node {
        Profile data;
        Node* next;
    };

    Node* head;

public:
    Portal() {
        head = NULL;
    }

    // 1) Insert Profile
    void InsertProfile(int id, string name, string gender, int age,
                       string email, string interest, string dob) {

        Node* newNode = new Node;
        newNode->data = Profile(id, name, gender, age, email, interest, dob);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }

        cout << "Profile Added Successfully!\n";
    }

    // 2) Update Profile by ID
    void UpdateProfile(int id) {
        Node* temp = head;

        while (temp != NULL) {
            if (temp->data.getID() == id) {

                string name, gender, email, interest, dob;
                int age;

                cout << "Enter New Name: ";
                cin >> name;
                cout << "Enter Gender: ";
                cin >> gender;
                cout << "Enter Age: ";
                cin >> age;
                cout << "Enter Email: ";
                cin >> email;
                cout << "Enter Interest: ";
                cin >> interest;
                cout << "Enter Date of Birth: ";
                cin >> dob;

                temp->data.updateProfile(name, gender, age, email, interest, dob);

                cout << "Profile Updated Successfully!\n";
                return;
            }
            temp = temp->next;
        }

        cout << "Profile with ID not found.\n";
    }

    // 3) Delete Profile by Name
    void DeleteProfile(string name) {
        if (head == NULL) {
            cout << "No Profiles Available.\n";
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        if (temp->data.getName() == name) {
            head = temp->next;
            delete temp;
            cout << "Profile Deleted Successfully!\n";
            return;
        }

        while (temp != NULL && temp->data.getName() != name) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Profile Not Found.\n";
            return;
        }

        prev->next = temp->next;
        delete temp;

        cout << "Profile Deleted Successfully!\n";
    }

    // 4) Search Profile by Name
    void searchProfile(string name) {
        Node* temp = head;

        while (temp != NULL) {
            if (temp->data.getName() == name) {
                cout << "Profile Found:\n";
                temp->data.display();
                return;
            }
            temp = temp->next;
        }

        cout << "Profile Not Found.\n";
    }

    // 5) Display All
    void Display() {
        if (head == NULL) {
            cout << "No Profiles to Display.\n";
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            temp->data.display();
            temp = temp->next;
        }
    }
};

// ================= MAIN MENU =================
int main() {
    Portal portal;
    int choice;

    do {
        cout << "\n===== SOCIAL MEDIA PORTAL =====\n";
        cout << "1) Add New Profile\n";
        cout << "2) Update Profile\n";
        cout << "3) Delete Profile\n";
        cout << "4) Search Profile\n";
        cout << "5) Display All Profiles\n";
        cout << "6) Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        int id, age;
        string name, gender, email, interest, dob;

        switch (choice) {
        case 1:
            cout << "Enter ID: "; cin >> id;
            cout << "Enter Name: "; cin >> name;
            cout << "Enter Gender: "; cin >> gender;
            cout << "Enter Age: "; cin >> age;
            cout << "Enter Email: "; cin >> email;
            cout << "Enter Interest: "; cin >> interest;
            cout << "Enter Date of Birth: "; cin >> dob;

            portal.InsertProfile(id, name, gender, age, email, interest, dob);
            break;

        case 2:
            cout << "Enter ID to Update: ";
            cin >> id;
            portal.UpdateProfile(id);
            break;

        case 3:
            cout << "Enter Name to Delete: ";
            cin >> name;
            portal.DeleteProfile(name);
            break;

        case 4:
            cout << "Enter Name to Search: ";
            cin >> name;
            portal.searchProfile(name);
            break;

        case 5:
            portal.Display();
            break;

        case 6:
            cout << "Exiting Program...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}
