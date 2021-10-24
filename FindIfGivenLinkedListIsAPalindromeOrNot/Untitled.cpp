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

Node *findMiddleOfLinkedList(Node *head) {
   if(head == NULL) {
      return head;
   }

   Node *slowPtr = head, *fastPtr = head;

   while(fastPtr->next != NULL && fastPtr->next->next != NULL) {
      fastPtr = fastPtr->next->next;
      slowPtr = slowPtr->next;
   }

   return slowPtr;
}

Node *reverseLL(Node *head) {
   if(head == NULL) {
      return head;
   }

   Node *curr = head, *prev = NULL, *next = curr->next;

   while(curr != NULL) {
      Node *temp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = temp;
      if(curr != NULL) {
         next = curr->next;
      }
   }

   return prev;
}

/**
 * @brief      Determines whether the specified linked list is palindrome or not
 *             using stack in O(n) time complexity and Q(n) space complexity.
 *
 * @param      head  The head of linked list
 *
 * @return     True if the specified linked list is palindrome, False otherwise.
 */
bool isLLPalindromeNaive(Node *head) {
   stack<int> linkedListData;

   for(Node *curr = head; curr != NULL; curr = curr->next) {
      linkedListData.push(curr->data);
   }

   for(Node *curr = head; curr != NULL; curr = curr->next) {
      if(curr->data != linkedListData.top()) {
         cout << "Not palindrome" << endl;
         return false;
      }
      linkedListData.pop();
   }

   cout << "Is palindrome" << endl;
   return true;
}

/**
 * @brief      Determines whether the specified linked list is palindrome or not
 *             by finding middle of the linked list and reversing the nodes
 *             after the middle. It's time complexity is O(n) and it's space
 *             complexity is Q(1).
 *
 * @param      head  The head of linked list
 *
 * @return     True if the specified linked list is palindrome, False otherwise.
 */
bool isLLPalindrome(Node *head) {
   Node *middlePtr = findMiddleOfLinkedList(head);
   Node *newMiddlePtr = reverseLL(middlePtr);
   Node *curr = head;

   while(curr != middlePtr && newMiddlePtr != NULL) {
      if(curr->data != newMiddlePtr->data) {
         cout << "Not palindrome";
         return false;
      }
      curr = curr->next;
      newMiddlePtr = newMiddlePtr->next;
   }

   cout << "Is palindrome";
   return true;
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      Node *head = initializeLL();
      isLLPalindrome(head);
   }

   return (0);
}
