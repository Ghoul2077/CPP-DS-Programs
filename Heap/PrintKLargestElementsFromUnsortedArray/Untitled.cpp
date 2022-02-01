#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;
#define deb(x) cout << # x << " = " << x << endl;
#define deb2(x, \
             y) cout << # x << " = " << x << ", " << # y << " = " << y << endl;
#define printArr(arr, size) \
   cout << # arr << " : ";  \
   for (int i = 0; i < size; i++) cout << arr[i] << " "; cout << endl;


void heapify(int *arr, int size, int i) {
   int smallest = i, left = 2 * i + 1, right = 2 * i + 2;

   if ((left < size) && (arr[smallest] > arr[left])) {
      smallest = left;
   }

   if ((right < size) && (arr[smallest] > arr[right])) {
      smallest = right;
   }

   if (smallest != i) {
      swap(arr[smallest], arr[i]);
      heapify(arr, size, smallest);
   }
}

void buildMinHeap(int *arr, int size) {
   for (int i = (size - 2) / 2; i >= 0; i--) {
      heapify(arr, size, i);
   }
}

/**
 * @brief      Prints the k largest element from a given unsorted array. The
 *             idea is to sort the aarray first and then print the last k
 *             elements. It's time complexity is O(nlogn) and it's space
 *             complexity is O(1).
 *
 * @param      arr   The array
 * @param[in]  size  The size of the array
 * @param[in]  k     Number of largest elements to print
 */
void printKLargestElementFromUnsortedArrayNaive(int *arr, int size, int k) {
   sort(arr, arr + size);

   for (int i = size - k; i < size; i++) {
      cout << arr[i] << " ";
   }
}

/**
 * @brief      Prints the k largest element from a given unsorted array. The
 *             idea is to use a max heap and print top element and pop it k
 *             times. It's time complexity is O(klogn) and it's space complexity
 *             is O(n).
 *
 * @param      arr   The array
 * @param[in]  size  The size of the array
 * @param[in]  k     Number of largest elements to print
 */
void printKLargestElementFromUnsortedArrayUsingMaxHeap(int *arr, int size,
                                                       int k) {
   priority_queue<int> pq(arr, arr + size);

   for (int i = 0; i < k; i++) {
      cout << pq.top() << " ";
      pq.pop();
   }
}

/**
 * @brief      Prints the k largest element from a given unsorted array. The
 *             idea is to use a min heap, here we build a min heap from the
 *             first k elements of the array and keep this seperate. Next we
 *             loop through from (size - k) to size and keep comparing each
 *             element to the top of the min heap, if the element is bigger than
 *             the top then we swap top with the element and reconstruct the
 *             min heap by calling heapify. It's time complexity is
 *             O((size-k)logk).
 *
 * @param      arr   The array
 * @param[in]  size  The size of the array
 * @param[in]  k     Number of largest elements to print
 */
void printKLargestElementFromUnsortedArrayUsingMinHeap(int *arr, int size,
                                                       int k) {
   buildMinHeap(arr, size);

   for (int i = size - k; i < size; i++) {
      if (arr[i] > arr[0]) {
         swap(arr[i], arr[0]);
         heapify(arr, k, 0);
      }
   }

   for (int i = 0; i < k; i++) {
      cout << arr[i] << " ";
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
      printKLargestElementFromUnsortedArrayUsingMinHeap(arr, size, k);
      cout << endl;
   }
   return (0);
}
