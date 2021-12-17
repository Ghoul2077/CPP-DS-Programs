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
    * @brief      Prints an inorder traversal of a given tree using iterations.
    *             The catch here is to use stack to store previously passed
    *             nodes and keep tranversing to left only switching to right
    *             when you encounter null. It's time complexity is O(n) and it's
    *             space complexity is Q(h).
    *
    * @param      root  The root of binary tree
    */
   void printInorderIterative(Node *root) {
      stack<Node *> st;
      Node *curr = root;

      while (curr != NULL || !st.empty()) {
         while (curr != NULL) {
            st.push(curr);
            curr = curr->left;
         }
         curr = st.top();
         st.pop();
         cout << curr->data << " ";
         curr = curr->right;
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
      printInorderIterative(root);
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
