#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

/**
* The sort function is used to sort the data in the file before adding it to the linked list.
* MyArray: is an 2d dimensional array, which store the data.
* len: is size of MyArray.
*/
void sort(string MyArray[][5], int len) {
    for(int i=0;i<len;i++) {
        for(int j=i+1;j<len;j++) {
            if(MyArray[i][0]>MyArray[j][0]) { // If footballer name is greater than the next footballer name, then swap it.
                swap(MyArray[i],MyArray[j]);
            }
        }
    }
}

int main()
{
    ifstream inputFile("input1.txt");

    string name,homeTeam,awayTeam;
    string line;
    string myString;
    int goalMinute=0,matchID=0;

    int lineCount = 0;
    while(getline(inputFile,line)) {
        lineCount++; }

    inputFile.clear();
    inputFile.seekg(0);

    string footballerInfo[lineCount][5];

    int i=0;
    while(getline(inputFile,line)) {
        stringstream ss(line);
        getline(ss,name,','); footballerInfo[i][0] = name;
        getline(ss,homeTeam,','); footballerInfo[i][1] = homeTeam;
        getline(ss,awayTeam,','); footballerInfo[i][2] = awayTeam;
        getline(ss,myString,','); footballerInfo[i][3] = myString;
        stringstream goalMin(myString);
        goalMin>>goalMinute;

        getline(ss,myString,','); footballerInfo[i][4] = myString;
        stringstream match(myString);
        match>>matchID;
        i++;
    }
    inputFile.close();

    int arrayLength = lineCount;
    sort(footballerInfo,arrayLength);

    int a,b;
    for (a=0; a<lineCount; a++) {
        for (b=0; b<5; b++) {
            cout<<footballerInfo[a][b]<<" ";
        }
        cout<<endl;
    }

}
