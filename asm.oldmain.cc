
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

//     // Now we process the tokens.
//     // Sample usage: print the tokens of each line.
//     for(int line=0; line < tokLines.size(); line++ ) {
//         for(int j=0; j < tokLines[line].size(); j++ ) {
//             Token token = tokLines[line][j];
//             cerr << "  Token: " << kindString(token.kind) 
//                 << " {" << token.lexeme << "}";
//             if(token.kind == INT || token.kind == HEXINT ||
//                     token.kind == REGISTER) {
//                 cerr << token.toInt();
//             }
//             cerr << endl;
//         }
//     }

      // All you have to do is to check that each line is
      // either null or contains .word and a valid operand, 
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
