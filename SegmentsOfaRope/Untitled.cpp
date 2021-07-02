#include <iostream>
using namespace std;

int max(int first, int second, int third) {
   if (first > second && first > third) {
      return(first);
   } else if (second > first && second > third) {
      return(second);
   } else {
      return(third);
   }
}

/**
 * @brief      the maximum cuts that can be put on the rope so that the
 *             resulting partitions are in [a, b, c]
 *
 * @param[in]  maxCuts   The maximum cuts allowed or No. of smaller
 *                       ropes main rope is composed of
 *
 * @param[in]  a         Part of set
 * @param[in]  b         Part of set
 * @param[in]  c         Part of set
 * @param[in]  cutCount  The cut count
 *
 * @return     tail reccursive return of the maximum cut possible
 */
int maxPieces(int maxCuts, int a, int b, int c, int cutCount = 0) {
   if (maxCuts == 0) {
      return(cutCount);
   }
   if (maxCuts < 0) {
      return(-1);
   }
   cutCount++;
   return(max(maxPieces(maxCuts - a, a, b, c, cutCount),
              maxPieces(maxCuts - b, a, b, c, cutCount),
              maxPieces(maxCuts - c, a, b, c, cutCount)
              ));
}

int main() {
   int count = maxPieces(23, 11, 9, 13);

   cout << count;
}
