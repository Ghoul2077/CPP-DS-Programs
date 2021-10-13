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

/**
 * @brief      Reverse a linked list in O(n) time complexity and Q(1) space
 *             complexity. 
 *
 * @param      head  The head
 *
 * @return     New head of linked list
 */
Node* reverseDLL(Node *head) {
   if (head == NULL) {
      return (head);
   }

   Node *curr = head;

   while (curr->next != NULL) {
      Node *temp = curr->next;
      curr->next = curr->prev;
      curr->prev = temp;
      curr       = temp;
   }

   curr->next = curr->prev;
   curr->prev = NULL;
   return (curr);
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      Node *head = initializeDLL();
      head = reverseDLL(head);
      printLL(head);
   }

   return (0);
}
