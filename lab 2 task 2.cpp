#include <iostream>
using namespace std;

// Function to swap two numbers using pointers
void swapNumbers(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;

    cout << "Before swapping:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    swapNumbers(&x, &y);   // passing addresses

    cout << "After swapping:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}

