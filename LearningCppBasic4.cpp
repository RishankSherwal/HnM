#include <iostream>
using namespace std;

class Number {
private:
    int value;

public:
    // Function to take input
    void input() {
        cout << "Enter value: ";
        cin >> value;
    }

    // Function to add two objects and store result in current object
    void add(Number a, Number b) {
        value = a.value + b.value;
    }

    // Function to display value
    void display() {
        cout << "Result: " << value << endl;
    }
};

int main() {
    Number obj1, obj2, obj3;

    cout << "Object 1\n";
    obj1.input();

    cout << "Object 2\n";
    obj2.input();

    // Passing obj1 and obj2 as arguments
    obj3.add(obj1, obj2);

    // Displaying result stored in obj3
    obj3.display();

    return 0;
}
