#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;
#define deb(x) cout << # x << " = " << x << endl;
#define deb2(x, \
             y) cout << # x << " = " << x << ", " << # y << " = " << y << endl;

void printArr(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
   }
   cout << endl;
}

/**
 * @brief      Sorts a given k sorted array. A k sorted array is an array where
 *             every element is at most k distance to the left from its position
 *             in the sorted array. In this naive approach we directly use the
 *             inbuild stl function to sort the array. It's time complexity is
 *             O(nlogn) and it's space complexity is O(1).
 *
 * @param      arr   The array
 * @param[in]  size  The size of the array
 * @param[in]  k     Max distance from original position
 */
void sortAKSortedArrayNaive(int *arr, int size, int k) {
   sort(arr, arr + size);
}

/**
 * @brief      Sorts a given k sorted array. A k sorted array is an array where
 *             every element is at most k distance to the left from its position
 *             in the sorted array. The idea is to slightly optimize naive
 *             approach by using priority queue. We store first k + 1 elements
 *             in the priority queue and then loop the rest of the items and at
 *             every iteration we keep replacing the (i - k - 1)th element with
 *             the current top of the min heap (priority queue). After we have
 *             looped through the remaining elements we insert the remaining
 *             elements in min heap to array one by one. It's time complexity is
 *             O(nlogk) and it's space complexity is O(n).
 *
 * @param      arr   The array
 * @param[in]  size  The size of the array
 * @param[in]  k     Max distance from original position
 */
void sortAKSortedArray(int *arr, int size, int k) {
   priority_queue<int, vector<int>, greater<int> > pq(arr, arr + k + 1);
   int index = 0;

   for (int i = k + 1; i < size; i++) {
      arr[index++] = pq.top();
      pq.pop();
      pq.push(arr[i]);
   }

   while (!pq.empty()) {
      arr[index++] = pq.top();
      pq.pop();
   }
}

// WRONG APPROACH : At first this seem as the same method as the optimized one
//                  but instead of priority queue we have used set. Where this
//                  method goes wrong is that set does not allow duplicate
//                  eements while priority queue does so in cases where we need
//                  sorting of some sort and we are not given any info about
//                  whether the elements are all distinct we prefer to go for
//                  priority queue.
void sortAKSortedArraySet(int *arr, int size, int k) {
   set<int> set(arr, arr + k + 1);
   int index = 0;

   for (int i = k + 1; i < size; i++) {
      arr[index++] = *(set.begin());
      set.erase(set.begin());
      set.insert(arr[i]);
   }

   while (!set.empty()) {
      arr[index++] = *(set.begin());
      set.erase(set.begin());
   }
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
      sortAKSortedArraySet(arr, size, k);
      printArr(arr, size);
      cout << endl;
   }
   return (0);
}
