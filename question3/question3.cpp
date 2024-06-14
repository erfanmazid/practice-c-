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

void shopping::menu()
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

void shopping ::adminPanel()
{
m:
    int choise;
    cout << "\t\t\t\t-------------------------------\n";
    cout << "\t\t\t\t                               \n";
    cout << "\t\t\t\t    1) Add the product         \n";
    cout << "\t\t\t\t                               \n";
    cout << "\t\t\t\t    2) Edit the product        \n";
    cout << "\t\t\t\t                               \n";
    cout << "\t\t\t\t    3) Remove the product      \n";
    cout << "\t\t\t\t                               \n";
    cout << "\t\t\t\t    4) inventory the product   \n";
    cout << "\t\t\t\t                               \n";
    cout << "\t\t\t\t    5) Back to menu            \n";
    cout << "\t\t\t\t                               \n";
    cout << "\t\t\t\t-------------------------------\n";
    cout << "\t\t\t\t    Enter your choice:         \n";
    cin >> choise;

    switch (choise)
    {
    case 1:
        addP();
        break;

    case 2:
        editP();
        break;

    case 3:
        removeP();
        break;

    case 4:
        inventory();
        break;

    case 5:
        menu();
        break;

    default:
        cout
            << "please select from options!";
        break;
    };

    goto m;
};