#include "command.h"

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    if (argc == 5 && !strcmp(argv[1], "-a") && (string(argv[3]).find(".") == string::npos)) {
        command_3(argc, argv);
    }
    cout<<"hahaha"<<endl;
} 
