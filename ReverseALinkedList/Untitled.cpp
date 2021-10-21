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
 * @brief      Reverses a linked list in O(n) time comeplexity by using 2
 *             independent loops and Q(n) space complexity due to auxillary
 *             array
 *
 * @param      head  The head
 *
 * @return     New head of the linked list
 */
Node* reverseLinkedListNaive(Node *head) {
   vector<int> arr;
   Node *curr = head;

   while (curr != NULL) {
      arr.push_back(curr->data);
      curr = curr->next;
   }
   curr = head;

   for (auto i = arr.end() - 1; i >= arr.begin(); i--) {
      curr->data = *i;
      curr       = curr->next;
   }

   arr.clear();
   return (head);
}

/**
 * @brief      Reverses a linked list in O(n) time comeplexity by using 1
 *             loop only and Q(1) space complexity.
 *
 * @param      head  The head
 *
 * @return     New head of the linked list
 */
Node* reverseLinkedList(Node *head) {
   Node *prev = NULL;
   Node *curr = head;
   Node *next = curr->next;

   while (curr != NULL) {
      curr->next = prev;
      prev       = curr;
      curr       = next;

      if (curr != NULL) {
         next = curr->next;
      }
   }

   return (prev);
}

/**
 * @brief      Reverses a linked list reccursivly using same methodology of
 *             iterative method. Time complexity is O(n) and space complexity is
 *             Q(1).
 *
 * @param      head  The head
 * @param      prev  The previous
 *
 * @return     New head of linked list
 */
Node* reverseLinkedListReccursive1(Node *head, Node *prev = NULL) {
   if (head == NULL) {
      return (prev);
   }
   Node *next = head->next;

   head->next = prev;
   prev       = head;
   head       = next;
   return (reverseLinkedListReccursive1(head, prev));
}

/**
 * @brief      Reverses a linked list reccursivly using custom implementation
 *             where we reverse last n - 1 node and then accordingly reverse  
 *             starting elements. It's time complexity is O(n) and space 
 *             complexity is Q(1).
 *
 * @param      head  The head
 * @param      prev  The previous
 *
 * @return     New head of linked list
 */
Node* reverseLinkedListReccursive2(Node *head) {
   if (head->next != NULL) {
      Node *prevHead = reverseLinkedListReccursive2(head->next);

      Node *prevTail = head->next;

      prevTail->next = head;
      head->next     = NULL;
      return (prevHead);
   }

   return head;
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      Node *head = initializeLL();
      head = reverseLinkedListReccursive2(head);
      printLL(head);
   }

   return (0);
}
