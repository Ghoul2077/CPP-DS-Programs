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
    * @brief      Does spiral / snake traversal of given binary tree. It uses
    *             level order traversal with stack data structure to get reverse
    *             of a given level. It's time complexity is O(n) and it's space
    *             complexity is O(h).
    *
    * @param      root  The root
    */
   void spiralTraversalNaive(Node *root) {
      if (root == NULL) {
         return;
      }
      queue<Node *> q;

      q.push(root);
      bool reverse = false;

      while (!q.empty()) {
         int size = q.size();
         stack<Node *> st;

         for (int i = 0; i < size; i++) {
            Node *curr = q.front();
            q.pop();

            if (reverse) {
               st.push(curr);
            } else {
               cout << curr->data << " ";
            }

            if (curr->left != NULL) {
               q.push(curr->left);
            }

            if (curr->right != NULL) {
               q.push(curr->right);
            }
         }

         while (reverse && !st.empty()) {
            Node *curr = st.top();
            st.pop();
            cout << curr->data << " ";
         }

         reverse = !reverse;
      }
   }

   /**
    * @brief      Does spiral / snake traversal of given binary tree. It uses
    *             level order traversal with 2 stacks for alternate levels to
    *             get alternating snake traversal. It's time complexity is O(n)
    *             and it's space complexity is O(h). It is more optimized than
    *             previous approach as it only pushes and pops every elements in
    *             the stack only once unlinke twice in previous approach.
    *
    * @param      root  The root
    */
   void spiralTraversal(Node *root) {
      if (root == NULL) {
         return;
      }
      stack<Node *> st1, st2;

      st1.push(root);
      bool reverse = false;

      while (!st1.empty() || !st2.empty()) {
         int size = reverse ? st1.size() : st2.size();

         for (int i = 0; i < size; i++) {
            Node *curr;

            if (reverse)  {
               curr = st1.top();
               st1.pop();

               if (curr->left != NULL) {
                  st2.push(curr->left);
               }

               if (curr->right != NULL) {
                  st2.push(curr->right);
               }
            } else {
               curr = st2.top();
               st2.pop();

               if (curr->right != NULL) {
                  st1.push(curr->right);
               }

               if (curr->left != NULL) {
                  st1.push(curr->left);
               }
            }
            cout << curr->data << " ";
         }
         reverse = !reverse;
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
      spiralTraversal(root);
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
