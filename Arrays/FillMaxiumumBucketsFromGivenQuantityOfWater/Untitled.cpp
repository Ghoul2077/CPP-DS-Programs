#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

/**
 * @brief      Given an array containing capacities of N buckets and a variable
 *             total water we need to find the maximum number of buckets we can
 *             fill with the given amount of water. The idea that we use is to
 *             sort the buckets by ascending order of capacity and then start
 *             filling buckets one by one until we run out of water. It's time
 *             complexity is O(nlogn) and it's space complexity is O(1).
 *
 * @param      arr    The capacities of buckets
 * @param[in]  size   The number of buckets
 * @param[in]  total  The total quantity of water
 *
 * @return     The maximum buckets that can be filled.
 */
int getMaximumBucketsThatCanBeFilled(int *arr, int size, int total) {
   int count = 0;

   sort(arr, arr + size);

   for (int i = 0; i < size; i++) {
      int diff = total - arr[i];

      if (diff >= 0) {
         total = diff;
         count++;
      } else {
         break;
      }
   }

   return (count);
}

int main() {
   int testCases;

   srand(time(0));
   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      int size;
      cin >> size;
      int *bucketCapacities = new int[size];
      int  waterCapacity    = 0;

      for (int i = 0; i < size; i++) {
         cin >> bucketCapacities[i];
         waterCapacity += (i + 1);
      }
      cout << getMaximumBucketsThatCanBeFilled(bucketCapacities,
                                               size,
                                               waterCapacity);
      cout << endl;
   }
   return (0);
}
