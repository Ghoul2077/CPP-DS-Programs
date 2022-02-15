#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;
#define deb(x) cout << # x << " = " << x << endl;
#define deb2(x, \
             y) cout << # x << " = " << x << ", " << # y << " = " << y << endl;
#define printArr(arr, size) cout << # arr << " : "; \
   for (int i = 0; i < size; i++) cout << arr[i] << " "; cout << endl;


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

int getLengthOfLL(Node *head) {
   int   len  = 0;
   Node *curr = head;

   while (curr != NULL) {
      curr = curr->next;
      len++;
   }
   return (len);
}

/**
 * @brief      Function to extract kth node and by extract we mean get kth node
 *             while also setting the next of (k+1)th node to NULL. The idea is
 *             to put of the nodes of a linked list in stack and then pop k+1
 *             times to get the (k+1)th node from the back. Then we set the next
 *             of this to NULL and return (k+1)th next pointer. It's time
 *             complexity is O(n) and it's space complexity is O(n).
 *
 * @param      head  The head of the linked list
 * @param[in]  k     Index of the node to find
 *
 * @return     Kth node if present, NULL otherwise
 */
Node* extractKthNodeFromEnd(Node *head, int k) {
   if (head == NULL) {
      return (NULL);
   }

   stack<Node *> st;
   Node *curr = head;

   while (curr != NULL) {
      st.push(curr);
      curr = curr->next;
   }
   int count = 0;

   while (count != k && !st.empty()) {
      st.pop();
      count++;
   }

   if (st.empty()) {
      return (NULL);
   }
   Node *res = (st.top())->next;

   (st.top())->next = NULL;
   return (res);
}

/**
 * @brief      Given a linked list and 2 values n and k we need to move the last
 *             k items to the nth place. The idea is to extract the kth node and
 *             by extract here we mean to get the kth node and set (k - 1)th
 *             nodes next to null. After extracting kth node as such we traverse
 *             to (n - 1)th node and make (n - 1)th nodes next as kth node and
 *             point the next of last element of the kth node trail to (n - 1)th
 *             next's next. It's time complexity is O(n) and it's space
 *             complexity is O(n).
 *
 * @param      head  The head of the linked list
 * @param[in]  n     New position last k elements are to be placed at
 * @param[in]  k     Number of element from last item to move to nth place
 *
 * @return     New head of the linked list
 */
Node* moveLastKNodesToNThPlace(Node *head, int n, int k) {
   if (head == NULL) {
      return (NULL);
   }

   Node *curr     = head;
   Node *kthNode  = extractKthNodeFromEnd(head, k);
   Node *lastNode = kthNode;

   while (lastNode->next != NULL) {
      lastNode = lastNode->next;
   }

   if (n == 0) {
      lastNode->next = head;
      return (kthNode);
   }

   for (int i = 0; i < n - 1 && curr != NULL; i++) {
      curr = curr->next;
   }
   Node *temp = curr->next;

   curr->next     = kthNode;
   lastNode->next = temp;
   return (head);
}

/**
 * @brief      Given a linked list and 2 values n and k we need to move the last
 *             k items to the nth place. The idea is the same as the previous
 *             one but the only optimization we made is that we calculate the
 *             length of the linked list to find the kth element instead of
 *             using a stack hence we are able to reduce the space complexity
 *             to O(1).
 *
 * @param      head  The head of the linked list
 * @param[in]  n     New position last k elements are to be placed at
 * @param[in]  k     Number of element from last item to move to nth place
 *
 * @return     New head of the linked list
 */
Node* moveLastKNodesToNThPlaceOptimized(Node *head, int n, int k) {
   if (head == NULL) {
      return (NULL);
   }
   int   len           = getLengthOfLL(head);
   Node *curr          = head;
   Node *kthNode       = NULL;
   Node *lastNode      = NULL;
   Node *nthNodeParent = NULL;

   for (int i = 0; i < len; i++) {
      if (i == len - k - 1) {
         kthNode    = curr->next;
         curr->next = NULL;
         curr       = kthNode;
         continue;
      }

      if (i == n - 1) {
         nthNodeParent = curr;
      }

      if (i == len - 1) {
         lastNode = curr;
      }
      curr = curr->next;
   }

   if (n == 0) {
      lastNode->next = head;
      return (kthNode);
   }
   Node *nthNode = nthNodeParent->next;

   nthNodeParent->next = kthNode;
   lastNode->next      = nthNode;
   return (head);
}

int main() {
   int testCases;

   srand(time(0));
   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      int n, k;
      cin >> n;
      cin >> k;
      Node *head    = initializeLL();
      Node *newHead = moveLastKNodesToNThPlaceOptimized(head, n, k);
      printLL(newHead);
      cout << endl;
   }

   return (0);
}
