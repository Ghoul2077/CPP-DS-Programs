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
    * @brief      Prints the nodes of a tree in level order traversal i.e first
    *             print all nodes at height 0, height 1, height 2 and so on. We
    *             use queue data structure to get time complexity of Q(n) and
    *             it's space complexity is O(n);
    *
    * @param      root  The root
    */
   void levelOrderTraversal(Node *root) {
      if (root == NULL) {
         return;
      }

      queue<Node *> q;

      q.push(root);

      while (!q.empty()) {
         Node *currNode = q.front();
         cout << currNode->data << " ";

         if (currNode->left != NULL) {
            q.push(currNode->left);
         }

         if (currNode->right != NULL) {
            q.push(currNode->right);
         }
         q.pop();
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

   void print() {
      levelOrderTraversal(root);
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
