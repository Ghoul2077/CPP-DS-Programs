#include <iostream>
using namespace std;

void removeConsecutive(char str[], int level = 0) {
   if (str[level] == '\0') {
      return;
   }
   if (level != 0 && (str[level - 1] == str[level])) {
      int i = level;
      for (; str[i] != '\0'; i++) {
         str[i - 1] = str[i];
      }
      str[i - 1] = str[i];
      level--;
   }
   removeConsecutive(str, level + 1);
}

int main() {
   char str[] = "aabbccddddeffffkllll";

   removeConsecutive(str);
   cout << str;
}
