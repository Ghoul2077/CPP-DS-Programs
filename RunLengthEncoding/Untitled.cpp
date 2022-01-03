#include <bits/stdc++.h>
using namespace std;

void runLengthEncoding(char str[], int count = 0, int level = 0) {
   if (str[level] == '\0') {
      if (count == 1) {
         cout << str[level - 1];
      } else {
         cout << count << str[level - 1];
      }
   } else if ((str[level - 1] != str[level]) && (level != 0)) {
      if (count == 1) {
         cout << str[level - 1];
      } else {
         cout << count << str[level - 1];
      }
      runLengthEncoding(str, 1, level + 1);
   } else {
      runLengthEncoding(str, count + 1, level + 1);
   }
}

int main() {
   char str[] = "aabbdcdddmnoldnvnngnbggifnbonosdcccdd";

   runLengthEncoding(str);
}
