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

/**
 * @brief      Searches a given value in linked list in O(n) time complexity and
 *             Q(1) space complexity.
 *
 * @param      head  The head
 * @param[in]  val   The value
 *
 * @return     Index of value if found, -1 otherwise
 */
int searchInLinkedList(Node *head, int val) {
   Node *curr  = head;
   int   count = 0;

   while (curr != NULL) {
      if (curr->data == val) {
         return (count);
      }
      curr = curr->next;
      count++;
   }

   return (-1);
}

/**
 * @brief      Searches a given value in linked list in O(n) time complexity and
 *             Q(N) space complexity using reccursive solution.
 *
 * @param      head  The head
 * @param[in]  val   The value
 *
 * @return     Index of value if found, -1 otherwise
 */
int searchInLinkedListReccursive(Node *head, int val, int level = 0) {
   if(head == NULL) {
      return -1;
   } else if (head->data == val) {
      return level;
   } else {
      return searchInLinkedListReccursive(head->next, val, level + 1);
   }
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      Node *head = initializeLL();
      cout << searchInLinkedList(head, 3);
   }

   return (0);
}
