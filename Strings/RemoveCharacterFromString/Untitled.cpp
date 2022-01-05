#include <bits/stdc++.h>
using namespace std;

void removeChar(char str[], char elem, int level = 0) {
   if (str[level] == '\0') {
      return;
   }

   if (str[level] == elem) {
      int i = level;

      for (; str[i] != '\0'; i++) {
         str[i] = str[i + 1];
      }
   }
   removeChar(str, elem, level + 1);
}

int length(char ch[], int level = 0) {
   if (ch[level] == '\0') {
      return (level);
   }
   return (length(ch, level + 1));
}

int main() {
   char str[] = "PIPAmPSoPCoolP";

   removeChar(str, 'P');
   cout << str << endl;
   cout << length(str);
}
