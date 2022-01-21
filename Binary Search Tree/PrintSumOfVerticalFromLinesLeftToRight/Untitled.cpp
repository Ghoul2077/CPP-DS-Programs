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
    * @brief      Prints a sum of vertical aligned nodes from left to right. The
    *             idea is to use a level variable which starts from 0 and
    *             decrements when we travel to left and increments when we
    *             travel to the right, nodes with same level value lie on the
    *             same vertical line. And to store sum we use a map as it can
    *             give us the output in sorted order with just log(n) insert
    *             complexity. The order of traversal does not matter here i.e
    *             you can use any inorder, postorder or preorder traversal. It's
    *             time complexity is O(nlog(hv)) and it's space complexity is
    *             O(h)
    *
    * @param      root       The root of binary tree
    * @param      m          The map to store sum of each vertical line
    * @param[in]  currLevel  The curr level
    */
   void printSumOfVerticalLinesLeftToRight(Node          *root,
                                           map<int, int>& m,
                                           int            currLevel = 0) {
      if (root == NULL) {
         return;
      }
      m[currLevel] += root->data;
      printSumOfVerticalLinesLeftToRight(root->left,  m, currLevel - 1);
      printSumOfVerticalLinesLeftToRight(root->right, m, currLevel + 1);
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
      map<int, int> m;

      printSumOfVerticalLinesLeftToRight(root, m);

      for (auto i: m) {
         cout << i.second << " ";
      }
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
