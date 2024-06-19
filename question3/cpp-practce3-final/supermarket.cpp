#include <iostream>
#include <sqlite3.h>
#include <vector>
#include <string>

using namespace std;

struct CartItem
{
    int id;
    string name;
    int quantity;
    double price;
};

void initializeDatabase(sqlite3 *&db)
{
    char *errMsg = 0;
    int rc = sqlite3_open("supermarket.db", &db);

    if (rc)
    {
        cerr << "Can't open database: " << sqlite3_errmsg(db) << endl;
        return;
    }
    else
    {
        cout << "Opened database successfully" << endl;
    }

    const char *sql = "CREATE TABLE IF NOT EXISTS PRODUCTS("
                      "ID INT PRIMARY KEY NOT NULL,"
                      "NAME TEXT NOT NULL,"
                      "QUANTITY INT NOT NULL,"
                      "PRICE REAL NOT NULL);";

    rc = sqlite3_exec(db, sql, 0, 0, &errMsg);

    if (rc != SQLITE_OK)
    {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
    else
    {
        cout << "Table created successfully" << endl;
    }

    const char *insertSql = "INSERT OR IGNORE INTO PRODUCTS (ID, NAME, QUANTITY, PRICE) VALUES "
                            "(1, 'Milk', 20, 1.5),"
                            "(2, 'Yogurt', 20, 1.0),"
                            "(3, 'Cheese', 20, 2.5),"
                            "(4, 'Butter', 20, 3.0);";

    rc = sqlite3_exec(db, insertSql, 0, 0, &errMsg);

    if (rc != SQLITE_OK)
    {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
    else
    {
        cout << "Initial products inserted successfully" << endl;
    }
}

void updateProductQuantity(sqlite3 *db, int productId, int quantity)
{
    char *errMsg = 0;
    string sql = "UPDATE PRODUCTS SET QUANTITY = QUANTITY - " + to_string(quantity) + " WHERE ID = " + to_string(productId) + " AND QUANTITY >= " + to_string(quantity) + ";";

    int rc = sqlite3_exec(db, sql.c_str(), 0, 0, &errMsg);

    if (rc != SQLITE_OK)
    {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
    else
    {
        cout << "Product quantity updated successfully" << endl;
    }
}

void displayProducts(sqlite3 *db)
{
    sqlite3_stmt *stmt;
    const char *sql = "SELECT * FROM PRODUCTS;";

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) == SQLITE_OK)
    {
        cout << "ID | Name   | Quantity | Price" << endl;
        cout << "-----------------------------" << endl;
        while (sqlite3_step(stmt) == SQLITE_ROW)
        {
            int id = sqlite3_column_int(stmt, 0);
            const unsigned char *name = sqlite3_column_text(stmt, 1);
            int quantity = sqlite3_column_int(stmt, 2);
            double price = sqlite3_column_double(stmt, 3);
            cout << id << "  | " << name << " | " << quantity << "      | " << price << endl;
        }
    }
    sqlite3_finalize(stmt);
}

void addToCart(vector<CartItem> &cart, sqlite3 *db, int productId, int quantity)
{
    sqlite3_stmt *stmt;
    string sql = "SELECT NAME, QUANTITY, PRICE FROM PRODUCTS WHERE ID = " + to_string(productId) + " AND QUANTITY >= " + to_string(quantity) + ";";

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) == SQLITE_OK)
    {
        if (sqlite3_step(stmt) == SQLITE_ROW)
        {
            string name = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0));
            double price = sqlite3_column_double(stmt, 2);
            cart.push_back({productId, name, quantity, price});
            updateProductQuantity(db, productId, quantity);
        }
        else
        {
            cout << "Product not found or insufficient quantity." << endl;
        }
    }
    else
    {
        cerr << "Failed to execute query." << endl;
    }

    sqlite3_finalize(stmt);
}

void displayCart(const vector<CartItem> &cart)
{
    double total = 0.0;
    cout << "Your cart:" << endl;
    cout << "ID | Name   | Quantity | Price | Total" << endl;
    cout << "--------------------------------------" << endl;
    for (const auto &item : cart)
    {
        double itemTotal = item.quantity * item.price;
        total += itemTotal;
        cout << item.id << "  | " << item.name << " | " << item.quantity << "      | " << item.price << "  | " << itemTotal << endl;
    }
    cout << "Total amount: " << total << endl;
}

int main()
{
    sqlite3 *db;
    initializeDatabase(db);
    vector<CartItem> cart;

    while (true)
    {
        cout << "1. Buy products\n2. Admin\n3. Exit\nChoose an option: ";
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            while (true)
            {
                displayProducts(db);
                cout << "Enter product ID to buy (0 to finish): ";
                int productId;
                cin >> productId;
                if (productId == 0)
                    break;

                cout << "Enter quantity: ";
                int quantity;
                cin >> quantity;

                addToCart(cart, db, productId, quantity);

                cout << "Do you want to continue shopping? (yes/no): ";
                string cont;
                cin >> cont;
                if (cont == "no")
                    break;
            }

            displayCart(cart);
            cart.clear();
        }
        else if (choice == 2)
        {
            // Admin section (Add/Remove/Edit products) can be implemented here
            cout << "Admin section (Add/Remove/Edit products) is under construction." << endl;
        }
        else if (choice == 3)
        {
            break;
        }
    }

    sqlite3_close(db);
    return 0;
}
