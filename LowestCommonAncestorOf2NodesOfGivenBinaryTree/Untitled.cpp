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

   bool findPath(Node *root, Node *node, vector<Node *>& arr) {
      if (root == NULL) {
         return (false);
      }
      arr.push_back(root);

      if (root == node) {
         return (true);
      }

      if (findPath(root->left, node, arr) || findPath(root->right, node, arr)) {
         return (true);
      }
      arr.pop_back();
      return (false);
   }

   bool isPartOfSubtree(Node *root, Node *node) {
      if ((root == NULL) || (node == NULL)) {
         return (false);
      }

      if (root == node) {
         return (true);
      }
      return (
         isPartOfSubtree(root->left,  node) ||
         isPartOfSubtree(root->right, node)
         );
   }

   /**
    * @brief      Gets the common ancestor of given 2 nodes from a tree. It's
    *             time complexity is O(n^2) and it's space complexity is Q(h).
    *             The idea behind this approach is that we use a function which
    *             tells us whether a given node exists in a given tree. Now we
    *             just call this function for every node reccursivly in bottom
    *             up manner until you hit the first node where both 2 given
    *             nodes exists in tree that node forms and then return that node
    *             otherwise keep going further into the tree until we hit null.
    *
    *
    * @param      root   The root
    * @param      node1  The node 1
    * @param      node2  The node 2
    *
    * @return     The common ancestor if any, NULL otherwise
    */
   Node* getCommonAncestorNaive1(
      Node *root,
      Node *node1,
      Node *node2
      ) {
      if ((root == NULL) || (node1 == NULL) || (node2 == NULL)) {
         return (NULL);
      }
      Node *res1 = getCommonAncestorNaive1(root->left, node1, node2);
      Node *res2 = getCommonAncestorNaive1(root->right, node1, node2);

      if ((res2 == NULL) && (res1 != NULL)) {
         return (res1);
      }

      if ((res1 == NULL) && (res2 != NULL)) {
         return (res2);
      }

      if (isPartOfSubtree(root, node1) && isPartOfSubtree(root, node2)) {
         return (root);
      }

      return (NULL);
   }

   /**
    * @brief      Gets the common ancestor of 2 given nodes of a tree. It's time
    *             complexity is O(n) overall which consists of 2 findPath (O(n))
    *             function calls which return whether given node exists in given
    *             tree and also takes a vector as parameter which given the
    *             path to that node from root of the tree. After getting the
    *             path to both nodes the rest of the idea is that the path to
    *             lowest common ancestor will always contain the same nodes so
    *             the first node encountered whose next nodes in both array are
    *             not matching will be our answer. It's space complexity is O(h)
    *
    * @param      root   The root
    * @param      node1  The node 1
    * @param      node2  The node 2
    *
    * @return     The common ancestor if exists, NULL otherwise
    */
   Node* getCommonAncestorNaive2(
      Node *root,
      Node *node1,
      Node *node2
      ) {
      vector<Node *> arr1, arr2;

      if (!findPath(root, node1, arr1) || !findPath(root, node2, arr2)) {
         return (NULL);
      }

      for (int i = 0; i < arr1.size() && i < arr2.size(); i++) {
         if (arr1[i + 1] != arr2[i + 1]) {
            return (arr1[i]);
         }
      }
      return (NULL);
   }

   /**
    * @brief      Gets the common ancestor of 2 given nodes of a tree. This
    *             approach is reccursive is is inspired by naive 1 approach and
    *             it works around the fact that a node will be LCA (lowest
    *             common ancestor) when one node is present in it's left subtree
    *             and the other node is present in it's right subtree. So based
    *             on that we reccursivly find first such ancestor in O(n) time
    *             complexity and Q(h) space complexity. One disadvantage of this
    *             approach is that it considers that both nodes are part of the
    *             given tree otherwise it returns random answer.
    *
    * @param      root   The root
    * @param      node1  The node 1
    * @param      node2  The node 2
    *
    * @return     The common ancestor if exists.
    */
   Node* getCommonAncestor(Node *root, Node *node1, Node *node2) {
      if (root == NULL) {
         return (NULL);
      }

      if ((root == node1) || (root == node2)) {
         return (root);
      }

      Node *lowestCommonAncestor1 = getCommonAncestor(root->left, node1, node2);
      Node *lowestCommonAncestor2 =
         getCommonAncestor(root->right, node1, node2);

      if ((lowestCommonAncestor1 != NULL) && (lowestCommonAncestor2 != NULL)) {
         return (root);
      }

      if (lowestCommonAncestor1 != NULL) {
         return (lowestCommonAncestor1);
      }

      return (lowestCommonAncestor2);
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
      Node *node1 = root->right;
      Node *node2 = root->right->left;
      Node *ans   = getCommonAncestor(root, node1, node2);

      if (ans != NULL) {
         cout << ans->data;
      } else {
         cout << "No common ancestor";
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
