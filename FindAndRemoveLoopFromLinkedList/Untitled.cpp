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

void findAndRemoveLoopsInLLNaive(Node *head) {
   unordered_set<Node *> vistiedNodes;
   Node *curr = head, *prev = NULL;

   while(curr != NULL) {
      if(vistiedNodes.count(curr) == 0) {
         vistiedNodes.insert(curr);
         prev = curr;
         curr = curr->next;
      } else {
         prev->next = NULL;
         break;
      }
   }
}

/**
 * @brief      Finds and remove loops in a given linked list in O(n) time
 *             complexity and Q(1) space complexity. It uses the floyde cycle
 *             detection algorithm and builds upon it by exploiting the fact
 *             after loop is detecting if we move slow pointer from head one
 *             node at a time and fast pointer from it position one node at a 
 *             time then we will be bound to hit at the starting point of the 
 *             loop.
 *
 * @param      head  The head
 */
void findAndRemoveLoopsInLL(Node *head) {
   Node *slowPtr = head, *fastPtr = head;

   while(fastPtr != NULL && fastPtr->next != NULL) {
      slowPtr = slowPtr->next;
      fastPtr = fastPtr->next->next;

      if(slowPtr == fastPtr) {
         break;
      }
   }

   if(slowPtr != fastPtr) {
      return;
   }

   // Edge case where the link list is actually circular linked list
   if(slowPtr == head && fastPtr == head) {
      do {
         fastPtr = fastPtr->next;
      } while(fastPtr->next != slowPtr);

      fastPtr->next = NULL;
      return;
   }

   slowPtr = head;
   while(slowPtr->next != fastPtr->next) {
      slowPtr = slowPtr->next;
      fastPtr = fastPtr->next;
   }

   fastPtr->next = NULL;
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      Node *head = initializeLL();
      findAndRemoveLoopsInLL(head);
      printLL(head);
   }

   return (0);
}
