#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;
#define deb(x) cout << # x << " = " << x << endl;
#define deb2(x, y) cout << # x << " = " << x << ", " << # y << " = " << y << endl;
#define printArr(arr, size) cout << # arr << " : "; for (int i = 0; i < size; i++) cout << arr[i] << " "; cout << endl;


/**
 * @brief      Given an odd number we need to print the following kind of 
 *			   pattern :-
 *			   
 *			   1 2 3 4 5
 *			   2   3   4
 *			   3 3 3 3 3
 *			   4   3   2
 *			   5 4 3 2 1
 *
 * @param[in]  num   The odd number
 */
void solve(int num) {
   for(int i = 1; i <= num; i++) {
      if(i == 1) {
         for (int j = 1; j <= num; ++j) {
            cout << j << " ";
         }
      } else if(i == num) {
         for (int j = num; j >= 1; --j) {
            cout << j << " ";
         }
      } else if(i != (num + 1) / 2) {
         cout << i << " ";
         for (int j = 0; j < (num - 3) / 2; ++j) {
            cout << "  ";
         }
         cout << (num + 1) / 2 << " ";
         for (int j = 0; j < (num - 3) / 2; ++j) {
            cout << "  ";
         }
         cout << (num - i + 1);
      } else {
         for (int i = 0; i < num; ++i) {
            cout << (num + 1) / 2 << " ";
         }
      }
      cout << endl;
   }
}

int main() {
   int testCases;

   srand(time(0));
   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      int num;
      cin >> num;
      solve(num);
      cout << endl;
   }
   return (0);
}
