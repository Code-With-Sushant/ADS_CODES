#include "iostream"

using namespace std;

struct Donar
{
  string DonarName;
  int DonarID;
  int DonarAmount;
  int DonarAge;
}d[10];

int i = 0;
void InsertRecord()
{
    cout << "\nInsert name of doner: ";
    cin >> d[i].DonarName;

    cout << "\nInsert ID of doner: ";
    cin >> d[i].DonarID;

    cout << "\nInsert Amount of donation: ";
    cin >> d[i].DonarAmount;

    cout << "\nInsert age of donation: ";
    cin >> d[i].DonarAge;

}
void UpdateRecord()
{
    int id;
    string updatedName;
    int updatedAmount;
    int updatedAge;
    int flag = 0;

    cout << "\nEnter the ID of the donar to be upadated: ";
    cin >> id;

    for (int j = 0 ; j < i+1; j++) 
    {
        if(id == d[j].DonarID)
        {
            cout << "\nEnter the name to be updated: ";
            cin >> updatedName;

            cout << "\nEnter the amount to be updated: ";
            cin >> updatedAmount;

            cout << "\nEnter the age to be updated: ";
            cin >> updatedAge;

            d[j].DonarName = updatedName;
            d[j].DonarAmount = updatedAmount;
            d[j].DonarAge = updatedAge;

            flag = 1;       
        }
    }
    if (flag == 0)
    {
        cout << "\nNo doner found, Please recheck donar ID.........." << endl; 
    }
}
void DeleteRecord()
{
    int id; 
    int flag = 0;
    int var;

    cout << "\nEnter the ID of the donar for deletion of record: ";
    cin >> id;

    for (int j = 0 ; j < 10 ; j++) 
    {
        if(id == d[j].DonarID)
        {
            flag = 1;       
            var = j;
            break;
        }
    }
    
    if (flag == 0)
    {
        cout << "\nNo doner found, Please recheck donar ID.........." << endl; 
    }
    else
    {
        for (int j = var; j < 10 ; j++)
        {
            d[++j] = d[j];
        }    
    }
}
void SearchRecord()
{
    int id; 
    int flag = 0;
    // int var;

    cout << "\nEnter the ID of the donar for searching of record: ";
    cin >> id;

    for (int j = 0 ; j < 10 ; j++) 
    {
        if(id == d[j].DonarID)
        {
            flag = 1;       
            cout << "\nRecord Found....." << endl;
            break;
        }
    }
    
    if (flag == 0)
    {
        cout << "\nNo doner found...." << endl; 
    }
}
void DisplayRecord()
{
    int id;
    int flag = 0;

    cout << "\nEnter the ID of the donar for display of record: ";
    cin >> id;

    for (int j = 0 ; j < 10 ; j++) 
    {
        if(id == d[j].DonarID)
        {
            flag = 1;       
            cout << "\nName: " << d[j].DonarName << endl;
            cout << "Amount: " << d[j].DonarAmount << endl;
            cout << "Age: " << d[j].DonarAge<< endl;
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout << "\nNo doner found, Please recheck donar ID.........." << endl; 
    } 
}

int main()
{
    int choice, choice1;
    sample:
    cout << "MENU" << endl;
    cout << "1. Insert Record " << endl;
    cout << "2. Update Record " << endl;
    cout << "3. Delete Record " << endl;
    cout << "4. Search Record " << endl;
    cout << "5. Display Record " << endl;
    cout << "6. Exit " << endl;    
    cin >> choice ;
    
    switch (choice)
    {
    case 1:
        InsertRecord();
        break;
    case 2:
        UpdateRecord();
        break;
    case 3:
        DeleteRecord();
        break;
    case 4:
        SearchRecord();
        break;
    case 5:
        DisplayRecord();
        break;
    case 6:
        exit(0);
        break;
    default:
        break;
    }
    cout << "Do you want to continue?";
    cin >> choice1;

    if (choice1 == 1)
    {
        goto sample;
    }
    return 0;
}