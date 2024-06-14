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
