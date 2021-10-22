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
 * @brief      Segregate even and odd elements of a linked list maintaining the
 *             order in which they occure. It's time complexity is O(n) and it's
 *             space complexity is Q(1). It takes 2 independent traversals, one
 *             to find the tail of linked list and the other one to move odd
 *             elements to the end of linked list.
 *
 * @param      head  The head
 *
 * @return     New head of the linked list
 */
Node *segregateEvenAndOddInLLNaive(Node *head) {
   Node *curr = head, *tail = head, *prev = NULL;

   while(tail->next != NULL) {
      tail = tail->next;
   }

   Node *currTail = tail;

   while(curr != tail) {
      Node *next = curr->next;

      if(curr->data % 2 != 0) {
         currTail->next = curr;
         currTail = currTail->next;
         currTail->next = NULL;

         if(prev != NULL) {
            prev->next = next;
         } else {
            head = next;
         }
         curr = next;
         continue;
      }

      prev = curr;
      curr = next;
   }

   return head;
}

/**
 * @brief      Segregate even and odd elements of a linked list maintaining the
 *             order in which they occure. It's time complexity is O(n) and it's
 *             space complexity is Q(1). It works by using only 1 traversal.
 *
 * @param      head  The head
 *
 * @return     New head of the linked list
 */
Node *segregateEvenAndOddInLL(Node *head) {
   Node *curr = head, *evenHead = NULL, *evenTail = NULL;
   Node *oddHead = NULL, *oddTail = NULL;

   while(curr != NULL) {
      Node *next = curr->next;

      if(curr->data % 2 == 0) {
         if(evenHead == NULL) {
            evenHead = curr;
            evenTail = curr;
         } else {
            evenTail->next = curr;
            evenTail = curr;
         }
      } else {
         if(oddHead == NULL) {
            oddHead = curr;
            oddTail = curr;
         } else {
            oddTail->next = curr;
            oddTail = curr;
         }
      }

      curr = next;
   }

   if(evenHead == NULL || oddHead == NULL) {
      return head;
   }

   evenTail->next = oddHead;
   oddTail->next = NULL;

   return evenHead;
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      Node *head = initializeLL();
      head = segregateEvenAndOddInLL(head);
      printLL(head);
   }

   return (0);
}
