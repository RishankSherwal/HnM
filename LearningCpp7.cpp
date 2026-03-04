#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Function to enter values
    void input();

    // Function to add two complex numbers
    Complex add(Complex c);

    // Function to subtract two complex numbers
    Complex subtract(Complex c);

    // Function to display complex number
    void display();
};

// -------- Function Definitions (Outside the class) --------

void Complex::input() {
    cout << "Enter real part: ";
    cin >> real;
    cout << "Enter imaginary part: ";
    cin >> imag;
}

Complex Complex::add(Complex c) {
    Complex result;
    result.real = real + c.real;
    result.imag = imag + c.imag;
    return result;
}

Complex Complex::subtract(Complex c) {
    Complex result;
    result.real = real - c.real;
    result.imag = imag - c.imag;
    return result;
}

void Complex::display() {
    cout << real << " + " << imag << "i" << endl;
}

// ------------------ Main Function ------------------

int main() {
    Complex c1, c2, sum, diff;

    cout << "Enter first complex number:\n";
    c1.input();

    cout << "\nEnter second complex number:\n";
    c2.input();

    sum = c1.add(c2);
    diff = c1.subtract(c2);

    cout << "\nSum = ";
    sum.display();

    cout << "Difference = ";
    diff.display();

    return 0;
}
