#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;
#define deb(x) cout << # x << " = " << x << endl;
#define deb2(x, \
             y) cout << # x << " = " << x << ", " << # y << " = " << y << endl;
#define printArr(arr, size) cout << # arr << " : "; \
   for (int i = 0; i < size; i++) cout << arr[i] << " "; cout << endl;


class MultiArrayElement {
public:
   int value;
   int arrayNum;
   int indexInArray;

   MultiArrayElement(int value, int arrayNum, int indexInArray) {
      this->value        = value;
      this->arrayNum     = arrayNum;
      this->indexInArray = indexInArray;
   }
};

struct Comparator {
   bool operator()(MultiArrayElement elem1, MultiArrayElement elem2) {
      return (elem1.value > elem2.value);
   }
};

/**
 * @brief      Merge given k sorted arrays. Here we use super naive approach by
 *             copying all elements from each array into a new array which we
 *             sort afterwards. It's time complexity is O(nklog(nk)) and it's
 *             space complexity is O(nk).
 *
 * @param      arr      The array of arrays
 * @param[in]  size     The number of arrays, in this case can also call it k
 * @param      arrSizes An array containing size of each individual array
 *
 * @return     Pointer to the merged array
 */
int* mergeKSortedArraysNaive(int **arr, int size, int *arrSizes) {
   int mergedArrSize = 0;

   for (int i = 0; i < size; i++) {
      mergedArrSize += arrSizes[i];
   }
   int *mergedArr = new int[mergedArrSize];
   int  counter   = 0;

   for (int i = 0; i < size; i++) {
      for (int j = 0; j < arrSizes[i]; j++) {
         mergedArr[counter++] = arr[i][j];
      }
   }
   sort(mergedArr, mergedArr + mergedArrSize);
   return (mergedArr);
}

/**
 * @brief      Merge given k sorted arrays. Here we use naive approach by
 *             running a loop k number of times and in each iteration we create
 *             a new temporary array which we use to merge the current state
 *             of the merged array and the current array we are at in the
 *             iteration. After merging in the temporary array we overwrite the
 *             merged array with this temporary array and move to the next
 *             iteration until all arrays are merged. It's time complexity is
 *             O(n*k*k) and it's space complexity is O(n*k).
 *
 * @param      arr      The array of arrays
 * @param[in]  size     The number of arrays, in this case can also call it k
 * @param      arrSizes An array containing size of each individual array
 *
 * @return     Pointer to the merged array
 */
int* mergeKSortedArrays(int **arr, int size, int *arrSizes) {
   int mergedArrSize = 0;

   for (int i = 0; i < size; i++) {
      mergedArrSize += arrSizes[i];
   }
   int *mergedArr       = new int[mergedArrSize];
   int  currLastElement = 0;

   for (int i = 0; i < size; i++) {
      int  currMergedArrSize = currLastElement + arrSizes[i];
      int *currMergedArr = new int[currMergedArrSize];
      int  arrPtr1 = 0, arrPtr2 = 0;
      int  indexCounter = 0;

      while (arrPtr1 != currLastElement && arrPtr2 != arrSizes[i]) {
         if (mergedArr[arrPtr1] < arr[i][arrPtr2]) {
            currMergedArr[indexCounter++] = mergedArr[arrPtr1++];
         } else {
            currMergedArr[indexCounter++] = arr[i][arrPtr2++];
         }
      }

      while (arrPtr1 != currLastElement) {
         currMergedArr[indexCounter++] = mergedArr[arrPtr1++];
      }

      while (arrPtr2 != arrSizes[i]) {
         currMergedArr[indexCounter++] = arr[i][arrPtr2++];
      }

      for (int i = 0; i < currMergedArrSize; i++) {
         mergedArr[i] = currMergedArr[i];
      }
      currLastElement = currMergedArrSize;
      delete currMergedArr;
   }
   return (mergedArr);
}

/**
 * @brief      Merge given k sorted arrays. The idea is to use a min heap with
 *             custom class function which stores value, array number that
 *             contains that value and index of the value in that array. We
 *             start by adding first element of all index into the min heap and
 *             then we loop through the heap extracting the root and storing the
 *             value in array and then add the next value to the heap from the
 *             object instance of the root we just extracted. It's time
 *             complexity is O(n*k*logk) and it's space complexity is O(n + k).
 *
 * @param      arr      The array of arrays
 * @param[in]  size     The number of arrays, in this case can also call it k
 * @param      arrSizes An array containing size of each individual array
 *
 * @return     Pointer to the merged array
 */
int* mergeKSortedArraysOptimized(int **arr, int size, int *arrSizes) {
   int mergedArrSize = 0;
   priority_queue<MultiArrayElement, vector<MultiArrayElement>, Comparator> pq;

   for (int i = 0; i < size; i++) {
      mergedArrSize += arrSizes[i];
   }
   int *mergedArr = new int[mergedArrSize];

   for (int i = 0; i < size; i++) {
      MultiArrayElement elem(arr[i][0], i, 0);
      pq.push(elem);
   }

   int counter = 0;

   while (!pq.empty()) {
      MultiArrayElement curr = pq.top();
      mergedArr[counter++] = curr.value;
      pq.pop();

      if (arrSizes[curr.arrayNum] - 1 != curr.indexInArray) {
         int nextArrayNum = curr.arrayNum;
         int nextIndex    = curr.indexInArray + 1;
         MultiArrayElement next(arr[nextArrayNum][nextIndex], nextArrayNum,
                                nextIndex);
         pq.push(next);
      }
   }

   return (mergedArr);
}

int main() {
   int testCases;

   srand(time(0));
   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      int size;
      cin >> size;
      int **arr           = new int *[size];
      int  *arrSizes      = new int[size];
      int   mergedArrSize = 0;

      for (int i = 0; i < size; i++) {
         cin >> arrSizes[i];
         mergedArrSize += arrSizes[i];
         arr[i]         = new int[arrSizes[i]];

         for (int j = 0; j < arrSizes[i]; j++) {
            cin >> arr[i][j];
         }
      }
      int *flattenedArr = mergeKSortedArraysOptimized(arr, size, arrSizes);
      printArr(flattenedArr, mergedArrSize);
      cout << endl;
   }
   return (0);
}
