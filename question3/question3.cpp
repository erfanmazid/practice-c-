#include <iostream>
#include <fstream>

using namespace std;

class shopping
{
private:
    int pId;
    string pName;
    float pPrice;
    float pNumbers;

public:
    void menu();
    void adminPanel();
    void invoicing();
    void inventory();
    void addP();
    void editP();
    void removeP();
    void list();
    void receipt();
};

void shopping ::menu()
{
m:
    int choise;
    string email;
    string password;

    cout << "\t\t\t\t-------------------------\n";
    cout << "\t\t\t\t  Welcome to application \n";
    cout << "\t\t\t\t-------------------------\n";
    cout << "\t\t\t\t                         \n";
    cout << "\t\t\t\t                         \n";
    cout << "\t\t\t\t-------------------------\n";
    cout << "\t\t\t\t  1) Admin Panel         \n";
    cout << "\t\t\t\t                         \n";
    cout << "\t\t\t\t  2) Order Panel         \n";
    cout << "\t\t\t\t                         \n";
    cout << "\t\t\t\t  3) Exit                \n";
    cout << "\t\t\t\t-------------------------\n";
    cout << "\t\t\t\t  Please select:         \n";
    cin >> choise;

    switch (choise)
    {
    case 1:
        cout << "\t\t\t\t  Please login    \n";
        cout << "\t\t\t\t                  \n";
        cout << "\t\t\t\t  Enter Email:    \n";
        cin >> email;
        cout << "\t\t\t\t                  \n";
        cout << "\t\t\t\t  Enter password: \n";
        cin >> password;

        if (email = "erfanmazidam@gmail.com" &&password = "qwer@1384")
        {
            adminPanel();
        }
        else
        {
            cout << "Wrong email or password";
        }
        break;

    case 2:
        invoicing();
        break;

    case 3:
        exit(0);

    default:
        cout << "please select from options!";
        break;
    };

    goto m;
};