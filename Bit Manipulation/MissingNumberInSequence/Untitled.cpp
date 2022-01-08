#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

/**
 * @brief      Given an array containing numbers from 1 to n, with one of the
 *             numbers missing. Find the missing number. It's time complexity is
 *             O(n^2) and it's space complexity is O(1).
 *
 * @param      arr         The array
 * @param[in]  size        The size
 * @param[in]  upperLimit  The upper limit of numbers in array
 *
 * @return     The missing number
 */
int findMissingNumberInGivenSequenceNaive(int *arr, int size, int upperLimit) {
   for (int i = 1; i <= upperLimit; i++) {
      bool isPresent = false;

      for (int j = 0; j < size; j++) {
         if (arr[j] == i) {
            isPresent = true;
            break;
         }
      }

      if (!isPresent) {
         return (i);
      }
   }
   return (-1);
}

/**
 * @brief      Given an array containing numbers from 1 to n, with one of the
 *             numbers missing. Find the missing number. It's time complexity is
 *             O(n) and it's space complexity is O(1).
 *
 * @param      arr         The array
 * @param[in]  size        The size
 * @param[in]  upperLimit  The upper limit of numbers in array
 *
 * @return     The missing number
 */
int findMissingNumberInGivenSequence(int *arr, int size, int upperLimit) {
   int totalXOR = arr[0];

   for (int i = 1; i < size; i++) {
      totalXOR ^= arr[i];
   }

   for (int i = 1; i <= upperLimit; i++) {
      totalXOR ^= i;
   }
   return (totalXOR);
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      int size, n;
      cin >> n;
      cin >> size;
      int *arr = new int[size];

      for (int i = 0; i < size; i++) {
         cin >> arr[i];
      }
      cout << findMissingNumberInGivenSequenceNaive(arr, size, n);
      cout << endl;
   }
   return (0);
}
