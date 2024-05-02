#include "iostream"

using namespace std;

int main()
{
    int* ptr;
    ptr = (int *)calloc(10, sizeof(int));

    ptr = (int *)realloc(ptr, 20);
    
    return 0;
}