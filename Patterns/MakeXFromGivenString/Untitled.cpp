#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;
#define deb(x) cout << # x << " = " << x << endl;
#define deb2(x, \
             y) cout << # x << " = " << x << ", " << # y << " = " << y << endl;
#define printArr(arr, size) cout << # arr << " : "; \
   for (int i = 0; i < size; i++) cout << arr[i] << " "; cout << endl;


/**
 * @brief      Given a string we need to print the string in form of x. See
 *             the following example :
 *
 *             Input String : program
 *
 *             Output :
 *
 *             p     p
 *              r   r
 *               o o
 *                g
 *               r r
 *              a   a
 *             m     m
 *
 * @param[in]  str   The string
 */
void solve(string str) {
   int size = (int)str.size();

   for (int i = 0; i < size; ++i) {
      if (i < size / 2) {
         for (int j = 0; j < i; ++j) {
            cout << " ";
         }
         cout << str[i];

         for (int j = 0; j < (size - 2 * (i + 1)); ++j) {
            cout << " ";
         }
         cout << str[i];
      } else {
         for (int j = 0; j < (size - i - 1); ++j) {
            cout << " ";
         }
         cout << str[i];

         for (int j = 0; j < (2 * i - size); ++j) {
            cout << " ";
         }

         if ((i != size / 2) || (size % 2 == 0)) {
            cout << str[i];
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
      string str;
      getline(cin, str);
      solve(str);
      cout << endl;
   }
   return (0);
}
