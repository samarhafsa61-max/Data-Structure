  #include <iostream>
using namespace std;

int main() {
    char* ch = new char;

    cout << "Enter a character: ";
    cin >> *ch;

    cout << "Stored character is: " << *ch << endl;

    delete ch;
    ch = NULL;   

    return 0;
}

