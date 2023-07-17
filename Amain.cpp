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
<<<<<<< HEAD
    cout<<"hahaha"<<endl;
} 
=======
    cout << "hehe thanh lz";
} 
>>>>>>> e7acd6d5e6ef05d980ff5bf9c87b39947bafe083
