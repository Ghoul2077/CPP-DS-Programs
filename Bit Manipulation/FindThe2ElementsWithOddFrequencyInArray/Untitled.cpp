#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

/**
 * @brief      Finds the 2 odd times occuring elements in a given array. It's
 *             time complexity is O(n^2) and it's space complexity is O(1).
 *
 * @param      arr   The array
 * @param[in]  size  The size
 */
void find2OddTimesOccuringElementsNaive(int *arr, int size) {
   vector<int> result;

   for (int i = 0; i < size; i++) {
      if (find(result.begin(), result.end(), arr[i]) != result.end()) {
         continue;
      }
      int count = 0;

      for (int j = 0; j < size; j++) {
         if (arr[i] == arr[j]) {
            count++;
         }
      }

      if (count % 2 != 0) {
         cout << arr[i] << " ";
         result.push_back(arr[i]);
      }
   }
}

/**
 * @brief      Finds the 2 odd times occuring elements in a given array. It's
 *             time complexity is O(n) and it's space complexity is O(1). The
 *             idea behind this method is a bit tricky, first we find out the
 *             xor of all the numbers in the array and then we check it's
 *             rightmost set bit and based on what values the numbers in array
 *             have at this bit position we divide the array into numbers whose
 *             this bit is set and whose this bit is not set. Now xor these 2
 *             groups individually to get the final 2 numbers with odd
 *             frequencies.
 *
 * @param      arr   The array
 * @param[in]  size  The size
 */
void find2OddTimesOccuringElements(int *arr, int size) {
   int totalXOR = arr[0];

   for (int i = 1; i < size; i++) {
      totalXOR ^= arr[i];
   }
   int mask = (totalXOR & (totalXOR - 1)) ^ totalXOR;
   int res1 = 0, res2 = 0;

   for (int i = 0; i < size; i++) {
      if ((arr[i] & mask) == 0) {
         res1 ^= arr[i];
      } else {
         res2 ^= arr[i];
      }
   }
   cout << res1 << " " << res2;
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      int size;
      cin >> size;
      int *arr = new int[size];

      for (int i = 0; i < size; i++) {
         cin >> arr[i];
      }
      find2OddTimesOccuringElements(arr, size);
      cout << endl;
   }
   return (0);
}
