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

   Node* findPredecessorModified(Node *root) {
      if ((root == NULL) || (root->left == NULL)) {
         return (NULL);
      }
      Node *curr = root->left;

      while (curr->right != NULL && curr->right != root) {
         curr = curr->right;
      }
      return (curr);
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
   void iterativePreorderTraversalNaive2(Node *root) {
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

   /**
    * @brief      Prints an preorder traversal of a given tree using iterations.
    *             This is a special method called morris traversal and it has
    *             O(1) space complexity but the idea is a bit tricky as we do
    *             some modifications to the tree which are reverted back after
    *             traversal. The idea behind this is to precompute the
    *             predecessor of current node in advance if left child node
    *             exists then point the right of this predecessor to the current
    *             node so this makes a loop where we will return to the current
    *             node after we have traversed the left subtree of the node.
    *             When the right of predecessor is not null we know that this is
    *             a node that we had previously modified to point to the current
    *             node and we need to move to the right tree. Based on where you
    *             put your print statement this same code can be used as inorder
    *             or postorder traversal. This approach has a time complexity of
    *             O(n) and it's time complexity is O(1).
    *
    * @param      root  The root of binary tree
    */
   void iterativePreorderTraversal(Node *root) {
      if (root == NULL) {
         return;
      }
      Node *curr = root;

      while (curr != NULL) {
         if (curr->left == NULL) {
            cout << curr->data << " ";
            curr = curr->right;
         } else {
            Node *predecessor = findPredecessorModified(curr);

            if (predecessor == NULL) {
               curr = curr->right;
            } else if (predecessor->right == NULL) {
               predecessor->right = curr;
               cout << curr->data << " ";
               curr = curr->left;
            } else {
               predecessor->right = NULL;
               curr               = curr->right;
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
