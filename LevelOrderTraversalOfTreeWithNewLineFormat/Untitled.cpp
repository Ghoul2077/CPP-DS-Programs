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

   int getHeight(Node *root, int count = 0) {
      if (root == NULL) {
         return (0);
      } else {
         return (max(getHeight(root->left), getHeight(root->right)) + 1);
      }
   }

   void printElementsAtKDistanceFromNode(Node *root, int k) {
      if (root == NULL) {
         return;
      } else if (k == 0) {
         cout << root->data << " ";
      } else {
         printElementsAtKDistanceFromNode(root->left,  k - 1);
         printElementsAtKDistanceFromNode(root->right, k - 1);
      }
   }

   /**
    * @brief      Prints the tree in level order i.e tree height wise. It's time
    *             complexity is O(h*n) as it finds height and then for every
    *             level prints nodes h distance from root in O(n) time. It's
    *             space complexity is O(1).
    *
    * @param      root  The root
    */
   void levelOrderTraversalWithNewLineNaive(Node *root) {
      int height = getHeight(root);

      for (int i = 0; i < height + 1; i++) {
         printElementsAtKDistanceFromNode(root, i);
         cout << endl;
      }
   }

   /**
    * @brief      Prints the tree in level order i.e tree height wise. It's time
    *             complexity is O(n + h) and it's space complexity is Q(n). This
    *             method works by putting a NULL pointer in the queue after the
    *             end of every level.
    *
    * @param      root  The root
    */
   void levelOrderTraversalWithNewLine(Node *root) {
      queue<Node *> q;

      q.push(root);
      q.push(NULL);

      while (q.size() > 1) {
         Node *curr = q.front();
         q.pop();

         if (curr == NULL) {
            q.push(NULL);
            cout << endl;
            continue;
         }

         cout << curr->data << " ";

         if (curr->left != NULL) {
            q.push(curr->left);
         }

         if (curr->right != NULL) {
            q.push(curr->right);
         }
      }
   }

   /**
    * @brief      Prints the tree in level order i.e tree height wise. It's time
    *             complexity is O(n) and it's space complexity is Q(n). This
    *             method is optimized version of the above given method and does
    *             not put uncessary NULL's in queue.
    *
    * @param      root  The root
    */
   void levelOrderTraversalWithNewLineOptimized(Node *root) {
      queue<Node *> q;

      q.push(root);

      while (!q.empty()) {
         int queueSize = q.size();

         for (int i = 0; i < queueSize; i++) {
            Node *curr = q.front();
            q.pop();
            cout << curr->data << " ";

            if (curr->left != NULL) {
               q.push(curr->left);
            }

            if (curr->right != NULL) {
               q.push(curr->right);
            }
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

   void print() {
      levelOrderTraversalWithNewLineOptimized(root);
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
      t->print();
      cout << endl;
   }
   return (0);
}
