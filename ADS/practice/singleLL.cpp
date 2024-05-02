#include "iostream"

using namespace std;

struct node
{
    int data;
    struct node *next;
};
node *get_node()
{
    node *temp;
    temp = new node;
    temp->next = NULL;
    return temp;
}
node *create()
{
    node *temp, *New, *head;
    int val, flag;
    char ans;
    temp = NULL;
    flag = true;
    do
    {
        cout << "Enter the element: ";
        cin >> val;
        New = get_node();
        if (New == NULL)
        {
            cout << "Memory is not allocation";
        }
        else
        {
            New->data = val;
        }
        if (flag == true)
        {
            head = New;
            temp = head;
            flag = false;
        }
        else
        {
            temp->next = New;
            temp = New;
        }
        cout << "Do you want to enter more elements(y/n) ?  ";
        cin >> ans;

    } while (ans == 'y');

    cout << "\nSingly LL is created" << endl;
    return head;
}

node *insert_head(node *head)
{
    node *New, *temp;
    New = get_node();
    temp = head;
    cout << "Enter the element you want to insert:";
    cin >> New->data;
    if (temp == NULL)
    {
        temp = New;
        head = temp;
    }
    else
    {
        New->next = temp;
        head = New;
    }

    return head;
}

node *insert_tail(node *head)
{
    node *New, *temp;
    New = get_node();
    cout << "Enter the element you want to insert:";
    cin >> New->data;
    if (head == NULL)
    {
        head = New;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = New;
        cout << "Number inserted successfully " << endl;
    }

    return head;
}

node *insert_after(node *head)
{
    int key;
    node *New, *temp;
    New = get_node();
    cout << "Enter the element you want to insert: ";
    cin >> New->data;

    if (head == NULL)
    {
        head = New;
        return head;
    }
    
    cout << "Enter element after which you want to insert a node: ";
    cin >> key;
    temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {

            New->next = temp->next;
            temp->next = New;
            break;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}

node *del(node *head)
{
    node *prev, *temp;
    temp = head;
    int val, flag = 0;
    cout << "Enter the element you want to delete: ";
    cin >> val;
    if (temp == NULL)
    {
        cout << "List is empty";
        flag = 1;
        return head;
    }
    else
    {
        while (temp != NULL && temp->data != val)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp != NULL)
        {
            prev->next = temp->next;
            delete temp;
            flag = 1;
        }
    }
    if (flag == 0)
    {
        cout << "Element not found in LL";
    }
    return head;
}

node *display(node *head)
{
    node *temp;
    temp = head;
    if (temp == NULL)
    {
        cout << "List is empty";
        return head;
    }
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return head;
}

int main()
{
    int choice;
    cout << "TO begin ... You need to create a LL" << endl;
    node *head = create();
    comeHere: 

    cout << "*************************************************" << endl;
    cout << "MENU: " << endl;
    
    cout << "1. Insert Head for specified LL" << endl;
    cout << "2. Insert Tail for specified LL" << endl;
    cout << "3. Insert after an specified element in LL" << endl;
    cout << "4. Search an element in LL" << endl;
    cout << "5. Display an element in LL" << endl;
    cout << "6. Delete an element in LL" << endl;
    cout << "*************************************************" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
            head = insert_head(head);
        break;
    case 2:
            head = insert_tail(head);
        break;
    case 3:
            head = insert_after(head);
        break;
    case 4:
            // search(node *head);
        break;
    case 5:
            display(head);
        break;
    case 6:
            head = del(head);
        break;
    default:
        cout << "You have entered an invalid choice. Please re-enter choice." << endl;
        goto comeHere;
        break;
    }
    
    cout << "\nDo you want to continue (0/1): ";
    cin >> choice;

    if (choice == 0)
    {
        return 0;
    }
    else
    {
        goto comeHere;
    }



    return 0;
}