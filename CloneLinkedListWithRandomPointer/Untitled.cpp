#include <bits/stdc++.h>
using namespace std;

struct Node {
   int   data;
   Node *next, *random;

   Node(int val) {
      data   = val;
      next   = NULL;
      random = NULL;
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

int getLengthOfLinkedList(Node *head) {
   Node *curr  = head;
   int   count = 0;

   while (curr != NULL) {
      curr = curr->next;
      count++;
   }

   return (count);
}

bool areLinkedListEqual(Node *head1, Node *head2) {
   if ((head1 == NULL) && (head2 == NULL)) {
      return (true);
   } else if ((head1 == NULL) || (head2 == NULL)) {
      return (false);
   }

   if (head1->data == head2->data) {
      Node *curr1 = head1->random, *curr2 = head2->random;

      while (curr1 != NULL && curr2 != NULL) {
         if (curr1->data != curr2->data) {
            return (false);
         }
         curr1 = curr1->next;
         curr2 = curr2->next;
      }

      if ((curr1 == NULL) && (curr2 == NULL)) {
         return (areLinkedListEqual(head1->next, head2->next));
      } else {
         return (false);
      }
   }

   return (false);
}

void insertRandomisedPointer(Node *head) {
   Node *curr  = head;
   int   count = getLengthOfLinkedList(head);

   while (curr != NULL) {
      int   randNum     = rand() % count;
      Node *destination = head;

      for (int i = 0; i < randNum; i++) {
         destination = destination->next;
      }

      curr->random = destination;
      curr         = curr->next;
   }
}

/**
 * @brief      Clones a linked list in which each node contains a special random
 *             pointer. It's time complexity is O(n) and it's space complexity
 *             is Q(n) as this uses hashing.
 *
 * @param      head  The head of linked list to clone
 *
 * @return     Head of new cloned linked list
 */
Node* cloneLinkedListNaive(Node *head) {
   if (head == NULL) {
      return (head);
   }

   unordered_map<Node *, Node *> nodeToNodeMap;

   for (Node *curr = head; curr != NULL; curr = curr->next) {
      nodeToNodeMap[curr] = new Node(curr->data);
   }

   for (Node *curr = head; curr != NULL; curr = curr->next) {
      Node *cloneCurr = nodeToNodeMap[curr];
      cloneCurr->next   = nodeToNodeMap[curr->next];
      cloneCurr->random = nodeToNodeMap[curr->random];
   }

   return (nodeToNodeMap[head]);
}

/**
 * @brief      Clones a linked list in which each node contains a special random
 *             pointer. It's time complexity is O(n) and it's space complexity
 *             is Q(1). This solution modifies the original linked list and
 *             adds copy of each node next to it, after which we traverse this
 *             new linked list setting the random pointers and next pointers
 *             accordingly.
 *
 * @param      head  The head of linked list to clone
 *
 * @return     Head of new cloned linked list
 */
Node* cloneLinkedList(Node *head) {
   if (head == NULL) {
      return (head);
   }

   for (Node *curr = head; curr != NULL;) {
      Node *temp = curr->next;
      curr->next       = new Node(curr->data);
      curr->next->next = temp;
      curr             = temp;
   }

   Node *newHead = head->next;

   for (Node *curr = head; curr != NULL; curr = curr->next->next) {
      curr->next->random = curr->random == NULL ? NULL : curr->random->next;
   }

   for (Node *curr = head; curr != NULL; curr = curr->next) {
      Node *temp = curr->next;
      curr->next = curr->next->next;

      if (temp->next != NULL) {
         temp->next = temp->next->next;
      } else {
         temp->next = NULL;
      }
   }

   return (newHead);
}

int main() {
   srand(time(0));
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      Node *head = initializeLL();
      insertRandomisedPointer(head);
      Node *newHead = cloneLinkedList(head);
      cout << (areLinkedListEqual(head, newHead) ? "Equal" : "Not Equal");
   }

   return (0);
}
