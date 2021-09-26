#include <iostream>
using namespace std;

/**
 * @brief      Prints frequency of all distinct characters in a given
 *             string in O(n) time complexity and Q(1) space
 *             complexity.
 *
 * @param      str   The string
 */
void printFrequency(string& str) {
   int countArr[128] = { 0 };

   for (unsigned int i = 0; i < str.size(); i++) {
      int asciiVal = (int)str[i];
      countArr[asciiVal]++;
   }

   for (unsigned int i = 0; i < 128; i++) {
      if (countArr[i] > 0) {
         cout << (char)(i) << " : " << countArr[i] << endl;
      }
   }
}

int main() {
   string str = "Prakhar";

   printFrequency(str);
   return (0);
}
