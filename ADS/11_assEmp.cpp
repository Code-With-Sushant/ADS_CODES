#include <iostream>
#include <stack>
using namespace std;
struct node
{
    int sal;
    string name;
    string emp_id;
    string designation;
    string level;
    node *left;
    node *right;
};
node *get_node()
{
    node *temp;
    temp = new node;
    temp->left = NULL;
    temp->right = NULL;
    cout << "Enter the employee name :\n";
    cin >> temp->name;
    cout << "\nEnter the salary of employee :\n";
    cin >> temp->sal;
    cout << "\nEnter employee id of employee :\n";
    cin >> temp->emp_id;
    cout << "Enter Designation: ";
    cin >> temp->designation;
    cout << "Enter Level: ";
    cin >> temp->level;
    return temp;
}
node *create()
{
    node *New, *ptr, *root;
    int choice;
    root = NULL;
    ptr = NULL;
    do
    {
        New = get_node();
        if (root == NULL)
            root = New;
        else
        {
            ptr = root;
            while (true)
            {
                if (ptr->sal > New->sal)
                {
                    if (ptr->left == NULL)
                    {
                        ptr->left = New;
                        break;
                    }
                    else
                        ptr = ptr->left;
                }
                else
                {
                    if (ptr->right == NULL)
                    {
                        ptr->right = New;
                        break;
                    }
                    else
                        ptr = ptr->right;
                }
            }
        }
        cout << "do you want to more data (1/0)\n";
        cin >> choice;
    } while (choice == 1);
    return root;
}
node *insert(node *root)
{
    node *New, *ptr;
    New = get_node();
    if (root == NULL)
        root = New;
    else
    {
        ptr = root;
        while (true)
        {
            if (ptr->sal > New->sal)
            {
                if (ptr->left == NULL)
                {
                    ptr->left = New;
                    break;
                }
                else
                    ptr = ptr->left;
            }
            else
            {
                if (ptr->right == NULL)
                {
                    ptr->right = New;
                    break;
                }
                else
                    ptr = ptr->right;
            }
        }
    }
    cout << "\nNode inserted successfully \n";
    return root;
}
void *find(node *root, int x)
{
    if (root == NULL)
        return NULL;
    if (root->sal == x)
    {
        cout << "employee found \n";
        cout << root->name << "\t";
        cout << root->sal << "\t";
        cout << root->emp_id << "\t";
        cout << root->designation << "\t";
        cout << root->level << "\n";
        return root;
    }
    if (x > root->sal)
        return find(root->right, x);
    return find(root->left, x);
}
void find_max(node *root)
{
    node *ptr;
    ptr = root;
    while (ptr->right != NULL)
        ptr = ptr->right;
    cout << "MAXIMUM SALARY EMPLOYEE IS :\n";
    cout << ptr->name << "\t" << ptr->sal << "\t" << ptr->emp_id << ptr->designation << "\t" << ptr->level << "\t" << endl;
}
void find_min(node *root)
{
    node *ptr;
    ptr = root;
    while (ptr->left != NULL)
        ptr = ptr->left;
    cout << "MINIMUM SALARY EMPLOYEE IS :\n";
    cout << ptr->name << "\t" << ptr->sal << "\t" << ptr->emp_id << ptr->designation << "\t" << ptr->level << "\t" << endl;
}
node *make_empty(node *root)
{
    if (root == NULL)
    {
        cout << "Record is already empty\n";
        return NULL;
    }

    if (root->left != NULL)
        make_empty(root->left);

    if (root->right != NULL)
        make_empty(root->right);

    delete root;
    return NULL;
}
void delete_node(node *root)
{
    node *ptr, *prev, *temp;
    int key;
    ptr = root;
    prev = NULL;
    cout << "Enter the salary of employee that you want to delete :\n";
    cin >> key;
    while (ptr != NULL && ptr->sal != key)
    {
        prev = ptr;
        if (ptr->sal > key)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    if (ptr == NULL)
    {
        cout << "Element not found\n";
        return;
    }
    if (ptr->left == NULL && ptr->right == NULL)
    {

        if (prev->sal > key)
            prev->left = NULL;
        else
            prev->right = NULL;
        delete ptr;
        cout << "Element deleted successfully \n";
    }
    else if (ptr->left != NULL && ptr->right == NULL)
    {

        if (prev->sal > key)
            prev->left = ptr->left;
        else
            prev->right = ptr->left;
        delete ptr;
        cout << "Element deleted successfully \n";
    }
    else if (ptr->left == NULL && ptr->right != NULL)
    {
        if (prev->sal > key)
            prev->left = ptr->right;
        else
            prev->right = ptr->right;
        delete ptr;
        cout << "Element deleted successfully \n";
    }
    else
    {
        temp = ptr->right;
        while (temp->left != NULL)
            temp = temp->left;
        temp->left = ptr->left;
        if (prev->sal > key)
            prev->left = ptr->right;
        else
            prev->right = ptr->right;
        delete ptr;
        cout << "Element deleted successfully \n";
    }
}

void inorder_dis(node *h)
{
    if (h == NULL)
    {
        cout << "Tree is empty\n";
        return;
    }
    else
    {
        if (h->left != NULL)
            inorder_dis(h->left);
        cout << h->name << "\t" << h->sal << "\t" << h->emp_id << "\t" << h->designation << "\t" << h->level << "\n";
        if (h->right != NULL)
            inorder_dis(h->right);
    }
}

void preorder_dis(node *h)
{
    if (h == NULL)
    {
        cout << "tree empty\n";
        return;
    }
    else
    {
        cout << h->name << "\t" << h->sal << "\t" << h->emp_id << "\t" << h->designation << "\t" << h->level << "\n";

        if (h->left != NULL)
            preorder_dis(h->left);
        if (h->right != NULL)
            preorder_dis(h->right);
    }
}
void postorder_dis(node *h)
{
    if (h == NULL)
    {
        cout << "tree empty\n";
    }
    else
    {
        if (h->left != NULL)
            postorder_dis(h->left);
        if (h->right != NULL)
            postorder_dis(h->right);
        cout << h->name << "\t" << h->sal << "\t" << h->emp_id << "\t " << h->designation << "\t" << h->level << "\n";
    }
}
void preorderTraversal(node *root)
{
    if (root == NULL)
        return;

    stack<node *> s;
    s.push(root);

    while (!s.empty())
    {
        node *temp = s.top();
        s.pop();
        cout << temp->name << "\t";
        cout << temp->sal << "\t";
        cout << temp->emp_id << "\n";

        if (temp->right != NULL)
            s.push(temp->right);
        if (temp->left != NULL)
            s.push(temp->left);
    }
}
void inorderTraversal(node *root)
{
    if (root == NULL)
        return;

    stack<node *> s;
    node *temp = root;

    do
    {
        while (temp != NULL)
        {
            s.push(temp);
            temp = temp->left;
        }

        if (!s.empty())
        {
            temp = s.top();
            s.pop();
            cout << temp->name << "\t";
            cout << temp->sal << "\t";
            cout << temp->emp_id << "\n";
            temp = temp->right;
        }
    } while (!s.empty() || temp != NULL);
}
void postorderTraversal(node *root)
{
    if (root == NULL)
        return;

    stack<node *> s1, s2;
    s1.push(root);

    while (!s1.empty())
    {
        node *temp = s1.top();
        s1.pop();
        s2.push(temp);

        if (temp->left != NULL)
            s1.push(temp->left);
        if (temp->right != NULL)
            s1.push(temp->right);
    }

    while (!s2.empty())
    {
        node *temp = s2.top();
        s2.pop();
        cout << temp->name << "\t";
        cout << temp->sal << "\t";
        cout << temp->emp_id << "\n";
    }
}
int main()
{
    int x, choice, ch;
    node *root;
    do
    {
        cout << "MENU\n";
        cout << "1. Create employee record \n";
        cout << "2. Insert new employee data \n";
        cout << "3. Find employee which has minimum salary \n";
        cout << "4. Find employee which has maxmium salary \n";
        cout << "5. Delete all record \n";
        cout << "6. Find particular employee data \n";
        cout << "7. Delete individual employee data \n";
        cout << "8. Inorder display \n";
        cout << "9. Preorder display \n";
        cout << "10. Postorder display \n";
        cout << "11. Exit \n";
        cout << "Enter your choice :\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            root = create();
            break;
        case 2:
            root = insert(root);
            break;
        case 3:
            find_min(root);
            break;
        case 4:
            find_max(root);
            break;
        case 5:
            root = make_empty(root);
            if (root == NULL)
                cout << "Record deletion successful\n";
            break;
        case 6:
            cout << "Enter the salary of employee which is to be find out :";
            cin >> x;
            find(root, x);
            break;
        case 7:
            delete_node(root);
            break;
        case 8:
            inorder_dis(root);
            break;
        case 9:
            preorder_dis(root);
            break;
        case 10:
            postorder_dis(root);
            break;
        case 11:
            exit(0);
            break;
        default:
            cout << "wrong input give correct input \n";
        }
        cout << "Do you want to continue (0/1)\n";
        cin >> ch;

    } while (ch == 1);
    return 0;
}