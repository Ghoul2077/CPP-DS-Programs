#include <iostream>
#include <list>
using namespace std;

class hashMapUsingChaining {
private:
   int bucketSize;
   list <int> *table;

public:
   hashMapUsingChaining(int size) {
      this->bucketSize = size;
      this->table      = new list <int>[size];
   }

   void insert(int data) {
      int        key        = data % this->bucketSize;
      list <int> *hashChain = &table[key];

      hashChain->push_back(data);
   }

   void search(int val) {
      int key = val % this->bucketSize;

      for (auto i: table[key]) {
         if (i == val) {
            cout << "Found" << endl;
            return;
         }
      }
      cout << "Not Found" << endl;
   }

   void _delete(int data) {
      int        key        = data % this->bucketSize;
      list <int> *hashChain = &table[key];

      hashChain->remove(data);
   }
};

int main() {
   hashMapUsingChaining *hashMap = new hashMapUsingChaining(7);

   hashMap->insert(40);
   hashMap->insert(60);
   hashMap->insert(30);
   hashMap->_delete(40);
   hashMap->search(20);
   hashMap->search(40);

   return(0);
}
