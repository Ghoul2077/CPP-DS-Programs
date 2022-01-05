#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

bool isPrime(int num) {
   if (num == 1) {
      return (false);
   }

   if ((num == 2) || (num == 3)) {
      return (true);
   }

   if ((num % 2 == 0) || (num % 3 == 0)) {
      return (false);
   }

   for (int i = 5; i < pow(num, 0.5); i += 6) {
      if ((num % i == 0) || (num % (i + 2) == 0)) {
         return (false);
      }
   }

   return (true);
}

void printAllPrimeNumbersLessThanKNaive(int k) {
   for (int i = 1; i < k; i++) {
      if (isPrime(i)) {
         cout << i << " ";
      }
   }
}

void printallprimenumberslessthank(int k) {
   bool *arr = new bool[k + 1];

   fill(arr, arr + k + 1, true);

   for (int i = 4; i < k + 1; i += 2) {
      arr[i] = false;
   }

   for (int i = 6; i < k + 1; i += 3) {
      arr[i] = false;
   }

   for (int i = 10; i < k + 1; i += 5) {
      arr[i] = false;
   }

   for (int i = 0; i < k + 1; i++) {
      if (arr[i]) {
         cout << i << " ";
      }
   }
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      int val;
      cin >> val;
      printAllPrimeNumbersLessThanKNaive(val);
      cout << endl;
   }
   return (0);
}
