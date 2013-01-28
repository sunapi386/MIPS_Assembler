// Test
#include <iostream>
#include <cstdio>    // outbyte (int)

using namespace std;

void outbyte (int i) {
   putchar (i>>24);
   putchar (i>>16);   
   putchar (i>>8);
   putchar (i);      
}
int main() {
   outbyte (24);
}
