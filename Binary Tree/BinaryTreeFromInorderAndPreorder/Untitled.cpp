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

   void printPostorder(Node *root) {
      if (root == NULL) {
         return;
      }
      printPostorder(root->left);
      printPostorder(root->right);
      cout << root->data << " ";
   }

   /**
    * @brief      Constructs a binary tree from given inorder and preorder
    *             arrays. The idea behind is that we use preorder to get the
    *             parent elements (eg: first element of preorder is always root
    *             of the tree) and inorder to get the left and right nodes. It's
    *             time complexity is O(n^2) and it's space complexity is Q(h).
    *
    * @param      inorder       The inorder
    * @param      preorder      The preorder
    * @param[in]  inorderStart  The inorder start
    * @param[in]  inorderEnd    The inorder end
    *
    * @return     Root of the binary tree
    */
   Node* postorderTraversalFromInorderAndPreorder(int *inorder,
                                                  int *preorder,
                                                  int  inorderStart,
                                                  int  inorderEnd) {
      if (inorderStart > inorderEnd) {
         return (NULL);
      }
      static int preorderIndex = 0;
      Node *root               = new Node(preorder[preorderIndex++]);

      int inIndex;

      for (int i = inorderStart; i <= inorderEnd; i++) {
         if (inorder[i] == root->data) {
            inIndex = i;
            break;
         }
      }

      root->left = postorderTraversalFromInorderAndPreorder(inorder,
                                                            preorder,
                                                            inorderStart,
                                                            inIndex - 1);
      root->right = postorderTraversalFromInorderAndPreorder(inorder,
                                                             preorder,
                                                             inIndex + 1,
                                                             inorderEnd);
      return (root);
   }

   /**
    * @brief      Constructs a binary tree from given inorder and preorder
    *             arrays. The idea behind is that we use preorder to get the
    *             parent elements (eg: first element of preorder is always root
    *             of the tree) and inorder to get the left and right nodes. It's
    *             time complexity is O(n) and it's space complexity is Q(h). We
    *             use some pre computations to convert inorder array to hashmap
    *             which reduces work done per reccursive call to O(1).
    *
    * @param      inorder       The inorder
    * @param      preorder      The preorder
    * @param[in]  inorderStart  The inorder start
    * @param[in]  inorderEnd    The inorder end
    *
    * @return     Root of the binary tree
    */
   Node* postorderTraversalFromInorderAndPreorderOptimized(
      unordered_map<int, int>& inorderHashmap,
      int                     *preorder,
      int                      inorderStart,
      int                      inorderEnd)
   {
      if (inorderStart > inorderEnd) {
         return (NULL);
      }
      static int preorderIndex = 0;
      Node *root               = new Node(preorder[preorderIndex++]);

      int inIndex = inorderHashmap[root->data];

      root->left = postorderTraversalFromInorderAndPreorderOptimized(
         inorderHashmap,
         preorder,
         inorderStart,
         inIndex - 1);
      root->right = postorderTraversalFromInorderAndPreorderOptimized(
         inorderHashmap,
         preorder,
         inIndex + 1,
         inorderEnd);
      return (root);
   }

public:
   Tree() {
      root = NULL;
   }

   Tree(int data) {
      root = new Node(data);
   }

   void solve(int *inorder, int *preorder, int size) {
      unordered_map<int, int> arrayToHashMap;

      for (int i = 0; i < size; i++) {
         arrayToHashMap.insert({ inorder[i], i });
      }
      root = postorderTraversalFromInorderAndPreorderOptimized(arrayToHashMap,
                                                               preorder,
                                                               0,
                                                               size - 1);
      printPostorder(root);
   }
};

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      int   inorder[]  = { 40, 20, 50, 10, 30, 80, 70, 90 };
      int   preorder[] = { 10, 20, 40, 50, 30, 70, 80, 90 };
      int   size       = sizeof(inorder) / sizeof(inorder[0]);
      Tree *t          = new Tree();
      t->solve(inorder, preorder, size);
      cout << endl;
   }
   return (0);
}
