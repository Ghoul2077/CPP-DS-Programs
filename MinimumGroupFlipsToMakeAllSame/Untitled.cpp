#include <iostream>
#include <math.h>
#include <vector>
#include <limits>
using namespace std;

void minimumGroupFlipsToMakeAllSame(bool *arr, int size) {
   int toSwitch;
   int switchCounter;

   if (arr[0] == arr[size - 1]) {
      toSwitch = !arr[0];
   } else {
      toSwitch = arr[0];
   }

   switchCounter = !toSwitch;

   for (int i = 1; i < size; i++) {
      if (arr[i] == toSwitch && arr[i - 1] == switchCounter) {
         cout << "From " << i << " to ";
      }
      if (arr[i] == switchCounter && arr[i - 1] == toSwitch) {
         cout << i - 1 << endl;
      }
   }
}

int main() {
   bool      arr[] = { 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1 };
   const int size  = sizeof(arr) / sizeof(arr[0]);

   minimumGroupFlipsToMakeAllSame(arr, size);
   return(0);
}
