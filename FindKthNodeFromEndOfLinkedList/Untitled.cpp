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
 * @brief      Finds kth node from end of linked list using double traversal
 *             of linked list i.e in O(n) time complexity and Q(1) space 
 *             complexity.
 *
 * @param      head  The head
 * @param[in]  k     Kth node value
 *
 * @return     Data in the kth node
 */
int kthNodeFromEndOfLinkedListNaive(Node *head, int k) {
   Node *curr  = head;
   int   count = 0;

   while (curr != NULL) {
      curr = curr->next;
      count++;
   }
   curr = head;

   if (k > count) {
      return (-1);
   }

   for (int i = 0; i < (count - k); i++) {
      curr = curr->next;
   }
   return (curr->data);
}

/**
 * @brief      Finds kth node from end of linked list using single traversal
 *             of linked list i.e in O(n) time complexity and Q(1) space 
 *             complexity.
 *
 * @param      head  The head
 * @param[in]  k     Kth node value
 *
 * @return     Data in the kth node
 */
int kthNodeFromEndOfLinkedList(Node *head, int k) {
   Node *ptr1 = head, *ptr2 = head;

   for (int i = 0; i < k && ptr2 != NULL; i++) {
      ptr2 = ptr2->next;
   }

   if (ptr2 == NULL) {
      return (-1);
   }

   while (ptr2 != NULL) {
      ptr2 = ptr2->next;
      ptr1 = ptr1->next;
   }
   return (ptr1->data);
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      Node *head = initializeLL();
      cout << kthNodeFromEndOfLinkedList(head, 4) << endl;
      printLL(head);
   }

   return (0);
}
