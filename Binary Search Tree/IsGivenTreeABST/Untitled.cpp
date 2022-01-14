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

int findMin(Node *root) {
   if (root == NULL) {
      return (INT_MAX);
   }
   int minLeft  = findMin(root->left);
   int minRight = findMin(root->right);

   return (min(min(minLeft, minRight), root->data));
}

int findMax(Node *root) {
   if (root == NULL) {
      return (INT_MIN);
   }
   int maxLeft  = findMax(root->left);
   int maxRight = findMax(root->right);

   return (max(max(maxLeft, maxRight), root->data));
}

/**
 * @brief      Determines whether the given binary tree is a binary search tree.
 *             The idea behind this method is to check if left of each node is
 *             smaller than the nodes and it's right is bigger than itself, but
 *             stopping there does not suffice as 2nd child or further are not
 *             checked which may be violating binary search tree property. To
 *             make sure that the right and left trees are not violating BST
 *             property we find the max value in the left subtree and min value
 *             of right subtree and compare with the current node value, if left
 *             max value is more than node value then condition is violating, if
 *             right min is less than node value then also condition violates.
 *             The time complexity of this method is O(n^2) and it's space
 *             complexity is O(h).
 *
 *
 * @param      root  The root of the binary tree
 *
 * @return     True if given tree is a BST, False otherwise.
 */
bool isBinarySearchTreeNaive(Node *root) {
   if (root == NULL) {
      return (true);
   }

   if ((root->left != NULL) && (root->left->data >= root->data)) {
      return (false);
   }

   if ((root->right != NULL) && (root->right->data <= root->data)) {
      return (false);
   }

   int leftSubtreeMax  = findMax(root->left);
   int rightSubtreeMin = findMin(root->right);

   if ((leftSubtreeMax > root->data) || (rightSubtreeMin < root->data)) {
      return (false);
   }

   return (isBinarySearchTreeNaive(root->left) &&
           isBinarySearchTreeNaive(root->right));
}

/**
 * @brief      Determines whether the given binary tree is a binary search tree.
 *             This a very tricky yet simple solution where the idea is to
 *             maintain an upperbound and lowerbound for the range where the
 *             values of subtree can lie, based on whether you traverse the left
 *             subtree or whether you traverse the right subtree we update the
 *             upperbound and lowerbound respectively and at every node check if
 *             the value of node is lying between the range if not we return
 *             false. It's time complexity is O(n) and it's space complexity is
 *             O(h).
 *
 * @param      root        The root of the binary tree
 * @param[in]  upperBound  The upper bound
 * @param[in]  lowerBound  The lower bound
 *
 * @return     True if given tree is a BST, False otherwise.
 */
bool isBinarySearchTree(Node *root,
                        int   upperBound = INT_MAX,
                        int   lowerBound = INT_MIN) {
   if (root == NULL) {
      return (true);
   }

   if ((root->data >= upperBound) || (root->data <= lowerBound)) {
      return (false);
   }
   return (isBinarySearchTree(root->left, root->data,
                              lowerBound) &&
           isBinarySearchTree(root->right, upperBound, root->data));
}

/**
 * @brief      Determines whether the given binary tree is a binary search tree.
 *             This is another efficient method to know whether a given tree is
 *             binary search tree or not. The idea is to use inorder traversal
 *             of the tree. Binary search tree have a unique property that their
 *             inorder traversal is always in ascending order so by using this
 *             fact we maintain a previous node pointer and keep checking if
 *             current node is greater than previous one all the while doing
 *             inorder traversal. It's time complexity is O(n) and it's space
 *             complexity is O(h).
 *
 * @param      root  The root of the binary tree
 *
 * @return     True if given tree is a BST, False otherwise.
 */
bool isBinarySearchTree2(Node *root) {
   static Node *prev = NULL;

   if (root == NULL) {
      return (true);
   }
   bool isLeftSubtreeBST = isBinarySearchTree2(root->left);

   if ((prev != NULL) && (prev->data >= root->data)) {
      return (false);
   }
   prev = root;
   bool isRightSubtreeBST = isBinarySearchTree2(root->right);

   return (isLeftSubtreeBST && isRightSubtreeBST);
}

int main() {
   int testCases;

   srand(time(0));
   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      Node *root = new Node(10);
      root->left        = new Node(5);
      root->left->right = new Node(9);
      root->right       = new Node(40);
      cout << (isBinarySearchTree2(root) ? "Binary tree" : "Not a binary tree");
      cout << endl;
   }
   return (0);
}
