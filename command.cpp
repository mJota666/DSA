#include "DataGenerator.h"
#include "command.h"

#include "shellSort.h"
#include "bubbleSort.h"
#include "countingSort.h"
#include "flashSort.h"
#include "heapSort.h"
#include "insertionSort.h"
#include "radixSort.h"
#include "selectionSort.h"
#include "shakerSort.h"
#include "mergeSort.h"

void command_2(int argc, char *argv[])
{

    string algorithm;
    string size;
    string order;
    string output;

    //./main -a bubble-sort 50000 -rand -time

    if (argc >= 6)
    {
        algorithm = argv[2];
        size = argv[3];
        order = argv[4];
        output = argv[5];
    }
    for (int i = 0; i < algorithm.length(); i++)
    {
        if (algorithm[i] == '-')
        {
            algorithm = algorithm.substr(0, i);
        }
    }

    int input_size = stoi(size);

    int *a = new int[input_size];
    if (order == "-rand")
    {
        GenerateData(a, input_size, 0);
    }
    else if (order == "-nsorted")
    {
        GenerateData(a, input_size, 1);
    }
    else if (order == "-sorted")
    {
        GenerateData(a, input_size, 3);
    }
    else if (order == "-rev")
    {
        GenerateData(a, input_size, 2);
    }

    int *b = new int[input_size];
    memcpy(b, a, input_size * sizeof(int));
    int count_comp = 0;
    long double time = 0;
    cout << "ALGORITHM MODE" << endl;
    cout << "Algorithm: " << algorithm << " sort" << endl;
    cout << "Input size: " << input_size << endl;
    cout << "Input order: " << order.substr(1, order.length() - 1) << endl;
    cout << "-----------------------------------" << endl;
    if (algorithm == "selection")
    {
    }
    else if (algorithm == "bubble")
    {

        if (output == "-time")
        {

            bubble_sort_time(a, input_size, time);
            cout << "Running time: " << time << endl;
        }
        else if (output == "-comp")
        {

            bubble_sort_comp(a, input_size, count_comp);
            cout << "Comparisions: " << count_comp << endl;
        }
        else if (output == "-both")
        {
            bubble_sort_comp(a, input_size, count_comp);
            bubble_sort_time(b, input_size, time);
            cout << "Running time: " << time << endl;
            cout << "Comparisions: " << count_comp << endl;
        }
    }
    else if (algorithm == "radix")
    {

        if (output == "-time")
        {

            radix_sort_time(a, input_size, time);
            cout << "Running time: " << time << endl;
        }
        else if (output == "-comp")
        {

            radix_sort_comp(a, input_size, count_comp);
            cout << "Comparisions: " << count_comp << endl;
        }
        else if (output == "-both")
        {
            radix_sort_comp(a, input_size, count_comp);
            radix_sort_time(b, input_size, time);
            cout << "Running time: " << time << endl;
            cout << "Comparisions: " << count_comp << endl;
        }
    }
    else if (algorithm == "heap")
    {
        if (output == "-time")
        {
            heap_sort_time(a, input_size, time);
            cout << "Running time: " << time << endl;
        }
        else if (output == "-comp")
        {

            heap_sort_comp(a, input_size, count_comp);
            cout << "Comparisions: " << count_comp << endl;
        }
        else if (output == "-both")
        {
            heap_sort_comp(a, input_size, count_comp);
            heap_sort_time(b, input_size, time);
            cout << "Running time: " << time << endl;
            cout << "Comparisions: " << count_comp << endl;
        }
    }
    else if (algorithm == "flash")
    {
    }
    else if (algorithm == "shaker")
    {
        if (output == "-time")
        {
            shaker_sort_time(a, input_size, time);
            cout << "Running time: " << time << endl;
        }
        else if (output == "-comp")
        {

            shaker_sort_comp(a, input_size, count_comp);
            cout << "Comparisions: " << count_comp << endl;
        }
        else if (output == "-both")
        {
            shaker_sort_comp(a, input_size, count_comp);
            shaker_sort_time(b, input_size, time);
            cout << "Running time: " << time << endl;
            cout << "Comparisions: " << count_comp << endl;
        }
    }
    else if (algorithm == "counting")
    {
    }
    else if (algorithm == "quick")
    {
    }
    else if (algorithm == "shell")
    {
    }
    else if (algorithm == "merge")
    {
    }
    else if (algorithm == "insertion")
    {
    }
    // clear mem
    delete[] a;
    delete[] b;
}

void command_3(int argc, char *argv[])
{
    cout << fixed << setprecision(5);
    string algorithm_sort = argv[2];
    int input_size = stoi(argv[3]);
    string output_param = argv[4];
    string param[] = {"-comp", "-time", "-both"};
    int cnt = 0;
    for (int i = 0; i < 3; i++)
    {
        if (output_param.find(param[i]) != string::npos)
        {
            cnt++;
        }
    }
    if (cnt == 0)
    {
        cout << "Wrong Syntax at Ouput Param\n";
        return;
    }

    cout << "ALGORITHM MODE\n";
    cout << "Algorithm: " << algorithm_sort << endl;
    cout << "Input size: " << input_size << endl;

    string input_order[] = {"Randomize", "Nearly Sorted", "Sorted", "Reversed"};
    for (int i = 0; i < 4; i++)
    {
        int *a = new int[input_size];
        int *a1 = new int[input_size];
        GenerateData(a, input_size, i);
        cout << "\nInput order: " << input_order[i] << endl;
        cout << "-------------------------\n";

        if (algorithm_sort.find("merge") != string::npos)
        {
            int count_comp = 0;
            long double time_use = 0;
            merge_sort_comp(a, input_size, count_comp);
            merge_sort_time(a1, input_size, time_use);
            if (output_param == "-time")
            {
                cout << "Running time: " << time_use << endl;
            }
            else if (output_param == "-comp")
            {
                cout << "Comparisions: " << count_comp << endl;
            }
            else if (output_param == "-both")
            {
                cout << "Running time: " << time_use << endl;
                cout << "Comparisions: " << count_comp << endl;
            }
        }
        else if (algorithm_sort.find("bubble") != string::npos)
        {
            int count_comp = 0;
            long double time_use = 0;
            bubble_sort_comp(a, input_size, count_comp);
            bubble_sort_time(a1, input_size, time_use);
            if (output_param == "-time")
            {
                cout << "Running time: " << time_use << endl;
            }
            else if (output_param == "-comp")
            {
                cout << "Comparisions: " << count_comp << endl;
            }
            else if (output_param == "-both")
            {
                cout << "Running time: " << time_use << endl;
                cout << "Comparisions: " << count_comp << endl;
            }
        }
        else if (algorithm_sort.find("counting") != string::npos)
        {
            int count_comp = 0;
            long double time_use = 0;
            counting_sort_comp(a, input_size, count_comp);
            counting_sort_time(a1, input_size, time_use);
            if (output_param == "-time")
            {
                cout << "Running time: " << time_use << endl;
            }
            else if (output_param == "-comp")
            {
                cout << "Comparisions: " << count_comp << endl;
            }
            else if (output_param == "-both")
            {
                cout << "Running time: " << time_use << endl;
                cout << "Comparisions: " << count_comp << endl;
            }
        }
        else if (algorithm_sort.find("flash") != string::npos)
        {
            int count_comp = 0;
            long double time_use = 0;
            flash_sort_comp(a, input_size, count_comp);
            flash_sort_time(a1, input_size, time_use);
            if (output_param == "-time")
            {
                cout << "Running time: " << time_use << endl;
            }
            else if (output_param == "-comp")
            {
                cout << "Comparisions: " << count_comp << endl;
            }
            else if (output_param == "-both")
            {
                cout << "Running time: " << time_use << endl;
                cout << "Comparisions: " << count_comp << endl;
            }
        }
        else if (algorithm_sort.find("heap") != string::npos)
        {
            int count_comp = 0;
            long double time_use = 0;
            heap_sort_comp(a, input_size, count_comp);
            heap_sort_time(a1, input_size, time_use);
            if (output_param == "-time")
            {
                cout << "Running time: " << time_use << endl;
            }
            else if (output_param == "-comp")
            {
                cout << "Comparisions: " << count_comp << endl;
            }
            else if (output_param == "-both")
            {
                cout << "Running time: " << time_use << endl;
                cout << "Comparisions: " << count_comp << endl;
            }
        }
        else if (algorithm_sort.find("insertion") != string::npos)
        {
            int count_comp = 0;
            long double time_use = 0;
            insertion_sort_comp(a, input_size, count_comp);
            insertion_sort_time(a1, input_size, time_use);
            if (output_param == "-time")
            {
                cout << "Running time: " << time_use << endl;
            }
            else if (output_param == "-comp")
            {
                cout << "Comparisions: " << count_comp << endl;
            }
            else if (output_param == "-both")
            {
                cout << "Running time: " << time_use << endl;
                cout << "Comparisions: " << count_comp << endl;
            }
        }
        else if (algorithm_sort.find("radix") != string::npos)
        {
            int count_comp = 0;
            long double time_use = 0;
            radix_sort_comp(a, input_size, count_comp);
            radix_sort_time(a1, input_size, time_use);
            if (output_param == "-time")
            {
                cout << "Running time: " << time_use << endl;
            }
            else if (output_param == "-comp")
            {
                cout << "Comparisions: " << count_comp << endl;
            }
            else if (output_param == "-both")
            {
                cout << "Running time: " << time_use << endl;
                cout << "Comparisions: " << count_comp << endl;
            }
        }
        else if (algorithm_sort.find("selection") != string::npos)
        {
            int count_comp = 0;
            long double time_use = 0;
            selection_sort_comp(a, input_size, count_comp);
            selection_sort_time(a1, input_size, time_use);
            if (output_param == "-time")
            {
                cout << "Running time: " << time_use << endl;
            }
            else if (output_param == "-comp")
            {
                cout << "Comparisions: " << count_comp << endl;
            }
            else if (output_param == "-both")
            {
                cout << "Running time: " << time_use << endl;
                cout << "Comparisions: " << count_comp << endl;
            }
        }
        else if (algorithm_sort.find("shaker") != string::npos)
        {
            int count_comp = 0;
            long double time_use = 0;
            shaker_sort_comp(a, input_size, count_comp);
            shaker_sort_time(a1, input_size, time_use);
            if (output_param == "-time")
            {
                cout << "Running time: " << time_use << endl;
            }
            else if (output_param == "-comp")
            {
                cout << "Comparisions: " << count_comp << endl;
            }
            else if (output_param == "-both")
            {
                cout << "Running time: " << time_use << endl;
                cout << "Comparisions: " << count_comp << endl;
            }
        }
        else if (algorithm_sort.find("shell") != string::npos)
        {
            int count_comp = 0;
            long double time_use = 0;
            shell_sort_comp(a, input_size, count_comp);
            shell_sort_time(a1, input_size, time_use);
            if (output_param == "-time")
            {
                cout << "Running time: " << time_use << endl;
            }
            else if (output_param == "-comp")
            {
                cout << "Comparisions: " << count_comp << endl;
            }
            else if (output_param == "-both")
            {
                cout << "Running time: " << time_use << endl;
                cout << "Comparisions: " << count_comp << endl;
            }
        }
      
        delete[] a;
        a = nullptr;
        delete[] a1;
        a1 = nullptr;
    }
}
/*
void command_5(int argc, char* argv[]){
    int n = stoi(argv[4]);
    int *data = new int[n];
    int *data1_comp = new int[n];
    int *data1_time = new int[n];
    int *data2_comp = new int[n];
    int *data2_time = new int[n];
    char *sort_algorithms_1 = new char[20], *sort_algorithms_2 =  new char[20];
    int cmp_sort_1 = 0 , cmp_sort_2 = 0 ;
    long double time_sort_1 = 0, time_sort_2 = 0 ;
    strcpy(sort_algorithms_1,argv[2]);
    strcpy(sort_algorithms_2,argv[3]);
    if (!strcmp(argv[5],"-rand")) {
        GenerateRandomData(data, n);
    }
    else if (!strcmp(argv[5],"-nsorted")){
        GenerateNearlySortedData(data, n);
    }
    else if (!strcmp(argv[5],"-sorted")){
        GenerateSortedData(data, n);
    }
    else if(!strcmp(argv[5],"-rev")){
        GenerateReverseData(data, n);
    }
    else{
        cout << "No array have init"  << endl;
        return;
    }
    memcpy(data1_comp, data, n*4);
    memcpy(data1_time, data, n*4);
    if (!strcmp(sort_algorithms_1,"quick-sort")){
       // quick_sort_comp(data1_comp, 0, n-1, cmp_sort_1);
        //quick_sort_time(data1_time, 0, n-1, time_sort_1);
    }
    else if (!strcmp(sort_algorithms_1,"selection-sort")){
        selection_sort_comp(data1_comp, n, cmp_sort_1);
        selection_sort_time(data1_time, n, time_sort_1);
    }
    else if (!strcmp(sort_algorithms_1,"counting-sort")){
        counting_sort_comp(data1_comp, n, cmp_sort_1);
        counting_sort_time(data1_time, n, time_sort_1);
    }
    else {
        cout <<"No sort 1 found" << endl;
        return;
    }
    delete [] data1_comp;
    delete [] data1_time;
    memcpy(data2_comp, data, n*4);
    memcpy(data2_time, data, n*4);
     if (!strcmp(sort_algorithms_2,"quick-sort")){
       // quick_sort_comp(data2_comp, 0, n-1, cmp_sort_2);
        //quick_sort_time(data2_time, 0, n-1, time_sort_2);
    }
    else if (!strcmp(sort_algorithms_2,"selection-sort")){
        selection_sort_comp(data2_comp, n, cmp_sort_2);
        selection_sort_time(data2_time, n, time_sort_2);
    }
    else if (!strcmp(sort_algorithms_2,"counting-sort")){
        counting_sort_comp(data2_comp, n, cmp_sort_2);
        counting_sort_time(data2_time, n, time_sort_2);
    }
    else {
        cout <<"No sort 2 found" << endl;
        return;
    }
    cout << "Algorithms: " << sort_algorithms_1 << " | " << sort_algorithms_2 << endl;
    cout << "Input size: " << n << endl;
    cout << "Input order: " << argv[5] << endl;
    cout << "---------------------------" << endl;
    cout << "Running time: " << setprecision(5)<< fixed << time_sort_1 << " | "<<setprecision(5)<< fixed << time_sort_2  << endl;
    cout << "Comparsions : " << cmp_sort_1 << " | " << cmp_sort_2 << endl;
    cout << endl;
    delete [] data;
    delete [] data2_comp;
    delete [] data2_time;
    delete []sort_algorithms_1;
    delete []sort_algorithms_2;
}
*/

void output_file(int n)
{
    int *a = new int[n];
    ofstream output("input.txt");
    GenerateRandomData(a, n);
    output << n << endl;
    for (int i = 0; i < n; i++)
    {
        output << a[i] << " ";
    }
    output.close();
    delete[] a;
}

void command_1(int argc, char *argv[])
{

    string algorithm_sort;
    string input_file;
    string output;

    if (argc >= 5)
    {
        algorithm_sort = argv[2];
        input_file = argv[3];
        output = argv[4];
    }
    for (int i = 0; i < algorithm_sort.length(); i++)
    {
        if (algorithm_sort[i] == '-')
        {
            algorithm_sort = algorithm_sort.substr(0, i);
        }
    }

    ifstream input(input_file);
    int n = 0;
    input >> n;
    int *a = new int[n];
    int *b = new int[n];
    for (int i = 0; i < n; i++)
    {
        input >> a[i];
    }
    memcpy(b, a, n * sizeof(int));
    input.close();
    int input_size = n;
    int count_comp = 0;
    long double time = 0;
    cout << "ALGORITHM MODE" << endl;
    cout << "Algorithm: " << algorithm_sort << " sort" << endl;
    cout << "Input file: " << input_file << endl;
    cout << "Input size: " << input_size << endl;
    cout << "-----------------------------------" << endl;
    if (algorithm_sort == "selection")
    {
        if (output == "-time")
        {
            selection_sort_time(a, input_size, time);
            cout << "Running time: " << time << endl;
        }
        else if (output == "-comp")
        {
            selection_sort_comp(a, input_size, count_comp);
            cout << "Comparisions: " << count_comp << endl;
        }
        else if (output == "-both")
        {
            selection_sort_comp(a, input_size, count_comp);
            selection_sort_time(b, input_size, time);
            cout << "Running time: " << time << endl;
            cout << "Comparisions: " << count_comp << endl;
        }
    }
    else if (algorithm_sort == "bubble")
    {
        if (output == "-time")
        {
            bubble_sort_time(a, input_size, time);
            cout << "Running time: " << time << endl;
        }
        else if (output == "-comp")
        {

            bubble_sort_comp(a, input_size, count_comp);
            cout << "Comparisions: " << count_comp << endl;
        }
        else if (output == "-both")
        {
            bubble_sort_comp(a, input_size, count_comp);
            bubble_sort_time(b, input_size, time);
            cout << "Running time: " << time << endl;
            cout << "Comparisions: " << count_comp << endl;
        }
    }
    else if (algorithm_sort == "radix")
    {
        if (output == "-time")
        {
            radix_sort_time(a, input_size, time);
            cout << "Running time: " << time << endl;
        }
        else if (output == "-comp")
        {
            radix_sort_comp(a, input_size, count_comp);
            cout << "Comparisions: " << count_comp << endl;
        }
        else if (output == "-both")
        {
            radix_sort_comp(a, input_size, count_comp);
            radix_sort_time(b, input_size, time);
            cout << "Running time: " << time << endl;
            cout << "Comparisions: " << count_comp << endl;
        }
    }
    else if (algorithm_sort == "heap")
    {
        if (output == "-time")
        {
            heap_sort_time(a, input_size, time);
            cout << "Running time: " << time << endl;
        }
        else if (output == "-comp")
        {
            heap_sort_comp(a, input_size, count_comp);
            cout << "Comparisions: " << count_comp << endl;
        }
        else if (output == "-both")
        {
            heap_sort_comp(a, input_size, count_comp);
            heap_sort_time(b, input_size, time);
            cout << "Running time: " << time << endl;
            cout << "Comparisions: " << count_comp << endl;
        }
    }
    else if (algorithm_sort == "flash")
    {
        if (output == "-time")
        {

            flash_sort_time(a, input_size, time);
            cout << "Running time: " << time << endl;
        }
        else if (output == "-comp")
        {

            flash_sort_comp(a, input_size, count_comp);
            cout << "Comparisions: " << count_comp << endl;
        }
        else if (output == "-both")
        {
            flash_sort_comp(a, input_size, count_comp);
            flash_sort_time(b, input_size, time);
            cout << "Running time: " << time << endl;
            cout << "Comparisions: " << count_comp << endl;
        }
    }
    else if (algorithm_sort == "shaker")
    {
        if (output == "-time")
        {
            shaker_sort_time(a, input_size, time);
            cout << "Running time: " << time << endl;
        }
        else if (output == "-comp")
        {

            shaker_sort_comp(a, input_size, count_comp);
            cout << "Comparisions: " << count_comp << endl;
        }
        else if (output == "-both")
        {
            shaker_sort_comp(a, input_size, count_comp);
            shaker_sort_time(b, input_size, time);
            cout << "Running time: " << time << endl;
            cout << "Comparisions: " << count_comp << endl;
        }
    }
    else if (algorithm_sort == "counting")
    {
        if (output == "-time")
        {
            counting_sort_time(a, input_size, time);
            cout << "Running time: " << time << endl;
        }
        else if (output == "-comp")
        {
            counting_sort_comp(a, input_size, count_comp);
            cout << "Comparisions: " << count_comp << endl;
        }
        else if (output == "-both")
        {
            counting_sort_comp(a, input_size, count_comp);
            counting_sort_time(b, input_size, time);
            cout << "Running time: " << time << endl;
            cout << "Comparisions: " << count_comp << endl;
        }
    }

    /*else if (algorithm_sort == "quick")
    {
        if (output == "-time")
        {
            quick_sort_time(a, input_size, time);
            cout << "Running time: " << time << endl;
        }
        else if (output == "-comp")
        {
            quick_sort_comp(a, input_size, count_comp);
            cout << "Comparisions: " << count_comp << endl;
        }
        else if (output == "-both")
        {
            quick_sort_comp(a, input_size, count_comp);
            quick_sort_time(b, input_size, time);
            cout << "Running time: " << time << endl;
            cout << "Comparisions: " << count_comp << endl;
        }
    }*/
    else if (algorithm_sort == "shell")
    {
        if (output == "-time")
        {
            shell_sort_time(a, input_size, time);
            cout << "Running time: " << time << endl;
        }
        else if (output == "-comp")
        {
            shell_sort_comp(a, input_size, count_comp);
            cout << "Comparisions: " << count_comp << endl;
        }
        else if (output == "-both")
        {
            shell_sort_comp(a, input_size, count_comp);
            shell_sort_time(b, input_size, time);
            cout << "Running time: " << time << endl;
            cout << "Comparisions: " << count_comp << endl;
        }
    }
    else if (algorithm_sort == "merge")
    {
        if (output == "-time")
        {
            // merge_sort_time(a, input_size, time);
            cout << "Running time: " << time << endl;
        }
        else if (output == "-comp")
        {
            //   merge_sort_comp(a, input_size, count_comp);
            cout << "Comparisions: " << count_comp << endl;
        }
        else if (output == "-both")
        {
            // merge_sort_comp(a, input_size, count_comp);
            // merge_sort_time(b, input_size, time);
            cout << "Running time: " << time << endl;
            cout << "Comparisions: " << count_comp << endl;
        }
    }
    else if (algorithm_sort == "insertion")
    {
        if (output == "-time")
        {
            //  merge_sort_time(a, input_size, time);
            cout << "Running time: " << time << endl;
        }
        else if (output == "-comp")
        {
            //  merge_sort_comp(a, input_size, count_comp);
            cout << "Comparisions: " << count_comp << endl;
        }
        else if (output == "-both")
        {
            // merge_sort_comp(a, input_size, count_comp);
            // merge_sort_time(b, input_size, time);
            cout << "Running time: " << time << endl;
            cout << "Comparisions: " << count_comp << endl;
        }
    }

    ofstream outputFile("output.txt");
    outputFile << n << endl;
    for (int i = 0; i < n; i++)
    {
        outputFile << a[i] << " ";
    }
    outputFile.close();

    // output
    delete[] a;
    delete[] b;
}
/*
void command_4(int argc,  char* argv[]) {


    string algorithm1;
    string algorithm2;
    string input_file;

    if (argc >= 5) {
        algorithm1 = argv[2];
        algorithm2 = argv[3];
        input_file = argv[4];
    }

    for (int i = 0; i < algorithm1.length(); i++)
    {
        if (algorithm1[i] == '-')
        {
            algorithm1 = algorithm1.substr(0, i);
        }
    }
    for (int i = 0; i < algorithm2.length(); i++)
    {
        if (algorithm2[i] == '-')
        {
            algorithm2 = algorithm2.substr(0, i);
        }
    }

    ifstream input(input_file);
    int n = 0;
    //a - comparision     b - time
    //1 - algo1           2 - algo2
    int* a1 = new int[n];
    int* b1 = new int[n];
    int* a2 = new int[n];
    int* b2 = new int[n];
    input >> n;
    for (int i = 0; i < n; i++) {
        input >> a1[i];
    }
    memcpy(b1, a1, n * sizeof(int));
    memcpy(a2, a1, n * sizeof(int));
    memcpy(b2, a1, n * sizeof(int));
    input.close();

    int input_size = n;
    int count_comp1 = 0;
    long double time1 = 0;
    int count_comp2 = 0;
    long double time2 = 0;

    cout << "COMPARE MODE" << endl;
    cout << "Algorithm: " << algorithm1 << " sort | "<<algorithm2 <<" sort" << endl;
    cout << "Input file: " << input_file << endl;
    cout << "Input size: " << input_size << endl;
    cout << "-----------------------------------" << endl;

    if (algorithm1 == "selection")
    {
        selection_sort_comp(a1, input_size, count_comp1);
        selection_sort_time(b1, input_size, time1);
        if (algorithm2 == "bubble")
        {
            bubble_sort_comp(a2, input_size, count_comp2);
            bubble_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "radix")
        {
            radix_sort_comp(a2, input_size, count_comp2);
            radix_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "heap")
        {
            heap_sort_comp(a2, input_size, count_comp2);
            heap_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "flash")
        {
            flash_sort_comp(a2, input_size, count_comp2);
            flash_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "shaker")
        {
            shaker_sort_comp(a2, input_size, count_comp2);
            shaker_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "counting")
        {
            counting_sort_comp(a2, input_size, count_comp2);
            counting_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "quick")
        {
          //  quick_sort_comp(a2, input_size, count_comp2);
           // quick_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "shell")
        {
            shell_sort_comp(a2, input_size, count_comp2);
            shell_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "merge")
        {
          //  merge_sort_comp(a2, input_size, count_comp2);
           // merge_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "insertion")
        {
            insertion_sort_comp(a2, input_size, count_comp2);
            insertion_sort_time(b2, input_size, time2);
        }
    }
    else if (algorithm1 == "bubble")
    {
        bubble_sort_comp(a1, input_size, count_comp1);
        bubble_sort_time(b1, input_size, time1);
        if (algorithm2 == "selection")
        {
            selection_sort_comp(a2, input_size, count_comp2);
            selection_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "radix")
        {
            radix_sort_comp(a2, input_size, count_comp2);
            radix_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "heap")
        {
            heap_sort_comp(a2, input_size, count_comp2);
            heap_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "flash")
        {
            flash_sort_comp(a2, input_size, count_comp2);
            flash_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "shaker")
        {
            shaker_sort_comp(a2, input_size, count_comp2);
            shaker_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "counting")
        {
            counting_sort_comp(a2, input_size, count_comp2);
            counting_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "quick")
        {
            //quick_sort_comp(a2, input_size, count_comp2);
            //quick_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "shell")
        {
            shell_sort_comp(a2, input_size, count_comp2);
            shell_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "merge")
        {
          //  merge_sort_comp(a2, input_size, count_comp2);
           // merge_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "insertion")
        {
            insertion_sort_comp(a2, input_size, count_comp2);
            insertion_sort_time(b2, input_size, time2);
        }
    }
    else if (algorithm1 == "radix")
    {
        radix_sort_comp(a1, input_size, count_comp1);
        radix_sort_time(b1, input_size, time1);
        if (algorithm2 == "selection")
        {
            selection_sort_comp(a2, input_size, count_comp2);
            selection_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "bubble")
        {
            bubble_sort_comp(a2, input_size, count_comp2);
            bubble_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "heap")
        {
            heap_sort_comp(a2, input_size, count_comp2);
            heap_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "flash")
        {
            flash_sort_comp(a2, input_size, count_comp2);
            flash_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "shaker")
        {
            shaker_sort_comp(a2, input_size, count_comp2);
            shaker_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "counting")
        {
            counting_sort_comp(a2, input_size, count_comp2);
            counting_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "quick")
        {
          //  quick_sort_comp(a2, input_size, count_comp2);
          //  quick_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "shell")
        {
            shell_sort_comp(a2, input_size, count_comp2);
            shell_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "merge")
        {
         //   merge_sort_comp(a2, input_size, count_comp2);
           // merge_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "insertion")
        {
            insertion_sort_comp(a2, input_size, count_comp2);
            insertion_sort_time(b2, input_size, time2);
        }
    }
    else if (algorithm1 == "heap")
    {
        heap_sort_comp(a1, input_size, count_comp1);
        heap_sort_time(b1, input_size, time1);
        if (algorithm2 == "selection")
        {
            selection_sort_comp(a2, input_size, count_comp2);
            selection_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "bubble")
        {
            bubble_sort_comp(a2, input_size, count_comp2);
            bubble_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "radix")
        {
            radix_sort_comp(a2, input_size, count_comp2);
            radix_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "flash")
        {
            flash_sort_comp(a2, input_size, count_comp2);
            flash_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "shaker")
        {
            shaker_sort_comp(a2, input_size, count_comp2);
            shaker_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "counting")
        {
            counting_sort_comp(a2, input_size, count_comp2);
            counting_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "quick")
        {
        //    quick_sort_comp(a2, input_size, count_comp2);
          //  quick_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "shell")
        {
            shell_sort_comp(a2, input_size, count_comp2);
            shell_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "merge")
        {
            //merge_sort_comp(a2, input_size, count_comp2);
          //  merge_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "insertion")
        {
            insertion_sort_comp(a2, input_size, count_comp2);
            insertion_sort_time(b2, input_size, time2);
        }
    }
    else if (algorithm1 == "flash")
    {
        flash_sort_comp(a1, input_size, count_comp1);
        flash_sort_time(b1, input_size, time1);
        if (algorithm2 == "selection")
        {
            selection_sort_comp(a2, input_size, count_comp2);
            selection_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "bubble")
        {
            bubble_sort_comp(a2, input_size, count_comp2);
            bubble_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "radix")
        {
            radix_sort_comp(a2, input_size, count_comp2);
            radix_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "heap")
        {
            heap_sort_comp(a2, input_size, count_comp2);
            heap_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "shaker")
        {
            shaker_sort_comp(a2, input_size, count_comp2);
            shaker_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "counting")
        {
            counting_sort_comp(a2, input_size, count_comp2);
            counting_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "quick")
        {
           // quick_sort_comp(a2, input_size, count_comp2);
            //quick_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "shell")
        {
            shell_sort_comp(a2, input_size, count_comp2);
            shell_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "merge")
        {
         //   merge_sort_comp(a2, input_size, count_comp2);
         //   merge_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "insertion")
        {
            insertion_sort_comp(a2, input_size, count_comp2);
            insertion_sort_time(b2, input_size, time2);
        }
    }
    else if (algorithm1 == "shaker")
    {
        shaker_sort_comp(a1, input_size, count_comp1);
        shaker_sort_time(b1, input_size, time1);
        if (algorithm2 == "selection")
        {
            selection_sort_comp(a2, input_size, count_comp2);
            selection_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "bubble")
        {
            bubble_sort_comp(a2, input_size, count_comp2);
            bubble_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "radix")
        {
            radix_sort_comp(a2, input_size, count_comp2);
            radix_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "heap")
        {
            heap_sort_comp(a2, input_size, count_comp2);
            heap_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "flash")
        {
            flash_sort_comp(a2, input_size, count_comp2);
            flash_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "counting")
        {
            counting_sort_comp(a2, input_size, count_comp2);
            counting_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "quick")
        {
       //     quick_sort_comp(a2, input_size, count_comp2);
         //   quick_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "shell")
        {
            shell_sort_comp(a2, input_size, count_comp2);
            shell_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "merge")
        {
           // merge_sort_comp(a2, input_size, count_comp2);
           // merge_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "insertion")
        {
            insertion_sort_comp(a2, input_size, count_comp2);
            insertion_sort_time(b2, input_size, time2);
        }
    }
    else if (algorithm1 == "counting")
    {
        counting_sort_comp(a1, input_size, count_comp1);
        counting_sort_time(b1, input_size, time1);
        if (algorithm2 == "selection")
        {
            selection_sort_comp(a2, input_size, count_comp2);
            selection_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "bubble")
        {
            bubble_sort_comp(a2, input_size, count_comp2);
            bubble_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "radix")
        {
            radix_sort_comp(a2, input_size, count_comp2);
            radix_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "heap")
        {
            heap_sort_comp(a2, input_size, count_comp2);
            heap_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "flash")
        {
            flash_sort_comp(a2, input_size, count_comp2);
            flash_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "shaker")
        {
            shaker_sort_comp(a2, input_size, count_comp2);
            shaker_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "quick")
        {
        //    quick_sort_comp(a2, input_size, count_comp2);
          //  quick_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "shell")
        {
            shell_sort_comp(a2, input_size, count_comp2);
            shell_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "merge")
        {
         //   merge_sort_comp(a2, input_size, count_comp2);
          //  merge_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "insertion")
        {
            insertion_sort_comp(a2, input_size, count_comp2);
            insertion_sort_time(b2, input_size, time2);
        }
    }
    else if (algorithm1 == "quick")
    {
      //  quick_sort_comp(a1, input_size, count_comp1);
        //quick_sort_time(b1, input_size, time1);
        if (algorithm2 == "selection")
        {
            selection_sort_comp(a2, input_size, count_comp2);
            selection_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "bubble")
        {
            bubble_sort_comp(a2, input_size, count_comp2);
            bubble_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "radix")
        {
            radix_sort_comp(a2, input_size, count_comp2);
            radix_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "heap")
        {
            heap_sort_comp(a2, input_size, count_comp2);
            heap_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "flash")
        {
            flash_sort_comp(a2, input_size, count_comp2);
            flash_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "shaker")
        {
            shaker_sort_comp(a2, input_size, count_comp2);
            shaker_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "counting")
        {
            counting_sort_comp(a2, input_size, count_comp2);
            counting_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "shell")
        {
            shell_sort_comp(a2, input_size, count_comp2);
            shell_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "merge")
        {
          //  merge_sort_comp(a2, input_size, count_comp2);
          //  merge_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "insertion")
        {
            insertion_sort_comp(a2, input_size, count_comp2);
            insertion_sort_time(b2, input_size, time2);
        }
    }
    else if (algorithm1 == "shell")
    {
        shell_sort_comp(a1, input_size, count_comp1);
        shell_sort_time(b1, input_size, time1);
        if (algorithm2 == "selection")
        {
            selection_sort_comp(a2, input_size, count_comp2);
            selection_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "bubble")
        {
            bubble_sort_comp(a2, input_size, count_comp2);
            bubble_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "radix")
        {
            radix_sort_comp(a2, input_size, count_comp2);
            radix_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "heap")
        {
            heap_sort_comp(a2, input_size, count_comp2);
            heap_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "flash")
        {
            flash_sort_comp(a2, input_size, count_comp2);
            flash_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "shaker")
        {
            shaker_sort_comp(a2, input_size, count_comp2);
            shaker_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "counting")
        {
            counting_sort_comp(a2, input_size, count_comp2);
            counting_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "quick")
        {
           // quick_sort_comp(a2, input_size, count_comp2);
            //quick_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "merge")
        {
            //merge_sort_comp(a2, input_size, count_comp2);
            //merge_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "insertion")
        {
            insertion_sort_comp(a2, input_size, count_comp2);
            insertion_sort_time(b2, input_size, time2);
        }
    }
    else if (algorithm1 == "merge")
    {
       // merge_sort_comp(a1, input_size, count_comp1);
       // merge_sort_time(b1, input_size, time1);
        if (algorithm2 == "selection")
        {
            selection_sort_comp(a2, input_size, count_comp2);
            selection_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "bubble")
        {
            bubble_sort_comp(a2, input_size, count_comp2);
            bubble_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "radix")
        {
            radix_sort_comp(a2, input_size, count_comp2);
            radix_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "heap")
        {
            heap_sort_comp(a2, input_size, count_comp2);
            heap_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "flash")
        {
            flash_sort_comp(a2, input_size, count_comp2);
            flash_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "shaker")
        {
            shaker_sort_comp(a2, input_size, count_comp2);
            shaker_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "counting")
        {
            counting_sort_comp(a2, input_size, count_comp2);
            counting_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "quick")
        {
         //   quick_sort_comp(a2, input_size, count_comp2);
           // quick_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "shell")
        {
            shell_sort_comp(a2, input_size, count_comp2);
            shell_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "insertion")
        {
            insertion_sort_comp(a2, input_size, count_comp2);
            insertion_sort_time(b2, input_size, time2);
        }
    }
    else if (algorithm1 == "insertion")
    {
        insertion_sort_comp(a1, input_size, count_comp1);
        insertion_sort_time(b1, input_size, time1);
        if (algorithm2 == "selection")
        {
            selection_sort_comp(a2, input_size, count_comp2);
            selection_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "bubble")
        {
            bubble_sort_comp(a2, input_size, count_comp2);
            bubble_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "radix")
        {
            radix_sort_comp(a2, input_size, count_comp2);
            radix_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "heap")
        {
            heap_sort_comp(a2, input_size, count_comp2);
            heap_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "flash")
        {
            flash_sort_comp(a2, input_size, count_comp2);
            flash_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "shaker")
        {
            shaker_sort_comp(a2, input_size, count_comp2);
            shaker_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "counting")
        {
            counting_sort_comp(a2, input_size, count_comp2);
            counting_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "quick")
        {
         //   quick_sort_comp(a2, input_size, count_comp2);
        //    quick_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "shell")
        {
            shell_sort_comp(a2, input_size, count_comp2);
            shell_sort_time(b2, input_size, time2);
        }
        else if (algorithm2 == "merge")
        {
          //  merge_sort_comp(a2, input_size, count_comp2);
           // merge_sort_time(b2, input_size, time2);
        }
    }

    //output
    cout << "Running time: " << time1 << " | " << time2 << endl;
    cout << "Comparisions: " << count_comp1 << " | " << count_comp2 << endl;
    delete[]a1;
    delete[]b1;
    delete[]a2;
    delete[]b2;
}
*/
