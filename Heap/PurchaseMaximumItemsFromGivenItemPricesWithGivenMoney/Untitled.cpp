#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;
#define deb(x) cout << # x << " = " << x << endl;
#define deb2(x, \
             y) cout << # x << " = " << x << ", " << # y << " = " << y << endl;

/**
 * @brief      Given an array with cost of n items and some money we need to
 *             find the maximum number of items we can purchase. The idea is to
 *             first sort the array and then loop through it from the left while
 *             checking if the current element can be purchased from remaining
 *             money if yes we increment the counter and decrease the money.
 *             We do this until we hit the first element which cannot be
 *             purchased from the remaining money and return the count. It's
 *             time complexity is O(nlogn) and it's space complexity is O(1).
 *
 * @param      arr    The array
 * @param[in]  size   The size of array
 * @param[in]  money  The money we initially have
 *
 * @return     Maximum items purchasable
 */
int purchaseMaximumItemFromArrayWithGivenMoneyNaive(int *arr, int size,
                                                    int money) {
   sort(arr, arr + size);
   int count = 0;

   for (int i = 0; i < size; i++) {
      int diff = money - arr[i];

      if (diff >= 0) {
         count++;
         money = diff;
         continue;
      }

      break;
   }

   return (count);
}

/**
 * @brief      Given an array with cost of n items and some money we need to
 *             find the maximum number of items we can purchase. The idea is to
 *             use a priority queue / min heap to store the array and keep
 *             checking if the top element purchasable from the money we have
 *             and if the answer is yes then we pop the element from heap and
 *             increment count and subtract item cost from the remaining money.
 *             It's time complexity is O(count * logn) and it's space complexity
 *             is O(n). This is better than above solution as this does not
 *             modify the original array and considering count can range from
 *             (1 to n) we have chances of faster algorithm if count is very
 *             small than n.
 *
 * @param      arr    The array
 * @param[in]  size   The size of array
 * @param[in]  money  The money we initially have
 *
 * @return     Maximum items purchasable
 */
int purchaseMaximumItemFromArrayWithGivenMoney(int *arr, int size, int money) {
   priority_queue<int, vector<int>, greater<int> > pq(arr, arr + size);
   int count = 0;

   while (pq.top() <= money) {
      count++;
      money -= pq.top();
      pq.pop();
   }

   return (count);
}

int main() {
   int testCases;

   srand(time(0));
   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      int size, money;
      cin >> money;
      cin >> size;
      int *arr = new int[size];

      for (int i = 0; i < size; i++) {
         cin >> arr[i];
      }
      cout << purchaseMaximumItemFromArrayWithGivenMoney(arr, size, money);
      cout << endl;
   }
   return (0);
}
