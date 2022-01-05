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
 * @brief      Finds the length of loop in a linked list in O(n) time complexity
 *             and Q(1) space complexity. This is a variation of Floyde cycle
 *             detection algorithm where after detecting a cycle we put one
 *             pointer ahead of our meeting point and run a loop until we reach
 *             the meeting point again to count the number of nodes.
 *
 * @param      head  The head
 *
 * @return     Count of nodes if loop is found, -1 otherwise
 */
int lengthOfLoopInLinkedList(Node *head) {
   Node *slowPtr = head, *fastPtr = head;
   int   count = 1;

   while (fastPtr != NULL && fastPtr->next != NULL) {
      slowPtr = slowPtr->next;
      fastPtr = fastPtr->next->next;

      if (slowPtr == fastPtr) {
         break;
      }
   }

   if (slowPtr != fastPtr) {
      return (-1);
   }

   slowPtr = slowPtr->next;

   while (slowPtr != fastPtr) {
      slowPtr = slowPtr->next;
      count++;
   }

   return (count);
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      Node *head = initializeLL();
      cout << lengthOfLoopInLinkedList(head) << endl;
      printLL(head);
   }

   return (0);
}
