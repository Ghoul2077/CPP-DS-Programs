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
 * @brief      Removes duplicate nodes from a sorted linked list in O(n)
 *             time complexity and Q(1) space complexity.
 *
 * @param      head  The head of linked list
 *
 */
Node* removeDuplicateFromSortedLL(Node *head) {
   if (head == NULL) {
      return (head);
   }

   Node *curr = head;

   while (curr->next != NULL) {
      if (curr->data == curr->next->data) {
         Node *temp = curr->next;
         curr->next = curr->next->next;
         delete temp;
      } else {
         curr = curr->next;
      }
   }

   return (head);
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      Node *head = initializeLL();
      removeDuplicateFromSortedLL(head);
      printLL(head);
   }

   return (0);
}
