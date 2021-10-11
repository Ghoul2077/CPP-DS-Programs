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
 * @brief      Inserts values at given index in linked list in O(n) time
 *             complexity and Q(1) space complexity.
 *
 * @param      head   The head of the linked list
 * @param[in]  val    The value to be inserted
 * @param[in]  index  The index to be inserted at
 *
 * @return     New head of the linked list
 */
Node* insertAtGivenPosition(Node *head, int val, int index) {
   if (index < 0) {
      cout << "Index underflow";
      return (head);
   }

   if (index == 0) {
      Node *newNode = new Node(val);
      newNode->next = head;
      return (newNode);
   }

   Node *curr       = head;
   int   indexCount = 0;

   while (curr != NULL && indexCount != index - 1) {
      curr = curr->next;
      indexCount++;
   }

   if (indexCount == index - 1) {
      Node *newNode = new Node(val);
      newNode->next = curr->next;
      curr->next    = newNode;

      if (head == NULL) {
         return (newNode);
      }
   } else {
      cout << "Index overflow";
   }

   return (head);
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      Node *head = initializeLL();
      head = insertAtGivenPosition(head, 100, 5);
      printLL(head);
   }

   return (0);
}
