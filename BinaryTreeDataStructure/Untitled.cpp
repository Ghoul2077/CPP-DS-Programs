#include <limits.h>
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

   /**
    * @brief      Prints tree in inorder fashion. It's time complexity is O(n)
    *             and it's space complexity is O(h) as at any given time there
    *             will be at max N functions in the recurrsion call stack.
    *
    * @param      root  The root of the tree
    */
   void printInorder(Node *root = NULL) {
      if (root != NULL) {
         printInorder(root->left);
         cout << root->data << " ";
         printInorder(root->right);
      }
   }

   /**
    * @brief      Prints tree in postorder fashion. It's time complexity is O(n)
    *             and it's space complexity is O(h) as at any given time there
    *             will be at max N functions in the recurrsion call stack.
    *
    * @param      root  The root of the tree
    */
   void printPostorder(Node *root = NULL) {
      if (root != NULL) {
         printPostorder(root->left);
         printPostorder(root->right);
         cout << root->data << " ";
      }
   }

   /**
    * @brief      Prints tree in preorder fashion. It's time complexity is O(n)
    *             and it's space complexity is O(h) as at any given time there
    *             will be at max N functions in the recurrsion call stack.
    *
    * @param      root  The root of the tree
    */
   void printPreorder(Node *root = NULL) {
      if (root != NULL) {
         cout << root->data << " ";
         printPreorder(root->left);
         printPreorder(root->right);
      }
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
   }
   return (0);
}
