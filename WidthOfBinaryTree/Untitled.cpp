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
    * @brief      Gets the width of given binary tree. It uses level order
    *             traversal and it's time complexity is O(n) and it's space
    *             complexity is O(width) or O(n).
    *
    * @param      root  The root
    *
    * @return     The width.
    */
   int getWidth(Node *root) {
      if (root == NULL) {
         return (0);
      }

      int width = INT_MIN;
      queue<Node *> q;

      q.push(root);

      while (!q.empty()) {
         int currSize = q.size();
         width = max(width, currSize);

         for (int i = 0; i < currSize; i++) {
            Node *currNode = q.front();
            q.pop();

            if (currNode->left != NULL) {
               q.push(currNode->left);
            }

            if (currNode->right != NULL) {
               q.push(currNode->right);
            }
         }
      }

      return (width);
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
      return (getWidth(root));
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
