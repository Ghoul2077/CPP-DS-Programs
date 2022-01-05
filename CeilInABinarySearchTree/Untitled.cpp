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
    * @brief      Finds a ceil of a given value from the given tree. Ceil is
    *             the nearest greater value from the tree. The time complexity
    *             of reccursive version is O(h) and it's space complexity is O(h)
    *
    * @param      root   The root
    * @param[in]  value  The value
    *
    * @return     Ceil value if present, INT_MAX otherwise
    */
   int findCeilReccursive(Node *root, int value) {
      if (root == NULL) {
         return (INT_MAX);
      }

      if (root->data < value) {
         return (findCeilReccursive(root->right, value));
      } else if (root->data > value) {
         int val = findCeilReccursive(root->left, value);
         return (min(val, root->data));
      }

      return (root->data);
   }

   /**
    * @brief      Finds a ceil of a given value from the given tree. Ceil is
    *             the nearest greater value from the tree. The time complexity
    *             of iterative version is O(h) and it's space complexity is O(1)
    *
    * @param      root   The root
    * @param[in]  value  The value
    *
    * @return     Ceil value if present, INT_MAX otherwise
    */
   int findCeilIterative(Node *root, int value) {
      Node *curr = root;
      int   res  = INT_MAX;

      while (curr != NULL) {
         if (curr->data == value) {
            return (curr->data);
         } else if (curr->data < value) {
            curr = curr->right;
         } else if (curr->data > value) {
            res  = curr->data;
            curr = curr->left;
         }
      }
      return (res);
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

   int solve(int value) {
      return (findCeilIterative(root, value));
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
      cout << t->solve(-3);
      cout << endl;
   }
   return (0);
}
