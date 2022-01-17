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

Node* getSecondLastNode(Node *head) {
   if (head == NULL) {
      return (NULL);
   }
   Node *curr = head;

   while (curr != NULL && curr->next != NULL && curr->next->next != NULL) {
      curr = curr->next;
   }

   if (curr->next == NULL) {
      return (NULL);
   }
   return (curr);
}

Node* getMiddleNode(Node *head) {
   Node *slow = head, *fast = head;

   while (fast != NULL && fast->next != NULL) {
      slow = slow->next;
      fast = fast->next->next;
   }
   return (slow);
}

Node* reverseLL(Node *head) {
   if (head == NULL) {
      return (NULL);
   }
   Node *curr = head, *prev = NULL, *next = curr->next;

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
 * @brief      This program inserts half of the nodes from the end in between
 *             the first half of a given linked list. This is a naive approach
 *             where we iterate through every node and at every iteration find
 *             the second last node starting from that node and using this
 *             second last node we detach the last node and modify its next to
 *             point to the curr node that is being iterated. We also maintain a
 *             prev node to correct the next pointer of previous nodes to new
 *             inserted nodes. It's time complexity is O(n^2) and it's space
 *             complexity is O(1).
 *
 * @param      head  The head of linked list
 *
 * @return     New head of the linked list
 */
Node* insertLastHalfOfLinkedListIntoTheFirstHalfNaive(Node *head) {
   if (head == NULL) {
      return (NULL);
   }
   Node *curr = head;
   Node *prev = NULL;

   while (true) {
      Node *secondLastNode = getSecondLastNode(curr);

      if (secondLastNode == NULL) {
         break;
      }
      Node *lastNode = secondLastNode->next;
      secondLastNode->next = NULL;
      lastNode->next       = curr;

      if (prev != NULL) {
         prev->next = lastNode;
      } else {
         head = lastNode;
      }
      prev = curr;
      curr = curr->next;
   }

   return (head);
}

/**
 * @brief      This program inserts half of the nodes from the end in between
 *             the first half of a given linked list. The idea behind this
 *             approach is to find the middle node using hare and tortoise
 *             method and reverse the linked list starting from this middle node
 *             to the last node. Now treat the newly reversed linked list as a
 *             seperate one and iterate through both normal and reversed linked
 *             list pointing the nodes of reversed linked list to the current
 *             one of the normal linked list. The time complexity of this
 *             method is O(n) and it's space complexity is O(1).
 *
 * @param      head  The head of linked list
 *
 * @return     New head of the linked list
 */
Node* insertLastHalfOfLinkedListIntoTheFirstHalf(Node *head) {
   Node *middleNode = getMiddleNode(head);
   Node *curr       = head;

   while (curr != middleNode) {
      curr = curr->next;
   }

   Node *secondHalfReverseHead = reverseLL(curr);
   Node *secondHalfReverseCurr = secondHalfReverseHead;
   Node *firstHalfCurr         = head;
   Node *firstHalfPrev         = NULL;

   while (firstHalfCurr != secondHalfReverseHead &&
          secondHalfReverseCurr != NULL) {
      Node *temp = secondHalfReverseCurr->next;
      secondHalfReverseCurr->next = firstHalfCurr;

      if (firstHalfPrev != NULL) {
         firstHalfPrev->next = secondHalfReverseCurr;
      }
      firstHalfPrev         = firstHalfCurr;
      firstHalfCurr         = firstHalfCurr->next;
      secondHalfReverseCurr = temp;
   }

   firstHalfPrev->next = NULL;

   return (secondHalfReverseHead);
}

int main() {
   int testCases;

   srand(time(0));
   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      Node *head    = initializeLL();
      Node *newHead = insertLastHalfOfLinkedListIntoTheFirstHalf(head);
      printLL(newHead);
   }

   return (0);
}
