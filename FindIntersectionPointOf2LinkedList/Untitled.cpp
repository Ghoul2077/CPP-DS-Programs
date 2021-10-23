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
 * @brief      Finds an intersection point of 2 linked list using hashing. It's
 *             time complexity is O(m + n) and space complexity is Q(m).
 *
 * @param      head1  The head of first linked list
 * @param      head2  The head of second linked list
 *
 * @return     Node where the linked lists intersect, NULL otherwise
 */
Node *findIntersectionPointOf2LinkedListNaive(Node *head1, Node *head2) {
   Node *curr1 = head1, *curr2 = head2;
   unordered_set<Node *> visitedNodes;

   while(curr1 != NULL) {
      visitedNodes.insert(curr1);
      curr1 = curr1->next;
   }

   while(curr2 != NULL) {
      if(visitedNodes.count(curr2) == 1) {
         return curr2;
      }
      curr2 = curr2->next;
   }

   cout << "No common node found" << endl;
   return NULL;
}

int getNodeCount(Node *head) {
   Node *curr = head;
   int count = 0;

   while(curr != NULL) {
      curr = curr->next;
      count++;
   }

   return count;
}

/**
 * @brief      Finds an intersection point of 2 linked list. It's time
 *             complexity is O(m + n) and space complexity is Q(1).
 *
 * @param      head1  The head of first linked list
 * @param      head2  The head of second linked list
 *
 * @return     Node where the linked lists intersect, NULL otherwise
 */
Node *findIntersectionPointOf2LinkedList(Node *head1, Node *head2) {
   int nodeCount1 = getNodeCount(head1);
   int nodeCount2 = getNodeCount(head2);
   int diff = abs(nodeCount2 - nodeCount1);

   Node *currOfBigger = NULL, *currOfSmaller = NULL;

   if(nodeCount1 > nodeCount2) {
      currOfBigger = head1;
      currOfSmaller = head2;
   } else {
      currOfBigger = head2;
      currOfSmaller = head1;
   }

   for(int i = 0; i < diff; i++) {
      currOfBigger = currOfBigger->next;
   }

   while(currOfBigger != NULL && currOfSmaller != NULL) {
      if(currOfBigger == currOfSmaller) {
         return currOfSmaller;
      }

      currOfBigger = currOfBigger->next;
      currOfSmaller = currOfSmaller->next;
   }

   cout << "No common node found" << endl;
   return NULL;
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      Node *head1 = new Node(1);
      head1->next = new Node(2);
      head1->next->next = new Node(3);

      Node *head2 = new Node(4);
      head2->next = new Node(5);
      head2->next->next = head1->next;

      Node *commonNode = findIntersectionPointOf2LinkedList(head1, head2);

      if(commonNode != NULL) {
         cout << commonNode->data;
      }
   }

   return (0);
}
