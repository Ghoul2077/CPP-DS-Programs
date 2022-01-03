#include <bits/stdc++.h>
#include <experimental/random>
using namespace std;

int min(int num1, int num2) {
   return (num1 > num2 ? num2 : num1);
}

int max(int num1, int num2) {
   return (num1 > num2 ? num1 : num2);
}

/**
 * @brief      Finds the maximum number of guests whom meeting is possible given
 *             their arrival time array and their respective departure time
 *             array in O(nlogn) time by using merge method of merge sort as
 *             base.
 *
 * @param      arrival    The arrival
 * @param      departure  The departure
 * @param[in]  size       The size
 *
 * @return     Max number of guests that is possible for us to meet
 */
int maxGuestsWhomMeetingPossible(int *arrival, int *departure, int size) {
   sort(arrival,   arrival + size);
   sort(departure, departure + size);

   int maxCount = INT_MIN;
   int count = 0;
   int i = 0, j = 0;

   while (i < size && j < size) {
      if (arrival[i] <= departure[j]) {
         count++;
         i++;
      } else {
         count--;
         j++;
      }
      maxCount = max(count, maxCount);
   }

   return (maxCount);
}

int main() {
   int arrival[]   = { 900, 600, 700 };
   int departure[] = { 1000, 800, 730 };
   int size        = sizeof(arrival) / sizeof(arrival[0]);

   int maxGuests = maxGuestsWhomMeetingPossible(arrival, departure, size);

   cout << maxGuests;

   return (0);
}
