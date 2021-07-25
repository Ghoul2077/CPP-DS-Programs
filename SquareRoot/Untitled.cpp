#include <iostream>
#include <math.h>
#include <vector>
#include <limits>
using namespace std;

int squareRootNaive(int num) {
   int i;

   for (i = 1; i <= num; i++) {
      if (i * i == num) {
         break;
      } else if (i * i > num) {
         return(i - 1);
      }
   }
   return(i);
}

int squareRoot(int num) {
   int start = 0, stop = num;
   int sqrt;

   while (start <= stop) {
      int mid        = (start + stop) / 2;
      int square     = mid * mid;
      int prevSqaure = (mid - 1) * (mid - 1);

      if (square == num) {
         sqrt = mid;
         break;
      } else if (prevSqaure < num && square > num) {
         sqrt = mid - 1;
         break;
      } else if (square < num) {
         start = mid + 1;
      } else {
         stop = mid - 1;
      }
   }

   return(sqrt);
}

int main() {
   int element = 1615;

   cout << squareRoot(element)<<endl;
   return(0);
}
