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
 * @brief      Merges 2 sorted linked list in O(m + n) time complexity and Q(1)
 *             space complexity. It's better than merging arrays.
 *
 * @param      head1  The head of first linked list
 * @param      head2  The head of second linked list
 *
 * @return     New head of linked list
 */
Node* mergeLinkedList(Node *head1, Node *head2) {
   if(head1 == NULL) {
      return head2;
   } 
   if(head2 == NULL) {
      return head1;
   }

   Node *newHead = NULL, *tail = NULL;
   newHead = tail = head1->data < head2->data ? head1 : head2;

   while(head1 != NULL && head2 != NULL) {
      Node *smallerNode = NULL;

      if(head1->data < head2->data) {
         smallerNode = head1;
         head1 = head1->next;
      } else {
         smallerNode = head2;
         head2 = head2->next;
      }

      tail->next = smallerNode;
      tail = tail->next;
   }

   if(head2 == NULL) {
      tail->next = head1;
   }

   if(head1 == NULL) {
      tail->next = head2;
   }

   return newHead;
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      Node *head1 = initializeLL();
      Node *head2 = initializeLL();
      Node *mergedHead = mergeLinkedList(head1, head2);
      printLL(mergedHead);
   }

   return (0);
}
