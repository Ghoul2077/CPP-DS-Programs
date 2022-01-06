#include <bits/stdc++.h>
using namespace std;

/**
 * @brief      This class describes a node.
 */
class Node {
public:
   int data;
   Node *next;

   /**
    * @brief      (Parameterized Constructor) Constructs a new instance.
    *
    * @param[in]  data  The data
    */
   Node(const int data) {
      this->data = data;
      this->next = NULL;
   }

   /**
    * @brief      (Copy Constructor) Constructs a new instance.
    *
    * @param      initNode  The node from which initial data is to be copied from
    */
   Node(const Node *initNode) {
      this->data = initNode->data;
      this->next = initNode->next;
   }
};

/**
 * @brief      This class describes a linked list.
 */
class LinkedList {
private:
   Node *head;
   int length;
   Node *tail;

public:

   /**
    * @brief      Constructs a new instance of linked list.
    */
   LinkedList() {
      this->head   = NULL;
      this->length = 0;
      this->tail   = NULL;
   }

   /**
    * @brief      Constructs a new instance of linked list from given pointer
    *             which we treat as head of another linked list and length that
    *             needs to be copied ahead of the head, if not given copied
    *             until null.
    *
    * @param      head    The head
    * @param[in]  length  The length (Optional)
    */
   LinkedList(Node *head, int length = -1) {
      this->head = new Node(head);
      Node *ptr1 = head;
      Node *ptr2 = this->head;

      if (length == -1) {
         this->length = 1;

         while (ptr1->next != NULL) {
            ptr1       = ptr1->next;
            ptr2->next = new Node(ptr1);
            ptr2       = ptr2->next;
            this->length++;
         }
         this->tail = new Node(ptr1);
      } else {
         this->length = length;

         for (int i = 0; i < length - 1; i++) {
            ptr1       = ptr1->next;
            ptr2->next = new Node(ptr1);
            ptr2       = ptr2->next;
         }
         this->tail = new Node(ptr1);
      }
      ptr2->next = NULL;
   }

   /**
    * @brief      Prints a linked list.
    */
   void printLL() {
      Node *ptr = this->head;

      cout << "*";

      while (ptr != NULL) {
         cout << "->" << ptr->data;
         ptr = ptr->next;
      }
      cout << "\n";
   }

   /**
    * @brief      Initializes the linked list.
    */
   void initializeLL() {
      int   data;
      Node *ptr = this->head;

      cout << "Enter value, otherwise enter -1 to exit : ";
      cin >> data;

      while (data != -1) {
         Node *newNode = new Node(data);

         if (ptr == NULL) {
            this->head = newNode;
            ptr        = newNode;
         } else {
            ptr->next = newNode;
            ptr       = ptr->next;
         }
         this->length++;
         cin >> data;
      }

      this->tail = ptr;
   }

   /**
    * @brief     Reverses the linked list
    */
   void reverseLL() {
      if (this->head == NULL) {
         return;
      }

      Node *curr = this->head;
      Node *prev = NULL;
      Node *next = curr->next;

      while (curr != NULL) {
         next       = curr->next;
         curr->next = prev;
         prev       = curr;
         curr       = next;
      }

      this->tail = this->head;
      this->head = prev;
   }

   /**
    * @brief     Merges link lists in sorted manner assuming both linked list
    *            are separately sorted in themselves
    *
    * @param      l2    The linked list to merge into current linked list
    */
   void merge(const LinkedList *l2) {
      if ((l2 == NULL) || (l2->head == NULL)) {
         return;
      } else if (this->head == NULL) {
         this->head = l2->head;
      }

      Node *ptr1 = l2->head->data < this->head->data ? l2->head : this->head;
      Node *ptr2 = this->head->data > l2->head->data ? this->head : l2->head;

      while (ptr1 != NULL && ptr2 != NULL) {
         if (ptr1->next != NULL) {
            if ((ptr1->data <= ptr2->data) &&
                (ptr2->data <= ptr1->next->data)) {
               Node *temp1 = ptr1->next;
               Node *temp2 = ptr2->next;
               ptr1->next = ptr2;
               ptr2->next = temp1;
               ptr2       = temp2;
            }
         } else {
            ptr1->next = ptr2;
            break;
         }
         ptr1 = ptr1->next;
      }

      this->length = this->length + l2->length;
      this->tail   = l2->tail;

      if (this->head->data > l2->head->data) {
         this->head = l2->head;
      }
   }

   /**
    * @brief     Merge sort
    *
    * @param      ll   Sub linked list parameter used for recursive call
    */
   void sort() {
      if (this->length > 1) {
         Node *middlePtr      = NULL;
         int   halfListLength = floor(this->length / 2);

         for (int i = 0; i < halfListLength; i++) {
            if (middlePtr == NULL) {
               middlePtr = this->head;
            } else {
               middlePtr = middlePtr->next;
            }
         }

         LinkedList *ll1 = new LinkedList(this->head, halfListLength);
         LinkedList *ll2 = new LinkedList(middlePtr->next,
                                          length - halfListLength);

         ll1->sort();
         ll2->sort();
         ll1->merge(ll2);

         deleteLL();
         this->head = ll1->head;
      }
   }

   /**
    * @brief      Deletes the linked list called upon
    */
   void deleteLL() {
      Node *current = this->head;
      Node *next    = NULL;

      while (current != NULL) {
         next = current->next;
         free(current);
         current = next;
      }

      this->head   = NULL;
      this->length = 0;
      this->tail   = NULL;
   }
};

int main() {
   LinkedList *l1 = new LinkedList;
   LinkedList *l2 = new LinkedList;

   l1->initializeLL();

   // l2->initializeLL();
   // l1->merge(l2);
   l1->sort();

   // l1->reverseLL();
   l1->printLL();
}
