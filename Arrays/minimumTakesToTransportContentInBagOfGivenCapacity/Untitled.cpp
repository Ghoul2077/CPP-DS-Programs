#include <bits/stdc++.h>
using namespace std;

int minimumTakesToTransportContentInBagOfCapacity(int *arr, int size, int cap) {
   sort(arr, arr + size);
   int left = 0, right = size - 1;
   int count = 0;

   while (left <= right) {
      int sum = arr[left] + arr[right];

      if (sum <= cap) {
         left++;
         right--;
      } else {
         right--;
      }
      count++;
   }
   return (count);
}

int main() {
   int cap, size;

   cin >> cap;
   cin >> size;
   int *arr = new int[size];

   for (int i = 0; i < size; i++) {
      cin >> arr[i];
   }

   cout << minimumTakesToTransportContentInBagOfCapacity(arr, size, cap);
}
