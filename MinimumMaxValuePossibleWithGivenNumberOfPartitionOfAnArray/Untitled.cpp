#include <bits/stdc++.h>
using namespace std;

int findMax(int *arr, int size) {
   int currMax = arr[0];

   for (int i = 1; i < size; i++) {
      currMax = max(currMax, arr[i]);
   }
   return (currMax);
}

int sum(int *arr, int size) {
   int sum = 0;

   for (int i = 0; i < size; ++i) {
      sum += arr[i];
   }
   return (sum);
}

/**
 * @brief      Find minimum number of maximum pages that any student from given
 *             number of student gets to read in O(numberOfStudents(C)books)
 *             time complexity using reccursion
 *
 * @param      arr               The arr
 * @param[in]  size              The size
 * @param[in]  numberOfStudents  The number of students
 *
 * @return     Minimum max page possible
 */
int minimumMaxPageAllocation(int *arr, int size, int numberOfStudents) {
   if (numberOfStudents == 1) {
      return (sum(arr, size));
   } else if (size == 1) {
      return (arr[0]);
   } else {
      int res = INT_MAX;

      for (int i = 1; i < size; ++i) {
         int totalPagesOfIBooks           = sum(&arr[0], i);
         int numberOfStudentsLeft         = numberOfStudents - 1;
         int numberOfBooksLeft            = size - i;
         int minimumMaxPagesFromRemaining = minimumMaxPageAllocation(&arr[i],
                                                                     numberOfBooksLeft,
                                                                     numberOfStudentsLeft);
         int maxWithIBooksRead = max(totalPagesOfIBooks,
                                     minimumMaxPagesFromRemaining);
         res = min(res, maxWithIBooksRead);
      }
      return (res);
   }
   return (0);
}

bool isFeasibleSolution(int *arr, int size, int numberOfStudents, int val) {
   int studentsRequired = 1, sum = 0;

   for (int i = 0; i < size; i++) {
      if (sum + arr[i] > val) {
         studentsRequired++;
         sum = arr[i];
      } else {
         sum += arr[i];
      }
   }
   return (studentsRequired <= numberOfStudents);
}

/**
 * @brief      Find minimum number of maximum pages that any student from given
 *             number of student gets to read in O(nlog(sumOfArray)) time
 *             complexity using binary search by finding that the maximum always
 *             lies between the maximum of the array and sum of the array & then
 *             checking each value between that range for feasability.
 *
 * @param      arr               The arr
 * @param[in]  size              The size
 * @param[in]  numberOfStudents  The number of students
 *
 * @return     Minimum max page possible
 */
int minimumMaxPageAllocationEfficient(int *arr, int size,
                                      int numberOfStudents) {
   int low  = findMax(arr, size);
   int high = sum(arr, size);
   int res  = 0;

   while (low <= high) {
      int mid = (low + high) / 2;

      if (isFeasibleSolution(arr, size, numberOfStudents, mid)) {
         res  = mid;
         high = mid - 1;
      } else {
         low = mid + 1;
      }
   }
   return (res);
}

int main() {
   int arr[]            = { 10, 20, 30, 40 };
   int size             = sizeof(arr) / sizeof(arr[0]);
   int numberOfStudents = 2;

   cout << minimumMaxPageAllocationEfficient(arr, size, numberOfStudents);
   return (0);
}
