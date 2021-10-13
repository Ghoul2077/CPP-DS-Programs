#include <limits.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
   int   data;
   Node *next;
   Node *prev;

   Node(int val) {
      data = val;
      next = NULL;
      prev = NULL;
   }
};

Node* initializeDLL() {
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
         curr->next    = newNode;
         newNode->prev = curr;
         curr          = curr->next;
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
 * @brief      Inserts at the beginning of a given linked list in O(1) time
 *             complexity and Q(1) space complexity.
 *
 * @param      head  The head of linked list
 * @param[in]  val   The value to insert in linked list
 *
 * @return     New head of linked list
 */
Node* insertInBeginning(Node *head, int val) {
   Node *newNode = new Node(val);

   newNode->next = head;

   if (head != NULL) {
      head->prev = newNode;
   }
   return (newNode);
}

/**
 * @brief      Inserts at the end of a given linked list in O(n) time complexity
 *             and Q(1) space complexity.
 *
 * @param      head  The head of linked list
 * @param[in]  val   The value to insert in linked list
 *
 * @return     New head of linked list
 */
Node* insertAtEnd(Node *head, int val) {
   Node *newNode = new Node(val);

   if (head == NULL) {
      return (newNode);
   }
   Node *curr = head;

   while (curr->next != NULL) {
      curr = curr->next;
   }
   curr->next    = newNode;
   newNode->prev = curr;
   return (head);
}

/**
 * @brief      Inserts at the given index of a given linked list in O(n) time
 *             complexity and Q(1) space complexity.
 *
 * @param      head  The head of linked list
 * @param[in]  val   The value to insert in linked list
 *
 * @return     New head of linked list
 */
Node* insertAtGivenIndex(Node *head, int val, int index) {
   if (index < 0) {
      cout << "Index underflow" << endl;
      return (head);
   }

   if (index == 0) {
      return (insertInBeginning(head, val));
   }

   Node *newNode = new Node(val);
   Node *curr    = head;
   int   count   = 0;

   while (curr->next != NULL && count != index - 1) {
      curr = curr->next;
      count++;
   }

   if (count == index - 1) {
      newNode->next = curr->next;
      curr->next    = newNode;
      newNode->prev = curr;
   } else {
      cout << "Index overflow" << endl;
   }
   return (head);
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      Node *head = initializeDLL();
      head = insertAtGivenIndex(head, 12, 1);
      printLL(head);
   }

   return (0);
}
