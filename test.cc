// Test
#include <iostream>
#include <bitset>
#include <climits>

using namespace std;

template<typename T>
void show_binrep (const T& a) {
   const char* beg = reinterpret_cast<const char*> (&a);
   const char* end = beg + sizeof (a);
   while (beg != end) {
      cout << bitset<32>(*beg++) << ' ';
   }
   cout << '\n';
}

int main() {
   int n = 30;
   show_binrep(n);
}
