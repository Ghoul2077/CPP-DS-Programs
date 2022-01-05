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
    * @brief      Finds preorder traversal of a given binary tree using
    *             iteration. This is a simple problem of putting elements in
    *             stack and popping them as they come, here the thing to note is
    *             we push right first to the stack because of last in first out
    *             nature of the stack. It's time complexity is O(n) and space
    *             complexity is O(n).
    *
    * @param      root  The root of the binary tree
    */
   void iterativePreorderTraversalNaive(Node *root) {
      Node *curr = root;
      stack<Node *> st;

      st.push(root);

      while (!st.empty()) {
         Node *curr = st.top();
         st.pop();
         cout << curr->data << " ";

         if (curr->right != NULL) {
            st.push(curr->right);
         }

         if (curr->left != NULL) {
            st.push(curr->left);
         }
      }
   }

   /**
    * @brief      Finds preorder traversal of a given binary tree using
    *             iteration. This method takes less space than the previous
    *             method. It's time complexity is O(n) and it's space complexity
    *             is O(n).
    *
    * @param      root  The root of the binary tree
    */
   void iterativePreorderTraversal(Node *root) {
      Node *curr = root;
      stack<Node *> st;

      while (curr != NULL || !st.empty()) {
         while (curr != NULL) {
            st.push(curr);
            cout << curr->data << " ";
            curr = curr->left;
         }
         curr = st.top();
         st.pop();
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
      iterativePreorderTraversalNaive(root);
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
