#include <bits/stdc++.h>
using namespace std;

void insert(bool *arr, int val) {
   arr[val] = true;
}

void search(bool *arr, int val) {
   cout << (arr[val] ? "Found" : "Not Found") << endl;
}

void _delete(bool *arr, int val) {
   arr[val] = false;
}

int main() {
   bool *hashArray = new bool[1000];

   insert(hashArray, 10);
   insert(hashArray, 20);
   insert(hashArray, 119);
   search(hashArray, 10);
   search(hashArray, 20);
   _delete(hashArray, 119);
   search(hashArray, 119);

   return (0);
}
