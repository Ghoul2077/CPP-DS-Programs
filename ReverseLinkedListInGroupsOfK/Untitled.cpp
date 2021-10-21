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
 * @brief      Reverses a linked list in groups of k in O(n) time complexity
 *             Q(1) space complexity.
 *
 * @param      head  The head
 * @param[in]  k     Number of nodes to flip at a time
 *
 * @return     New head of the linked list
 */
Node *reverseLinkedListInGroupsOfK(Node *head, int k) {
   Node *curr = head, *prevTail = NULL;
   bool firstPass = true;

   while(curr != NULL) {
      Node *currTail = curr, *prev = NULL;
      int count = 0;
      while(curr != NULL && count < k) {
         Node *next = curr->next;
         curr->next = prev;
         prev = curr;
         curr = next;
         count++;
      }
      if(firstPass) {
         head = prev;
         firstPass = false;
      }
      if(prevTail != NULL) {
         prevTail->next = prev;
      }
      prevTail = currTail;
   }

   return head;
}

/**
 * @brief      Reverses a linked list in groups of k in O(n) time complexity
 *             Q(n / k) space complexity by using modified reverse linked list
 *             function which reverses at most k nodes at a time and then uses
 *             reccursion to handle rest of the nodes.
 *
 * @param      head  The head
 * @param[in]  k     Number of nodes to flip at a time
 *
 * @return     New head of the linked list
 */
Node *reverseLinkedListInGroupsOfKReccursive(Node *head, int k) {
   Node *curr = head, *prev = NULL, *next = NULL;
   int count = 0;

   while(curr != NULL && count < k) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
      count++;
   }

   if(next != NULL) {
      Node *nextHead = reverseLinkedListInGroupsOfKReccursive(next, k);
      head->next = nextHead;
   }

   return prev;
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      Node *head = initializeLL();
      head = reverseLinkedListInGroupsOfK(head, 2);
      printLL(head);
   }

   return (0);
