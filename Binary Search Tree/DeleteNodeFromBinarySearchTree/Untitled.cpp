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

   void printInorder(Node *root) {
      if (root == NULL) {
         return;
      }
      printInorder(root->left);
      cout << root->data << " ";
      printInorder(root->right);
   }

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

   /**
    * @brief      Gets the successor of the given node. The idea behind this is
    *             to return the left most leaf node of the right subtree formed
    *             by the given root node.
    *             NOTE :- This is not a standalone way to get successor node and
    *             is only helpful for the delete functions as delete functions
    *             never calls this functions for it's edge cases such as leaf
    *             nodes.
    *
    * @param      root  The root node of the tree
    *
    * @return     The successor node.
    */
   Node* getSuccessor(Node *root) {
      Node *curr = curr->right;

      while (curr != NULL && curr->left != NULL) {
         curr = curr->left;
      }
      return (curr);
   }

   /**
    * @brief      Find and deletes the specified value from a given binary tree.
    *             It does this by handling 4 cases, first one is NULL where we
    *             return root as it is, second one is where current node value
    *             is less than to delete value in which case we go in reccursive
    *             call to the right subtree, third one is where current node
    *             value is greater than to delete value in which case we go in
    *             reccursive call to the left subtree, lastly when current node
    *             is the one we want to delete then we check if the tree formed
    *             by this node is skewed or not if it is then we just need to
    *             join the next left or right node to its parent otherwise if
    *             both left and right children are present we find the nearest
    *             successor of the current node in terms of value and replace
    *             it in the to be deleted node. From on here out we try to
    *             delete that nearest successor from the subtrees reccursivly.
    *             It's time complexity is O(h) and it's space complexity is O(h)
    *
    * @param      root   The root
    * @param[in]  value  The value
    *
    * @return     New root after deleting the node
    */
   Node* deleteNode(Node *root, int value) {
      if (root == NULL) {
         return (root);
      } else if (root->data < value) {
         root->right = deleteNode(root->right, value);
      } else if (root->data > value) {
         root->left = deleteNode(root->left, value);
      } else {
         if (root->left == NULL) {
            Node *temp = root->right;
            delete root;
            return (temp);
         } else if (root->right == NULL) {
            Node *temp = root->left;
            delete root;
            return (temp);
         } else {
            Node *successor = getSuccessor(root);
            root->data  = successor->data;
            root->right = deleteNode(root->right, successor->data);
         }
      }

      return (root);
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

   void print() {
      printInorder(root);
   }

   void solve(int val) {
      Node *newRoot = deleteNode(root, val);

      root = newRoot;
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
      t->print();
      cout << endl;
      t->solve(15);
      t->print();
      cout << endl;
   }
   return (0);
}
