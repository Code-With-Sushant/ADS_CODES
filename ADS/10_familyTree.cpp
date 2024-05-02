#include "iostream"

using namespace std;

struct Tree
{
    string men;
    string women;
    struct Tree *left;
    struct Tree *right;
};

Tree *getTree()
{
    Tree *tree = new Tree;
    cout << "Enter the name of men:";
    cin >> tree->men;
    cout << "Enter the name of women:";
    cin >> tree->women;

    tree->left = NULL;
    tree->right = NULL;

    return tree;
}

Tree *createTree()
{
    Tree *temp, *ptr, *root = NULL;
    int ch;
    string choice;
    do
    {
        temp = getTree();
        if (root == NULL)
        {
            root = temp;
        }
        else
        {
            ptr = root;
            while (ptr != NULL)
            {
                sampleDir:
                cout << "-------------------------------------" << endl;
                cout << "Enter the direction: ";
                cin >> choice;
                cout << "-------------------------------------" << endl;

                if (choice == "l")
                {
                    if (ptr->left == NULL)
                    {
                        ptr->left = temp;     
                    }
                    else
                    {
                        ptr = ptr->left; 
                    }
                }
                else if (choice == "r")
                {
                    if (ptr->right == NULL)
                    {
                        ptr->right = temp;
                    }
                    else
                    {
                        ptr = ptr->right;
                    }
                }
                else
                {
                    cout << "Invalid direction";
                    goto sampleDir;
                }
            }

            cout << "Do you want to continue: ";
            cin >> ch;
        }
    }while (ch == 1);

    return root;
}

int main()
{
    Tree *root;
    int ch;
    int ch1;
    root = createTree();
    cout << "MENU" << endl;
    cout << "1. Add element" << endl;
    cout << "2. Display" << endl;

    cin >> ch;

    switch(ch)
    {
    case 1:
        createTree();
        break;
    case 2:
        cout << "Menu" << endl;
        cout <<"1. Inorder Travarsal" << endl;
        cout <<"2. Preorder Travarsal" << endl;
        cout <<"3. Postorder Travarsal" << endl;

        cin >> ch1;
        break;
    default:
        break;
    }
    return 0;
}