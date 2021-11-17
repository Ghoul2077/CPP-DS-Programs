#include <limits.h>
#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

/**
 * @brief      Gets the which petrol pump to start with to travel in circle and
 *             reach back, given the petrol that can be filled at each petrol
 *             pump and distance to next petrol from current petrol pump. It's
 *             time complexity is O(n^2) and space complexity is Q(1).
 *
 * @param      petrol    The petrol
 * @param      distance  The distance
 * @param[in]  size      The size
 *
 * @return     The which petrol pump to start with
 */
int getWhichPetrolPumpToStartWithNaive(int *petrol, int *distance, int size) {
   for (int i = 0; i < size; i++) {
      bool isPossible = true;
      int  petrolLeft = petrol[i];

      for (int j = i; j < i + size; j++) {
         int curr = j % size;
         petrolLeft -= distance[curr];

         if (petrolLeft < 0) {
            isPossible = false;
            break;
         }

         petrolLeft += petrol[curr];
      }

      if (isPossible) {
         return (i + 1);
      }
   }

   return (-1);
}

/**
 * @brief      Gets the which petrol pump to start with to travel in circle and
 *             reach back, given the petrol that can be filled at each petrol
 *             pump and distance to next petrol from current petrol pump. It's
 *             time complexity is O(n) and space complexity is Q(n).
 *
 * @param      petrol    The petrol
 * @param      distance  The distance
 * @param[in]  size      The size
 *
 * @return     The which petrol pump to start with
 */
int getWhichPetrolPumpToStartWith(int *petrol, int *distance, int size) {
   deque<int> dq;

   dq.push_front(0);
   int petrolLeft = 0;
   int start = 0, end = 1;

   while (end != start || petrolLeft < 0) {
      while (petrolLeft < 0 && end != start) {
         petrolLeft -= (petrol[start] - distance[start]);
         start       = (start + 1) % size;

         if (start == 0) {
            return (-1);
         }
      }
      petrolLeft += (petrol[end] - distance[end]);
      end         = (end + 1) % size;
   }

   return (start + 1);
}

/**
 * @brief      Gets the which petrol pump to start with to travel in circle and
 *             reach back, given the petrol that can be filled at each petrol
 *             pump and distance to next petrol from current petrol pump. It's
 *             time complexity is O(n) and space complexity is Q(1).
 *
 * @param      petrol    The petrol
 * @param      distance  The distance
 * @param[in]  size      The size
 *
 * @return     The which petrol pump to start with
 */
int getWhichPetrolPumpToStartWithOptimized(int *petrol, int *distance,
                                           int size) {
   int petrolLeft = 0, prevPetrol = 0;
   int start = 0;

   for (int i = 0; i < size; i++) {
      petrolLeft += (petrol[i] - distance[i]);

      if (petrolLeft < 0) {
         start       = i + 1;
         prevPetrol += petrolLeft;
         petrolLeft  = 0;
      }
   }

   return ((petrolLeft + prevPetrol) >= 0 ? start + 1 : -1);
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      int size;
      cin >> size;
      int *arr1 = new int[size];
      int *arr2 = new int[size];

      for (int i = 0; i < size; i++) {
         cin >> arr1[i];
      }

      for (int i = 0; i < size; i++) {
         cin >> arr2[i];
      }
      cout << getWhichPetrolPumpToStartWithOptimized(arr1, arr2, size);
      cout << endl;
   }
   return (0);
}
