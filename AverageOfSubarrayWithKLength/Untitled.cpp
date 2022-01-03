#include <bits/stdc++.h>
using namespace std;

vector<float>maxSumOfKElements(int *arr, int size, int k) {
   vector<float> averages;

   int maxWindowSum = 0;

   for (int i = 0; i < k; i++) {
      maxWindowSum += arr[i];
   }

   averages.push_back(maxWindowSum / k);

   int prevWindowSum = maxWindowSum;

   for (int i = k; i < size; i++) {
      int   newWindowSum = prevWindowSum - arr[i - k] + arr[i];
      float newAverage   = newWindowSum / k;
      prevWindowSum = newWindowSum;
      averages.push_back(newAverage);
   }

   return (averages);
}

void printVector(vector<float> *vect) {
   for (auto i = vect->begin(); i != vect->end(); ++i) {
      cout << *i << " ";
   }
}

int main() {
   int arr[]      = { 1, 8, 30, -5, 20, 7 };
   const int size = sizeof(arr) / sizeof(arr[0]);

   vector<float> averages = maxSumOfKElements(arr, size, 3);

   printVector(&averages);

   return (0);
}
