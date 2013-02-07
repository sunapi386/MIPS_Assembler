// Test
#include <iostream>
#include "dbgmsg.h"
#include <cstdio>
#include <stdint.h>  // uint16_t

using namespace std;

void outbyte (int i) {
   putchar (i>>24);
   putchar (i>>16);
   putchar (i>>8);
   putchar (i);
}


void asm_beq (int s, int t, uint16_t i) {outbyte (0x10000000|(s<<21)|(t<<16)|i);}
void asm_bne (int s, int t, uint16_t i) {outbyte (0x14000000|(s<<21)|(t<<16)|i);}
void asm_lw (int t, uint16_t i, int s) {outbyte (0x8c000000|(s<<21)|(t<<16)|i);}
void asm_sw (int t, uint16_t i, int s) {outbyte (0xac000000|(s<<21)|(t<<16)|i);}

int main() {
   asm_lw (0,0xffff,0);
}



//beq $1, $2, -123
//bne $1, $2, -123
//lw $1, -123($1)
//sw $1, -123($1)
