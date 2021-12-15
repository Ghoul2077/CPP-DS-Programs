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

   void inorderPrint(Node *root) {
      if (root == NULL) {
         return;
      }
      inorderPrint(root->left);
      cout << root->data << " ";
      inorderPrint(root->right);
   }

   /**
    * @brief      Function to serialize a binary tree, serializing means
    *             converting / flattening the tree to string or array. Normally
    *             serialize is done in such a way that tree could be constructed
    *             back. In case of tree to construct it back from an array we
    *             need any 2 types of ordering but using some modification we
    *             can do this with single array i.e using -1 for every time we
    *             hit a null. It's time complexity is O(n) and it's space
    *             complexity is O(h).
    *
    * @param      root  The root
    * @param      v     Array containing the serialized result
    */
   void serialize(Node *root, vector<int>& v) {
      if (root == NULL) {
         v.push_back(-1);
         return;
      }
      v.push_back(root->data);
      serialize(root->left,  v);
      serialize(root->right, v);
   }

   /**
    * @brief      Reconstruct binary tree back from given array. The concept
    *             behind this is the we reccursivly traverse the array based on
    *             whether the value is -1 or not create a new node whose left
    *             and right are determined by successive reccursive calls. It's
    *             time complexity is O(n) and it's space complexity is also O(n)
    *
    *
    * @param      v      Serialized version of binary tree
    * @param      index  The index variable to track reccursion depth
    *
    * @return     Root of reconstructed tree
    */
   Node* deserialize(vector<int>& v, int& index) {
      if (index == v.size()) {
         return (NULL);
      }
      int val = v[index++];

      if (val == -1) {
         return (NULL);
      }
      Node *root = new Node(val);

      root->left  = deserialize(v, index);
      root->right = deserialize(v, index);
      return (root);
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
      vector<int> order = {
         10, 5, -1, 9, 7, 6, -1, -1, 8, -1, -1, -1, 15, 11, -1, -1, -1
      };
      int   index = 0;
      Node *res   = deserialize(order, index);

      inorderPrint(res);
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
