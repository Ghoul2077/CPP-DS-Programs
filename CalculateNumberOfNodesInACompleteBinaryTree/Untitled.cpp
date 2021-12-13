#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

struct Node {
   int   data;
   Node *left;
   Node *right;

   Node(int val) {
      data  = val;
      left  = NULL;
      right = NULL;
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
         root->left = push(root->left, data);
      } else {
         root->right = push(root->right, data);
      }

      return (root);
   }

   int countNodeOfBinaryTree(Node *root) {
      if (root == NULL) {
         return (0);
      }
      return (countNodeOfBinaryTree(root->left) +
              countNodeOfBinaryTree(root->right) + 1);
   }

   /**
    * @brief      Counts the number of node of a complete binary tree. A
    *             complete binary tree is one where all nodes of every level are
    *             present except the last level (containing leaf nodes) where
    *             the condition is that if it is partially filled it should be
    *             from left to right with no missing leafs in between. Below
    *             method uses naive approach + fact that our tree is a complete
    *             binary tree to get our answer. For a complete binary tree with
    *             all nodes present even the leaf one we can find the count of
    *             nodes by the formula 2 ^ h - 1 where we can get h by just
    *             traversing the slope of the tree. So breaking the tree from
    *             root to left and right we check if the height of left slope
    *             and right slope is equal for each subtree or not basis on
    *             which we use one out of 2 methods i.e naive or 2 ^ h - 1 to
    *             count the number of nodes effectivly giving us the opportunity
    *             to skip tedious task of going through each node of tree in
    *             some cases. It's time complexity is (logn * logn) and it's
    *             space complexity is O(n).
    *
    * @param      root  The root
    *
    * @return     Number of nodes in a complete binary tree.
    */
   int countNodeOfCompleteBinaryTree(Node *root) {
      Node *curr = root;
      int   leftSlopeCount = 0, rightSlopeCount = 0;

      while (curr != NULL) {
         curr = curr->left;
         leftSlopeCount++;
      }

      curr = root;

      while (curr != NULL) {
         curr = curr->right;
         rightSlopeCount++;
      }
      cout << leftSlopeCount << " : " << rightSlopeCount << endl;

      if (leftSlopeCount == rightSlopeCount) {
         return (pow(2, leftSlopeCount) - 1);
      }
      return (countNodeOfCompleteBinaryTree(root->left) +
              countNodeOfCompleteBinaryTree(root->right) + 1);
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

   int solve() {
      return (countNodeOfCompleteBinaryTree(root));
   }

   void insert(int data) {
      root = push(root, data);
   }
};

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      Tree *t = new Tree();
      t->initialize();
      cout << t->solve();
      cout << endl;
   }
   return (0);
}
