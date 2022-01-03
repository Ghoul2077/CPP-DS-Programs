#include <bits/stdc++.h>
using namespace std;

void search(string str1, string str2) {
   int size1 = str1.length();
   int size2 = str2.length();

   for (int i = 0; i < size1 - size2; i++) {
      int j;

      for (j = 0; j < size2; j++) {
         if (str1[i + j] != str2[j]) {
            break;
         }
      }

      if (j == size2) {
         cout << "Pattern found at index " << i;
      }
   }
}

int main() {
   string str1 = "PrakharIsHere";
   string str2 = "Prakhar";

   search(str1, str2);
   return (0);
}
