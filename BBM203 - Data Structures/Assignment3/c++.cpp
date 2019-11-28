#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;


void write(ofstream &output_File) {
    output_File<<"First Input";
    output_File<<"First Input";
    output_File<<"First Input";
}
int main() {
    ofstream output_File;
    output_File.open("output.txt");
    write(output_File);


}
