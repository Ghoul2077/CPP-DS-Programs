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
    * @brief      Converts given binary tree to doubly linked list using inorder
    *             traversal of tree with the twist that we store which immediate
    *             node we just passed in a prevNode static variable. It's time
    *             complexity is O(n) and it's space complexity is Q(h).
    *
    * @param      root  The root
    *
    * @return     New head of the tree
    */
   Node* convertToDLL(Node *root) {
      if (root == NULL) {
         return (NULL);
      }
      static Node *prevNode = NULL;
      Node *head            = convertToDLL(root->left);

      if (prevNode == NULL) {
         head = root;
      } else {
         root->left      = prevNode;
         prevNode->right = root;
      }
      prevNode = root;
      convertToDLL(root->right);
      return (head);
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
      Node *head = convertToDLL(root);

      while (head != NULL) {
         cout << head->data << " ";
         head = head->right;
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
