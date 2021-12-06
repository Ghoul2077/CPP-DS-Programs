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

   void inorderPrint(Node *root) {
      if (root == NULL) {
         return;
      }
      inorderPrint(root->left);
      cout << root->data << " ";
      inorderPrint(root->right);
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

   void invertBinaryTree(Node *root) {
      if (root == NULL) {
         return;
      }
      Node *left = root->left;

      root->left  = root->right;
      root->right = left;
      invertBinaryTree(root->left);
      invertBinaryTree(root->right);
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
      inorderPrint(root);
      cout << endl;
   }

   void solve() {
      invertBinaryTree(root);
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
      t->solve();
      t->print();
      cout << endl;
   }
   return (0);
}
