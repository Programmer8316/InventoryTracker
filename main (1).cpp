#include <iostream>
#include <fstream>
using namespace std;

int addItems()
{
    ofstream writeFile("inventory.txt", ios::app); 
    static int itemCount;
    string name = "";
    int quantity = 0;
    double price = 0;
    bool inValid = false;
    
    if(itemCount < 10)
    {
        cout << "Item Name: ";
        cin >> name;
        writeFile << name << " "; 
    
        do
        {
            cout << "Quantity Amount: ";
            cin >> quantity;
        
            if (quantity < 1 || quantity > 1000)
            {
                cout << "Invalid quantity amount. Quantity must be between 1 "
                     << "and 1000, please try again!";
                
                inValid = true;
            }
            
            else
            {
                writeFile << quantity << " ";
                
                inValid = false;
            }
        }while(inValid);
        
        do
        {
            cout << "Item Price: ";
            cin >> price;
            
            if (price <= 0 || price > 10000)
            {
                cout << "Invalid price amount. Price must be greater than 0 and"
                     << " less than or equal to 10000, please try again!";
            }
            
            else
            {
                writeFile << price << endl;
                
                inValid = false;
            }
        }while(inValid);
        
        itemCount++;
    }
    
    else
    {
        cout << "Inventory is full. Cannot add more items." << endl;
    }
    
    writeFile.close();
    
    return itemCount;
}

void displayItems()
{
    ifstream readFile("inventory.txt");
    string name = "";
    int quantity = 0;
    double price = 0;
    
    if(readFile)
    {
        cout << "\tInventory List" << endl;
        while (readFile >> name >> quantity >> price)
        {
            cout << "Item Name: " << name << endl
                 << "Item Quantity: " << quantity << endl
                 << "Item Price: " << price << endl << endl;
        }
    }
    
    else
    {
        cout << "There are currently no items in inventory to display." << endl;
    }
    
    readFile.close();
}

void calculateItems(int itemQuantities[], double itemPrices[])
{
    ifstream readFile("inventory.txt");
    double totalValue = 0;
    string name = "";
    int quantity = 0;
    double price = 0;
    int count = 0;
    
    if(readFile)
    {
        while(readFile >> name >> quantity >> price)
        {
            itemQuantities[count] = quantity;
            itemPrices[count] = price;
            count++;
        }
        
        for(int item = 0; item < count; item++)
        {
            totalValue += itemQuantities[item] * itemPrices[item];
        }
    }
    
    cout << "Total Value: $" << totalValue << endl;
    
    readFile.close();
}

int main()
{
    const int MAX_ITEMS = 10;
    string itemNames[MAX_ITEMS];
    int itemQuantities[MAX_ITEMS];
    double itemPrices[MAX_ITEMS];
    bool terminate = false;
    int option = 0;
    int itemCount = 0;
    
    while(!terminate)
    {
        cout << "\tMenu" << endl 
             << "1. Add a new item" << endl
             << "2. View all inventory items" << endl
             << "3. Calculate total value of inventory" << endl
             << "4. Exit" << endl << endl
             << "Select an option[1 - 4]: ";
        cin >> option;
        
        switch(option)
        {
            case 1: 
                itemCount = addItems();
                terminate = true;
                break;
            case 2:
                displayItems();
                terminate = true;
                break;
            case 3:
                calculateItems(itemQuantities, itemPrices);
                terminate = true;
                break;
            case 4:
                terminate = true;
                break;
            default:
                cout << "Invalid option. Please try again!" << endl;
        }
    }
    
    return 0;
}