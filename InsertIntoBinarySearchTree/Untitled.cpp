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

class BSTree {
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

   Node* insertInBSTReccursive(Node *root, int data) {
      if (root == NULL) {
         Node *newNode = new Node(data);
         return (newNode);
      }

      if (data < root->data) {
         root->left = insertInBSTReccursive(root->left, data);
      } else if (data > root->data) {
         root->right = insertInBSTReccursive(root->right, data);
      }

      return (root);
   }

   Node* insertInBSTIterative(Node *root, int data) {
      Node *newNode = new Node(data);
      Node *parent  = NULL;
      Node *curr    = root;

      while (curr != NULL) {
         parent = curr;

         if (curr->data < data) {
            curr = curr->right;
         } else if (curr->data > data) {
            curr = curr->left;
         } else {
            return (root);
         }
      }

      if (parent == NULL) {
         return (newNode);
      } else if (parent->data > data) {
         parent->left = newNode;
      } else {
         parent->right = newNode;
      }

      return (root);
   }

public:
   BSTree() {
      root = NULL;
   }

   BSTree(int data) {
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

   void printBST() {
      printInorder(root);
   }

   void insert(int data) {
      root = insertInBSTIterative(root, data);
   }
};

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      BSTree *t = new BSTree();
      t->initialize();
      t->printBST();
      cout << endl;
   }
   return (0);
}
