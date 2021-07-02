#include <iostream>
using namespace std;

int findSubsetsWithSum(int set[], int len, int sum, int index = 0, int count = 0) {
   if (sum == 0) {
      return(++count);
   }
   if (sum < 0 || index == len) {
      return(count);
   }
   return(findSubsetsWithSum(set, len, sum, index + 1, count) +
          findSubsetsWithSum(set, len, sum - set[index], index + 1, count));
}

// Easier Implementation
// countSubsetsWithGivenSum(int arr[], int n, int sum){
//  if(n == 0)
//      return sum == 0 ? 1 : 0;
//  return countSubsetsWithGivenSum(arr, n - 1, sum) +
//  countSubsetsWithGivenSum(arr, n - 1, sum - arr[n - 1]);
// }

int main() {
   int set[] = { 10, 5, 2, 3, 6 }, sum = 8;

   cout << findSubsetsWithSum(set, 5, sum);
}
