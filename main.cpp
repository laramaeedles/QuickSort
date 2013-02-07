#include <iostream>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

int partition(int* input, int l, int g)
{
    int pivot = input[g];

    while ( l < g )
    {
        while ( input[l] < pivot )
            l++;

        while ( input[g] > pivot )
            g--;

        if ( input[l] == input[g] )
            l++;
        else if ( l < g )
        {
            int temp = input[l];
            input[l] = input[g];
            input[g] = temp;
        }
    }

    return g;
}

void quicksort(int* input, int l, int g)
{
    if ( l < g )
    {
        int w = partition(input, l, g);
        quicksort(input, l, w-1);
        quicksort(input, w+1, g);
    }
}

int main()
{
    int c = 0, n=10000;
    int numbers[10000];
    string line;
    fstream myfile;
    myfile.open("data10k.txt");
    while(myfile.good())
    {
        getline(myfile,line);
        stringstream(line)>>numbers[c];
        c++;
    }
//Laman ng Array
    /*for(c = 0; c<n; c++)
    {
        cout<<numbers[c]<<endl;
    }*/

    cout<<"\n\n\nSorting\n";
    quicksort(numbers, 0, n);

//Laman ng Sorted Array
    for(c = 0; c<n; c++)
    {
        cout<<numbers[c]<<endl;
    }
    myfile.close();

    return 0;
}
