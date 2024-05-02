#include "iostream"
#include "cstdlib"

using namespace std;

int main()
{
    int* ptr;
    ptr = (int *)malloc(10 * sizeof(int));

    if (!ptr)
    {
        cout << "cannot allocate memory" << endl;
    }
    else
    {
        cout << "operation successful" << endl;
    }
    return 0;
}