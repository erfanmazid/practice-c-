#include <iostream>
#include <fstream>

using namespace std;

class shopping
{
private:
    int pId;
    string pName;
    float pPrice;
    int pNumbers;

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

        if (email == "erfanmazidam@gmail.com" && password == "qwer@1384")
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
        cout << "please select from options!";
    };

    goto m;
};

void shopping::invoicing()
{
m:
    int choise;
    cout << "\t\t\t\t-------------------------------\n";
    cout << "\t\t\t\t                               \n";
    cout << "\t\t\t\t       Ordering system         \n";
    cout << "\t\t\t\t                               \n";
    cout << "\t\t\t\t    1) New order               \n";
    cout << "\t\t\t\t                               \n";
    cout << "\t\t\t\t    2) GO back                 \n";
    cout << "\t\t\t\t                               \n";
    cout << "\t\t\t\t-------------------------------\n";
    cout << "\t\t\t\t    Enter your choice:         \n";
    cin >> choise;

    switch (choise)
    {
    case 1:
        receipt();
        break;

    case 2:
        menu();
        break;

    default:
        cout << "please select from options!";
    };

    goto m;
};

void shopping ::addP()
{
m:
    fstream data;
    int i;
    int token = 0;
    string n;
    float p;
    int c;

    cout << "\t\t\t\t                               \n";
    cout << "\t\t\t\t       Add new product         \n";
    cout << "\t\t\t\t                               \n";
    cout << "\t\t\t\t    enter a product id:        \n";
    cin >> pId;
    cout << "\t\t\t\t    Enter a name for product   \n";
    cin >> pName;
    cout << "\t\t\t\t    Enter a price for product  \n";
    cin >> pPrice;
    cout << "\t\t\t\t    Enter a number for product \n";
    cin >> pNumbers;

    data.open("database.txt", ios::in);

    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pId << " " << pName << " " << pPrice << " " << pNumbers << "\n";
        data.close();
    }
    else
    {
        data >> i >> n >> p >> c;

        while (data.eof())
        {
            if (i == pId)
            {
                token++;
            };
            data >> i >> n >> p >> c;
        };
        data.close();

        if (token == 1)
        {
            goto m;
        }
        else
        {
            data.open("database.txt", ios::app | ios::out);
            data << " " << pId << " " << pName << " " << pPrice << " " << pNumbers << "\n";
            data.close();
        };
    };
    cout << "Success adding products"
};