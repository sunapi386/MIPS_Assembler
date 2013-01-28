//You are to write an assembler, as outlined in class last week. asm.cc has most
//of what you need to do a3p3. All you have to do is to check that each line is
//either null or contains .word and a valid operand, and then output the value of
//the operand, as 32 bits, to standard output. If the input is invalid you must
//output ERROR to standard error.

// checkLine: if string it contains ".word" and a valid operand, output TRUE.
//checkLine (string line) {}

// if invalid input, output ERROR to stderr
//invalid(string input) {}


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

   try {
      vector<string> srcLines;

      // Read the entire input file, storing each line as a
      // single string in the array srcLines.
      while(true) {
      string line;
      getline(cin, line);
      if(cin.fail()) break;
      srcLines.push_back(line);
      }

      // Tokenize each line, storing the results in tokLines.
      vector<vector<Token> > tokLines;

      for(int line = 0; line < srcLines.size(); line++) {
      tokLines.push_back(scan(srcLines[line]));
      }

      // Check that each line is either null or contains .word and a valid operand,
      // output the value of the operand, as 32 bits, to standard output.
      // If the input is invalid you must output ERROR to standard error.

      for(int line=0; line < tokLines.size(); line++ ) {
         for(int j=0; j < tokLines[line].size(); j++ ) {
            Token token = tokLines[line][j];
            if(token.kind == DOTWORD) {
               Token nextToken = tokLines[line][j+1];
               if (nextToken.kind == INT || nextToken.kind == HEXINT) {
                  int value = nextToken.toInt();
                  outbyte (value);
                  j++;
               }
            } else {
               cerr << "ERROR unrecognized token: " << token.lexeme << endl;
            }
         }
      }


   } catch(string msg) {
     cerr << msg << endl;
   }

   return 0;
}



