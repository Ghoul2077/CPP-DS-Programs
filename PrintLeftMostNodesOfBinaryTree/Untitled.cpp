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
    * @brief      Prints left most nodes of each level of the tree. It is a
    *             reccursive solution that follows pre order traversal of the
    *             tree with added condition to print the data of the node if
    *             the left most node of that level is not already printed, for
    *             that we use additional global variable maxLevel which is
    *             incremented when leftmost node is accessed. It's time
    *             complexity is O(n) and it's space complexity is O(h).
    *
    * @param      root      The root
    * @param      maxLevel  The maximum level
    * @param[in]  level     The level
    */
   void printLeftMostNodesReccursive(Node *root, int& maxLevel, int level = 1) {
      if (root == NULL) {
         return;
      }

      if (maxLevel < level) {
         cout << root->data << " ";
         maxLevel = level;
      }
      printLeftMostNodesReccursive(root->left,  maxLevel, level + 1);
      printLeftMostNodesReccursive(root->right, maxLevel, level + 1);
   }

   /**
    * @brief      Prints left most nodes of each level of the tree. It is an
    *             iterative solution that uses queue to keep track of items of
    *             each level and then print the first item in queue which is
    *             always the left most element of that level. It's time
    *             complexity is Q(n) and it's space complexity is O(n).
    *
    * @param      root      The root
    * @param      maxLevel  The maximum level
    * @param[in]  level     The level
    */
   void printLeftMostNodes(Node *root) {
      if (root == NULL) {
         return;
      }

      queue<Node *> q;

      q.push(root);

      while (!q.empty()) {
         cout << q.front()->data << " ";
         int size = q.size();

         for (int i = 0; i < size; i++) {
            Node *curr = q.front();
            q.pop();

            if (curr->left != NULL) {
               q.push(curr->left);
            }

            if (curr->right != NULL) {
               q.push(curr->right);
            }
         }
      }
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
      int maxLevel = 0;

      printLeftMostNodesReccursive(root, maxLevel);
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
