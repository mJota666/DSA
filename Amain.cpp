#include "command.h"

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
}

int main(int argc, char* argv[])
{
    string mode = (string)argv[1];
    if ( mode =="-a" ){
        if(argc == 5){
            // command 1 - 3
            if(isalpha(argv[3][0])){
                command_1(argc, argv);
            }
            else{
                command_3(argc, argv);
            }
        }
        else if( argc == 6){
            // command 2
            command_2(argc, argv);
        }
        else {
            cout << "Wrong command!!!" << endl;
        }
    }
    else if (mode == "-c"){
        if(argc == 5){
            //command 4
            command_4(argc, argv);
        }
        else if(argc == 6){
            //command 5
            command_5(argc, argv);
        }
        else {
            cout << "Wrong command!!!" << endl;
        }
    }
    else{
        cout << "Wrong command!!!" << endl;
    }
    return 0;
}
