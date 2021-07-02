#include <iostream>
#include <string>
#include <math.h>
using namespace std;

const char KEYPAD[9][3] = {
   { 'a', 'b', 'c' },
   { 'd', 'e', 'f' },
   { 'g', 'h', 'i' },
   { 'j', 'k', 'l' },
   { 'm', 'n', 'o' },
   { 'p', 'q', 'r' },
   { 's', 't', 'u' },
   { 'v', 'w', 'x' },
   { 'y', 'z', ' ' }
};

void printArr(string arr[], int size) {
   for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
   }
   cout << endl;
}

int subSequence(int num, string *output) {
   if (num == 0) {
      output[0] = "";
      return(1);
   } else {
      int unitsDigit  = num % 10;
      int smallerNum  = num / 10;
      int smallerSize = subSequence(smallerNum, output);
      for (int i = 0; i < 3; i++) {
         for (int j = 0; j < smallerSize; j++) {
            output[j + smallerSize * (i + 1)] = (
               KEYPAD[unitsDigit - 1][i] + output[j]
               );
         }
      }
      return(smallerSize * 3);
   }
}

int main() {
   int    num;
   string *output = new string[100];

   cout << "Enter number : ";
   cin >> num;

   subSequence(num, output);
   printArr(output, 100);
}
