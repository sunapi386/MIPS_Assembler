// Test
#include <iostream>
#include <cstdio>    // outbyte (int)
#include <map>       // labelling

using namespace std;

void outbyte (int i) {
   putchar (i>>24);
   putchar (i>>16);   
   putchar (i>>8);
   putchar (i);      
}
int TestByteOrder() {
   short int word = 0x0001;
   char *byte = (char*) &word;
   return (byte[0] ? LITTLE_ENDIAN : BIG_ENDIAN);
}

int main() {
//   outbyte (24);
//   cout << TestByteOrder() << endl;
   map<string, int> labelMap;
   labelMap["begin"] = 3;
   labelMap["end"] = 12;
   for (map<string, int>::const_iterator it = labelMap.begin();
   it != labelMap.end(); it++) {
         cout << "key " << it->first << " value " << it->second << endl;
   }
 
}
