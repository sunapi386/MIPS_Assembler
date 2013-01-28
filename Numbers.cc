// Reads a list of numbers from stdin and prints it twice to stdout

#include <iostream>
#include <vector>

using namespace std;

int main () {
   int i;
   vector<int> v;
   while (cin >> i) {
      v.push_back (i);
   }
   for (unsigned j = 0; j != v.size(); j++) {
      cout << v.at(j) << endl;
   }
   for (unsigned j = 0; j != v.size(); j++) {
      cout << v.at(j) << endl;
   }
}


