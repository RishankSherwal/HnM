#include <iostream>
#include <fstream>
using namespace std;

// ================= BASE CLASS =================
class Person
{
protected:
    string name;
    string phone;

public:
    void getPersonDetails()
    {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Phone: ";
        cin >> phone;
    }

    void showPersonDetails()
    {
        cout << "\nName: " << name << endl;
        cout << "Phone: " << phone << endl;
    }
};

// ================= DERIVED CLASS =================
class Customer : public Person
{
private:
    int roomNumber;
    int days;
    float bill;

public:
    void bookRoom()
    {
        getPersonDetails();

        cout << "Enter Room Number: ";
        cin >> roomNumber;

        cout << "Enter number of days: ";
        cin >> days;

        bill = days * 1000; // room rent per day
    }

    void showBooking()
    {
        showPersonDetails();
        cout << "Room Number: " << roomNumber << endl;
        cout << "Days: " << days << endl;
        cout << "Total Bill: " << bill << endl;
    }

    int getRoomNumber()
    {
        return roomNumber;
    }

    void saveToFile()
    {
        ofstream file("hotel.txt", ios::app);
        file << name << " " << phone << " " << roomNumber << " " << days << " " << bill << endl;
        file.close();
    }
};

// ================= FILE HANDLING CLASS =================
class HotelRecord
{
public:
    void showAllRecords()
    {
        ifstream file("hotel.txt");
        string name, phone;
        int room, days;
        float bill;

        cout << "\n===== Hotel Records =====\n";

        while (file >> name >> phone >> room >> days >> bill)
        {
            cout << "\nName: " << name
                 << "\nPhone: " << phone
                 << "\nRoom: " << room
                 << "\nDays: " << days
                 << "\nBill: " << bill << endl;
        }

        file.close();
    }
};

// ================= POLYMORPHISM =================
class Bill
{
public:
    virtual void showBill(float amount)
    {
        cout << "\nTotal Bill: " << amount << endl;
    }
};

class DiscountBill : public Bill
{
public:
    void showBill(float amount)
    {
        float finalAmount = amount - (amount * 0.1);
        cout << "\nBill after 10% discount: " << finalAmount << endl;
    }
};

// ================= MAIN FUNCTION =================
int main()
{
    Customer c;
    HotelRecord h;
    Bill *b;
    DiscountBill db;

    int choice;

    do
    {
        cout << "\n====== HOTEL MANAGEMENT SYSTEM ======";
        cout << "\n1. Book Room";
        cout << "\n2. Show All Records";
        cout << "\n3. Show Bill with Discount";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            c.bookRoom();
            c.saveToFile();
            break;

        case 2:
            h.showAllRecords();
            break;

        case 3:
            b = &db; // polymorphism
            b->showBill(5000);
            break;

        case 4:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 4);

    return 0;
}
