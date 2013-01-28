//You are to write an assembler, as outlined in class last week. asm.cc has most
//of what you need to do a3p3. All you have to do is to check that each line is
//either null or contains .word and a valid operand, and then output the value of
//the operand, as 32 bits, to standard output. If the input is invalid you must
//output ERROR to standard error.
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
using namespace std;

// checkLine: if string it contains ".word" and a valid operand, output TRUE.
//checkLine (string line) {}

// decimalStringToBinaryString: converts decimal string to a 32-bit binary string
// example input:    "30"
// example output:   "00000000000000000000000000011110"
// WARNING: DECIMAL STRING MUST BE GREATER THAN 0
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



// hexStringToBinaryString: convert hex string to a 32-bit binary string
// example input:    "1234abcd"
// example output:   "00010010001101001010101111001101"
string hexStringToBinaryString (string hexString) {
   string BinaryString = "";
   for (unsigned i = 0; i != hexString.length(); i++)  {
      switch (hexString[i]) {
         case '0': BinaryString.append ("0000"); break;
         case '1': BinaryString.append ("0001"); break;
         case '2': BinaryString.append ("0010"); break;
         case '3': BinaryString.append ("0011"); break;
         case '4': BinaryString.append ("0100"); break;
         case '5': BinaryString.append ("0101"); break;
         case '6': BinaryString.append ("0110"); break;
         case '7': BinaryString.append ("0111"); break;
         case '8': BinaryString.append ("1000"); break;
         case '9': BinaryString.append ("1001"); break;
         case 'a': BinaryString.append ("1010"); break;
         case 'b': BinaryString.append ("1011"); break;
         case 'c': BinaryString.append ("1100"); break;
         case 'd': BinaryString.append ("1101"); break;
         case 'e': BinaryString.append ("1110"); break;
         case 'f': BinaryString.append ("1111"); break;         
      }
   }
   return BinaryString;
}

// if invalid input, output ERROR to stderr
//invalid(string input) {}

int main () {
//   cout << "enter a hex number" << endl;
//   string input;
//   cin >> input;
//   cout << hexStringToBinaryString(input) << endl;
//   cout << "enter a dec number" << endl;
//   cin >> input;
//   cout << decimalStringToBinaryString(input) << endl;
}
