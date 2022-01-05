#include <bits/stdc++.h>
using namespace std;

int minSubarrayWithGivenSumNaive(int *arr, int size, int sum) {
   int minCount = INT_MAX;

   for (int i = 0; i < size; i++) {
      int currSum = arr[i];

      if (currSum == sum) {
         minCount = 1;
      }

      for (int j = i + 1; j < size; j++) {
         currSum += arr[j];

         if (currSum == sum) {
            int windowSize = j - i + 1;
            minCount = min(minCount, windowSize);
         }
      }
   }

   return (minCount);
}

int minSubarrayWithGivenSum(int *arr, int size, int sum) {
   int start = -1, end = -1;
   int minWindowSizeWithGivenSum = INT_MAX;
   int windowSum                 = 0;

   while (start <= size && end <= size) {
      if (windowSum < sum) {
         windowSum += arr[++end];
      } else if (windowSum > sum) {
         windowSum -= arr[++start];
      } else {
         minWindowSizeWithGivenSum =
            min(minWindowSizeWithGivenSum, end - start);
         windowSum += arr[++end];
      }
   }

   return (minWindowSizeWithGivenSum);
}

int main() {
   int arr[] = { 3, 4, 1, 1, 6 };
   int size  = sizeof(arr) / sizeof(arr[0]);

   cout << minSubarrayWithGivenSum(arr, size, 8);
   return (0);
}
