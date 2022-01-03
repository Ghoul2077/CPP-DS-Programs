#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

struct Node {
   int   data;
   Node *next;

   Node(int val) {
      data = val;
      next = NULL;
   }
};

/**
 * @brief      Prints the linked list in reccursive manner in O(n) time
 *             complexity and O(n) space complexity
 *
 * @param      currNode  The starting node of linked list
 */
void printLLReccursive(Node *currNode) {
   if (currNode == NULL) {
      return;
   } else {
      cout << currNode->data << " ";
      printLLReccursive(currNode->next);
   }
}

/**
 * @brief      Prints the linked list in reccursive manner in O(n) time
 *             complexity and Q(1) space complexity
 *
 * @param      currNode  The starting node of linked list
 */
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

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      Node *head = new Node(10);
      head->next             = new Node(20);
      head->next->next       = new Node(30);
      head->next->next->next = new Node(40);
      printLL(head);
      cout << endl;
   }

   return (0);
}
