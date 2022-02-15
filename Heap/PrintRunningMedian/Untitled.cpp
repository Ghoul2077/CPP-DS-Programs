#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;
#define deb(x) cout << # x << " = " << x << endl;
#define deb2(x, \
             y) cout << # x << " = " << x << ", " << # y << " = " << y << endl;
#define printArr(arr, size) cout << # arr << " : "; \
   for (int i = 0; i < size; i++) cout << arr[i] << " "; cout << endl;


struct Node {
   int   data;
   Node *left, *right;

   Node(int val) {
      data  = val;
      left  = NULL;
      right = NULL;
   }
};

// Helper function to extract median from a sorted array
float extractMedianFromSortedArray(int *arr, int size) {
   float median;

   if (size % 2 == 0) {
      float val1 = arr[size / 2];
      float val2 = arr[size / 2 - 1];
      median = (val1 + val2) / 2;
   } else {
      int medianIndex = size / 2;
      median = arr[medianIndex];
   }
   return (median);
}

/**
 * @brief      Prints a running median of a given array. Running median means
 *             median of every subarray that includes 0th index. The idea here
 *             is to use super naive method where we loop through the array n
 *             times and sort every subarray inplace in the original array. From
 *             this sorted subarray we find the median using a prebuilt method
 *             to extract median from sorted array. It's time complexity is
 *             O(n^2*logn) and it's space complexity is O(1).
 *
 * @param      arr   The array
 * @param[in]  size  The size of the array
 */
void printRunningMedianSuperNaive(int *arr, int size) {
   for (int i = 1; i <= size; i++) {
      sort(arr, arr + i);
      float median = extractMedianFromSortedArray(arr, i);
      cout << median << " ";
   }
}

/**
 * @brief      Prints a running median of a given array. Running median means
 *             median of every subarray that includes 0th index. The idea here
 *             is to use insertion sort the premise of which is built around
 *             placing ith item in it's correct place assuming all elements from
 *             0 to i - 1 are already sorted. Using this insertion sort method
 *             we sort the array for ith value and then we extract median from
 *             0 to i after we insert ith item in it's place. It's time
 *             complexity is O(n^2) and it's space complexity is O(1).
 *
 * @param      arr   The array
 * @param[in]  size  The size of the array
 */
void printRunningMedianNaive(int *arr, int size) {
   cout << arr[0] << " ";

   for (int i = 1; i < size; i++) {
      int j;
      int curr = arr[i];

      for (j = i - 1; j >= 0 && arr[j] > curr; j--) {
         arr[j + 1] = arr[j];
      }
      swap(curr, arr[j + 1]);

      int   runningSize = i + 1;
      float median      = extractMedianFromSortedArray(arr, runningSize);
      cout << median << " ";
   }
}

/**
 * @brief      Prints a running median of a given array. Running median means
 *             median of every subarray that includes 0th index. The idea here
 *             is to use a self balancing binary tree (Set in case of c++). We
 *             traverse the array and at each iteration we keep adding current
 *             item to the set (Balacing binary tree) along with which we also
 *             know how to find the kth smallest element of a binary tree so by
 *             looking at the size of current binary tree we figure out which
 *             all elements are needed to find the median and then we extract
 *             those from the tree and calculate the median. It's time
 *             complexity is O(n*(logn + h)) and it's space complexity is O(n).
 *
 * @param      arr   The array
 * @param[in]  size  The size of the array
 */
void printRunningMedian(int *arr, int size) {
   set<int> set;

   for (int i = 1; i <= size; i++) {
      set.insert(arr[i - 1]);
      auto  it = set.begin();
      float median, sum = 0;

      if (i % 2 == 0) {
         advance(it, i / 2 - 1);
         sum += *it;
         advance(it, 1);
         sum   += *it;
         median = sum / 2;
      } else {
         advance(it, i / 2);
         median = *it;
      }
      cout << median << " ";
   }
}

/**
 * @brief      Prints a running median of a given array. Running median means
 *             median of every subarray that includes 0th index. The idea is to
 *             have 2 seperate containers one will store smaller half of the
 *             running arrays the other one will store bigger half of the
 *             running array. At every point we know that the median can be
 *             either the rightmost element of the smaller container or the
 *             average of the rightmost element of smaller container and
 *             leftmost element of the bigger container. So we iterate through
 *             the array and keep adjusting the 2 containers in such a way that
 *             we maintain almost half of elements in each of the container.
 *             For containers the best choice is min heap and max heap
 *             (cache friendly) respectivly as we have need to continuosly
 *             extract max and min from the containers and we also insert and
 *             remove. It's time complexity is O(nlogn) and it's space
 *             complexity is O(n).
 *
 * @param      arr   The array
 * @param[in]  size  The size of the array
 */
void printRunningMedianOptimize(int *arr, int size) {
   priority_queue<int> smallerContainer;
   priority_queue<int, vector<int>, greater<int> > biggerContainer;

   smallerContainer.push(arr[0]);
   cout << arr[0] << " ";

   for (int i = 1; i < size; i++) {
      if (smallerContainer.size() > biggerContainer.size()) {
         if (smallerContainer.top() > arr[i]) {
            biggerContainer.push(smallerContainer.top());
            smallerContainer.pop();
            smallerContainer.push(arr[i]);
         } else {
            biggerContainer.push(arr[i]);
         }
         cout << (smallerContainer.top() + biggerContainer.top()) / 2.0 << " ";
      } else {
         if (smallerContainer.top() >= arr[i]) {
            smallerContainer.push(arr[i]);
         } else {
            biggerContainer.push(arr[i]);
            smallerContainer.push(biggerContainer.top());
            biggerContainer.pop();
         }
         cout << smallerContainer.top() << " ";
      }
   }
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
      printRunningMedianOptimize(arr, size);
      cout << endl;
   }
   return (0);
}
