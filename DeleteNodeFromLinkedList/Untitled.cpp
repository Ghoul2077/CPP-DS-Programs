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
 * @brief      Deletes the first node from a given linked list in Q(1) and Q(1)
 *             space complexity.
 *
 * @param      head  The head of linked list
 *
 * @return     New head of the linked list
 */
Node* deleteFirstNode(Node *head) {
   if (head == NULL) {
      cout << "Underflow" << endl;
      return (head);
   }

   Node *newHead = head->next;

   delete (head);
   return (newHead);
}

/**
 * @brief      Deletes the last node from a given linked list in Q(N) and Q(1)
 *             space complexity.
 *
 * @param      head  The head of linked list
 *
 * @return     New head of the linked list
 */
Node* deleteLastNode(Node *head) {
   if (head == NULL) {
      cout << "Underflow" << endl;
      return (head);
   }

   if (head->next == NULL) {
      delete head;
      return (NULL);
   }

   Node *curr = head;

   while (curr->next->next != NULL) {
      curr = curr->next;
   }
   Node *toDelete = curr->next;

   curr->next = NULL;

   delete (toDelete);
   return (head);
}

/**
 * @brief      Deletes the node at given index from a given linked list in Q(N) 
 *             time complexity and Q(1) space complexity.
 *
 * @param      head  The head of linked list
 *
 * @return     New head of the linked list
 */
Node* deleteAtGivenIndex(Node *head, int index) {
   if (index == 0) {
      return (deleteFirstNode(head));
   }

   int   count = 0;
   Node *curr  = head;

   while (curr->next->next != NULL && count != index - 1) {
      curr = curr->next;
      count++;
   }

   if (count == index - 1) {
      Node *toDelete = curr->next;
      curr->next = curr->next->next;
      delete toDelete;
   } else {
      cout << "Index value overflow" <<endl;
   }

   return (head);
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      Node *head = initializeLL();
      head = deleteAtGivenIndex(head, 0);
      head = deleteAtGivenIndex(head, 2);
      printLL(head);
      cout << endl;
   }

   return (0);
}
