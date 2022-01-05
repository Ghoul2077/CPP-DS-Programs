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

   int getHeight(Node *root) {
      if (root == NULL) {
         return (0);
      }
      return (max(getHeight(root->left), getHeight(root->right)) + 1);
   }

   /**
    * @brief      Determines whether the specified tree is balanced or not. It's
    *             time complexity is O(n^2) and it's space complexity is O(h).
    *
    * @param      root  The root
    *
    * @return     True if the specified tree is balanced naive, False otherwise.
    */
   bool isBalancedNaive(Node *root) {
      if (root == NULL) {
         return (true);
      }
      int heightDiff = getHeight(root->left) - getHeight(root->right);

      if (abs(heightDiff) <= 1) {
         return (isBalancedNaive(root->left) && isBalancedNaive(root->right));
      }
      return (false);
   }

   /**
    * @brief      Determines whether the specified tree is balanced or not. It's
    *             time complexity is O(n) and it's space complexity is O(h). We
    *             make use of pair data structure to reduce time complexity of
    *             previous naive solution by returning boolean and height in pair.
    *
    * @param      root  The root
    *
    * @return     True if the specified tree is balanced naive, False otherwise.
    */
   pair<bool, int>isBalanced(Node *root) {
      if (root == NULL) {
         return { true, 0 };
      }
      pair<bool, int> res1 = isBalanced(root->left);
      pair<bool, int> res2 = isBalanced(root->right);
      int newHeight        = max(res1.second, res2.second) + 1;

      return { res1.first && res2.first && abs(res1.second - res2.second) <= 1,
               newHeight };
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
      if (isBalanced(root).first) {
         cout << "Balanced";
      } else {
         cout << "Not Balanced";
      }
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
