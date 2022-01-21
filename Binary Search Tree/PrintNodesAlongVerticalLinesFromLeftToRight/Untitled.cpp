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
    * @brief      Prints nodes as vertical lines from left to right. It uses
    *             level order traversal and map to store nodes along same
    *             vertical line. Level order traversal makes sure that the order
    *             in which the nodes appear remains top to bottom. It's time
    *             complexity is O(n) and it's space compleixty is O(n).
    *
    * @param      root  The root of binary tree
    */
   void printVerticalLinesFromLeftToRight(Node *root) {
      if (root == NULL) {
         return;
      }
      map<int, vector<int> >    map;
      queue<pair<Node *, int> > q;

      q.push({ root, 0 });

      while (!q.empty()) {
         pair<Node *, int> curr = q.front();
         int   currVal          = (curr.first)->data;
         Node *leftNode         = (curr.first)->left;
         Node *rightNode        = (curr.first)->right;
         int   currLevel        = curr.second;
         map[currLevel].push_back(currVal);
         q.pop();

         if (leftNode != NULL) {
            q.push({ leftNode, currLevel - 1 });
         }

         if (rightNode != NULL) {
            q.push({ rightNode, currLevel + 1 });
         }
      }

      for (auto i: map) {
         for (auto j : i.second) {
            cout << j << " ";
         }
         cout << endl;
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
      printVerticalLinesFromLeftToRight(root);
   }

   void insert(int data) {
      root = push(root, data);
   }
};

int main() {
   int testCases;

   srand(time(0));
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
