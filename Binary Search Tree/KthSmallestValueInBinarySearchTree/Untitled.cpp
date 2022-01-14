#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

struct Node {
   int   data;
   Node *left;
   Node *right;
   int   leftNodeCount;

   Node(int val) {
      data          = val;
      left          = NULL;
      right         = NULL;
      leftNodeCount = 0;
   }
};

class Tree {
private:
   Node *root;

   Node* push(Node *root, int data) {
      if (root == NULL) {
         Node *newNode = new Node(data);
         return (newNode);
      }

      if (data < root->data) {
         root->left           = push(root->left, data);
         root->leftNodeCount += 1;
      } else if (data > root->data) {
         root->right = push(root->right, data);
      }

      return (root);
   }

   /**
    * @brief      Finds a kth smallest in a given binary tree. This method is
    *             reccursive one which works by continuously traversing to the
    *             leftmost node and from there we starting traversing back up
    *             and keep count of nodes we passed until we pass k nodes at
    *             which we stop and return the value present in the node we
    *             stop at. It's time complexity is O(h + k) as first we traverse
    *             to the leftmost node which will be at most (h) and after that
    *             we travel up k nodes to get to the final node.
    *
    *             Note :- For this method assume node struct has no
    *                     "leftNodeCount" value as that is used for the
    *                     optimized solution.
    *
    * @param      root  The root
    * @param[in]  k     Order of smallest value to find
    */
   void findKthSmallestNaive(Node *root, int k) {
      static int count = 0;

      if (root != NULL) {
         findKthSmallestNaive(root->left, k);
         count++;

         if (count == k) {
            cout << root->data;
            return;
         }
         findKthSmallestNaive(root->right, k);
      }
   }

   /**
    * @brief      Finds a kth smallest in a given binary tree. This method makes
    *             use of "Augmented Search Tree". This is nothing but a binary
    *             search tree with additional properties in the Node structure
    *             which makes our solution easier in one way or another. Like in
    *             this case we store the number of left nodes of each node in a
    *             property called "leftNodeCount". This optimization makes the
    *             time complexity of finding kth element O(h).
    *
    * @param      root  The root
    * @param[in]  k     Order of smallest value to find
    */
   void findKthSmallest(Node *root, int k) {
      if (root->leftNodeCount == k - 1) {
         cout << root->data;
      } else if (root->leftNodeCount < k - 1) {
         findKthSmallest(root->right, k - root->leftNodeCount - 1);
      } else {
         findKthSmallest(root->left, k);
      }
   }

public:
   Tree() {
      root = NULL;
   }

   Tree(int data) {
      root = new Node(data);
   }

   void initialize() {
      int val;

      cin >> val;

      while (val != -1) {
         insert(val);
         cin >> val;
      }
   }

   void solve(int k) {
      findKthSmallest(root, k);
   }

   void insert(int data) {
      root = push(root, data);
   }
};

int main() {
   int testCases;

   srand(time(0));
   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      int k;
      cin >> k;
      Tree *t = new Tree();
      t->initialize();
      t->solve(k);
      cout << endl;
   }
   return (0);
}
