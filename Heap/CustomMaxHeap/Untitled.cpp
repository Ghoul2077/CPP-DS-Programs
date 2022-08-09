#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;
#define deb(x) cout << # x << " = " << x << endl;
#define deb2(x, \
             y) cout << # x << " = " << x << ", " << # y << " = " << y << endl;

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

class MaxHeap {
private:
   int *arr;
   int size;
   int capacity;

   /**
    * @brief      Fixes the ith, (2*i+1)th, (2*i+2)th nodes of the tree
    *             reccursivly. The idea is to find the left child node and
    *             right child node of the current node. Between the 3 nodes find
    *             if the parent node is the biggest of them all if not then we
    *             swap the parent node with the biggest value and then we
    *             reccursivly call heapify to fix subsequent subtree which have
    *             been disrupted with our swap. It's time complexity is O(logn)
    *             or O(h). As heap is a complete binary tree it's height is
    *             equal to logn so both time complexity are viable
    *
    * @param[in]  i     The parent node to fix
    */
   void maxHeapify(int i) {
      int largest = i, left = getLeftChild(i), right = getRightChild(i);

      if ((left < size) && (arr[largest] < arr[left])) {
         largest = left;
      }

      if ((right < size) && (arr[largest] < arr[right])) {
         largest = right;
      }

      if (largest != i) {
         swap(arr[largest], arr[i]);
         maxHeapify(largest);
      }
   }

   /**
    * @brief      Used to build tree from any given array, it's time complexity
    *             is O(n). The idea is to keep calling heapify function for all
    *             parent nodes. The last parent node from top will always be at
    *             (n - 2) / 2 position.
    */
   void buildHeap() {
      for (int i = (size - 2) / 2; i >= 0; i--) {
         maxHeapify(i);
      }
   }

public:
   MaxHeap(int capacity_ = 50) {
      arr      = new int[capacity_];
      size     = 0;
      capacity = capacity_;
   }

   void initialize() {
      size = 0;

      for (int i = 0; i < capacity; i++) {
         int val;
         cin >> val;

         if (val == -1) {
            break;
         }
         arr[size++] = val;
      }

      buildHeap();
   }

   void printHeap() {
      for (int i = 0; i < size; i++) {
         cout << arr[i] << " ";
      }
      cout << endl;
   }

   int getLeftChild(int i) {
      return (2 * i + 1);
   }

   int getRightChild(int i) {
      return (2 * i + 2);
   }

   int getParent(int i) {
      return (floor((i - 1) / 2));
   }

   int getMin() {
      return (size > 0 ? arr[0] : INT_MAX);
   }

   /**
    * @brief      Inserts a given value into given heap. The idea is to insert
    *             value at the end of the array and then starting from the
    *             last node we start comparing current node with it's parent and
    *             if it is smaller then we swap current node with it's parent.
    *             After swapping we goto our next node which will be the parent
    *             of the previous node. The time complexity of insert in a heap
    *             is O(logn) or O(h).
    *
    * @param[in]  data  The data to be inserted
    */
   void insert(int data) {
      if (size != capacity) {
         arr[size] = data;

         for (int i = size; i != 0 && arr[getParent(i)] < arr[i];) {
            swap(arr[getParent(i)], arr[i]);
            i = getParent(i);
         }
         size++;
      }
   }

   /**
    * @brief      Removes the max value from the max heap. The idea is to swap
    *             the root element with the last element and then reduce the
    *             size of heap, after this we call heapify on the root element
    *             to fix it's position by calling heapify function on the root
    *             element. It's time complexity is same as heapify i.e O(logn).
    *
    * @return     Max value if exists, INT_MIN otherwise
    */
   int extractMax() {
      if (size != 0) {
         swap(arr[0], arr[--size]);
         maxHeapify(0);
         return (arr[size]);
      }
      return (INT_MIN);
   }

   /**
    * @brief      Update the value at given index of a binary heap tree to a
    *             greater value. The idea is to replace the index value and then
    *             we start heapifying starting from the given index until we
    *             reach a node that does not need heapifying or we reach the
    *             root node. It's time complexity is O(n).
    *
    * @param[in]  index   The index to replace
    * @param[in]  newVal  The new value
    */
   void increaseIndexVal(int index, int newVal) {
      if ((index < size) && (newVal > arr[index])) {
         arr[index] = newVal;

         while (index != 0 && arr[getParent(index)] < arr[index]) {
            swap(arr[index], arr[getParent(index)]);
            index = getParent(index);
         }
      }
   }

   /**
    * @brief      Deletes a given index, here we use the same methodology that
    *             we use for extract max i.e we swap last element with the
    *             element we want to delete and after this we call heapify for
    *             the to delete index. It's time complexity is O(logn).
    *
    * @param[in]  index  The index to delete
    */
   void deleteIndex(int index) {
      if (index < size) {
         swap(arr[index], arr[--size]);
         maxHeapify(index);
      }
   }
};

int main() {
   int testCases;

   srand(time(0));
   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      MaxHeap *t = new MaxHeap();
      t->initialize();
      t->insert(17);
      t->extractMax();
      t->increaseIndexVal(2, 12);
      t->deleteIndex(3);
      t->printHeap();
      cout << endl;
   }
   return (0);
}
