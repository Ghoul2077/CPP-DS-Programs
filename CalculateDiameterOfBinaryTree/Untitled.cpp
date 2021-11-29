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

   int getHeightModified(
      Node *root, unordered_map<Node *, int>& nodeToHeightMap
      ) {
      if (root == NULL) {
         return (0);
      }
      int currHeight = max(getHeightModified(root->left, nodeToHeightMap),
                           getHeightModified(root->right, nodeToHeightMap)) + 1;

      nodeToHeightMap.insert({ root, currHeight });
      return (currHeight);
   }

   /**
    * @brief      Gets the diameter of tree reccursivly. Diameter of a tree is
    *             maximum distance between any 2 nodes in a tree. It's time
    *             complexity is O(n^2) and it's space complexity is Q(h).
    *
    * @param      root  The root
    *
    * @return     The diameter of tree naive.
    */
   int getDiameterOfTreeNaive(Node *root) {
      if (root == NULL) {
         return (0);
      }
      int currNodeDiameter = getHeight(root->left) + getHeight(root->right) +
                             1;
      int leftNodeDiameter  = getDiameterOfTreeNaive(root->left);
      int rightNodeDiameter = getDiameterOfTreeNaive(root->right);

      return (max(rightNodeDiameter, max(currNodeDiameter, leftNodeDiameter)));
   }

   /**
    * @brief      Gets the diameter of tree reccursivly. Diameter of a tree is
    *             maximum distance between any 2 nodes in a tree. It's time
    *             complexity is O(n) and it's space complexity is Q(h+n). It's
    *             optimized version of the above naive approach as we have done
    *             some precomputation and calculated heights of each node and
    *             stored them in a map which essentially removes the need of
    *             calculating height in each reccusive call.
    *
    * @param      root  The root
    *
    * @return     The diameter of tree naive.
    */
   int getDiameterOfTree(
      Node                     *root,
      unordered_map<Node *, int>nodeToHeightMap
      ) {
      if (root == NULL) {
         return (0);
      }
      int currNodeDiameter = nodeToHeightMap[root->left] +
                             nodeToHeightMap[root->right] + 1;
      int leftNodeDiameter  = getDiameterOfTree(root->left, nodeToHeightMap);
      int rightNodeDiameter = getDiameterOfTree(root->right, nodeToHeightMap);

      return (max(rightNodeDiameter, max(currNodeDiameter, leftNodeDiameter)));
   }

   /**
    * @brief      Gets the diameter of tree reccursivly. Idea behind this method
    *             is that we modify the height function to get diameter of every
    *             node and store the maximum one in a reference variable passed
    *             to the function. It's time comlpexity is O(n) and it's space
    *             complexity is Q(h).
    *
    * @param      root  The root
    *
    * @return     The diameter of tree naive.
    */
   int getDiameterOfTreeEfficient(Node *root, int& diameter) {
      if (root == NULL) {
         return (0);
      }
      int leftSubtreeHeight  = getDiameterOfTreeEfficient(root->left, diameter);
      int rightSubtreeHeight =
         getDiameterOfTreeEfficient(root->right, diameter);
      int currHeight = max(leftSubtreeHeight, rightSubtreeHeight) + 1;

      diameter = max(diameter, leftSubtreeHeight + rightSubtreeHeight + 1);
      return (currHeight);
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

   int solve() {
      unordered_map<Node *, int> nodeToHeightMap;

      getHeightModified(root, nodeToHeightMap);
      return (getDiameterOfTree(root, nodeToHeightMap));
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
      cout << t->solve();
      cout << endl;
   }
   return (0);
}
