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
 * @brief      Finds a first node of the loop in a given linked list in O(n)
 *             time complexity and Q(1) space complexity. This is a variation
 *             of floyde cycle detection and removal algorithm and just changes
 *             last step to achieve the first node.
 *
 * @param      head  The head
 *
 * @return     Node reference if loop is present, NULL otherwise
 */
Node* findFirstNodeOfTheLoop(Node *head) {
   Node *slowPtr = head, *fastPtr = head;

   while (fastPtr != NULL && fastPtr->next != NULL) {
      slowPtr = slowPtr->next;
      fastPtr = fastPtr->next->next;

      if (slowPtr == fastPtr) {
         break;
      }
   }

   if (slowPtr != fastPtr) {
      return (NULL);
   }

   slowPtr = head;

   while (slowPtr != fastPtr) {
      slowPtr = slowPtr->next;
      fastPtr = fastPtr->next;
   }

   return (slowPtr);
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      Node *head             = initializeLL();
      Node *loopStartingNode = findFirstNodeOfTheLoop(head);

      if (loopStartingNode) {
         cout << loopStartingNode->data << endl;
      }
      printLL(head);
   }

   return (0);
}
