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

void asm_jr (int s) {outbyte ((s<<21)|8);}
void asm_jalr (int s) {outbyte ((s<<21)|9);}

void asm_add  (int d, int s, int t) {outbyte ((s<<21)|(t<<16)|(d<<11)|32);}
void asm_sub  (int d, int s, int t) {outbyte ((s<<21)|(t<<16)|(d<<11)|34);}
void asm_slt  (int d, int s, int t) {outbyte ((s<<21)|(t<<16)|(d<<11)|42);}
void asm_sltu (int d, int s, int t) {outbyte ((s<<21)|(t<<16)|(d<<11)|43);}

void beq (int s, int t, int i) {outbyte (0x10000000|(s<<21)|(t<<16)|(i>>8)|i);}
void bne (int s, int t, int i) {outbyte (0x14000000|(s<<21)|(t<<16)|(i>>8)|i);}

void asm_lis  (int d) {outbyte ((d<<11)|20);}
void asm_mflo (int d) {outbyte ((d<<11)|18);}
void asm_mfhi (int d) {outbyte ((d<<11)|16);}

void asm_mult  (int s, int t) {outbyte ((s<<21)|(t<<16)|24);}
void asm_multu (int s, int t) {outbyte ((s<<21)|(t<<16)|25);}
void asm_div   (int s, int t) {outbyte ((s<<21)|(t<<16)|26);}
void asm_divu  (int s, int t) {outbyte ((s<<21)|(t<<16)|27);}

void asm_lw (int t, int i, int s) {outbyte (0x8c000000|(s<<21)|(t<<16)|(i>>8)|i);}
void asm_sw (int t, int i, int s) {outbyte (0xac000000|(s<<21)|(t<<16)|(i>>8)|i);}




int main() {
   asm_jr(31);
   asm_jalr(30);
   asm_add(1,2,3);
   asm_sub(3,2,1);
   asm_slt(5,6,1);
   asm_sltu(3,4,5);
   beq (1,2,3);
   bne (1,2,3);
   asm_lis (5);
   asm_mflo (3);
   asm_mfhi (2);
   asm_mult (2, 3);
   asm_multu (2, 3);
   asm_div (4, 1);
   asm_divu (4, 1);
   asm_lw (4, 1, 2);
   asm_sw (4, 1, 2);
}


//jr $31
//jalr $30
//add $1, $2, $3
//sub $3, $2, $1
//slt $5, $6, $1
//sltu $3, $4, $5
//beq $1, $2, 3
//bne $1, $2, 3
//lis $5
//mflo $3
//mfhi $2
//mult $2, $3
//multu $2, $3
//div $4, $1
//divu $4, $1
//lw $4, 1($2)
//sw $4, 1($2)


