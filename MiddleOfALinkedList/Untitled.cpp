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
 * @brief      Finds the middle of a linked list using 2 traversals in O(n) time
 *             complexity and Q(1) space complexity.
 *
 * @param      head  The head
 *
 * @return     Data at middle of the linked list
 */
int middleOfALinkedListNaive(Node *head) {
   Node *curr;
   int   count = 0;

   for (curr = head; curr != NULL; curr = curr->next) {
      count++;
   }
   curr = head;

   for (int i = 0; i < count / 2; i++) {
      curr = curr->next;
   }
   return (curr->data);
}

/**
 * @brief      Finds the middle of a linked list used tortoise and hare
 *             methodology in O(n) time complexity and Q(1) space complexity.
 *
 * @param      head  The head
 *
 * @return     Data at middle of the linked list
 */
int middleOfALinkedList(Node *head) {
   Node *tortoisePtr = head;
   Node *harePtr     = head;

   while (harePtr != NULL && harePtr->next != NULL) {
      harePtr     = harePtr->next->next;
      tortoisePtr = tortoisePtr->next;
   }

   if (tortoisePtr != NULL) {
      return (tortoisePtr->data);
   } else {
      return (-1);
   }
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      Node *head = initializeLL();
      cout << middleOfALinkedListNaive(head) << endl;
      printLL(head);
   }

   return (0);
}
