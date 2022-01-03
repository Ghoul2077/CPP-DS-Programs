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

class BSTree {
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

   void searchReccursive(Node *root, int data) {
      if (root == NULL) {
         cout << "False";
         return;
      }

      if (root->data == data) {
         cout << "True";
         return;
      }

      if (root->data < data) {
         searchReccursive(root->right, data);
      } else {
         searchReccursive(root->left, data);
      }
   }

   void searchIterative(Node *root, int data) {
      Node *curr = root;

      while (curr != NULL) {
         if (curr->data == data) {
            cout << "True";
            break;
         }

         if (curr->data < data) {
            curr = curr->right;
         } else {
            curr = curr->left;
         }
      }

      if (curr == NULL) {
         cout << "False";
      }
   }

public:
   BSTree() {
      root = NULL;
   }

   BSTree(int data) {
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

   void solve(int data) {
      searchIterative(root, data);
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
      BSTree *t = new BSTree();
      t->initialize();
      int searchVal;
      cin >> searchVal;
      t->solve(searchVal);
      cout << endl;
   }
   return (0);
}
