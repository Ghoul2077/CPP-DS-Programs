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
    * @brief      Prints the nodes at distance k from the root. It's time
    *             time complexity is O(n) and space complexity is O(h).
    *
    * @param      root  The root
    * @param[in]  k     Distance from root
    */
   void printNodesAtDistanceKMain(Node *root, int k) {
      if (root == NULL) {
         return;
      } else if (k == 0) {
         cout << root->data << " ";
      } else {
         printNodesAtDistanceKMain(root->left,  k - 1);
         printNodesAtDistanceKMain(root->right, k - 1);
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

   void printNodesAtDistanceK(int k) {
      printNodesAtDistanceKMain(root, k);
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
      t->printNodesAtDistanceK(1);
      cout << endl;
   }
   return (0);
}
