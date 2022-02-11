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
 * @brief      Gets the minimum number of groups that can be formed from a given
 *             array with a maximum difference of k. The idea is to first sort
 *             the array then iterate over the array from left, the current ith
 *             index will be starting element of a new group and inside the
 *             loop we run another while loop where we find the other elements
 *             of the group by checking the difference between ith and jth
 *             element which gives us the maximum difference of the current
 *             group if it is less than equal to k move to next element in the
 *             while loop until we find the element that violates the above
 *             condition. After coming out of the while loop we increment the
 *             group count. It's time complexity is O(nlogn) and it's space
 *             complexity is O(1).
 *
 * @param      arr   The array
 * @param[in]  size  The size of the array
 * @param[in]  k     Max distance between the elements of the group
 *
 * @return     The number of groups.
 */
int getNumberOfGroups(int *arr, int size, int k) {
   sort(arr, arr + size);
   int groupCount = 0;

   for (int i = 0; i < size; i++) {
      int currStart = i;

      while (i < size && (arr[i + 1] - arr[currStart]) <= k) {
         i++;
      }
      groupCount++;
   }
   return (groupCount);
}

int main() {
   int testCases;

   srand(time(0));
   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      int size, k;
      cin >> k;
      cin >> size;
      int *arr = new int[size];

      for (int i = 0; i < size; i++) {
         cin >> arr[i];
      }
      cout << getNumberOfGroups(arr, size, k);
      cout << endl;
   }
   return (0);
}
