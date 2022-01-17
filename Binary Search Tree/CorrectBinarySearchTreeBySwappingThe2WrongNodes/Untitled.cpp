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

void printInorder(Node *root) {
   if (root == NULL) {
      return;
   }
   printInorder(root->left);
   cout << root->data << " ";
   printInorder(root->right);
}

/**
 * @brief      Finds the 2 swapped nodes of a binary tree. This method uses the
 *             method from "Finding if a tree is a BST" where we go through
 *             inorder traversal finding every pair of node that are wrong and
 *             everytime we find such pair we update the first wrong node and
 *             keeping it fix we keep updating the second wrong node as the
 *             second node of every succeeding pair we find. This method is a
 *             bit tricky but is efficient. It's time complexity is O(n) and
 *             it's space complexity is O(h).
 *
 * @param      root        The root of the binary tree
 * @param      wrongNode1  The wrong node 1
 * @param      wrongNode2  The wrong node 2
 */
void find2SwappedNodesOfABinaryTree(Node  *root,
                                    Node **wrongNode1,
                                    Node **wrongNode2) {
   static Node *prev = NULL;

   if (root == NULL) {
      return;
   }
   find2SwappedNodesOfABinaryTree(root->left, wrongNode1, wrongNode2);

   if ((prev != NULL) && (prev->data >= root->data)) {
      if (*wrongNode1 == NULL) {
         *wrongNode1 = prev;
      }
      *wrongNode2 = root;
   }

   prev = root;
   find2SwappedNodesOfABinaryTree(root->right, wrongNode1,
                                  wrongNode2);
}

int main() {
   int testCases;

   srand(time(0));
   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      Node *root = new Node(20);
      root->left         = new Node(60);
      root->left->right  = new Node(10);
      root->left->left   = new Node(4);
      root->right        = new Node(80);
      root->right->right = new Node(100);
      root->right->left  = new Node(8);
      cout << "Before swapping" << " : ";
      printInorder(root);
      cout << endl;

      Node *wrongNode1 = NULL, *wrongNode2 = NULL;
      find2SwappedNodesOfABinaryTree(root, &wrongNode1, &wrongNode2);

      swap(wrongNode1->data, wrongNode2->data);
      cout << "After swapping" << "  : ";
      printInorder(root);
      cout << endl;
   }
   return (0);
}
