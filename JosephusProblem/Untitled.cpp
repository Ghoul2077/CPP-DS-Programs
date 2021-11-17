#include <iostream>
using namespace std;

void josephusProblem(string arr[], int numOfPeople, int killNum) {
   if (numOfPeople == 1) {
      cout << arr[0] << endl;
   } else {
      string newArr[numOfPeople - 1];

      if (killNum > numOfPeople) {
         killNum = (killNum % numOfPeople == 0) ?
                   numOfPeople : (killNum % numOfPeople);
      }

      for (int i = 0; i < numOfPeople; i++) {
         if (i == killNum - 1) {
            continue;
         }

         if (i < killNum - 1) {
            newArr[numOfPeople - killNum + i] = arr[i];
         } else {
            newArr[i - killNum] = arr[i];
         }
      }
      josephusProblem(newArr, numOfPeople - 1, killNum);
   }
}

int josephusProblemBetterSolution(int numOfPeople, int killNum) {
   if (numOfPeople == 1) {
      return (0);
   } else {
      return ((josephusProblemBetterSolution(numOfPeople - 1, killNum)
               + killNum) % numOfPeople);
   }
}

int main() {
   string table[] = { "A", "B", "C", "D", "E", "F", "G" };

   josephusProblem(table, 7, 3);
   cout << table[josephusProblemBetterSolution(7, 3)];
}
