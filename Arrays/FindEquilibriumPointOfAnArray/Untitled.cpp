#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;
#define deb(x) cout << # x << " = " << x << endl;
#define deb2(x, \
             y) cout << # x << " = " << x << ", " << # y << " = " << y << endl;
#define printArr(arr, size) cout << # arr << " : "; \
   for (int i = 0; i < size; i++) cout << arr[i] << " "; cout << endl;


/**
 * @brief      Finds an equilibrium point of a given array. Equilibrium point is
 *             a point at which the sum of left elements is equal to sum of the
 *             right elements. In the below method we use naive approach and use
 *             2 for loops and taking each element as dividing point and
 *             calculating left sum and right sum for every iteration. It's time
 *             complexity is O(n^2) and it's space complexity is O(1).
 *
 * @param      arr   The array
 * @param[in]  size  The size of array
 *
 * @return     The number at which left and right halves sum become equal,
 *             -1 if not exists
 */
int findEquilibriumPointOfArrayNaive(int *arr, int size) {
   for (int i = 1; i < size - 1; i++) {
      int leftSum = 0, rightSum = 0;

      for (int j = 0; j < i; j++) {
         leftSum += arr[j];
      }

      for (int j = i; j < size; j++) {
         rightSum += arr[j];
      }

      if (leftSum == rightSum) {
         return (i);
      }
   }

   return (-1);
}

/**
 * @brief      Finds an equilibrium point of a given array. Equilibrium point is
 *             a point at which the sum of left elements is equal to sum of the
 *             right elements. The idea is to first calculate the total sum of
 *             the array in advance and then start calculating rolling sum from
 *             left end, each iteration gives us sum of all elements to the left
 *             as the current rolling sum and right element sum is total sum -
 *             rolling sum. Equating the right and left sums on each iteration
 *             will give us our index. It's time complexity is O(n) and it's
 *             space complexity is O(1).
 *
 * @param      arr   The array
 * @param[in]  size  The size of array
 *
 * @return     The number at which left and right halves sum become equal,
 *             -1 if not exists
 */
int findEquilibriumPointOfArray(int *arr, int size) {
   int rollingSum    = 0;
   int totalSumOfArr = 0;

   for (int i = 0; i < size; i++) {
      totalSumOfArr += arr[i];
   }

   for (int i = 0; i < size; i++) {
      rollingSum += arr[i];

      if (rollingSum == totalSumOfArr - rollingSum) {
         return (i + 1);
      }
   }

   return (-1);
}

int main() {
   int testCases;

   srand(time(0));
   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      int size;
      cin >> size;
      int *arr = new int[size];

      for (int i = 0; i < size; i++) {
         cin >> arr[i];
      }
      cout << findEquilibriumPointOfArray(arr, size);
      cout << endl;
   }
   return (0);
}
