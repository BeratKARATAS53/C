#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  vector<string> lst;
  lst.push_back("Burak Mert");  lst.push_back("Burak Fert");  lst.push_back("Ali Çolak");
  int cnt = count(lst.begin(), lst.end(), "Burak Fert");
  cout<<"Main: "<<cnt<<endl;
}
