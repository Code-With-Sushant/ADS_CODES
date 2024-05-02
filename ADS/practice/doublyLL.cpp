#include "iostream"

using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

node *getNode()
{
    node *temp;
    temp = new node;
    temp->next = NULL;
    return temp;
}

node *createNode()
{
    int *head, *temp;

}
node *displayNode( node *head )
{
    
}
node *insertHead( node *head )
{
    
}
node *insertTail( node *head )
{
    
}
node *insertTail( node *head )
{
    
}
node *insertAfter( node *head )
{
    
}
node *deleteNode( node *head )
{
    
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
            head = insertHead(head);
        break;
    case 2:
            head = insertTail(head);
        break;
    case 3:
            head = insertAfter(head);
        break;
    case 4:
            // search(node *head);
        break;
    case 5:
            displayNode(head);
        break;
    case 6:
            head = deleteNode(head);
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