
#include "iostream"
using namespace std;
struct Music
{
    int no;
    string title;
    string artist;
    string generation;
    int duration;
    int releaseYear;
    struct Music *next;
};
Music *get_Music()
{
    Music *temp;
    temp = new Music;
    temp->next = NULL;
    return temp;
}
Music *createMusic()
{
    Music *temp, *New, *head;
    int no, duration, releaseYear;
    string generation, title, artist;
    bool flag = true;
    int ans;
    temp = NULL;
    do
    {
        cout << "Enter music number : ";
        cin >> no;
        cout << "Enter title : ";
        cin >> title;
        cout << "Enter artist : ";
        cin >> artist;
        cout << "Enter duration : ";
        cin >> duration;
        cout << "Enter generation : ";
        cin >> generation;
        cout << "Enter release year : ";
        cin >> releaseYear;

        New = get_Music();
        if (New == NULL)
        {
            cout << "Memory not allocated" << endl;
        }
        else
        {
            New->no = no;
            New->title = title;
            New->artist = artist;
            New->generation = generation;
            New->duration = duration;
            New->releaseYear = releaseYear;
        }
        if (flag == true)
        {
            head = New;
            New->next = head;
            temp = head;
            flag = false;
        }
        else
        {
            temp = head;
        }
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = New;
        New->next = head;
        cout << "do you want to continue(1/0) : ";
        cin >> ans;
    } while (ans == 1);
    return head;
}
Music* displayMusic(Music *head)
{
    Music *temp;
    temp = head;
    if (temp == NULL)
    {
        cout << "Music list is empty." << endl;
        return head;
    }

    do
    {
        cout << temp->no << "\t" << temp->title << "\t" << temp->artist << "\t" << temp->generation << "\t" << temp->duration << "\t" << temp->releaseYear << endl;
        temp = temp->next;
    } while (temp != head);

    return head;
}
Music *insertMusic(Music *head)
{
    Music *New, *temp;
    New = get_Music();
    cout << "Enter music number : ";
    cin >> New->no;
    cout << "Enter Title : ";
    cin >> New->title;
    cout << "Enter artist : ";
    cin >> New->artist;
    cout << "Enter Duration : ";
    cin >> New->duration;
    cout << "enter generation : ";
    cin >> New->generation;
    cout << "Enter release year : ";
    cin >> New->releaseYear;
    if (head == NULL)
    {
        head = New;
    }
    else
    {
        temp = head;
        temp->next = New;
        New->next = head;
        head = New;
        cout << "Song inserted." << endl;
        return head;
    }
    return head;
}

Music* insertAfter(Music *head)
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return head;
    }

    int key;
    cout << "Enter key after which you want to insert : ";
    cin >> key;

    Music *temp = head;
    do
    {
        if (temp->no == key)
        {
            Music *New = get_Music();
            cout << "Enter music number : ";
            cin >> New->no;
            cout << "Enter Title : ";
            cin >> New->title;
            cout << "Enter artist : ";
            cin >> New->artist;
            cout << "Enter Duration : ";
            cin >> New->duration;
            cout << "enter generation : ";
            cin >> New->generation;
            cout << "Enter release year : ";
            cin >> New->releaseYear;

            New->next = temp->next;
            temp->next = New;

            cout << "Music inserted." << endl;
            return head;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Key not found, Cannot insert song" << endl;

    return head;
}

Music *deleteMusic(Music *head)
{
    int val;
    cout << "Enter the music to delete : ";
    cin >> val;

    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return head;
    }

    Music *temp = head;
    Music *prev = NULL;
    bool found = false;

    do
    {
        if (temp->no == val)
        {
            if (prev == NULL)
            {
                while (temp->next != head)
                {
                    temp = temp->next;
                }
                temp->next = head->next;
                delete head;
                head = temp->next;
            }
            else
            {
                prev->next = temp->next;
                delete temp;
            }
            cout << "Song deleted." << endl;
            found = true;
            break;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != head);

    if (!found)
    {
        cout << "Song not found." << endl;
    }

    return head;
}

Music *searchMusic(Music *head)
{
    int val;
    cout << "Enter value to find: ";
    cin >> val;
    if (head == NULL)
    {
        cout << "Music list is empty, Cannot search." << endl;
        return head;
    }

    Music *temp = head;
    do
    {
        if (temp->no == val)
        {
            cout << "Song found." << endl;
            cout << temp->no << "\t" << temp->title << "\t" << temp->artist << "\t" << temp->generation << "\t" << temp->duration << "\t" << temp->releaseYear << endl;
            return temp;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Element not found." << endl;
    return head;
}
Music* updateMusic(Music *head)
{
    int val;
    cout << "Enter song number to update : ";
    cin >> val;
    Music *temp = head;
    if (head == NULL)
    {
        cout << "Music list is empty, Cannot search." << endl;
        return head;
    }
    do
    {
        if (temp->no == val)
        {
            cout << "Enter music number : ";
            cin >> temp->no;
            cout << " Enter Title : ";
            cin >> temp->title;
            cout << "Enter artist : ";
            cin >> temp->artist;
            cout << "Enter Duration : ";
            cin >> temp->duration;
            cout << "enter generation : ";
            cin >> temp->generation;
            cout << "Enter release year : ";
            cin >> temp->releaseYear;
            cout << "Song updated..." << endl;
            cout << temp->no << "\t" << temp->title << "\t" << temp->artist << "\t" << temp->generation << "\t" << temp->duration << "\t" << temp->releaseYear << endl;
        }
        temp = temp->next;
    } while (temp != head);
    return head;
}
int main()
{
    int ch, choice1;
    Music *head;
    
    head = createMusic();
    sample:
    cout << "********************************" << endl;
    cout << "MENU" << endl;
    cout << "1. Insert Record " << endl;
    cout << "2. Insert After Record " << endl;
    cout << "3. Update Record " << endl;
    cout << "4. Delete Record " << endl;
    cout << "5. Search Record " << endl;
    cout << "6. Display Record " << endl;
    cout << "7. Exit " << endl;
    cout << "********************************" << endl;
    cin >> ch;

    switch (ch)
    {
    case 1:
        head = insertMusic(head);
        break;
    case 2:
        head = insertAfter(head);
        break;
    case 3:
        head = updateMusic(head);
        break;
    case 4:
        head = deleteMusic(head);
        break;
    case 5:
        head = searchMusic(head);
        break;
    case 6:
        head = displayMusic(head);
        break;
    case 7:
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