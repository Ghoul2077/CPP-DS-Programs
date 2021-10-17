#include <limits.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
   int   data;
   Node *next;
   Node *prev;

   Node(int val) {
      data = val;
      next = NULL;
      prev = NULL;
   }
};

Node* initializeDLL() {
   int val;

   cin >> val;
   Node *head = NULL;
   Node *curr = head;

   while (val != -1) {
      Node *newNode = new Node(val);

      if (head == NULL) {
         head = newNode;
         curr = newNode;
      } else {
         curr->next    = newNode;
         newNode->prev = curr;
         curr          = curr->next;
      }
      cin >> val;
   }

   return (head);
}

void printLL(Node *head) {
   Node *currNode = head;

   if (head == NULL) {
      return;
   } else {
      while (currNode != NULL) {
         cout << currNode->data << " ";
         currNode = currNode->next;
      }
   }
}

Node* deleteHeadDLL(Node *head) {
   if (head == NULL) {
      return (head);
   }

   Node *prevHead = head;

   head       = head->next;
   head->prev = NULL;

   delete prevHead;

   return (head);
}

Node* deleteAtIndexDLL(Node *head, int index) {
   if (index == 0) {
      return (deleteHeadDLL(head));
   }
   Node *curr  = head;
   int   count = 0;

   while (curr->next != NULL && count != index) {
      curr = curr->next;
      count++;
   }

   if (count == index) {
      Node *toDelete = curr;
      Node *prev     = curr->prev;

      curr       = curr->next;
      curr->prev = prev;
      prev->next = curr;

      delete toDelete;
   }
   return (head);
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      Node *head = initializeDLL();
      head = deleteAtIndexDLL(head, 1);
      printLL(head);
   }

   return (0);
}
