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
