#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

/**
 * @brief      Generates first N numbers with digits as 5 and 6 only. It's time
 *             complexity is O(n^2) and this approach fails for large N values
 *             as the numbers will exceed maximum allowed size by c++.
 *
 * @param[in]  num   The number
 */
void generateFirstNNumbersWithGivenDigitsNaive(int num) {
   int count = 0, i = 1;

   while (count != num) {
      bool doesContainOnlyFiveAndSixes = true;
      int  num                         = i;

      while (num > 0) {
         int digit = num % 10;
         num /= 10;

         if ((digit != 5) && (digit != 6)) {
            doesContainOnlyFiveAndSixes = false;
            break;
         }
      }

      if (doesContainOnlyFiveAndSixes) {
         cout << i << " ";
         count++;
      }

      i++;
   }
}

/**
 * @brief      Generates first N numbers with digits as 5 and 6 only. It's time
 *             complexity is O(n) and space complexity is Q(n). This is a unique
 *             queue based approach to the problem and this handles the cases of
 *             large inputs too.
 *
 * @param[in]  num   The number
 */
void generateFirstNNumbersWithGivenDigits(int num) {
   queue<string> q;

   q.push("5");
   q.push("6");

   for (int i = 0; i < num; ++i) {
      string curr = q.front();
      q.pop();
      q.push(curr + '5');
      q.push(curr + '6');
      cout << curr << " ";
   }
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      int num;
      cin >> num;
      generateFirstNNumbersWithGivenDigits(num);
      cout << endl;
   }
   return (0);
}
