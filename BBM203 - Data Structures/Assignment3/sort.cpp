#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void sort(int MyArray[22][5]) {
    for(int i=0;i<22;i++) {
        for(int j=i+1;j<22;j++) {
            if(MyArray[i][0]>MyArray[j][0]) {
                swap(MyArray[i],MyArray[j]);
            }
        }
    }
}

void print(int MyArray[22][5]) {
    for (int i=0; i<22; i++) {
        for (int j=0; j<5; j++) {
            cout<<MyArray[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main ()
{
    srand ((unsigned)time(0));
    int array[22][5]; //you don't have to define stuff in the global scope, defining your array here is fine
    for (int i=0; i<22; i++) {
        for (int j=0; j<5; j++) {
            array[i][j]=rand()%(9) + 1; //fill the array with elements
        }
    }
    print(array);
    sort (array); //sort
    print(array); //print after sorting
    cout<<endl<<endl;
    system ("pause");
    return 0;
}
