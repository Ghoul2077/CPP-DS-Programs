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

/**
 * @brief      This class describes an AVL tree. This is a self balancing tree
 *             which balances itself whenever we perform any sort of operation
 *             on it which may distrub it's balance. It's speciality is that
 *             it always maintains a height of log(n) where n is the number of
 *             nodes making most of the operation whose time complexity is
 *             dependent on height very efficient.
 */
class AVLTree {
private:
   Node *root;

   void prettyPrint(string prefix, Node *root, bool isLeft) {
      if (root != nullptr) {
         cout << prefix;
         cout << (isLeft ? "├──" : "└──");
         cout << root->data << endl;
         prettyPrint(prefix + (isLeft ? "│   " : "    "), root->left,  true);
         prettyPrint(prefix + (isLeft ? "│   " : "    "), root->right, false);
      }
   }

   int getHeight(Node *root) {
      if (root == NULL) {
         return (0);
      }
      return (max(getHeight(root->left), getHeight(root->right)) + 1);
   }

   int getBalanceFactor(Node *root) {
      if (root == NULL) {
         return (0);
      }
      int leftHeight  = getHeight(root->left);
      int rightHeight = getHeight(root->right);

      return (rightHeight - leftHeight);
   }

   Node* leftRotate(Node *root) {
      if ((root == NULL) || (root->right == NULL)) {
         return (root);
      }
      Node *newRoot = root->right;
      Node *temp    = newRoot->left;

      newRoot->left = root;
      root->right   = temp;

      return (newRoot);
   }

   Node* rightRotate(Node *root) {
      if ((root == NULL) || (root->left == NULL)) {
         return (root);
      }
      Node *newRoot = root->left;
      Node *temp    = newRoot->right;

      newRoot->right = root;
      root->left     = temp;
      return (newRoot);
   }

   /**
    * @brief      This function is used to insert element in the AVL tree and it
    *             is also responsible for balancing the binary search tree after
    *             insertion of the node. Due to it's bottom up nature we are
    *             able to do both insertion as well as balancing in a single
    *             function itself. After insertion of node, this function checks
    *             for the balance factor of each parent node in the way starting
    *             from newly inserted node to the root node and at the first
    *             node it detects imbalance it performs one out of the four
    *             rotations to correct the balance, namely "left left", "right
    *             right", "left right", "right left". Out of which the latter 2
    *             are double rotations. Time complexity of below implementation
    *             is O(h^2) because of calculation of balance factor on every
    *             level. This method can be further optimised by changing the
    *             node class to contain height variable too which will make
    *             calculation of balance factor O(1) and making AVL tree insert
    *             time complexity same as binary tree insertion.
    *
    * @param      root  The root of the binary search tree
    * @param[in]  data  The data to be inserted
    *
    * @return     New root of the tree
    */
   Node* push(Node *root, int data) {
      static bool hasBeenBalanced = false;

      if (root == NULL) {
         Node *newNode = new Node(data);
         return (newNode);
      }

      if (data < root->data) {
         root->left = push(root->left, data);
      } else if (data > root->data) {
         root->right = push(root->right, data);
      }

      int balanceFactor = getBalanceFactor(root);

      // Left Left case
      if ((balanceFactor < -1) && (root->left != NULL) &&
          (data < root->left->data)) {
         root = rightRotate(root);
      }

      // Right Right case
      if ((balanceFactor > 1) && (root->right != NULL) &&
          (data > root->right->data)) {
         root = leftRotate(root);
      }

      // Left Right case
      if ((balanceFactor < -1) && (root->left != NULL) &&
          (data > root->left->data)) {
         root->left = leftRotate(root->left);
         root       = rightRotate(root);
      }

      // Right Left Case
      if ((balanceFactor > 1) && (root->right != NULL) &&
          (data < root->right->data)) {
         root->right = rightRotate(root->right);
         root        = leftRotate(root);
      }

      return (root);
   }

public:
   AVLTree() {
      root = NULL;
   }

   AVLTree(int data) {
      root = new Node(data);
   }

   void print() {
      prettyPrint("", root, false);
   }

   void initialize() {
      int val;

      cin >> val;

      while (val != -1) {
         insert(val);
         cin >> val;
      }
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
      AVLTree *t = new AVLTree();
      t->initialize();
      t->print();
      cout << endl;
   }
   return (0);
}
