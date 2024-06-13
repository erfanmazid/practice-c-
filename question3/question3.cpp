#include <iostream>
#include <fstream>

using namespace std;

class shopping
{
private:
    int pid;
    string name;
    float price;
    float dis;
    int numbers;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void remove();
    void edit();
    void list();
    void receipt();
};

void shopping::menu()
{
m:
    int choice;
    string email;
    string password;

    cout << "\t\t\t\t______________________________________\n";
    cout << "\t\t\t\t                                      \n";
    cout << "\t\t\t\t           Supermarket Menu           \n";
    cout << "\t\t\t\t                                      \n";
    cout << "\t\t\t\t______________________________________\n";
    cout << "\t\t\t\t                                      \n";
    cout << "\t\t\t\t|  1) Administrator   |\n";
    cout << "\t\t\t\t|                     |\n";
    cout << "\t\t\t\t|  2) Buyer           |\n";
    cout << "\t\t\t\t|                     |\n";
    cout << "\t\t\t\t|  3) Exit            |\n";
    cout << "\t\t\t\t|                     |\n";
    cout << "\n\t\t\t Please select!";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\t\t\t Please Login \n";
        cout << "\t\t\t Enter Email   \n";
        cin >> email;
        cout << "\t\t\t Password       \n";
        cin >> password;

        if (email == "erfanmazidam@gmail.com" && password == "qwer@1384")
        {
            administrator();
        }
        else
        {
            cout << "Invalid email/password";
        }
        break;

    case 2:
    {
        buyer();
    }

    case 3:
    {
        exit(0);
    }

    default:
    {
        cout << "Please select from the given options";
    }
    }
    goto m;
};