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
         root->right = push(root->right,
                            data);
      }

      return (root);
   }

   /**
    * @brief      Finds the time taken to burn a tree given a leaf node. The
    *             meaning of burning a tree is we burn a node then in next turn
    *             we burn all the node connected to that node simulatneously and
    *             so on until all nodes are burnt. The idea to solve this
    *             problem is that by hit and trial we can see that the answer is
    *             always equal to the (longest diameter - 1) starting from the
    *             leaf node node provided in the question. So how we go about
    *             coding this is that we write a function which calculates
    *             height of binary tree and we keep calling this function
    *             for each node. On side we also keep track of distance in a
    *             variable for every reccursive call based on which we keep
    *             keep tracking time in a global variable ( or a reference
    *             variable ). It's time complexity is O(n) and it's space
    *             complexity is O(n)
    *
    * @param      root      The root of the tree
    * @param      leafNode  A leaf node of the tree
    * @param      dist      The distance of a node from the leaf node
    * @param      time      The time taken to burn the tree
    *
    * @return     Height of tree
    */
   int timeTakenToBurnTheTree(Node *root, Node *leafNode, int& dist,
                              int& time) {
      if (root == NULL) {
         return (0);
      }

      if (root == leafNode) {
         dist = 0;
         return (1);
      }

      int leftDist = -1, rightDist = -1;
      int leftHeight = timeTakenToBurnTheTree(root->left,
                                              leafNode,
                                              leftDist,
                                              time);
      int rightHeight = timeTakenToBurnTheTree(root->right,
                                               leafNode,
                                               rightDist,
                                               time);

      if (leftDist != -1) {
         dist = leftDist + 1;
         time = max(time, dist + rightHeight);
      } else if (rightDist != -1) {
         dist = rightDist + 1;
         time = max(time, dist + leftHeight);
      }
      return (max(leftHeight, rightHeight) + 1);
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
      int res = -1, dist = -1;

      timeTakenToBurnTheTree(root, root->right->left, dist, res);
      cout << res;
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
