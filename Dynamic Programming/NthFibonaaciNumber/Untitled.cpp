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
 * @brief      Find the nth fibonaaci number. This method uses top down dynamic
 *             programming approach which is memoization on the standard
 *             reccursive method. Here we maintain a memoization table that is
 *             shared across reccursive calls, on every new calculation of
 *             new fibonacci number we store them in the table so that next time
 *             we encounter situation where we need to calculate them again we
 *             don't make redundant reccursive calls again. One thing to note is
 *             that the base case is not included in the memoization table here.
 *             The time complexity of this method is O(N) and it's space
 *             complexity is O(N).
 *
 * @param[in]  num   N in the Nth Fibonnaci number
 *
 * @return     Nth Fibonacci number
 */
int nthFibonacciNumber(int num) {
   static vector<int> dp(1000 + 1, -1);

   if ((num == 0) || (num == 1)) {
      return (num);
   }

   int ans = 0;

   if (dp[num - 1] == -1) {
      dp[num - 1] = nthFibonacciNumber(num - 1);
   }

   if (dp[num - 2] == -1) {
      dp[num - 2] = nthFibonacciNumber(num - 2);
   }

   ans += dp[num - 1];
   ans += dp[num - 2];

   return (ans);
}

/**
 * @brief      Find the nth fibonaaci number. This method uses bottom up dynamic
 *             programming approach which is a tabulation method on the standard
 *             iterative method. Here we maintain a result table that is storing
 *             all the fibonnaci numbers before (i - 1). So we initially begin
 *             with putting the base case in the table and then begin from there,
 *             Now using iteration we fill the corresponding ith cell of the
 *             table using any of the previous results i.e before ith. In this
 *             case we use arr[i] = arr[i - 1] + arr[i - 2]. It's time
 *             complexity is O(N) and it's space complexity is O(N). This is
 *             generally faster than reccursive method because there is no
 *             overhead of reccurisve calls.
 *
 * @param[in]  num   N in the Nth Fibonnaci number
 *
 * @return     Nth Fibonacci number
 */
int nthFibonacciNumber2(int num) {
   static vector<int> dp(1000 + 1, -1);

   dp[0] = 0;
   dp[1] = 1;

   for (int i = 2; i <= num; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
   }

   return (dp[num]);
}

int main() {
   int testCases;

   srand(time(0));
   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      int num;
      cin >> num;
      cout << nthFibonacciNumber2(num);
      cout << endl;
   }
   return (0);
}
