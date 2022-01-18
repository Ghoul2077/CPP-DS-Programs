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
 * @brief      Removes all repeating elements from sorted linked list. This is
 *             not to be confused with removing of duplicates only as we remove
 *             all entries if a particular value repeats. The idea is inspired
 *             from removing duplicates from a linked list, the only
 *             modification is we keep a previous pointer and the last deleted
 *             value where our normal duplicate deletion algortihm takes care
 *             of deleting the duplicate elements in the front of current
 *             node and when it stops we compare if last deleted value is equal
 *             to the value of current node and if it is we delete that node
 *             also. It's time complexity is O(n) and it's space complexity is
 *             O(1).
 *
 * @param      head  The head of linked list
 *
 * @return     New head of the linked list
 */
Node* removeAllRepeatingElementsFromSortedLinkedList(Node *head) {
   if (head == NULL) {
      return (NULL);
   }
   int   lastDeletedVal = -1;
   Node *curr = head, *prev = NULL;

   while (curr->next != NULL) {
      if (curr->data == curr->next->data) {
         lastDeletedVal = curr->data;
         Node *temp = curr->next;
         curr->next = curr->next->next;
         delete temp;
      } else if (curr->data == lastDeletedVal) {
         Node *temp = curr;

         if (prev != NULL) {
            prev->next = curr->next;
         } else {
            head = curr->next;
         }
         curr = curr->next;
         delete temp;
      } else {
         prev = curr;
         curr = curr->next;
      }
   }

   return (head);
}

int main() {
   int testCases;

   srand(time(0));
   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      Node *head    = initializeLL();
      Node *newHead = removeAllRepeatingElementsFromSortedLinkedList(head);
      printLL(newHead);
   }

   return (0);
}
