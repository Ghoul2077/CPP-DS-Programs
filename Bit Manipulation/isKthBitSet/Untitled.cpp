#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

bool isKthBitSetRightShift(int num, int bitNum) {
   num >>= (bitNum - 1);
   return (num & 1);
}

bool isKthBitSetLeftShift(int num, int bitNum) {
   int mask = num << (bitNum - 1);

   return (num & mask);
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      int num, bitNum;
      cin >> num;
      cin >> bitNum;
      cout << (isKthBitSetLeftShift(num, bitNum) ? "Yes" : "No");
      cout << endl;
   }
   return (0);
}
