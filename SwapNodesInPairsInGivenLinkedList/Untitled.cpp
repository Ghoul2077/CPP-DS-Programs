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
 * @brief      Swaps the data of linked list in pairs at a time. It's time
 *             complexity is O(n) time complexity and Q(1) space complexity.
 *             It's drawback is that here we assume that the data is integer, in
 *             case the data is a more complex entity then swapping itself
 *             becomes a high complexity task.
 *
 * @param      head  The head
 *
 * @return     New head of linked list
 */
Node* swapNodesInPairsNaive(Node *head) {
    Node *curr = head;

    while(curr != NULL && curr->next != NULL) {
      swap(curr->data, curr->next->data);
      curr = curr->next->next;
    }

    return head;
}

/**
 * @brief      Swaps the data of linked list in pairs at a time. It's time
 *             complexity is O(n) time complexity and Q(1) space complexity.
 *             This is the best method to complete such task as there is no need
 *             to know about the internal structure of the linked list nodes to 
 *             swap.
 *
 * @param      head  The head
 *
 * @return     New head of linked list
 */
Node *swapNodesInPairs(Node *head) {
   if(head == NULL || head->next == NULL) {
      return head;
   }

   Node *curr = head, *prev = NULL;
   head = head->next;

   while(curr != NULL && curr->next != NULL) {
      if(prev != NULL) {
         prev->next = curr->next;
      }
      prev = curr;

      Node *next = curr->next->next;
      curr->next->next = curr;
      curr->next = next;
      curr = next;
   }

   return head;
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      Node *head = initializeLL();
      head = swapNodesInPairs(head);
      printLL(head);
   }

   return (0);
}
