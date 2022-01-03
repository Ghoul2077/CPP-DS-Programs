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

   /**
    * @brief      Gets the maximum value of a tree. It's time complexity is O(n)
    *             and O(h) space complexity.
    *
    * @param      root  The root
    *
    * @return     The maximum value of tree if exist INT_MIN otherwise.
    */
   int getMax(Node *root) {
      if (root == NULL) {
         return (INT_MIN);
      }
      int largest = root->data;
      int max1    = getMax(root->left);
      int max2    = getMax(root->right);

      if (max1 > largest) {
         largest = max1;
      }

      if (max2 > largest) {
         largest = max2;
      }
      return (largest);
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
      return (getMax(root));
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
