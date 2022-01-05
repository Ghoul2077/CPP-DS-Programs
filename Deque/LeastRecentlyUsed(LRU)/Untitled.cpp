#include <bits/stdc++.h>
using namespace std;

class Node {
public:
   int data;
   Node *next, *prev;

   Node(int val) {
      data = val;
      next = NULL;
      prev = NULL;
   }
};

class LRU {
private:
   int length;
   Node *head, *tail;
   unordered_map<int, Node *>dataToNode;

   void moveNodeToFront(Node *ref) {
      if (ref != head) {
         if (ref == tail) {
            tail = ref->prev;
         }
         ref->prev->next = ref->next;
         ref->next       = head;
         head->prev      = ref;
         ref->prev       = NULL;
         head            = ref;
      }
   }

   void insertFromFront(int val) {
      Node *newNode = new Node(val);

      dataToNode.insert({ val, newNode });
      newNode->next = head;

      if (head == NULL) {
         tail = newNode;
      } else {
         head->prev = newNode;
      }

      head = newNode;
   }

   void deleteTail() {
      Node *temp = tail;

      if (tail->prev != NULL) {
         tail->prev->next = NULL;
      }

      if (head == tail) {
         head = NULL;
      }
      tail = tail->prev;
      dataToNode.erase(temp->data);
      delete temp;
   }

public:
   LRU(int len) {
      length = len;
      head   = NULL;
      tail   = NULL;
   }

   LRU(Node *node, int len) {
      length = len;
      head   = node;
      tail   = node;
   }

   void print() {
      Node *curr = head;

      while (curr != NULL) {
         cout << curr->data << " ";
         curr = curr->next;
      }

      cout << endl;
   }

   string read(int val) {
      if (dataToNode.count(val) == 1) {
         Node *valNode = dataToNode[val];
         moveNodeToFront(valNode);
         return ("Hit");
      }

      insertFromFront(val);

      if (dataToNode.size() > length) {
         deleteTail();
      }

      return ("Miss");
   }
};

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      LRU *cache = new LRU(4);
      cout << cache->read(1) << endl;
      cout << cache->read(3) << endl;
      cout << cache->read(1) << endl;
      cout << cache->read(2) << endl;
      cout << cache->read(4) << endl;
      cout << cache->read(5) << endl;
      cout << cache->read(1) << endl;
      cout << cache->read(5) << endl;
   }

   return (0);
}
