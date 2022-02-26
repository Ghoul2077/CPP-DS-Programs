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
    * @brief      Finds if the binary tree follows child sum property i.e is
    *             every parent is sum of it's child nodes. It's time complexity
    *             is O(n) and it's space complexity is O(h).
    *
    * @param      root  The root
    *
    * @return     True if follows child sum property, False otherwise.
    */
   bool followsChildSumProperty(Node *root) {
      if ((root == NULL) || (root->left == NULL) && (root->right == NULL)) {
         return (true);
      }
      int currSum = 0;

      if (root->left) {
         currSum += root->left->data;
      }

      if (root->right) {
         currSum += root->right->data;
      }

      if (root->data == currSum) {
         return (followsChildSumProperty(root->left) &&
                 followsChildSumProperty(root->right));
      }
      return (false);
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

   void solve() {
      if (followsChildSumProperty(root)) {
         cout << "True";
      } else {
         cout << "False";
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
      Tree *t = new Tree();
      t->initialize();
      t->solve();
      cout << endl;
   }
   return (0);
}
