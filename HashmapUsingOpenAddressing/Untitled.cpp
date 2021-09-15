#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;

class hashMapUsingOpenAddressing {
private:
   bigInt numberOfElements;
   int *deletedIndicator = new int(0);
   vector<int *> *hashBucket;

   bigInt hashCodeGenerator(int data) {
      bigInt key = data % 7;

      return key;
   }

public:
   hashMapUsingOpenAddressing() {
      this->numberOfElements = 0;
      this->hashBucket       = new vector<int *>;
   }

   void insert(int data)  {
      if (this->hashBucket->max_size() <= this->hashBucket->size()) {
         cout << "Out of memory" << endl;
         return;
      }

      bigInt initialKey = hashCodeGenerator(data);
      bigInt key        = initialKey;
      int   *newData    = new int(data);

      if (this->hashBucket->size() <= key) {
         this->hashBucket->resize(key + 1, NULL);
         this->hashBucket->at(key) = newData;
      } else if (this->hashBucket->size() == numberOfElements) {
         this->hashBucket->push_back(newData);
      } else {
         while (this->hashBucket->at(key) != NULL &&
                *this->hashBucket->at(key) != data) {
            if (this->hashBucket->at(key) == deletedIndicator) {
               break;
            }
            ++key %= this->hashBucket->size();
         }
         this->hashBucket->at(key) = newData;
      }

      this->numberOfElements++;
   }

   void print()           {
      for (auto i = this->hashBucket->begin(); i < this->hashBucket->end();
           i++) {
         if ((*i == deletedIndicator) || (*i == NULL)) {
            cout << "NULL" << "  ";
         } else {
            cout << **i << "  ";
         }
      }
      cout << endl;
   }

   void search(int val)   {
      bigInt initialKey = hashCodeGenerator(val);
      bigInt key        = initialKey;

      if (key >= this->hashBucket->size()) {
         cout << "Not Found" << endl;
         return;
      }

      while (this->hashBucket->at(key) != NULL) {
         if ((this->hashBucket->at(key) != deletedIndicator) &&
             (*this->hashBucket->at(key) == val)) {
            cout << "Found at index " << key << endl;
            return;
         }
         ++key %= this->hashBucket->size();

         if (key == initialKey) {
            break;
         }
      }
      cout << "Not Found" << endl;
   }

   void _delete(int data) {
      bigInt initialKey = hashCodeGenerator(data);
      bigInt key        = initialKey;

      if (key >= this->hashBucket->size()) {
         return;
      }

      while (this->hashBucket->at(key) != NULL) {
         if ((this->hashBucket->at(key) != deletedIndicator) &&
             (*this->hashBucket->at(key) == data)) {
            delete this->hashBucket->at(key);
            this->hashBucket->at(key) = deletedIndicator;
            break;
         }
         ++key %= this->hashBucket->size();

         if (key == initialKey) {
            return;
         }
      }

      this->numberOfElements--;
   }
};

int main() {
   hashMapUsingOpenAddressing *newHashMap = new hashMapUsingOpenAddressing();

   newHashMap->insert(40);
   newHashMap->insert(60);
   newHashMap->insert(18);
   newHashMap->insert(30);
   newHashMap->_delete(18);
   newHashMap->search(18);
   newHashMap->search(20);

   return 0;
}
