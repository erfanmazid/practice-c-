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
    cout << "\t\t\t\t    Enter a product id:        \n";
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
    cout << "Success adding products";
};

void shopping::editP()
{
    fstream data, data1;
    int pKey;
    int i;
    int token = 0;
    string n;
    float p;
    int c;

    cout << "\t\t\t\t                               \n";
    cout << "\t\t\t\t      edit exist product       \n";
    cout << "\t\t\t\t                               \n";
    cout << "\t\t\t\t    enter a product id:        \n";
    cin >> pKey;

    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\t\t\t\t file dosent exist!";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);

        data >> pId >> pName >> pPrice >> pNumbers;
        while (!data.eof())
        {
            if (pKey == pId)
            {
                cout << "\t\t\t\t    enter a product new id:    \n";
                cin >> i;
                cout << "\t\t\t\t    enter a new name:          \n";
                cin >> n;
                cout << "\t\t\t\t    enter a new price:         \n";
                cin >> p;
                cout << "\t\t\t\t    enter a new number:        \n";
                cin >> c;
                data1 << " " << i << " " << n << " " << p << " " << c << "\n";
                cout << "\t\t\t\t Product updated";
                token++;
            }
            else
            {
                data1 << " " << pId << " " << pName << " " << pPrice << " " << pNumbers << "\n";
            };
            data >> pId >> pName >> pPrice >> pNumbers;
        };
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\t\t\t\t Record not found sorry!";
        };
    };
};

void shopping ::removeP()
{
    fstream data, data1;
    int pKey;
    int token = 0;

    cout << "\t\t\t\t                               \n";
    cout << "\t\t\t\t     remove exist product      \n";
    cout << "\t\t\t\t                               \n";
    cout << "\t\t\t\t    enter a product id:        \n";
    cin >> pKey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\t\t\t\t file dosent exist!";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);

        data >> pId >> pName >> pPrice >> pNumbers;
        while (!data.eof())
        {
            if (pKey == pId)
            {
                cout << "\t\t\t\t Prodouct deleted succesfully.";
                token++;
            }
            else
            {
                data1 << " " << pId << " " << pName << " " << pPrice << " " << pNumbers << "\n";
            };
            data >> pId >> pName >> pPrice >> pNumbers;
        };
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\t\t\t\t Record not found sorry!";
        };
    };
};

void shopping ::list()
{
    fstream data;
    int pkey;
    string q;
    array p = [100];
    data.open("database.txt", ios::in);

    do
    {

        cout << "Enter product id:";
        cin >> pkey;

        if (data.is_open())
        {
            Item item;
            while (data >> item.pId >> item.pName >> item.pPrice >> pNumbers >>)
            {
                if (item.id == pkey)
                {
                    items.push_back(item);
                };
            };
            file.close();
        }
        else
        {
            cout << "\t\t\t\t Your db is close!"
        };

        cout << "Do you want add anouther product? y or n";
        cin >> q;

        for (const Item &item : items)
        {
            cout << "ID: " << item.id << endl;
            cout << "Name: " << item.name << endl;
            cout << "Value: " << item.value << endl;
            cout << endl;
        }

    } while (q == "y");

    cout << " tanks for your buyying";
};

int main()
{
    shopping s;
    s.menu();
}
