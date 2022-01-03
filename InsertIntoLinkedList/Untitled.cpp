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
 * @brief      Inserts a node at beginning of the linked list in Q(1) time
 *             complexity and Q(1) space complexity.
 *
 * @param      head  The head of linked list
 * @param[in]  val   The value to be inserted
 *
 * @return     New head of the linked list
 */
Node* insertAtBeginning(Node *head, int val) {
   Node *newNode = new Node(val);

   newNode->next = head;
   return (newNode);
}

/**
 * @brief      Inserts a node at end of the linked list in Q(n) time
 *             complexity and Q(1) space complexity.
 *
 * @param      head  The head of linked list
 * @param[in]  val   The value to be inserted
 *
 * @return     New head of the linked list
 */
Node* insertAtEnd(Node *head, int val) {
   Node *newNode = new Node(val);

   if (head == NULL) {
      head = newNode;
   } else {
      Node *curr = head;

      while (curr->next != NULL) {
         curr = curr->next;
      }
      curr->next = newNode;
   }

   return (head);
}

/**
 * @brief      Insert to any given index position in the linked list, here index
 *             is 0 based. Insertion is done in O(n) time complexity and Q(1)
 *             space complexity.
 *
 * @param      head   The head of the linked list
 * @param[in]  val    The value to insert
 * @param[in]  index  The index to insert at
 *
 * @return     New head of the linked list
 */
Node* insert(Node *head, int val, int index) {
   Node *newNode = new Node(val);
   Node *curr    = head;

   if (index == 0) {
      return (insertAtBeginning(head, val));
   }

   int counter = 0;

   while (curr->next != NULL && counter < index - 1) {
      curr = curr->next;
      counter++;
   }

   if (counter == index - 1) {
      newNode->next = curr->next;
      curr->next    = newNode;
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
      Node *head = initializeLL();
      head = insert(head, 7, 5);
      printLL(head);
      cout << endl;
   }

   return (0);
}
