#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> *vect) {
   for (auto i = vect->begin(); i != vect->end(); ++i) {
      cout << *i << " ";
   }
}

vector<int>primeFactorsNaiveApproach(int num) {
   vector<int> primeFactors;

   while (num % 2 == 0) {
      primeFactors.push_back(2);
      num /= 2;
   }

   for (int i = 3; i <= sqrt(num); i += 2) {
      while (num % i == 0) {
         primeFactors.push_back(i);
         num /= i;
      }
   }

   if (num > 2) {
      primeFactors.push_back(num);
   }

   return (primeFactors);
}

int main() {
   vector<int> v1;
   int input;

   cout << "Enter the number : ";
   cin >> input;
   v1 = primeFactorsNaiveApproach(input);
   printVector(&v1);
   return (0);
}
