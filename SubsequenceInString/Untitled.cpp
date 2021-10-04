#include <iostream>
#include <string>
using namespace std;

int subSequence(string str, int level = 0, string sequence = "") {
   if (level == str.size()) {
      cout << sequence << "  ";
      return(1);
   } else {
      return(subSequence(str, level + 1, sequence) +
             subSequence(str, level + 1, sequence + str[level]));
   }
}

int main() {
   string str = "abc";

   subSequence(str);
}
