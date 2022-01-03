#include <bits/stdc++.h>
using namespace std;

struct Node {
   int   data;
   Node *next;
   bool  isVisited;

   Node(int val) {
      data      = val;
      next      = NULL;
      isVisited = false;
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
 * @brief      Finds if a linked list contains loop in O(n^2) time complexity
 *             and Q(1) space complexity.
 *
 * @param      head  The head
 *
 * @return     True if loop exists, false otherwise
 */
bool containsLoopNaive(Node *head) {
   Node *currHead  = head;
   bool  loopFound = false;

   while (currHead != NULL) {
      Node *curr = currHead->next;

      while (curr != NULL && curr->next != currHead) {
         curr = curr->next;
      }

      if (curr != NULL) {
         cout << "Loop Found" << endl;
         loopFound = true;
         break;
      }
      currHead = currHead->next;
   }

   return (loopFound);
}

/**
 * @brief      Finds if a linked list contains loop in O(n) time complexity
 *             and Q(1) space complexity. But this approach requires one to
 *             modify the structure of linked list and add a property isVisited
 *             so this approach might less desirable.
 *
 * @param      head  The head
 *
 * @return     True if loop exists, false otherwise
 */
bool containsLoop(Node *head) {
   Node *curr      = head;
   bool  loopFound = false;

   while (curr != NULL) {
      if (!curr->isVisited) {
         curr->isVisited = true;
         curr            = curr->next;
      } else {
         cout << "Loop found" << endl;
         loopFound = true;
         break;
      }
   }

   return (loopFound);
}

/**
 * @brief      Determines if the linked list contains loop in O(n) time
 *             complexity and Q(1) space complexity. This is better solution
 *             than previous one as it only modifies the linked list rather than
 *             its structre.
 *
 * @param      head  The head
 *
 * @return     True if linked list contains loop, false otherwise.
 */
bool containsLoopOptimized(Node *head) {
   Node *curr      = head;
   Node *tempNode  = new Node(0);
   bool  loopFound = false;

   while (curr != NULL) {
      if (curr->next != tempNode) {
         Node *next = curr->next;
         curr->next = tempNode;
         curr       = next;
      } else {
         cout << "Loop found" << endl;
         loopFound = true;
         break;
      }
   }

   return (loopFound);
}

/**
 * @brief      Finds if a given linked list contains a loop / cycle in O(n) time
 *             complexity and Q(n) space complexity. This is the best solution
 *             as it makes use of hashmap and does not modify linked list or its
 *             structure in anyway.
 *
 * @param      head  The head
 *
 * @return     True if loop is found, false otherwise
 */
bool containsLoopEfficient(Node *head) {
   unordered_set<Node *> visitedNodes;
   Node *curr      = head;
   bool  loopFound = false;

   while (curr != NULL) {
      if (visitedNodes.count(curr) == 0) {
         visitedNodes.insert(curr);
         curr = curr->next;
      } else {
         cout << "Loop found" << endl;
         loopFound = true;
         break;
      }
   }

   return (loopFound);
}

/**
 * @brief      Finds if a given linked list contains loop in O(n) time
 *             complexity and Q(1) space complexity. This is the only solution
 *             that has the best time and space complexity and does not modify
 *             linked list in anyway.
 *
 * @param      head  The head
 *
 * @return     True if loop is found, false otherwise
 */
bool floydeWarshallLoopDetection(Node *head) {
   Node *slowPtr = head, *fastPtr = head;

   while (fastPtr != NULL && fastPtr->next != NULL) {
      slowPtr = slowPtr->next;
      fastPtr = fastPtr->next->next;

      if (slowPtr == fastPtr) {
         break;
      }
   }

   if (slowPtr == fastPtr) {
      cout << "Loop found" << endl;
      return (true);
   }

   return (false);
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      Node *head = initializeLL();
      floydeWarshallLoopDetection(head);
      printLL(head);
   }

   return (0);
}
