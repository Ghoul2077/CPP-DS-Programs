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
    * @brief      Given a binary tree we need to find the maximum difference
    *             between a node and any of it's ancestor. The idea is to use a
    *             modified method to find the minimum in a given binary tree and
    *             at every node we find (node value - minimum from its subtrees)
    *             and compare it to value we already have and accordingly update
    *             result if new difference is bigger. The main key is that for
    *             any node the max difference will always be difference between
    *             node and minimum from it's subtrees. The time complexity of
    *             this method is O(n) and it's time complexity is O(1).
    *
    * @param      root  The root of binary tree
    * @param      res   The max difference is stored here
    *
    * @return     Minimum value of the binary tree
    */
   int maxDiffBetween2NodesOneOfWhichIsAncestorOfOther(Node *root, int& res) {
      if (root == NULL) {
         return (INT_MAX);
      }

      if ((root->left == NULL) && (root->right == NULL)) {
         return (root->data);
      }

      int min1 = maxDiffBetween2NodesOneOfWhichIsAncestorOfOther(root->left,
                                                                 res);
      int min2 = maxDiffBetween2NodesOneOfWhichIsAncestorOfOther(root->right,
                                                                 res);
      int minVal = min(min1, min2);

      res = max(res, root->data - minVal);

      return (min(minVal, root->data));
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
      int res = INT_MIN;

      maxDiffBetween2NodesOneOfWhichIsAncestorOfOther(root, res);
      cout << res;
   }

   void insert(int data) {
      root = push(root, data);
   }
};

int main() {
   int testCases;

   srand(time(0));
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
