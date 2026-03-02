#include <iostream>
using namespace std;

// ================= MOBILE CLASS =================
class Mobile {
private:
    string name;
    int unitsOnHand;
    double price;

public:
    // Constructor
    Mobile(string n = "", int u = 0, double p = 0.0) {
        name = n;
        unitsOnHand = u;
        price = p;
    }

    // Setters
    void setName(string n) {
        name = n;
    }

    void setUnits(int u) {
        unitsOnHand = u;
    }

    void setPrice(double p) {
        price = p;
    }

    // Getters
    string getName() {
        return name;
    }

    int getUnits() {
        return unitsOnHand;
    }

    double getPrice() {
        return price;
    }
};

// ================= STORE CLASS (Linked List) =================
class Store {
private:
    struct Node {
        Mobile data;
        Node* next;
    };

    Node* head;

public:
    // Constructor
    Store() {
        head = NULL;
    }

    // Insert Mobile at end
    void insertMobile(string name, int units, double price) {
        Node* newNode = new Node;
        newNode->data = Mobile(name, units, price);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Delete Mobile by name
    void deleteMobile(string name) {
        if (head == NULL) {
            cout << "Store is empty.\n";
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        // If first node matches
        if (temp->data.getName() == name) {
            head = temp->next;
            delete temp;
            cout << "Mobile deleted successfully.\n";
            return;
        }

        // Search for node
        while (temp != NULL && temp->data.getName() != name) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Mobile not found.\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "Mobile deleted successfully.\n";
    }

    // Display all mobiles
    void displayMobiles() {
        if (head == NULL) {
            cout << "No mobiles available.\n";
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            cout << "Brand: " << temp->data.getName() << endl;
            cout << "Units: " << temp->data.getUnits() << endl;
            cout << "Price: " << temp->data.getPrice() << endl;
            cout << "---------------------\n";
            temp = temp->next;
        }
    }
};

// ================= MAIN FUNCTION =================
int main() {
    Store store;

    // Insert mobiles
    store.insertMobile("Samsung", 10, 85000);
    store.insertMobile("Apple", 5, 250000);
    store.insertMobile("Oppo", 20, 50000);

    cout << "\nAll Mobiles in Store:\n";
    store.displayMobiles();

    // Delete one mobile
    cout << "\nDeleting Apple...\n";
    store.deleteMobile("Apple");

    cout << "\nUpdated List:\n";
    store.displayMobiles();

    return 0;
}

