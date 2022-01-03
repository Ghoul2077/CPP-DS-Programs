#include <bits/stdc++.h>
using namespace std;

void printMatrix(int matrix[20][20], int maxWeight) {
   for (int i = 0; i <= 3; i++) {
      for (int j = 0; j <= maxWeight; j++) {
         cout << matrix[i][j] << " ";
      }
      cout << endl;
   }
}

int max(int first, int second) {
   return (first > second ? first : second);
}

/**
 * @brief      finds maximum value that can be obtained with given items and
 *             weight contraints using dynamic programming
 *
 * @param      objects    The objects / items as array
 * @param[in]  maxWeight  The maximum weight
 *
 * @return     integer -> maximum value possible
 */
int knapSack(int objects[][2], int maxWeight) {
   int valMatrix[20][20], i, j, itemWeight, itemValue;

   for (i = 0; i <= 3; i++) {
      if (i != 0) {
         itemWeight = objects[i - 1][0];
         itemValue  = objects[i - 1][1];
      }

      for (j = 0; j <= maxWeight; j++) {
         if ((i == 0) || (j == 0)) {
            valMatrix[i][j] = 0;
         } else {
            int bagWeight = j;
            int diff      = bagWeight - itemWeight;

            if (diff < 0) {
               valMatrix[i][j] = valMatrix[i - 1][j];
            } else {
               valMatrix[i][j] = max(
                  valMatrix[i - 1][j],
                  itemValue + valMatrix[i - 1][diff]
                  );
            }
         }
      }
   }

   // printMatrix(valMatrix, maxWeight);
   return (valMatrix[i - 1][j - 1]);
}

int main() {
   // [[weight, value]] -> representation of sack
   int objects[][2] = { { 1, 10 }, { 2, 15 }, { 3, 40 } };
   int maxVal       = knapSack(objects, 6);

   cout << maxVal;
}
