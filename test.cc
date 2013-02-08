// Test
#include <iostream>
#include "dbgmsg.h"
#include <cstdio>
#include <stdint.h>  // uint16_t

using namespace std;

int x = 32769;

bool inRange16signed (int x) {
   if (x >= -32767 && x <= 32767) {return true;}
   return false;
}

int main() {
   if (inRange16signed(x)) {
      cout << "In range \n";
   } else {
      cout << "Not in range\n";
   }
   
}



//beq $1, $2, -123
//bne $1, $2, -123
//lw $1, -123($1)
//sw $1, -123($1)
