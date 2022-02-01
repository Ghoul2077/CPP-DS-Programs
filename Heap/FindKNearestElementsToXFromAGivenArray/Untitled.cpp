#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;
#define deb(x) cout << # x << " = " << x << endl;
#define deb2(x, \
             y) cout << # x << " = " << x << ", " << # y << " = " << y << endl;
#define printArr(arr, size) cout << # arr << " : "; \
   for (int i = 0; i < size; i++) cout << arr[i] << " "; cout << endl;

// Modified version of max heapify to work with vector of pairs
void maxHeapify(vector<pair<int, int> >& arr, int size, int index) {
   int largest = index, left = 2 * index + 1, right = 2 * index + 2;

   if ((left < size) && (arr[left].second > arr[largest].second)) {
      largest = left;
   }

   if ((right < size) && (arr[right].second > arr[largest].second)) {
      largest = right;
   }

   if (largest != index) {
      swap(arr[largest], arr[index]);
      maxHeapify(arr, size, largest);
   }
}

void buildHeap(vector<pair<int, int> >& arr) {
   int size = arr.size();

   for (int i = (size - 2) / 2; i >= 0; i--) {
      maxHeapify(arr, arr.size(), i);
   }
}

/**
 * @brief      Finds a k nearest elements to x from a given array. The idea is
 *             to use iterate over the array k times and each time we find the
 *             element whose distance is minimum from the value x. Each time we
 *             find the closest element we add it to a hashmap to keep a track
 *             of which number have already been accounted for so that in next
 *             loops we don't consider them again. It's time complexity is
 *             O(n*k) and it's space complexity is O(n).
 *
 * @param      arr   The array
 * @param[in]  size  The size of the array
 * @param[in]  x     Any given number
 * @param[in]  k     Count of nearest numbers to find to x
 */
void findKNearestElementsToXFromArrayNaive(int *arr, int size, int x, int k) {
   unordered_set<int> set;

   for (int i = 0; i < k; i++) {
      int minDiff      = INT_MAX;
      int minDiffIndex = -1;

      for (int j = 0; j < size; j++) {
         if ((set.count(j) == 0) && (abs(arr[j] - x) < minDiff)) {
            minDiff      = abs(arr[j] - x);
            minDiffIndex = j;
         }
      }
      cout << arr[minDiffIndex] << " ";
      set.insert(minDiffIndex);
   }
}

/**
 * @brief      Finds a k nearest elements to x from a given array. The idea is
 *             to use a binary search tree map and store absolute difference to
 *             index mapping. Now we just iterate over this map and print the
 *             first k elements as iteration over a map is always in ascending
 *             order so we get first k nearest elements. It's time complexity is
 *             O(nlogn) and it's space complexity is O(n).
 *
 * @param      arr   The array
 * @param[in]  size  The size of the array
 * @param[in]  x     Any given number
 * @param[in]  k     Count of nearest numbers to find to x
 */
void findKNearestElementsToXFromArray1(int *arr, int size, int x, int k) {
   map<int, int> map;

   for (int i = 0; i < size; i++) {
      int currDiff = abs(arr[i] - x);
      map[currDiff] = i;
   }

   int count = 0;

   for (auto i : map) {
      cout << arr[i.second] << " ";

      if (++count == k) {
         return;
      }
   }
}

/**
 * @brief      Finds a k nearest elements to x from a given array. The idea is
 *             to use a max heap. We make a new vector of pair where we store
 *             index and the absolute difference of value at that index and x.
 *             Now we form a heap of this vector using build heap method and
 *             then this becomes a problem of K smallest elements which can be
 *             solved in same exact way by continuosly forming heap of first k
 *             elements, we keep checking every element from k to size - 1 and
 *             if it is smaller than max then we keep replacing the root of heap
 *             with that value and fixing the heap of first k elements using
 *             heapify. It's time complexity is O(nlogk) and space complexity is
 *             O(n).
 *
 * @param      arr   The array
 * @param[in]  size  The size of the array
 * @param[in]  x     Any given number
 * @param[in]  k     Count of nearest numbers to find to x
 */
void findKNearestElementsToXFromArrayUsingCustomHeapImplementation(int *arr,
                                                                   int  size,
                                                                   int  x,
                                                                   int  k) {
   vector<pair<int, int> > itemAndIndexArr;

   for (int i = 0; i < size; i++) {
      itemAndIndexArr.push_back({ i, abs(arr[i] - x) });
   }
   buildHeap(itemAndIndexArr);

   for (int i = k; i < size; i++) {
      int currAbsoluteDiff = abs(itemAndIndexArr[i].second - x);

      if (currAbsoluteDiff < itemAndIndexArr[0].second) {
         swap(itemAndIndexArr[i], itemAndIndexArr[0]);
         maxHeapify(itemAndIndexArr, k, 0);
      }
   }

   for (int i = 0; i < k; i++) {
      cout << arr[itemAndIndexArr[i].first] << " ";
   }
}

/**
 * @brief      Finds a k nearest elements to x from a given array. This is the
 *             exact same method as previous one, this one just uses the inbuilt
 *             priority queue instead of creating a custom one.
 *
 * @param      arr   The array
 * @param[in]  size  The size of the array
 * @param[in]  x     Any given number
 * @param[in]  k     Count of nearest numbers to find to x
 */
void findKNearestElementsToXFromArrayUsingSTL(int *arr, int size, int x,
                                              int k) {
   priority_queue<pair<int, int> > pq;

   for (int i = 0; i < k; i++) {
      pq.push({ abs(arr[i] - x), i });
   }

   for (int i = k; i < size; i++) {
      int currAbsoluteDiff = abs(arr[i] - x);

      if ((pq.top()).first > currAbsoluteDiff) {
         pq.pop();
         pq.push({ currAbsoluteDiff, i });
      }
   }

   while (!pq.empty()) {
      cout << arr[(pq.top()).second] << " ";
      pq.pop();
   }
}

int main() {
   int testCases;

   srand(time(0));
   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      int size, x, k;
      cin >> x;
      cin >> k;
      cin >> size;
      int *arr = new int[size];

      for (int i = 0; i < size; i++) {
         cin >> arr[i];
      }
      findKNearestElementsToXFromArrayUsingSTL(arr, size, x, k);
      cout << endl;
   }
   return (0);
}
