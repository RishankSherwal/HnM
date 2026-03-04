#include<iostream>
#include <fstream>
#include <thread>
#include <chrono>
using namespace std;

// ========== LOGIN SYSTEM ==========
class LoginSystem
{
private:
    string password = "admin";

public:
    bool authenticate()
    {
        string input;
        cout << "\nEnter system password: ";
        cin >> input;

        if (input == password)
        {
            cout << "Access Granted ✅\n";
            return true;
        }
        else
        {
            cout << "Access Denied ❌\n";
            return false;
        }
    }
};

// ========== LOADING ANIMATION ==========
class Loader
{
public:
    void loading()
    {
        cout << "\nLoading";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            this_thread::sleep_for(chrono::milliseconds(300));
        }
        cout << endl;
    }
};

// ========== VALIDATOR ==========
class Validator
{
public:
    bool isValidKey(int key)
    {
        return key > 0;
    }
};

// ========== ABSTRACT BASE CLASS ==========
class Crypto
{
protected:
    string text;
    int key;

public:
    virtual void getData()
    {
        cin.ignore();
        cout << "Enter message: ";
        getline(cin, text);
        cout << "Enter key: ";
        cin >> key;
    }

    virtual string process() = 0;
};

// ========== CAESAR CIPHER ==========
class CaesarCipher : public Crypto
{
public:
    string process()
    {
        string result = text;

        for (int i = 0; i < result.length(); i++)
        {
            if (isalpha(result[i]))
            {
                char base = isupper(result[i]) ? 'A' : 'a';
                result[i] = (result[i] - base + key) % 26 + base;
            }
        }
        return result;
    }

    string decrypt()
    {
        string result = text;

        for (int i = 0; i < result.length(); i++)
        {
            if (isalpha(result[i]))
            {
                char base = isupper(result[i]) ? 'A' : 'a';
                result[i] = (result[i] - base - key + 26) % 26 + base;
            }
        }
        return result;
    }
};

// ========== XOR CIPHER ==========
class XORCipher : public Crypto
{
public:
    string process()
    {
        string result = text;

        for (int i = 0; i < result.length(); i++)
            result[i] = result[i] ^ key;

        return result;
    }

    string decrypt()
    {
        return process(); // XOR decrypt = encrypt
    }
};

// ========== FILE MANAGER ==========
class FileManager
{
public:
    void saveToFile(string data)
    {
        ofstream file("encrypted.txt");
        file << data;
        file.close();
        cout << "Saved to file 📁\n";
    }

    string readFromFile()
    {
        ifstream file("encrypted.txt");
        string data;
        getline(file, data);
        file.close();
        return data;
    }
};

// ========== USER INTERFACE ==========
class UserInterface
{
public:
    void showMenu()
    {
        cout << "\n========== MAIN MENU ==========\n";
        cout << "1. Caesar Encrypt\n";
        cout << "2. Caesar Decrypt\n";
        cout << "3. XOR Encrypt\n";
        cout << "4. XOR Decrypt\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
    }
};

// ========== MAIN ==========
int main()
{
    LoginSystem login;
    Loader load;
    Validator valid;
    FileManager file;
    UserInterface ui;

    if (!login.authenticate())
        return 0;

    load.loading();

    int choice;
    Crypto *ptr;

    do
    {
        ui.showMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            ptr = new CaesarCipher();
            ptr->getData();
            string result = ptr->process();
            cout << "Encrypted: " << result << endl;
            file.saveToFile(result);
            break;
        }

        case 2:
        {
            CaesarCipher obj;
            obj.getData();
            cout << "Decrypted: " << obj.decrypt() << endl;
            break;
        }

        case 3:
        {
            ptr = new XORCipher();
            ptr->getData();
            string result = ptr->process();
            cout << "Encrypted: " << result << endl;
            file.saveToFile(result);
            break;
        }

        case 4:
        {
            XORCipher obj;
            obj.getData();
            cout << "Decrypted: " << obj.decrypt() << endl;
            break;
        }

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}
