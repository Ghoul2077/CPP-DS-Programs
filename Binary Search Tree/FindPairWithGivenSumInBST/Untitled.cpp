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

   bool isValuePresent(Node *root, int val) {
      if (root == NULL) {
         return (false);
      }

      if (root->data == val) {
         return (true);
      }
      return (isValuePresent(root->left, val) || isValuePresent(root->right,
                                                                val));
   }

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

   void getInorderArray(Node *root, vector<int>& arr) {
      if (root == NULL) {
         return;
      }
      getInorderArray(root->left, arr);
      arr.push_back(root->data);
      getInorderArray(root->right, arr);
   }

   void getPairWithGivenSumInArray(vector<int>& arr, int sum) {
      int val1 = 0, val2 = arr.size();

      while (val1 < val2) {
         int currSum = arr[val1] + arr[val2];

         if (currSum < sum) {
            val1++;
         } else if (currSum > sum) {
            val2--;
         } else {
            cout << arr[val1] << " + " << arr[val2];
            return;
         }
      }
   }

   /**
    * @brief      Finds a pair with given sum in a given binary search tree. The
    *             idea behind this approach is to find the difference of sum and
    *             current node value then find this value in the subtrees of
    *             this node. If found we print those values else we repeat the
    *             process for left child node and right child node reccursivly.
    *             It's time complexity is O(n^2) and it's space complexity is
    *             O(n).
    *
    * @param      root  The root of binary search tree
    * @param[in]  sum   The sum we need to find
    */
   void findPairWithGivenSumNaive1(Node *root, int sum) {
      if (root == NULL) {
         return;
      }
      int diff = sum - root->data;

      if (isValuePresent(root->left,
                         diff) || isValuePresent(root->right, diff)) {
         cout << root->data << ", " << diff;
         return;
      }
      findPairWithGivenSumNaive1(root->left,  sum);
      findPairWithGivenSumNaive1(root->right, sum);
   }

   /**
    * @brief      Finds a pair with given sum in a given binary search tree. The
    *             idea is to get the inorder traversal of the tree in an array
    *             and then use two pointer approach on the array to find pair
    *             with the given sum. The thing to remember is that inorder
    *             traversal of a binary tree is always sorted so finding pair
    *             is O(n) in itself. The time complexity of this approach is
    *             Q(n) and it's space complexity is Q(n).
    *
    * @param      root  The root of binary search tree
    * @param[in]  sum   The sum we need to find
    */
   void findPairWithGivenSumNaive2(Node *root, int sum) {
      if (root == NULL) {
         return;
      }
      vector<int> arr;

      getInorderArray(root, arr);
      getPairWithGivenSumInArray(arr, sum);
   }

   /**
    * @brief      Finds a pair with given sum in a given binary search tree. The
    *             idea is to do inorder traversal of the tree and at the same
    *             time keep storing the values in a hash set. At every level we
    *             check if difference exists in the set and if it does then we
    *             found our pair else we keep reccursing until we get our pair
    *             or hit NULL. It's time complexity is O(n) and it's space
    *             complexity is O(n).
    *
    * @param      root  The root of binary search tree
    * @param[in]  sum   The sum we need to find
    */
   void findPairWithGivenSum(Node *root, int sum, unordered_set<int>& s) {
      if (root == NULL) {
         return;
      }
      int diff = sum - root->data;

      if (s.count(diff) == 1) {
         cout << root->data << " + " << diff;
         return;
      }
      findPairWithGivenSum(root->left, sum, s);
      s.insert(root->data);
      findPairWithGivenSum(root->right, sum, s);
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

   void solve(int sum) {
      unordered_set<int> st;

      findPairWithGivenSum(root, sum, st);
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
      int sum;
      cin >> sum;
      t->solve(sum);
      cout << endl;
   }
   return (0);
}
