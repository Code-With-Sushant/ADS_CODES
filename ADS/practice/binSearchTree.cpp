#include"iostream"
using namespace std;
struct Tree
{
    int data;
    struct Tree *left;
    struct Tree *right;
};
Tree *get_node()
{
    Tree *temp;
    temp=new Tree;
    cout<<"Enter Element: ";
    cin>>temp->data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
Tree *createBinaryTree()
{
    Tree *temp,*ptr,*root=NULL;
    int ch;
    char dir;
    do
    {
        temp=get_node();
        if(root==NULL)
        {
            root=temp;
        }
        else
        {
            ptr=root;
            while(ptr!=NULL)
            {
                cout<<"Enter the direction: ";
                cin>>dir;
                if(dir=='l')
                {
                    
                    if(ptr->left==NULL)
                    {
                        if (ptr->data > temp->data)
                        {
                            cout << "Value should be lesser than root node";
                            break;
                        }
                        ptr->left=temp;
                        break;
                    }
                    else
                    {
                        ptr=ptr->left;
                    }
                }
                else
                {
                    if(ptr->right==NULL)
                    {
                        if (ptr->data < temp->data)
                        {
                            cout << "Value should be greater than root node";
                            break;
                        }
                        ptr->right=temp;
                        break;
                    }
                    else
                    {
                        ptr=ptr->right;
                    }
                }
            }
        }
        cout<<"do you want to add more data ?"<<endl;
        cin>>ch;
    }while(ch==1);
    return root;
}
Tree *add_element(Tree *h)
{
    Tree *temp,*ptr,*root=h;
    int ch;
    char dir;

    temp=get_node();
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        ptr=root;
        while(ptr!=NULL)
        {
            cout<<"Enter The direction: ";
            cin>>dir;
            if(dir=='l')
            {
                if(ptr->left==NULL)
                {
                    if (ptr->data > temp->data)
                    {
                        cout << "Value should be lesser than root node";
                        break;
                    }

                    ptr->left=temp;
                    break;
                }
                else 
                {
                    ptr=ptr->left;
                }
            }
            else
            {
                if(ptr->right==NULL)
                {
                    if (ptr->data < temp->data)
                    {
                        cout << "Value should be greater than root node";
                        break;
                    }
                    ptr->right=temp;
                    break;
                }
                else
                {
                    ptr=ptr->right;
                }
            }
        }
    }
    return root;
}
void display_preorder(Tree *h)
{
    if(h!=NULL)
    {
        cout<<h->data<<"  ";
        display_preorder(h->left);
        display_preorder(h->right);
    }
}
void inorder_traversal(Tree *h)
{
    if(h != NULL)
    {
        inorder_traversal(h->left);
        cout<<h->data<<"  ";
        inorder_traversal(h->right);
    }
}
void post_order_traversal(struct Tree *h)
{
    if(h != NULL)
    {
        post_order_traversal(h->left);
        post_order_traversal(h->right);
        cout<<h->data<<"  ";
    }
}
int main()
{
    Tree *h;
    h=createBinaryTree();
    int ch;
    do{
        cout<<"\nMenu....\n1)Display\t2)add data\n";
        cout<<"Enter your choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                cout<<"Pre-Order Display: ";
                display_preorder(h);
                cout<<endl;
                cout<<"In-Order display: ";
                inorder_traversal(h);
                cout<<endl;
                cout<<"Post-order Display: ";
                post_order_traversal(h);
                break;
            }
            case 2:
            {
                add_element(h);
                cout<<"Element added...\n";
                break;
            }
        }
        cout<<"\ndo you want to comtinue ? \n"<<endl;
        cin>>ch;
    }while(ch==1);
    return 0;
}