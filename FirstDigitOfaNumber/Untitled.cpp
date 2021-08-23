#include <iostream>
using namespace std;

int findFirstDigit(int num) {
   while (num > 10) {
      num /= 10;
   }
   return(num);
}

int main() {
   int num   = 34561029;

   cout << findFirstDigit(num);
   return(0);
}
