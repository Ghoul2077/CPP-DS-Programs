#include <iostream>
#include <math.h>
using namespace std;

class Node {
public:
   int data;
   Node *next;

   Node(int data) {
      this->data = data;
      this->next = NULL;
   }
};

class LinkedList {
private:
   Node *head;
   int length;
   Node *tail;

public:
   LinkedList() {
      this->head   = NULL;
      this->length = 0;
      this->tail   = NULL;
   }

   void printLL() {
      Node *ptr = this->head;

      cout << "*";
      while (ptr != NULL) {
         cout << "->" << ptr->data;
         ptr = ptr->next;
      }
   }

   void initializeLL() {
      int  data;
      Node *ptr = this->head;

      cout << "Enter value, otherwise enter -1 to exit : ";
      cin >> data;

      while (data != -1) {
         Node *newNode = new Node(data);
         if (ptr == NULL) {
            this->head = newNode;
            ptr        = newNode;
         } else {
            ptr->next = newNode;
            ptr       = ptr->next;
         }
         this->length++;
         cin >> data;
      }
   }

   void reverseLL() {
      Node *curr = this->head;
      Node *prev = NULL;
      Node *next = curr->next;

      while (curr != NULL) {
         next       = curr->next;
         curr->next = prev;
         prev       = curr;
         curr       = next;
      }

      this->head = prev;
   }

   void merge(LinkedList *l2) {
   }
};

int main() {
   LinkedList *l1 = new LinkedList;

   l1->initializeLL();
   l1->reverseLL();
   l1->printLL();
}
