// Test
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
using namespace std;

string decimalStringToBinaryString (string decimalString) {
   string BinaryString = "";
   int decimalNumber = atoi (decimalString.c_str());
   if (decimalNumber < 0) { 
      cerr << "ERROR decimalStringToBinaryString: negative value" << endl;
      exit(1);
   }
   while (decimalNumber != 0) {
      int remainder = decimalNumber % 2;
      string r;
      ostringstream convert;
      convert << remainder;
      r = convert.str();
      BinaryString.insert (0, r);
      decimalNumber /= 2;
   }
   string zero = "0";
   while (BinaryString.length() < 32) {
      BinaryString.insert (0, zero);
   }
   return BinaryString;
}



int main() {
    string decimalString;
    cout << "enter in a decimal number to be converted to binary\n";
    cin >> decimalString;
    cout << decimalStringToBinaryString (decimalString) << endl;
}
