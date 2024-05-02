#include "iostream"

using namespace std;

struct Node 
{
    Node *data;
    Node *index;
};


int main()
{
    int head, i, j, choice;

    cout << "MENU" << endl;
    cout << "1. Create LL " << endl;
    cout << "2. Delete LL " << endl;
    cout << "3. Insert element in existing LL " << endl;
    cout << "4. Delete element in existing LL " << endl;
    cout << "5. Display element in existing LL " << endl;
    cout << "6. Searching element in existing LL " << endl;
    cin >> choice ;
    
    switch (choice)
    {
    case 1:
        cout <<"Let's create a new LL" << endl;
        cout << "--------------------------------" << endl;

        cout << "Insert index of first node" << endl;
        cin >> i;

        head = i;

        while (i != -1)
        {
            cout << "Insert the data and the index" << endl;
            cin >> a[i].data >> a[i].index ;

            i = a[i].index;
        }
        cout << " Head is " << head << endl;

        break;
    case 2:
        
        break;
    case 3:
            int newData, tempData;
            cout << "\nEnter the new data to be inserted: ";
            cin >> newData;

            cout << "\nEnter the data after which you want to insert: ";
            cin >> tempData;

            for (int i = 0; i < 10 ; i++)
            {
                if (a[i].data == tempData)
                {
                    break;
                }
                // if (a[])
            }
        break;
    case 4:

        break;
    case 5:
            cout << "--------------------------------" << endl;
            while (i != -1)
            {
                if (a[i].data == -1)
                {
                    cout << " " ;
                }
                else
                {
                    cout << a[i].data ;
                }
                i = a[i].index;
            }
            
        break;
    case 6:

        break;
    default:
        break;
    }

    return 0;
}