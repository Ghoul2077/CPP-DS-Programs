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
    * @brief      Prints the bottom view of a binary tree. Bottom view means
    *             the last node of every vertical line from left to right. The
    *             idea is to go through level order traversal and keep updating
    *             the the last value of every level in the map, by this way we
    *             end up with the last node of every vertical line at end of the
    *             traversal which we print by looping through the for loop. It's
    *             time complexity is O(nlogn) and it's space complexity is O(h).
    *
    * @param      root       The root of binary tree
    */
   void printBottomViewOfBinaryTree(Node *root) {
      if (root == NULL) {
         return;
      }
      map<int, int> map;
      queue<pair<Node *, int> > q;

      q.push({ root, 0 });

      while (!q.empty()) {
         Node *currNode  = (q.front()).first;
         int   currLevel = (q.front()).second;
         map[currLevel] = currNode->data;
         q.pop();

         if (currNode->left != NULL) {
            q.push({ currNode->left, currLevel - 1 });
         }

         if (currNode->right != NULL) {
            q.push({ currNode->right, currLevel + 1 });
         }
      }

      for (auto i: map) {
         cout << i.second << " ";
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
      printBottomViewOfBinaryTree(root);
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
