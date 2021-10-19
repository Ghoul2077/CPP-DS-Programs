#include <limits.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
   int   data;
   Node *next;

   Node(int val) {
      data = val;
      next = NULL;
   }
};

Node* initializeLL() {
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
         curr->next = newNode;
         curr       = curr->next;
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
 * @brief      Inserts into a sorted linked list and maintains sorted order in 
 *             O(n) time complexity and Q(1) space complexity.
 *
 * @param      head  The head
 * @param[in]  val   The value
 *
 * @return     New head of the linked list
 */
Node* sortedInsertInLL(Node *head, int val) {
   Node *newNode = new Node(val);

   if (head == NULL) {
      return (newNode);
   }

   Node *curr = head;
   Node *prev = NULL;

   while (curr != NULL && curr->data < val) {
      prev = curr;
      curr = curr->next;
   }

   newNode->next = curr;

   if (prev != NULL) {
      prev->next = newNode;
      return (head);
   } else {
      return (newNode);
   }
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      Node *head = initializeLL();
      head = sortedInsertInLL(head, 5);
      head = sortedInsertInLL(head, 23);
      printLL(head);
   }

   return (0);
}
